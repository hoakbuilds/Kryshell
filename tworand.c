#include "shell.h"

void tworand(){
	
	char prompt[] = "Insira valor MAX.\n";
	char vmax[10];
	char buffer[10];
	int pid, Vmax, status, result;
	int fd[2];
	
	pipe(fd);
	
	if((pid= fork())==-1){
		perror("fork");
		exit(1);
	}
	
	
	if(pid==0){
		closefd(fd[0]);
		write(STDOUT_FILENO, prompt, (strlen(prompt)+1));
		scanf("%d", &Vmax);
		snprintf(vmax, 10, "%d",  Vmax);
		write(fd[1], vmax, sizeof(vmax));
	}else
	{	
		while (wait (&status) != pid);
		closefd(fd[1]);
		read(fd[0], buffer, sizeof(buffer));
		result = 1+rand()%atoi(buffer);
		snprintf(vmax, 10, "%d", result);
		write(STDOUT_FILENO, buffer, (strlen(buffer)));
		result = 1+rand()%atoi(buffer);
		snprintf(vmax, 10, "%d", result);
		write(STDOUT_FILENO, buffer, (strlen(buffer)));
	}

}
