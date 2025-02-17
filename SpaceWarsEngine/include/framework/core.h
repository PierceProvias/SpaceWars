#include <stdio.h>

namespace sw
{
    #define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}