

#ifndef __CLONE_ENNTITY_HPP
#define __CLONE_ENNTITY_HPP

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <ctime>
#include <iomanip>

#include "entity_graph.hpp"

using namespace nlohmann;

namespace JSON_CONST {
    const char * const Entities = "entities";
    const char * const EntityID = "entity_id";
    const char * const Links = "links";
}


typedef struct __EntityNode{
  uint64_t entity_id;
  uint64_t clone_id;
}entityNode;


class CloneEntity {

public:
    CloneEntity();
    ~CloneEntity();
    bool ProcessEntityJson(std::string jsonfileame, uint64_t entityId);

private:
    bool m_cloneEntity(uint64_t _id, uint64_t _copyId);
    bool m_cloneLinks(uint64_t _clone_id_from, uint64_t _clone_id_to);
    void m_updateJson(std::string _filename, nlohmann::json _jsonObj);

    nlohmann::json m_entityJsonObj;
    DirectedGraph* m_entityGraph;
};

#endif // __CLONE_ENNTITY_HPP
