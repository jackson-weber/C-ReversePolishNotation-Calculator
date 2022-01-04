CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTFLAGS = -DTEST_STACK
GCC = gcc $(CFLAGS)
EXEC = calc
EXEC2 = stackTest
OBJS =  calc.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) calc.h
	$(GCC) $(OBJS) -o $(EXEC) 

all: $(EXEC)

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) inputs/test1
	$(VALGRIND) --log-file=log2 ./$(EXEC) inputs/test2
	$(VALGRIND) --log-file=log3 ./$(EXEC) inputs/test3
	$(VALGRIND) --log-file=log4 ./$(EXEC) inputs/test4
	$(VALGRIND) --log-file=log5 ./$(EXEC) inputs/test5
	$(VALGRIND) --log-file=log6 ./$(EXEC) inputs/test6
	

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f id? first? last? log?
