#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <ctime>
#include <iomanip>


#include "entity_graph.hpp"
#include "clone_entity.hpp"
#include "utils.hpp"

using namespace nlohmann;

bool CloneEntity::m_cloneEntity(uint64_t _id, uint64_t _copyId) {
    for (auto& el : m_entityJsonObj[JSON_CONST::Entities].items()) {
        if (el.value()[JSON_CONST::EntityID] == _id) {
            //std::cout << std::setw(4) << el.value();
            nlohmann::json jobj = el.value();
            jobj[JSON_CONST::EntityID] = _copyId;
            m_entityJsonObj[JSON_CONST::Entities].push_back(jobj);
            return true;
        }
    }
    return false;
}

bool CloneEntity::m_cloneLinks(uint64_t _clone_id_from, uint64_t _clone_id_to) {
    nlohmann::json jobj;
    jobj["from"] = _clone_id_from;
    jobj["to"] = _clone_id_to;
    m_entityJsonObj[JSON_CONST::Links].push_back(jobj);
    return true;
}

CloneEntity::CloneEntity() {
    m_entityGraph = new DirectedGraph();
    // Init RNG
    utils::InitRNG();
}

CloneEntity::~CloneEntity() {
    delete m_entityGraph;
}

bool CloneEntity::ProcessEntityJson(std::string _jsonFileName, uint64_t _entityId) {

    std::set<uint64_t> visited;
    std::set<uint64_t> neighbours;
    std::set<uint64_t>::iterator it;
    std::list<entityNode> queue;
    entityNode node;

    if( !utils::fileExists(_jsonFileName) ) {
        std::cout << "File not found !!" << std::endl;
        return false;
    }
    // 2. read a JSON file
    std::ifstream jsonEntityFile(_jsonFileName);
    jsonEntityFile >> m_entityJsonObj;

    // Create entity dependency graph
    for (auto& el : m_entityJsonObj[JSON_CONST::Links].items()) {
      //std::cout << el.value()["from"] << " -> " << el.value()["to"] << '\n';
      m_entityGraph->AddEdge(el.value()["from"], el.value()["to"]);
    }
    // Print entity Graph
    m_entityGraph->PrintGraph();
    //m_entityGraph->SearchEdge(3,5);

    // Get all the neighbours of entity

    node.entity_id = _entityId;
    node.clone_id = utils::GetNextRandomNum();

    neighbours = m_entityGraph->GetRootList(_entityId);
    for (it = neighbours.begin(); it != neighbours.end(); ++it) {
        m_cloneLinks(*it, node.clone_id);
    }

    queue.push_back(node);
    //visited.insert(_entityId);
    while(!queue.empty())
    {
        node = queue.front();
        queue.pop_front();
        if(visited.find(node.entity_id) == visited.end()) {
            std::cout << "Node Entity ID Processing : " << node.entity_id << std::endl;
            m_cloneEntity(node.entity_id, node.clone_id);
            neighbours = m_entityGraph->GetVertexNeighbours(node.entity_id);
            for( it = neighbours.begin() ; it != neighbours.end(); ++it ) {
               // if(visited.find(*it) == visited.end()){
                    std::cout << "NG -> " << *it << std::endl;
                    // Mark visited
                    entityNode nextNode;
                    //visited.insert(*it);
                    nextNode.entity_id = *it;
                    nextNode.clone_id = utils::GetNextRandomNum();
                    m_cloneLinks(node.clone_id, nextNode.clone_id);
                    queue.push_back(nextNode);
                //} else {
                //    std::cout << "visited -> " << *it << std::endl;
            }
            visited.insert(node.entity_id);
            } else {
                std::cout << "Node Entity ID Processing (skipped): " << node.entity_id << std::endl;
            }
    }

    m_updateJson(_jsonFileName, m_entityJsonObj);
    return true;
}

void CloneEntity::m_updateJson(std::string _filename, nlohmann::json _jsonObj) {
    std::cout << std::setw(4) << _jsonObj;
}
