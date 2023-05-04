#include "Partitions.h"

bool Partitions::isPrime(int number) {
    if(number == 2) return true; // this is not necessary for generatePrimes, but it's correct
    for(int i = 2; i*2 < number; i++) {
        if(number % i == 0) return false;
    }
    return true;
}

int Partitions::getPrimeNumber(int number) {
    for(int i = 0; i < primes.size(); i++) {
        if(number == primes[i]) return i;
    }
    return ERROR;
}

void Partitions::generatePrimes(int max) {
    primes.clear();
    for(int i = 2; i <= max; i++) {
        if(i == 2) primes.push_back(i);
        else if(i%2 == 1) {
            if(isPrime(i))
                primes.push_back(i);
        }
    }
}

void Partitions::doPartition(int number, int max) {
    k.clearContent();
    int lastPrime = getPrimeNumber(max);
    if(lastPrime != ERROR)
        partition(number, getPrimeNumber(max), getPrimeNumber(max));
}

void Partitions::partition(int reminder, int lastPrime, int firstPrime) {
    if(reminder == 0) {
        printPartition();
        return;
    }
    for(int i = firstPrime; i <= lastPrime; i++) {
        for(int j = 1; j <= reminder/primes[i]; j++) {
            k.clearRange(0, i-1);
            k[i] = j;
            partition(reminder-primes[i]*j, i-1);
        }
    }
}

Partitions::Partitions(int max_prime) {
    generatePrimes(max_prime);
    k.initWithSize(primes.size());
}

void Partitions::printPartition() {
    bool isFirst = true;
    for(int i = primes.size()-1; i >= 0; i--) {
        for(int j = 0; j < k[i]; j++) {
            if(!isFirst)
                std::cout << "+";
            else isFirst = false;
            std::cout << primes[i];
        }
    }
    std::cout << std::endl;
}
