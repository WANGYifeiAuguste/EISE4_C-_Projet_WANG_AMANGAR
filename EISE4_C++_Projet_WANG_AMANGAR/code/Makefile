CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
OBJ_TEST= $(filter-out ./main.o, $(OBJ))

demo: $(OBJ_TEST)
	$(CC) $(CCFLAGS) -o $@ $^

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ_TEST) demo
