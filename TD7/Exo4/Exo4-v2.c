#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int var1 = 0;
int var2 = 2;

void *majThread(void *args){
    while(1){
        if (var1 != var2){
            printf("Thread %i : Var 1 = %d différent de Var 2 = %d \n", (int)args, var1, var2);
            var1 = var2;
        }
        var1++;
        var2++;
    }   
}

int main(int argc, char *argv[]){
    pthread_t threads[4]; // Tableau des threads

    for(int i = 0; i < 4; i++){
        pthread_create(&threads[i], NULL, majThread, (int *)(i+1));
    }

    sleep(5);
    
    for(int i = 0; i < 4; i++){
        pthread_cancel(threads[i]);
    }

    printf("Var1 = %d, Var2 = %d", var1, var2);

    return EXIT_SUCCESS;
}
