#include "Partitions.h"

#define MAX_PRIME 255

int main() {
    Partitions partitions(MAX_PRIME);
    int lines, n, k;
    std::cin >> lines;
    for(int i = 0; i < lines; i++) {
        std::cin >> n >> k;
        partitions.doPartition(n, k);
    }
    return 0;
}