#include "shell.h"

void printhelp(){

	printf("\nUsage of all shell built-in functions:\n\n");
	printf("----> sair				Leaves the shell and displays some miscellanea.\n\n");
	printf("----> quemsoueu 			Displays user info.\n\n");
	printf("----> PS1				Changes the shell's prompt to whatever is written after the = symbol.\nExample:\nPS1=syntax\nsyntax>\n\n");
	printf("----> cd [PATH]				Changes directory to path specified.\nExample:\ncd /home/usr/\n\n");
	printf("----> socp [SRC] [DEST]			Copies text content from SRC file to DEST file.\nExample:\nsocp /home/usr/Desktop/src.txt /home/usr/Desktop/dest.txt\n\n");
	printf("----> closefd [FILE]			Closes the given FILE descriptor.\nExample:\nclosefd 0 				(This would generally close the stdin, please do not try it at home)\n\n");
	printf("----> openfile [FILE] [MODE]	Opens a FILE descriptor. Note that you have to be in that FILE's directory.\n								MODE: '0' for reading, '1' for writing, '2' for reading and writing.\nExample:\nopenfile thisshell.txt\n\n");
	printf("----> fileinfo				Displays information on the status of the STDOUT file pointer,\n					if it's opened or not and what file descriptor it is using.\n					The max number of open files the current process can have,\n					the number of opened file descriptors as well as the file descriptors that are open\n					and information regarding that file descriptor.\nExample:\nfileinfo\nSTDOUT is open: File number 1.\nCurrent process has 1024 file limit.\nProcess 10763 has 7 open files.\nCurrent opened file descriptors:\n0 - character device  -  MODE:  20620 (octal)  -  OWNERSHIP:  UID=1000   GID=5\n1 - character device  -  MODE:  20620 (octal)  -  OWNERSHIP:  UID=1000   GID=5\n2 - character device  -  MODE:  20620 (octal)  -  OWNERSHIP:  UID=1000   GID=5\n3 - regular file  -  MODE:  100644 (octal)  -  OWNERSHIP:  UID=1000   GID=1000\n\n");
	printf("----> soread [BYTES] [FDIN] [FDIN]	Reads the first N specified BYTES from an opened file with file descriptor FDIN and writes them to the file descriptor FDOUT\nExample:\nsoread 18 2 1\nwill you pri\n\n");
	
}
