//Edge.cpp includes the Edge.hpp header file and contains the implementation for the Edge class
#include <Edge.hpp>

Edge::Edge(const Node& n1, const Node& n2) : 
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

//Tests run in main.cpp ALL TESTS PASSED
/*
#include <Edge.hpp>

int main(){
    int x1 = 1;
    int y1 = 2;
    int x2 = 3;
    int y2 = 4;
    Node n1(x1,y1);
    Node n2(x2,y2);
    int myweight = abs(x1 - x2) + abs(y1 - y2);

    Edge testEdge(n1,n2);//should construct an edge with _node1 n1, _node2 n2, _weight myWeight
    std::vector<Node> testNodes = testEdge.getNodes(); // should return {n1, n2}
    int testWeight = testEdge.getWeight(); // should return myWeight
    testEdge.printEdge(); //Should print: "Edge between: (n1) and (n2)
                          //               Edge weight: myWeight"

}
*/