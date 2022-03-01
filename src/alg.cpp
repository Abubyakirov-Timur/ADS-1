// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
  if (value <= 1)
    return false;
  for (int j = 2; j <= (value / 2); j++) {
    if ((value % j) == 0)
      return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
  bool flag1 = true;
  uint64_t check = 0;
  uint64_t num = 0;
  for (int i = 2; flag1 != false; i++) {
    num = i;
    bool flag2 = true;
    for (int i = 2; i <= sqrt(num); i++) {
      if (num % i == 0) {
        flag2 = false;
        break;
      }
    }
    if (flag2) {
      check++;
      if (check == n) {
        flag1 = false;
      }
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
for (uint64_t i = value + 1;; ++i) {
if (checkPrime(i)) {
return i;
}
}
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
  uint64_t div, k, i, digit;
  digit = 0;
  uint64_t* prime = new uint64_t[hbound];
  prime[1] = 0;
  for (i = 2; i <= hbound; i++)
    prime[i] = 1;
  for (div = 2; div * div <= hbound; div++) {
    if (prime[div] == 1) {
      for (k = div * div; k <= hbound; k += div) {
        prime[k] = 0;
      }
    }
  }
  for (i = 0; i < hbound; i++) {
    if (prime[i])
      digit += i;
  }
  return digit;
}
