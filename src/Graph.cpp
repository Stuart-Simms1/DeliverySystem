//Graph.cpp - includes Graph.hpp and contains the implementation for class Graph

#include<Graph.hpp>

Graph::Graph(const std::vector<Node>& nodes, const std::vector<Edge>& edges) : _nodes(nodes), _edges(edges) {}

std::vector<Node> Graph::getNodes() const{
    return _nodes;
}

std::vector<Edge> Graph::getEdges() const{
    return _edges;
}

void Graph::pushNode(const Node& node){
    _nodes.push_back(node);
}

void Graph::pushEdge(const Edge& edge){
    _edges.push_back(edge);
}

std::queue<Edge> Graph::findShortestPath(const Node& startNode, const Node& endNode){
    //implement Dijkstra's algorithm here
}

//Potentially write a function here to give all shortest paths to all nodes starting from a single node  (dijsktra's algorithm in full)
