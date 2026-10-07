#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define TOTAL_OPERATIONS 1000000
#define NUM_THREADS 4

long long shared_counter = 0;

pthread_mutex_t counter_mutex;

typedef struct {
    long long operations;
} ThreadData;

/* Worker function */
void *worker_function(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    for (long long i = 0; i < data->operations; i++) {

        pthread_mutex_lock(&counter_mutex);

        shared_counter++;

        pthread_mutex_unlock(&counter_mutex);
    }

    return NULL;
}

/* Single-thread benchmark */
double single_thread_test(void) {
    shared_counter = 0;

    clock_t start = clock();

    for (long long i = 0; i < TOTAL_OPERATIONS; i++) {
        shared_counter++;
    }

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

/* Multi-thread benchmark */
double multi_thread_test(void) {
    pthread_t threads[NUM_THREADS];
    ThreadData data;

    data.operations = TOTAL_OPERATIONS / NUM_THREADS;

    shared_counter = 0;

    clock_t start = clock();

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL,
                           worker_function, &data) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(void) {
    printf("TASK 3: CONCURRENCY AND MULTITHREADING\n\n");

    if (pthread_mutex_init(&counter_mutex, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    printf("Total operations: %d\n", TOTAL_OPERATIONS);
    printf("Number of threads: %d\n\n", NUM_THREADS);

    /* Single-thread test */
    double single_time = single_thread_test();

    printf("Single-thread result:\n");
    printf("Counter = %lld\n", shared_counter);
    printf("Time    = %.6f seconds\n\n", single_time);

    /* Multi-thread test */
    double multi_time = multi_thread_test();

    printf("Multi-thread result:\n");
    printf("Counter = %lld\n", shared_counter);
    printf("Time    = %.6f seconds\n\n", multi_time);

    if (single_time > multi_time) {
        printf("Multi-thread execution was faster in this run.\n");
    } else {
        printf("Single-thread execution was faster in this run.\n");
    }

    pthread_mutex_destroy(&counter_mutex);

    printf("\nMutex destroyed and program completed.\n");

    return 0;
}