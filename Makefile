
CC=cc
FLAGS=-c -Wall
LIBS=-lm
OBS=main.o execute.o parse.o socp.o files.o help.o redirects.o calcs.o rsi.o history.o
 
 
all :  kryshell
 
main.o 		: ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/main.c
	$(CC) $(FLAGS)  ~/Desktop/Kryshell/src/main.c
	
execute.o   : ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/execute.c
	$(CC) $(FLAGS) ~/Desktop/Kryshell/src/execute.c
	
parse.o     : ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/parse.c
	$(CC) $(FLAGS) ~/Desktop/Kryshell/src/parse.c
	
socp.o      : ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/socp.c
	$(CC) $(FLAGS) ~/Desktop/Kryshell/src/socp.c

files.o     : ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/files.c
	$(CC) $(FLAGS) ~/Desktop/Kryshell/src/files.c

help.o    	: ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/help.c
	$(CC) $(FLAGS) ~/Desktop/Kryshell/src/help.c
	
redirects.o : ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/redirects.c
	$(CC) $(FLAGS) ~/Desktop/Kryshell/src/redirects.c

calcs.o : ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/calcs.c
	$(CC) $(FLAGS) ~/Desktop/Kryshell/src/calcs.c

rsi.o : ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/rsi.c
	$(CC) $(FLAGS) ~/Desktop/Kryshell/src/rsi.c

history.o : ~/Desktop/Kryshell/src/shell.h ~/Desktop/Kryshell/src/history.c
	$(CC) $(FLAGS) ~/Desktop/Kryshell/src/history.c
	
kryshell     : $(OBS)
	$(CC)  -o ~/Desktop/Kryshell/kryshell  $(OBS) $(LIBS)
	
clean limpar:
	rm -f kryshell *.o
	rm *~
	echo "Cleaning executables, compilation files and other trash."
