// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
    bool check = true;
    
    if ((value % 2 == 1) && (value != 1)) {
        for (int k = 3; k <= sqrt(value); k++) {
            if (value % k == 0) {
 check = false;
                break;
            }
        }
 } else if (value != 2) {
 check = false;
    }
    
    return check;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
    uint64_t i = 2;
    
    if (n != 1) {
 i = 1;
        while (n != 1) {
 i += 2;
            if (checkPrime(i)) {
 n--;
            }
        }
    }
    
    return i;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
    uint64_t i = value + 1;
    
    if ((i % 2 == 0) && (i != 2)) {
 i++;
    }
    
    bool check = false;
    while (!(check)) {
        if (checkPrime(i)) {
 check = true;
            break;
        }
 i += 2;
    }
    
    return i;
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
    uint64_t sum = 0;
    
    for (int i = 1; i < hbound; i++) {
        if (checkPrime(i)) {
 sum += i;
        }
    }
    
    return sum;
}
