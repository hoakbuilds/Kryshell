#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <errno.h>
#include <dirent.h>


int parse (char *buf, char **args);

void execute (char **args, int numargs);

int builtin (char **args);

int ultimo (int numargs, char **args);

void socp (char *src, char *dest);

int filecp (int src, int dest);

int validfd (int fd);

void openfile (char *filename);

void closefd (int fd);

void fileinfo ();

int get_num_fds();

void soread (int fdin, int fdout, int n);

					/*CONSTANTS THAT MAY BE USEFUL*/

#define BG 0		  				/* used for background process*/
#define FG 1		  				/* used for foreground process*/
#define LLFIOBUFF 256 				/* low level file input/output buffer size */
