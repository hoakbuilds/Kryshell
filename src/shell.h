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
#include <math.h>

					/*CONSTANTS THAT MAY BE USEFUL*/

#define BG 0		  				/* used for background process*/
#define FG 1		  				/* used for foreground process*/
#define LLFIOBUFF 256 				/* low level file input/output buffer size */
#define FILE_MODE ( S_IRUSR | S_IWUSR ) /* File permissions when using creat */

typedef struct LL{
	char *string;	
	struct LL *next;
}LinkedList;

typedef struct{
	char msg[100];
	char prompt[100];
	int tempo;
}Aviso_t;

					/* HISTORY LIST OPERATION */
LinkedList *insertFirst(LinkedList *head, char *string);
void printhistory(LinkedList *head);

					/* SHELL OPERATION */
void printhelp();
int parse (char *buf, char **args);
void redirects(int numargs, char *args[]);
void execute (char **args, int numargs);
int builtin (char **args, int numargs, LinkedList *head, char *prompt);
int ultimo (int numargs, char **args);

					/* TEXT COPY */
void socp (char *src, char *dest);
int socpaux (int src, int dest);
void soread (int n, int fdin, int fdout);
void cat (char* input, char* output);

					/* FILE DESCRIPTORS */
int validfd (int fd);
void openfile (char *filename, int mode);
void closefd (int fd);
void fileinfo ();
int isjpeg( int fd );
int get_num_fds();

					/* MATHEMATICAL OPERATIONS */
void tworand ();
void calc(char *value1, char *op, char *value2);
void bits(char *value1, char *op, char *value2);

					/* STOCK MARKETS (ETC) TECHNICAL INDICATORS */
void rsi(char *filename, int periods, double top, double bottom );

					/* UTILITY FUNCTIONS */

void aviso(char *msg, int tempo);
void avisot(char *msg, int tempo, char *prompt);
void * avisowrapper(void *args);
