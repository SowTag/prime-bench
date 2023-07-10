#include <stdio.h>
#include <stdbool.h>

#define UPPER_LIMIT 100000

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

int main() {
    int found = 0;

    for(int i = 1; i < UPPER_LIMIT; i++) {
        if(is_prime(i)) {
            found++;
            printf("%i is prime!\n", i);
        }
    }

    printf("%i prime numbers found between 1 and %i\n", found, UPPER_LIMIT);
    return 0;
}
