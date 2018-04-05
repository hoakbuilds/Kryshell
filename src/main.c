#include "shell.h"

char prompt[100];

int main ()
{
	int len;
	int numargs=0;
	LinkedList *history = NULL;
	char buf[1024];		/* um comando */
	char *args[64];		/* com um maximo de 64 argumentos */

	strcpy (prompt, "Kryshell>");

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

        if( !builtin (args, numargs, history) ) execute (args, numargs);		/* executa o comando */
    }
	return 0;
}

int builtin (char **args, int numargs, LinkedList *history)
{
	if (strcmp(args[0], "help") == 0 ){
		printhelp();
		return 1;
	}
	
	if (strcmp(args[0], "murloc") == 0 ){
		printf("Who would've thought that a pesky Murloc could 'code'?\n");
		return 1;
	}

	if (strcmp(args[0], "42") == 0 ){
		printf("42 is the answer to life, the universew and everything.\n");
		return 1;
	}

	if (strcmp(args[0], "420") == 0 ){
		printf("blaze it\n");
		return 1;
	}
	
	if (strcmp (args[0], "sair") == 0 || strcmp (args[0], "exit") == 0){
		printf("Farewell mortals, your bravery is admirable for such flawed creatures.\n");
		exit (0);
		return 1;
	}
	
	if (strcmp (args[0], "quemsoueu") == 0 || strcmp (args[0], "whoami") == 0){
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
			printf("Syntax error: socp [SRC] [DEST]\n");
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
		if(numargs != 3){
			printf("Syntax error: openfile [FILE] [MODE]\nMODE: '0' for reading, '1' for writing, '2' for reading and writing.\nNote that you have to be in that FILE's directory.\n");
			return 1;
		}
		openfile(args[1], atoi(args[2]));
		return 1;
	}
	
	if (strcmp (args[0],"fileinfo") == 0){
		fileinfo();
		return 1;
	}
	
	if (strcmp (args[0], "soread") == 0){
		if( numargs != 4){
			printf("Syntax error: soread [BYTES] [FDIN] [FDOUT]\n");
			return 1;
		}
		soread( atoi(args[1]), atoi(args[2]), atoi(args[3]) );
		return 1;
	}

	if (strcmp (args[0], "tworand") == 0){
		tworand();
		return 1;
	}

	if (strcmp (args[0], "calc") == 0 ){
		if( numargs != 4 ){
			printf("Syntax error: calc [VALUE1] [OP] [VALUE2]\n");
			return 1;
		}
		calc(args[1], args[2], args[3]);
		return 1;
	}

	if (strcmp (args[0], "isjpeg") == 0 ){
		
		if( isjpeg(open(args[1], O_RDONLY)) != 1 ){
			printf("Not jpeg.\n");
		}else printf("Is jpeg.\n");
		
		return 1;
	}

	if (strcmp (args[0], "bits") == 0 ){
		if( numargs != 4 ){
			printf("Syntax error: calc [VALUE1] [OP] [VALUE2]\n");
			return 1;
		}
		bits(args[1], args[2], args[3]);
		return 1;
	}


	if (strcmp (args[0], "history") == 0){


	}


	if (strcmp (args[0], "rsi") == 0){

		double top = 0.0, bottom = 0.0;
		int periods = 0;
		sscanf(args[2], "%d", &periods);
		sscanf(args[3], "%lf", &top);
		sscanf(args[4], "%lf", &bottom);

		printf("RSI ::\nPeriods %d \nTop (Oversold) %lf\nBottom (Overbought) %lf\n\n",periods, top, bottom);

		rsi(args[1], periods, top, bottom);

		return 1;
	}

	//devolver 0 indica que n�o h� comando embutido

  return 0;

}
