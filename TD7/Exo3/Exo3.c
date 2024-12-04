#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void *thread_1();
void *thread_2();

int main(int argc, char *argv[]){
    pthread_t tid_1,tid_2;

    pthread_create(&tid_1, NULL, thread_1, NULL);
    pthread_create(&tid_2, NULL, thread_2, NULL);

    pthread_join(tid_1, NULL);
    pthread_join(tid_2, NULL);

    return EXIT_SUCCESS;
}

void *thread_1(){
    for(int i = 0; i < 201; i++){
        printf("Thread 1 : %d \n", i);
    }
    return NULL;
}

void *thread_2(){
    for(int i = 0; i < 201; i++){
        printf("Thread 2 : %d \n", i);
    }
    return NULL;
}