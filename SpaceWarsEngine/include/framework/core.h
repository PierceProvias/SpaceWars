#pragma once
#include <stdio.h>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

namespace sw
{
    #define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

    template<typename T>
    using unique = std::unique_ptr<T>;

    template<typename T>
    using shared = std::shared_ptr<T>;

    template<typename T>
    using weak = std::weak_ptr<T>;

    template<typename T>
    using list = std::vector<T>;

    template <typename key_type, typename value_type, typename pr = std::less<key_type>>
    using map = std::map<key_type, value_type, pr>;

    template <typename key_type, typename value_type, typename hasher = std::hash<key_type>>
    using dictionary = std::unordered_map<key_type, value_type, hasher>;
}