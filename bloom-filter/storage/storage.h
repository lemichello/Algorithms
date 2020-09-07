#ifndef ALGORITHMS_STORAGE_H
#define ALGORITHMS_STORAGE_H

#include <string>
#include <vector>

using namespace std;

class Storage {
public:
    explicit Storage(size_t initialSize);

    bool getValue(int index);

    void setValue(int index);

private:
    vector<bool> storage_;
};

#endif //ALGORITHMS_STORAGE_H
