#ifndef ALGORITHMS_BLOOM_FILTER_H
#define ALGORITHMS_BLOOM_FILTER_H

#include "storage/storage.h"
#include "array"

class BloomFilter {
public:
    explicit BloomFilter(int size);

    virtual ~BloomFilter();

    void insert(const string &element);

    bool mayContain(const string &element);

private:
    int size_;
    Storage *storage_;

    int hash1(const string &element);

    int hash2(const string &element);

    int hash3(const string &element);

    array<int, 3> getHashes(const string &element);
};

#endif //ALGORITHMS_BLOOM_FILTER_H
