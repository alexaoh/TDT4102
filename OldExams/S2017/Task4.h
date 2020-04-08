#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

class Network{
    std::set<std::string> nodes;
    std::map<std::string, std::set<std::string>> edges;
    bool symmetric;
public:
    Network(bool symmetric = true):nodes(), edges(), symmetric(symmetric){};
    void addNode(std::string n){nodes.insert(n);}
    void addEdge(std::string u, std::string v);
    void addPath(std::vector<std::string>nodes);
    Network operator+(Network &rhs);
    std::map<std::string, int> traverse(std::string start);
    int distance(std::string from, std::string to);
    float avgPathLength();

    friend Network operator+(Network& rhs);
};  

Network loadNetwork(std::string filename, bool symmetric = true);
