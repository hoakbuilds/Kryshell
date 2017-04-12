/*
	files.c .:.
	program file for file descriptor manipulations with the following functions:
	validfd(int fd)   			-- checks if a given file descriptor is valid
	openfile(char *filename)	-- opens a file with the given filename
	closefd(int fd)				-- closes a file with the given file descriptor
	fileinfo()  				-- returns info on the status of the stdout file pointer (opened or not:: NULL || !NULL)
								   what file descriptor it is using
							       the max number of open files the current process can have
							       the number of opened file descriptors and the file descriptors that are open
*/

#include "shell.h"

int validfd(int fd){
	
	return fcntl(fd, F_GETFD) != -1 || errno != EBADF;
	
	/* on error, fcntl returns -1 and errno is set accordingly */

}

void openfile(char *filename){
	
	if( open(filename, O_RDONLY)>=0 ) printf("Opened %s successfully.\n", filename);
	else perror(filename);
	
}

void closefd(int fd){
		
	if( close(fd)<0 ) perror(NULL);
	else printf("%d closed successfully.\n", fd);
		
}

void fileinfo(){
	
	int i=0;
	struct rlimit rl;
	struct stat fd;
	
	if( fileno(stdout) != -1 ) printf("STDOUT is open: File number %d.\n", fileno(stdout) );
	else printf("STDOUT is closed.\n");
	
	if( getrlimit(RLIMIT_NOFILE, &rl) == 0 ) printf("Current process has %lld file limit.\n", (long long int)rl.rlim_cur);
	
	printf("Process %d has %d open files.\n", getpid(), get_num_fds());
	
	printf("Current opened file descriptors:\n");
	
	for(i=0; i<rl.rlim_cur; i++){
		if( validfd(i) ){
			fstat(i, &fd);
			printf("%d - ", i);
			switch (fd.st_mode & S_IFMT) {
				case S_IFBLK:  printf("block device  -");            break;
				case S_IFCHR:  printf("character device  -");        break;
				case S_IFDIR:  printf("directory  -");               break;
				case S_IFIFO:  printf("FIFO/pipe  -");               break;
				case S_IFLNK:  printf("symlink  -");                 break;
				case S_IFREG:  printf("regular file  -");            break;
				case S_IFSOCK: printf("socket  -");                  break;
				default:       printf("unknown?  -");                break;
			}
			printf("  MODE:  %lo (octal)  -  ", (unsigned long) fd.st_mode);
			printf("OWNERSHIP:  UID=%ld   GID=%ld\n", (long) fd.st_uid, (long) fd.st_gid);

		}
	}

}

void soread(int fdin, int fdout, int n){
	
	if( validfd(fdin) && validfd(fdout) ) {
		
	}
}

int get_num_fds()
{
     int fd_count;
     char buf[64];
     struct dirent *dp;

     snprintf(buf, 64, "/proc/%i/fd/", getpid());

     fd_count = 0;
     DIR *dir = opendir(buf);
     while ((dp = readdir(dir)) != NULL) {
          fd_count++;
     }
     closedir(dir);
     return fd_count;
}
