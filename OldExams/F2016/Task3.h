#include <set>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>

template<typename T>
class Graph{
    std::set<T> nodes;
    std::map<T, std::set<T>> edges;
    bool directed;
public: 
    Graph(bool directed = false):nodes(), edges(), directed(directed){}
    int sixe() const { return nodes.size(); }
    int degree(T n) { return edges[n].size(); }
    const std::set<T>& getNodes() const { return nodes; }
    const std::set<T>& getEdges(T n) { return edges[n]; }
    void addNode(T n);
    void addEdge(T u, T v);
    void removeEdge(T u, T v);
    void removeNode(T n);
    int countEdges();
    bool isConnected();
    int distance(T u, T v);
    std::map<T, int> traverse(T n);
};

template<typename T>
void printNodes(Graph<T>& g);
