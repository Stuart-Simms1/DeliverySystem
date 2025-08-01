#include <Edge.hpp>

int main(){
    int x1 = 1;
    int y1 = 2;
    int x2 = 3;
    int y2 = 4;
    Node n1(x1,y1);
    Node n2(x2,y2);
    int myweight = abs(x1 - x2) + abs(y1 - y2);

    Edge testEdge(n1,n2);//should construct an edge with _startNode n1, _endNode n2, _weight myWeight
    std::vector<Node> testNodes = testEdge.getNodes(); // should return {n1, n2}
    int testWeight = testEdge.getWeight(); // should return myWeight
    std::queue<Node> testAllSteps = testEdge.getPath(); //should return a queue {(1,2),(1,3),(1,4),(2,4),(3,4)}
    Node testNode = testEdge.getNextStep(); //should return (1,2)
    Node testStep = testEdge.step();    //should pop (1,2) from _steps and return (1,3)
    testEdge.printEdge(); //Should print: "Edge between: (n1) and (n2)
                          //               Edge weight: myWeight"
                          //               Path: (1,2),(1,3),(1,4),(2,4),(3,4)

}
