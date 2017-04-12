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

	strcpy (prompt, "SOSHELL: Introduza um comando : prompt>");

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

        if(!builtin (args)) execute (args, numargs);		/* executa o comando */
    }
	return 0;
}

int builtin (char **args)
{
	if (strcmp (args[0], "sair") == 0){
		exit (0);
		return 1;
	}
	
	if (strcmp (args[0], "quemsoueu") == 0){
		system("id");
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
