#include <stdio.h>

void fun_1(FILE*, int[], int);
int fun_2(int[], int);
void fun_3(int, int);

int main(void) {
    int array_1[100] = {0}, array_2[1000] = {0}, array_3[10000] = {0};
    int index = 0, num_prime = 0;
    FILE* ghp_ptr = NULL;

    ghp_ptr = fopen("ghp_17_18_1.dat", "r");
    fun_1(ghp_ptr, array_1, 100);
    num_prime = fun_2(array_1, 100);
    fun_3(num_prime, 100);
    fclose(ghp_ptr);

    ghp_ptr = fopen("ghp_17_18_2.dat", "r");
    fun_1(ghp_ptr, array_2, 1000);
    num_prime = fun_2(array_2, 1000);
    fun_3(num_prime, 1000);
    fclose(ghp_ptr);

    ghp_ptr = fopen("ghp_17_18_3.dat", "r");
    fun_1(ghp_ptr, array_3, 10000);
    num_prime = fun_2(array_3, 10000);
    fun_3(num_prime, 10000);
    fclose(ghp_ptr);

    return 0;
}

void fun_1(FILE* fun_ptr, int in_array[], int max_index) {
    for (int i = 0; i < max_index; i++) {
        fscanf(fun_ptr, "%d", &in_array[i]);
    }
}

int fun_2(int in_array[], int max_index) {
    int is_prime = 0, prime_counter = 0;

    for (int i = 0; i < max_index; i++) {
        is_prime = 1;

        if (in_array[i] < 2)
            is_prime = 0;
        else {
            for (int j = 2; j * j <= in_array[i]; j++) {
                if (in_array[i] % j == 0) {
                    is_prime = 0;
                    break;
                }
            }
        }

        if (is_prime)
            prime_counter++;
    }

    return prime_counter;
}

void fun_3(int num_primes, int array_elements) {
    printf("\nThe array of %d elements had %d prime numbers.\n\n",
           array_elements, num_primes);
}
