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

void printhelp();

int parse (char *buf, char **args);

void redirects(int numargs, char *args[]);

void execute (char **args, int numargs);

int builtin (char **args, int numargs);

int ultimo (int numargs, char **args);

void socp (char *src, char *dest);

int socpaux (int src, int dest);

int validfd (int fd);

void openfile (char *filename, int mode);

void closefd (int fd);

void fileinfo ();

int get_num_fds();

void soread (int n, int fdin, int fdout);

void tworand ();

					/*CONSTANTS THAT MAY BE USEFUL*/

#define BG 0		  				/* used for background process*/
#define FG 1		  				/* used for foreground process*/
#define LLFIOBUFF 256 				/* low level file input/output buffer size */
