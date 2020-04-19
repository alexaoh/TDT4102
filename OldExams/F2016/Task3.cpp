#include "Task3.h"

template<typename T>
void Graph<T>::addNode(T n){
    nodes.insert(n);
}

template<typename T>
void Graph<T>::addEdge(T u, T v){
    edges[u].insert(v);
    if (!directed){
        edges[v].insert(u);
    }
}

template<typename T>
void printNodes(Graph<T>& g){
    std::set<T> nodes = g.getNodes();
    for (std::set<T>::iterator it = nodes.begin(); 
        it != nodes.end(); ++it){
            std::cout << *it << " ";
        }
}

template<typename T>
void Graph<T>::removeEdge(T u, T v){
    edges[u].erase(v);
    if (!directed){
        edges[v].erase(u);
    }
}

template<typename T>
void Graph<T>::removeNode(T n){
    for (auto x : nodes){
        removeEdge(n, x);
    }
    nodes.erase(n);
    edges.erase(n);
}

template<typename T>
int Graph<T>::countEdges(){
    int amount{0};
    for (auto pair : edges){
        amount += pair.second.size();
    }
    if (!directed) amount /= 2;
    return amount;
}

template<typename T>
bool Graph<T>::isConnected(){
    for (auto node : nodes){ //unødvendig å sjekke hver eneste node, holder med én. Misforstod funksjonen til traverse!
        std::map<T, int> values = traverse(node);
        if (values.size() != nodes.size()) return false;
    }
    return true;
}   

template<typename T>
int Graph<T>::distance(T u, T v){
    std::map<T, int> dist = traverse(u);
    if (dist.find(v) == dist.end()) return -1;
    return dist[v];
}

template<typename T>
std::map<T, int> Graph<T>::traverse(T n){
    std::queue<T> q;
    std::map<T, int> dist;
    q.push(n);
    dist[n] = 0;
    while (q.size()){
        T current = q.front();
        q.pop();
        std::set<T> neighbours = edges[current];
        for (auto neighbour : neighbours){
            if (dist.find(neighbour) == dist.end()){
                dist[neighbour] = dist[current] + 1;
                q.push(neighbour);
            }
        }
    }
    return dist;
}
