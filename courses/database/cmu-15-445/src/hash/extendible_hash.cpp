#include <cassert>
#include <functional>
#include <list>
#include <bitset>
#include <iostream>

#include "hash/extendible_hash.h"

namespace cmudb {

/*
 * constructor
 * array_size: fixed array size for each bucket
 */

template <typename K, typename V>
ExtendibleHash<K, V>::ExtendibleHash(size_t size): bucket_size_(size), bucket_count_(0), depth(0), pair_count(0) {
    directory_.emplace_back(new Bucket(0, 0));
    // initial: 1 bucket
    bucket_count_ = 1;
}
}