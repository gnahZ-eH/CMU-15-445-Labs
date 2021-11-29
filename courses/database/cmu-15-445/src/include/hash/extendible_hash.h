#pragma
#include <cstdlib>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include "hash/hash_table.h"

namespace cmudb {

template<typename K, typename V>
class ExtendibleHash : public HashTable<K, V> {
    struct Bucket {
        Bucket() = default;
        explicit Bucket(size_t i, int d) : id(i), depth(d) {}
        std::map<K, V> items;
        boolean overflow = false;
        size_t id = 0;
        int depth = 0;
    };

public:
    // constructor
    explicit ExtendibleHash(size_t size);

    // disable copy
    ExtendibleHash(const ExtendibleHash &) = delete;
    ExtendibleHash& operator=(const ExtendibleHash &) = delete;

    // helper function to generate hash addressing
    size_t HashKey(const K &key);

    // helper function to get global & local depth
    int GetGlobalDepth() const;

    int GetLocalDepth(int bucket_id) const;

    int GetNumBuckets() const;

    bool Find(const K &key, V &value) override;

    bool Remove(const K &key) override;

    void Insert(const K &key, const V &value) override;

    size_t Size() const override { return pair_count; }

private:
    std::unique_ptr<Bucket> split(std::shared_ptr<Bucket> &);
    size_t bucketIndex(const K &key);

    mutable std::mutex mutex_;  // to protect shared data structure
    const size_t bucket_size_;  // largest number of elements in a bucket
    int bucket_count_;          // number of buckets in use
    int depth;                  // global depth
    size_t pair_count;          // key-value number in table
    std::vector<std::shared_ptr<Bucket>> directory_;  // smart pointer for auto memory management
};


}