#include <Node.hpp>

int main(){
    int xCoord = 1;
    int yCoord = 2;
    Node testNode(xCoord,yCoord);   //should construct a node with _coord = (xCoord,yCoord)
    std::vector<int> testCoord = testNode.getCoord(); //should return a vector testCoord = (xCoord,yCoord)
    testNode.printCoord(); //should print "(xCoord, yCoord) " to the console
}
