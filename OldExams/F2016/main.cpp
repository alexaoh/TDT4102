#include "Task3.h"

int main(){
    //3c)
    Graph graph;
    graph.addNode("TOS");
    graph.addNode("OSL");
    graph.addNode("SVG");
    graph.addNode("BGO");
    graph.addNode("TRD");
    graph.addNode("BOO");
    graph.addEdge("TOS", "OSL");
    graph.addEdge("TOS", "TRD");
    graph.addEdge("OSL", "SVG");
    graph.addEdge("OSL", "BGO");
    graph.addEdge("OSL", "TRD");
    graph.addEdge("OSL", "BOO");
    graph.addEdge("SVG", "BGO");
    graph.addEdge("TRD", "SVG");
    graph.addEdge("BGO", "TRD");
    graph.addEdge("TRD", "BOO");
}

