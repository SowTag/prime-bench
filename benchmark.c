#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>

#define UPPER_LIMIT 100000
#define THREADS 8

typedef struct {
    int id;
    int start;
    int end;
} ThreadConfig;

int total = 0;

bool is_prime(int number) {
    // Common occurences
    if(number == 1) return false;       // 1 is not prime for some reason
    int div = 2;                        // Start dividing by two

    while(div < number / 2) {
        if(number % div == 0) return false;
        div++;
    }

    return true;
}

void* single(void* arg) {
    ThreadConfig* args = (ThreadConfig*) arg;

    printf("Thread #%d started! (%i -> %i)\n", args -> id, args -> start, args -> end);

    int found = 0;
    for(int i = args -> start; i < args -> end; i++) {
        if(is_prime(i)) {
            found++;
            // printf("[%i] %i is prime!\n", args -> id, found);
            // ^ Disabled to prevent printf overhead
        }
    }


    printf("Thread #%i finished (found %i)\n", args -> id, found);
    total += found;
    return NULL;
}

int main() {

    int id = 0;
    int last_limit = UPPER_LIMIT;

    pthread_t threads[THREADS];

    for(int i = UPPER_LIMIT - (UPPER_LIMIT / THREADS); i >= 0; i -= UPPER_LIMIT / THREADS) {
        ThreadConfig* tc = (ThreadConfig *) malloc(sizeof(ThreadConfig));

        tc -> id = id;
        tc -> start = i;
        tc -> end = last_limit;

        pthread_create(&threads[id], NULL, single, (void*) tc);

        ++id;
        last_limit = i;
    }

    for(int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nDone! All threads found %i primes in total.\n", total);
    return 0;
}
