#include <iostream>
#include "clone_entity.hpp"


int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cout << "Please provide proper argumets !!!" << std::endl;
        std::cout << "help : <program_name> <inputfile> <entityid>" << std::endl;
        exit(1);
    }

    std::string jsonFileName = argv[1];
    uint64_t entityId = std::stoi(argv[2]);

    CloneEntity cloneEnt;
    cloneEnt.ProcessEntityJson(jsonFileName, entityId);

    return 0;
}
