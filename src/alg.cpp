// Copyright 2025 UNN-CS

#include "alg.h"

#include <cstdint>

namespace {

bool hasCompositeDivisors(uint64_t num) {
    if (num < 2) {
        return true;
    }
    if (num % 2 == 0) {
        return num != 2;
    }
    for (uint64_t divisor = 3; divisor * divisor <= num; divisor += 2) {
        if (num % divisor == 0) {
            return true;
        }
    }
    return false;
}

}  // namespace

bool checkPrime(uint64_t value) {
    return !hasCompositeDivisors(value);
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) {
        return 0;
    }

    uint64_t candidate = 1;

    for (uint64_t rank = 0; rank < n; ++rank) {
        do {
            ++candidate;
        } while (!checkPrime(candidate));
    }

    return candidate;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t probe = value;

    do {
        ++probe;
    } while (!checkPrime(probe));

    return probe;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t total = 0;
    uint64_t num = 2;

    while (num < hbound) {
        if (checkPrime(num)) {
            total += num;
        }
        ++num;
    }

    return total;
}
