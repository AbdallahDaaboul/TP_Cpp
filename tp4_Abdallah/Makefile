CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS=
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
OBJ_TEST = $(filter-out logic.o, $(OBJ))
EXEC= Executable


all: $(EXEC)

testcase : $(OBJ_TEST)
	g++ -std=c++11 -Wall  -o $@ $^

$(EXEC): $(OBJ)
	$(CC) $(CCFLAGS) $(LIBFLAGS) $^ -o $@

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depend:
	g++ -MM $(SRC) > .depends
-include .depends

clean:
	rm -f FormeNormalisee_exo2.txt FormeNormalisee_exo1.txt $(OBJ) $(EXEC)
