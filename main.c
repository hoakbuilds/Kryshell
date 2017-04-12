/*
	SOSHELL PROJECT main program file .:.
	calls parser & executer and runs built in functions
*/

#include "shell.h"

char prompt[100];

int main ()
{
	int len;
	int numargs=0;
	char buf[1024];		/* um comando */
	char *args[64];		/* com um maximo de 64 argumentos */

	strcpy (prompt, "murlocSHELL 1.0>");

	while (1){
		printf ("%s", prompt);

    if ( fgets(buf,1023,stdin) == NULL){
		printf ("\n");
		exit (0);
	}
	len=strlen(buf);
	
	if ( 1==len ) continue;  // string is only a barra n
	
	if ( buf[len-1] == '\n' ) buf[len-1] ='\0';
	
		numargs = parse(buf, args);	/* particiona a string em argumentos e retorna o numero de argumentos */

        if( !builtin (args, numargs) ) execute (args, numargs);		/* executa o comando */
    }
	return 0;
}

int builtin (char **args, int numargs)
{
	if (strcmp(args[0], "help") == 0 ){
		printf("\nUsage of all shell built-in functions:\n\n");
		printf("----> sair				Leaves the shell and displays some miscellanea.\n\n");
		printf("----> quemsoueu 			Displays user info.\n\n");
		printf("----> PS1				Changes the shell's prompt to whatever is written after the = symbol.\nExample:\nPS1=syntax\nsyntax>\n\n");
		printf("----> cd [PATH]				Changes directory to path specified.\nExample:\ncd /home/usr/\n\n");
		printf("----> socp [SRC] [DEST]			Copies text content from SRC file to DEST file.\nExample:\nsocp /home/usr/Desktop/src.txt /home/usr/Desktop/dest.txt\n\n");
		printf("----> closefd [FILE]			Closes the given FILE descriptor.\nExample:\nclosefd 0 				(This would generally close the stdin, please do not try it at home)\n\n");
		printf("----> openfile [FILE]			Opens a FILE descriptor. Note that you have to be in that FILE's directory.\nExample:\nopenfile thisshell.txt\n\n");
		printf("----> fileinfo				Displays information on the status of the STDOUT file pointer,\n					if it's opened or not and what file descriptor it is using.\n					The max number of open files the current process can have,\n					the number of opened file descriptors as well as the file descriptors that are open\n					and information regarding that file descriptor.\nExample:\nfileinfo\nSTDOUT is open: File number 1.\nCurrent process has 1024 file limit.\nProcess 10763 has 7 open files.\nCurrent opened file descriptors:\n0 - character device  -  MODE:  20620 (octal)  -  OWNERSHIP:  UID=1000   GID=5\n1 - character device  -  MODE:  20620 (octal)  -  OWNERSHIP:  UID=1000   GID=5\n2 - character device  -  MODE:  20620 (octal)  -  OWNERSHIP:  UID=1000   GID=5\n3 - regular file  -  MODE:  100644 (octal)  -  OWNERSHIP:  UID=1000   GID=1000\n\n");
		return 1;
	}
	
	if (strcmp(args[0], "murloc") == 0 ){
		printf("Who would've thought that a pesky murloc could 'code'?\n");
		return 1;
	}
	
	if (strcmp (args[0], "sair") == 0){
		printf("Farewell mortals, your bravery is admirable for such flawed creatures.\n");
		exit (0);
		return 1;
	}
	
	if (strcmp (args[0], "quemsoueu") == 0){
		system("id");
		return 1;
	}
	
	if (strlen(args[0])>4 && 0==strncmp(args[0],"PS1=",4) ){
		strcat(args[0], ">");
		strcpy(prompt,args[0]+4);
		return 1 ; 
	}
	
	if (strcmp (args[0], "cd") == 0){
		int err;
		if( args[1]==NULL || 0==strncmp(args[1], "~", 1)) err = chdir(getenv("HOME"));
		else err = chdir(args[1]);
		if(err<0) perror("chdir failed\n");
		return 1;
	}
	
	if (strcmp (args[0], "socp") == 0){
		
		if(numargs != 3){
			printf("Syntax error: socp source_file destination_file\n");
			return 1;
		}
		
		socp(args[1], args[2]); 
		return 1;
	}
	
	if (strcmp (args[0], "closefd") == 0){
		if(args[1] == NULL){
			 printf("No valid file descriptor.\n");
			 return 1;
		}
		closefd( atoi(args[1]) );
		return 1;
	}
	
	if (strcmp (args[0], "openfile") == 0){
		if(args[1] == NULL){
			printf("No valid file path.\n");
			return 1;
		}
		openfile(args[1]);
		return 1;
	}
	
	if (strcmp (args[0],"fileinfo") == 0){
		fileinfo();
		return 1;
	}
	

	//devolver 0 indica que não há comando embutido

  return 0;
}
