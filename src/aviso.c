#include "shell.h"

void aviso (char *msg, int tempo){
    while (tempo > 0) {
    sleep (1);
        tempo--;
    }
    fprintf (stderr, "Aviso : %s\n", msg );
}