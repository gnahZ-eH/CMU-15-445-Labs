#pragma once

namespace cmudb {

template<typename K, typename  V> class HashTable {
public:
    HashTable() {}
    virtual ~HashTable() {}

    virtual bool Find(const K &key, V &value) = 0;

    virtual bool Remove(const K &key) = 0;

    virtual bool Insert(const K &key, const V &value) = 0;

    virtual size_t Size() const = 0;
};
}