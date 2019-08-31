

#ifndef __GRAPH_HPP
#define __GRAPH_HPP

#include <iostream>
#include <set>
#include <map>
#include <iterator>

// representation of graphs using sets
using namespace std;

class DirectedGraph {
private:
    uint32_t m_numVert;
    std::map<uint64_t, set<uint64_t > > m_adjList;
    std::map<uint64_t, set<uint64_t> >::iterator m_it;

public:
    // A utility function that creates a graph of V vertices
    DirectedGraph();
    ~DirectedGraph();

    // Adds an edge to an undirected graph
    void AddEdge(uint64_t src, uint64_t dest);

    // A utility function to print the adjacency
    // list representation of graph
    void PrintGraph();

    // Searches for a given edge in the graph
    void SearchEdge(uint64_t src, uint64_t dest);

    // Get all the neighbours of entity
    std::set<uint64_t> GetVertexNeighbours(uint64_t _entity_id);
    std::set<uint64_t> GetRootList(uint64_t _entity_id);

};

#endif // __GRAPH_HPP
