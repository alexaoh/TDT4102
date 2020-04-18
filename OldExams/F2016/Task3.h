#include <set>
#include <iostream>
#include <map>

class Graph{
    std::set<std::string> nodes;
    std::map<std::string, std::set<std::string>> edges;
    bool directed;
public: 
    Graph(bool directed = false):nodes(), edges(), directed(directed){}
    int sixe() const { return nodes.size(); }
    int degree(std::string n) { return edges[n].size(); }
    const std::set<std::string>& getNodes() const { return nodes; }
    const std::set<std::string>& getEdges(std::string n) { return edges[n]; }
    void addNode(std::string n);
    void addEdge(std::string u, std::string v);
    void removeEdge(std::string u, std::string v);
    void removeNode(std::string n);
    int countEdges();
    bool isConnected();
    int distance(std::string u, std::string v);
    std::map<std::string, int> traverse(std::string start);
};
