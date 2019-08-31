

#ifndef __UTILS_HPP
#define __UTILS_HPP

#include <string>

namespace utils {
    // Init RNG
    void InitRNG();

    uint64_t GetNextRandomNum();

    bool fileExists (const std::string& name);

}

#endif // __UTILS_HPP
