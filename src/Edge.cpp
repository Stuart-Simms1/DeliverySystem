//Edge.cpp includes the Edge.hpp header file and contains the implementation for the Edge class
#include <Edge.hpp>

Edge::Edge(const Node& n1, const Node& n2): 
    _node1(n1), _node2(n2), 
    _weight(abs(n1.getCoord()[0]-n2.getCoord()[0]) + abs(n1.getCoord()[1]-n2.getCoord()[1])) {}

std::vector<Node> Edge::getNodes() const{
    return {_node1, _node2};
}

int Edge::getWeight() const{
    return _weight;
}

void Edge::printEdge() const{
    std::cout << "Edge between: ";
    _node1.printCoord();
    std::cout << "and ";
    _node2.printCoord();
    std::cout << "\nEdge weight: " << _weight << "\n";
}