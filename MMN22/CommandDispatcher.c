//
// Created by Yotam Levit on 14/05/2024.
//

#include "stdlib.h"

#include "CommandDispatcher.h"
#include "set.h"
#include "Errors.h"
#include "CommandParser.h"

#define NUM_OF_COMMANDS 6


int threeSetDispatcher(FunctionPointer func, UserCommandPtr userCommand)
{
    if (userCommand->setsCount != 3)
        return userCommand->setsCount < 3 ? missingParamError : tooManySets;

    if (userCommand->argCount)
        return extraTextAfterCommand;

    return func.threeSetFunctions(userCommand->sets[0], userCommand->sets[1], userCommand->sets[2]);
}

int strOutputSetDispatcher(FunctionPointer func, UserCommandPtr userCommand)
{
    int result;
    char *output = NULL;
    //ThreeSetFunctionsPointer execFunc = func;

    if (userCommand->setsCount != 1)
        return userCommand->setsCount < 1 ? missingParamError : tooManySets;

    if (userCommand->argCount > 0)
        return extraTextAfterCommand;

    result = func.strOutputSetFunction(userCommand->sets[0], &output);

    printf("\n%s\n\n", output);

    return result;
}

int* convertAToIntList(char** numberList, int listLength)
{
    int i;
    //int intList[listLength];
    int* intList = (int*) malloc( listLength * sizeof(int));

    for (i = 0; i < listLength; ++i) {
        intList[i] = atoi(numberList[i]);
    }

    return intList;
}

int setAndNumbersDispatcher(FunctionPointer func, UserCommandPtr userCommand)
{
    int* numbers;
    int result;

    if(userCommand->setsCount != 1)
        return userCommand->setsCount < 1 ? missingParamError : tooManySets;

    if (userCommand->argCount == 0)
        return missingParamError;

    numbers = convertAToIntList(userCommand->arguments, userCommand->argCount);

    if(numbers[userCommand->argCount-1] != END_OF_LIST)
        return missingEndOfListError;

    result = func.setAndNumbersFunction(userCommand->sets[0], numbers);

    free(numbers);

    return result;
}

HashMapPtr initCommandMap() {
    int i;
    char *commandNames[NUM_OF_COMMANDS] = {"read_set", "print_set", "union_set", "intersect_set", "sub_set",
                                           "symdiff_set"};

    CommandMapValue *commandsFunctions[NUM_OF_COMMANDS];
    for (i = 0; i < NUM_OF_COMMANDS; ++i) {
        commandsFunctions[i] = malloc(sizeof(CommandMapValue));
    }
    *commandsFunctions[0] = (CommandMapValue){{.setAndNumbersFunction = readSet}, setAndNumbersDispatcher};
    *commandsFunctions[1] = (CommandMapValue){{.strOutputSetFunction = printSet}, strOutputSetDispatcher};
    *commandsFunctions[2] = (CommandMapValue){{.threeSetFunctions = unionSet}, threeSetDispatcher};
    *commandsFunctions[3] = (CommandMapValue){{.threeSetFunctions = intersectSet}, threeSetDispatcher};
    *commandsFunctions[4] = (CommandMapValue){{.threeSetFunctions = subSet}, threeSetDispatcher};
    *commandsFunctions[5] = (CommandMapValue){{.threeSetFunctions = symDiffSet}, threeSetDispatcher};


/*    CommandMapValue commandsFunctions[NUM_OF_COMMANDS] = {
            {{.setAndNumbersFunction = readSet}, (Dispatcher) setAndNumbersDispatcher},
            {{.strOutputSetFunction = printSet}, (Dispatcher) strOutputSetDispatcher},
            {{.threeSetFunctions = unionSet}, (Dispatcher) threeSetDispatcher},
            {{.threeSetFunctions = intersectSet}, (Dispatcher) threeSetDispatcher},
            {{.threeSetFunctions = subSet}, (Dispatcher) threeSetDispatcher},
            {{.threeSetFunctions = symDiffSet}, (Dispatcher) threeSetDispatcher}
    };*/

    HashMapPtr map = createHashMap(NUM_OF_COMMANDS, NULL, NULL);

    if (!map)
        return NULL;

    for (i = 0; i < NUM_OF_COMMANDS; i++) {
        hashMapInsert(map, commandNames[i], commandsFunctions[i]);
    }

    return map;
}


int runCommand(HashMapPtr commandMap, UserCommandPtr command)
{
    CommandMapValuePtr commandFunction = (CommandMapValuePtr)hashMapFind(commandMap, command->command);

    if (!commandFunction)
        return undefinedCommandNameError;

    return commandFunction->functionDispatcher(commandFunction->commandFunction, command);
    //dp(commandFunction->commandFunction, command);
}
