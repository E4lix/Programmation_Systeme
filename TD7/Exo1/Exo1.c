#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void *printMessage1(void *ptr);
void *printMessage2(void *ptr);
void *printMessage3(void *ptr);
void *printMessage(void *arg);

int main(int argc, char *argv[]){
    // pthread_t tid1, tid2, tid3; // Descripteur de Thread
    // const char *s1 = "Thread 1";
    // const char *s2 = "Thread 2";
    // const char *s3 = "Thread 3";

    // pthread_create(&tid1, NULL, printMessage1, (void*) s1);
    // pthread_create(&tid2, NULL, printMessage2, (void*) s2);
    // pthread_create(&tid3, NULL, printMessage3, (void*) s3);

    // pthread_join(tid1, NULL);
    // pthread_join(tid2, NULL);
    // pthread_join(tid3, NULL);

    srand(time(NULL));

    int n = atoi(argv[1]);
    pthread_t threads[n];
    int threads_args[n];

    for(int i = 0; i < n; i++){
        threads_args[i] = i+1;
        int r = rand() % 5;
        sleep(r);

        pthread_create(&threads[i], NULL, printMessage, &threads_args[i]);
    }

    return EXIT_SUCCESS;
}

void *printMessage1(void *arg){
    char *mess = (char*) arg;

    sleep(2);
    printf("%s \n", mess);
    return NULL;
}

void *printMessage2(void *arg){
    char *mess = (char*) arg;

    printf("%s \n", mess);
    return NULL;
}

void *printMessage3(void *arg){
    char *mess = (char*) arg;

    printf("%s \n", mess);
    return NULL;
}

void *printMessage(void *arg){
    int i = *(int *)arg;
    printf("Thread %d \n", i);
    return NULL;
}