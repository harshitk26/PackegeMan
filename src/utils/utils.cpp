

#include <sys/stat.h>
#include <unistd.h>

#include "utils.hpp"
namespace utils {
    // Init RNG
    void InitRNG() {
        srand(time(0));
    }

    uint64_t GetNextRandomNum() {
        return rand();
    }

    bool fileExists (const std::string& name) {
        return ( access( name.c_str(), F_OK ) != -1 );
    }
}
