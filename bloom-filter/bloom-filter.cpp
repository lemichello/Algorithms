#include "bloom-filter.h"
#include <cmath>
#include <iostream>

using namespace std;

BloomFilter::BloomFilter(int size) {
    this->size_ = size;
    this->storage_ = new Storage(size);
}

void BloomFilter::insert(const string &element) {
    array<int, 3> hashes = this->getHashes(element);

    for (int hash : hashes) {
        this->storage_->setValue(hash);
    }
}

bool BloomFilter::mayContain(const string &element) {
    array<int, 3> hashes = this->getHashes(element);
    bool result = true;

    for (int hash : hashes) {
        if (!this->storage_->getValue(hash)) {
            result = false;

            break;
        }
    }

    return result;
}

int BloomFilter::hash1(const string &element) {
    int hash = 0;

    for (int symbol : element) {
        hash = (hash << 3) + hash + symbol;
        hash &= hash;
        hash = abs(hash);
    }

    return hash % this->size_;
}

int BloomFilter::hash2(const string &element) {
    int hash = 4985;

    for (int symbol : element) {
        hash = (hash << 3) - hash;
        hash += symbol;
        hash &= hash;
    }

    return abs(hash % this->size_);
}

int BloomFilter::hash3(const string &element) {
    int hash = 0;

    for (int symbol : element) {
        hash = (hash << 3) - hash;
        hash += symbol;
        hash &= hash;
    }

    return abs(hash % this->size_);
}

array<int, 3> BloomFilter::getHashes(const string &element) {
    array<int, 3> hashes = array<int, 3>(
            {this->hash1(element),
             this->hash2(element),
             this->hash3(element)
            }
    );

    return hashes;
}

BloomFilter::~BloomFilter() {
    delete this->storage_;
}

