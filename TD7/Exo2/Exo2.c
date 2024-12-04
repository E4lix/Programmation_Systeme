#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *processusPere();
void *processusFils();

int x = 0;

int main(int argc, char *argv[]){

    // int pid;

    pthread_t tid_Pere, tid_Fils;

    // pid = fork();
    // printf("Valeur de fork = %d \n", pid);
    // printf("Processus %d de père %d \n", (int)getpid(), (int)getppid());

    pthread_create(&tid_Pere, NULL, processusPere, NULL);
    pthread_create(&tid_Fils, NULL, processusFils, NULL);

    pthread_join(tid_Pere, NULL);
    // pthread_join(tid_Fils, NULL);

    return EXIT_SUCCESS;
}

void *processusPere(){
    while(x != 25){
        sleep(4);
        printf("Valeur de x pour le père : %d \n", x);
    }
    
    printf("Fin du processus père \n");
    return NULL;
}

void *processusFils(){
    printf("Valeur de x pour le fils : %d \n", x);
    printf("Fin du processus fils \n");
    x = 25;

    return NULL;
}