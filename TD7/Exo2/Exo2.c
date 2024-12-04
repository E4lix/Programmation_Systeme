#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int x = 0;
    int pid;

    pid = fork();
    printf("Valeur de fork = %d \n", pid);
    printf("Processus %d de père %d \n", (int)getpid(), (int)getppid());

    if(pid == 0){
        x = 25;
        printf("Valeur de x pour le fils : %d \n", x);
        printf("Fin du processus fils \n");
    }
    else {
        while(x != 25){
            sleep(2);
            printf("Valeur de x pour le père : %d \n", x);
        }
        printf("Fin du processus père \n");
    }
    return EXIT_SUCCESS;
}