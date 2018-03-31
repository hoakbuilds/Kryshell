/*
	socp.c .:.
	creates the file descriptors to be used in copying from the SRC (source) to the DEST (destination) file
	and calls the copying function if there are no errors
 */

#include "shell.h"

void socp(char *src, char* dest){
		
		int source, destination;
		
		source = open(src, O_RDONLY);
		
		if( source<0 ){
			perror("Error opening source file.\n");
			return;
		}
		
		destination = creat(dest, S_IWUSR|S_IRUSR);
		
		if( destination<0 ){
			perror("Error creating destination file.\n");
			return;
		}
		
		socpaux(source, destination);
		
		return;	
}

int socpaux (int src, int dest){

	int n, w;
	char buf[LLFIOBUFF];
	
	while( (n=read(src, buf, LLFIOBUFF)>0) ) {
		w=write(dest, buf, n);
		if(w!=n)
			perror("Error writing to destination file.\n");
	}
		if(n<0)
			perror("Error reading from source file.\n");
	
	return 0;

}
