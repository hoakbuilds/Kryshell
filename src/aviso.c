#include "shell.h"

void aviso (char *msg, int tempo){
    while (tempo > 0) {
    sleep (1);
        tempo--;
    }
    fprintf (stderr, "\nAviso : %s\n\n", msg );
}

void avisot (char *msg, int tempo, char *prompt){
    while (tempo > 0) {
    sleep (1);
        tempo--;
    }
    fprintf (stderr, "\n\nAviso : %s\n\n%s", msg, prompt );
}

void * avisowrapper(void *args) {
    Aviso_t *avs = (Aviso_t *) args;
    avisot( avs->msg, avs->tempo, avs->prompt);
    free(avs);
    return NULL;
}