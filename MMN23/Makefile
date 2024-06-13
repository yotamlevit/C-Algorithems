CC=gcc
CFLAGS = -Wall -pedantic -std=c90
LDFLAGS = -lm
SRC = List.c HashTable.c hash.c
OBJ = $(SRC:.c=.o)
EXEC = hash

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)