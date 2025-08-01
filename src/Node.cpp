//Node.cpp includes Node class header file and contains the implementation for the Node class
#include <Node.hpp>

Node::Node(const int xCoord, const int yCoord) : _coord({xCoord, yCoord}) {};

std::vector<int> Node::getCoord() const {
    return _coord;
};

void Node::printNode() const{
    auto myX = _coord[0];
    auto myY = _coord[1];
    std::cout << '(' << _coord[0] << ", " << _coord[1] << ") ";
}

//Tests run in main.cpp: ALL TESTS PASSED

/*
#include <Node.hpp>

int main(){
    int xCoord = 1;
    int yCoord = 2;
    Node testNode(xCoord,yCoord);   //should construct a node with _coord = (xCoord,yCoord)
    std::vector<int> testCoord = testNode.getCoord(); //should return a vector testCoord = (xCoord,yCoord)
    testNode.printNode(); //should print "(xCoord, yCoord) " to the console
}
*/