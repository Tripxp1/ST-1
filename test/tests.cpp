// Copyright 2025 UNN-CS

#include "alg.h"

#include <gtest/gtest.h>

namespace {

void assertPrime(uint64_t value) {
    EXPECT_TRUE(checkPrime(value));
}

void assertComposite(uint64_t value) {
    EXPECT_FALSE(checkPrime(value));
}

void assertNthPrime(uint64_t n, uint64_t expected) {
    EXPECT_EQ(nPrime(n), expected);
}

void assertNextPrime(uint64_t from, uint64_t expected) {
    EXPECT_EQ(nextPrime(from), expected);
}

void assertPrimeSum(uint64_t bound, uint64_t expected) {
    EXPECT_EQ(sumPrime(bound), expected);
}

}  // namespace

TEST(PrimeLib_Check, rejectsValuesBelowTwo) {
    assertComposite(0);
    assertComposite(1);
}

TEST(PrimeLib_Check, acceptsTwo) {
    assertPrime(2);
}

TEST(PrimeLib_Check, acceptsSmallPrimes) {
    assertPrime(3);
    assertPrime(5);
    assertPrime(7);
}

TEST(PrimeLib_Check, rejectsEvenComposites) {
    assertComposite(4);
    assertComposite(10);
    assertComposite(100);
}

TEST(PrimeLib_Check, rejectsOddComposites) {
    assertComposite(9);
    assertComposite(15);
    assertComposite(21);
}

TEST(PrimeLib_Nth, firstInSequence) {
    assertNthPrime(1, 2);
}

TEST(PrimeLib_Nth, earlySequence) {
    assertNthPrime(2, 3);
    assertNthPrime(3, 5);
    assertNthPrime(5, 11);
}

TEST(PrimeLib_Nth, tenthInSequence) {
    assertNthPrime(10, 29);
}

TEST(PrimeLib_Next, afterComposite) {
    assertNextPrime(4, 5);
}

TEST(PrimeLib_Next, afterPrime) {
    assertNextPrime(11, 13);
}

TEST(PrimeLib_Next, fromSmallValues) {
    assertNextPrime(0, 2);
    assertNextPrime(1, 2);
    assertNextPrime(2, 3);
}

TEST(PrimeLib_Sum, belowTen) {
    assertPrimeSum(10, 17);
}

TEST(PrimeLib_Sum, belowTwo) {
    assertPrimeSum(2, 0);
}

TEST(PrimeLib_Sum, belowTwenty) {
    assertPrimeSum(20, 77);
}

TEST(PrimeLib_Sum, largeBound) {
    assertPrimeSum(2000000, 142913828922ULL);
}
