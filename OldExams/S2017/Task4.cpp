#include "Task4.h"

void Network::addEdge(std::string u, std::string v){
    edges[u].insert(v);
    if (symmetric){
        edges[v].insert(u);
    }
}

Network loadNetwork(std::string filename, bool symmetric = true){
    Network network{symmetric};
    std::ifstream ist{filename};
    if (!ist) throw std::runtime_error("Cannot open file.");
    std::string line;
    while (getline(ist, line)){
        std::stringstream ss{line};
        std::string node; 
        std::string edge;
        ss >> node;
        while(ss >> edge){
            network.addEdge(node, edge);
        }
    }
    return network;
}

void Network::addPath(std::vector<std::string>nodes){
    std::vector<std::string>::iterator it;
    for (it = nodes.begin(); it != nodes.end(); ++it){
        addNode(*it);
        if (it+1 == nodes.end()) continue; //break vil gi samme resultat her. 
        else{
            addEdge(*it, *(it+1));
        }
        //Likte løsningen i LF bedre!
    }   
}

Network Network::operator+(Network& rhs){
    Network network{rhs.symmetric};
    network.nodes = nodes;
    network.nodes.insert(rhs.nodes.begin(), rhs.nodes.end());
    network.edges = edges;
    for (auto x : rhs.edges){
        network.edges.insert(x); //Tror dette vil fungere!
    }
    return network;
}

int Network::distance(std::string from, std::string to){
    std::map<std::string, int> distances = traverse(from);
    if (distances.find(to) == distances.end()) return -1;
    return distances[to];
}

float Network::avgPathLength(){
    float sum{0};
    float N = static_cast<float>(nodes.size());
    for (std::string n : nodes){
        std::map<std::string, int> dist = traverse(n);
        for (std::pair<std::string, int> p : dist){
            sum += p.second;
        }
    }
    return sum / (N*(N+1));
}
