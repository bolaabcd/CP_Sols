// Generates a random integer between a and b, inclusive.

#ifndef GET_A_RANDOM_INTEGER
#define GET_A_RANDOM_INTEGER

#include <random>

int rand(int a, int b) {// [a,b]
    return rand()%(b-a+1) + a;
}

#endif