#include "storage.h"

bool Storage::getValue(int index) {
    return this->storage_[index];
}

void Storage::setValue(int index) {
    this->storage_[index] = true;
}

Storage::Storage(size_t initialSize) {
    this->storage_ = vector<bool>(initialSize);
    this->storage_.reserve(initialSize);
}
