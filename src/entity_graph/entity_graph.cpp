
#include "entity_graph.hpp"
// representation of graphs using sets
using namespace std;

// A utility function that creates a graph of V vertices
DirectedGraph::DirectedGraph() {
}

// A utility function that creates a graph of V vertices
DirectedGraph::~DirectedGraph() {
}

// Adds an edge to an undirected graph
void DirectedGraph::AddEdge(uint64_t src, uint64_t dest) {
    m_adjList[src].insert(dest);
}

// A utility function to print the adjacency
// list representation of graph
void DirectedGraph::PrintGraph() {
    std::cout <<"\n";
    for (m_it = m_adjList.begin(); m_it != m_adjList.end(); ++m_it) {
        cout <<"Vertex: " << m_it->first << '\t';
        set <uint64_t, greater <uint64_t> > :: iterator itr;
        for (itr = m_it->second.begin(); itr != m_it->second.end(); ++itr) {
            cout << "" << *itr << "->";
        }
        std::cout <<"\n";
    }
}

std::set<uint64_t> DirectedGraph::GetVertexNeighbours(uint64_t _entity_id) {
    return m_adjList[_entity_id];
}

std::set<uint64_t> DirectedGraph::GetRootList(uint64_t _entity_id) {
    set <uint64_t> rootList;
    set <uint64_t> :: iterator itr;
    for (m_it = m_adjList.begin(); m_it != m_adjList.end(); ++m_it) {
        for (itr = m_it->second.begin(); itr != m_it->second.end(); ++itr) {
            if(*itr == _entity_id) {
                rootList.insert(m_it->first);
            }
        }
    }
    return rootList;
}


// Searches for a given edge in the graph
void DirectedGraph::SearchEdge(uint64_t src, uint64_t dest)
{
    auto itr = m_adjList[src].find(dest);
    if (itr == m_adjList[src].end())
        cout << endl << "Edge from " << src
             << " to " << dest << " not found."
             << endl;
    else
        cout << endl << "Edge from " << src
             << " to " << dest << " found."
             << endl;
}
