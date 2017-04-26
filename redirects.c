#include "shell.h"

void redirects(int numargs, char *args[]){
	/*fazer pela ordem inversa- 2> >> > <*/
	
	if(numargs <3) return;
	int fd;
	
	if(strcmp(args[numargs-2], "2>") == 0) {
		fd=creat(args[numargs-1], S_IWUSR|S_IRUSR); if(fd<0) perror("error");
		close(STDERR_FILENO);
		dup(fd);
		close(fd);
		args[numargs-2]=NULL;
		numargs = numargs-2;	
	}	
	
	if(strcmp(args[numargs-2], ">>") == 0) {
		fd=open(args[numargs-1], S_IWUSR|S_IRUSR); if(fd<0) perror("error");
		close(STDOUT_FILENO);
		dup(fd);
		close(fd);
		args[numargs-2]=NULL;
		numargs = numargs-2;	
	}
	
	if(strcmp(args[numargs-2], ">") == 0) {
		fd=creat(args[numargs-1], S_IWUSR|S_IRUSR); if(fd<0) perror("error");
		close(STDOUT_FILENO);
		dup(fd);
		close(fd);
		args[numargs-2]=NULL;
		numargs = numargs-2;	
	}
	
	if(strcmp(args[numargs-2], "<") == 0) {
		fd=open(args[numargs-1], O_RDONLY); if(fd<0) perror("error");
		close( STDIN_FILENO );
		dup(fd);
		close(fd);
		args[numargs-2]=NULL;
		numargs = numargs-2;	
	}

}
