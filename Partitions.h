#ifndef PARTITION2_PARTITIONS_H
#define PARTITION2_PARTITIONS_H

#include <iostream>
#include "vector.h"

#define ERROR -1

class Partitions {
public:
    Partitions(int max_prime);
    void doPartition(int number, int max);
private:
    Vector<int> primes;
    Vector<int> k;
    void generatePrimes(int max);
    bool isPrime(int number);
    int getPrimeNumber(int number);

    void partition(int reminder, int lastPrime, int firstPrime = 0);
    void printPartition();
};

#endif //PARTITION2_PARTITIONS_H
