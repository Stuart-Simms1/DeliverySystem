//Edge.cpp includes the Edge.hpp header file and contains the implementation for the Edge class
#include <Edge.hpp>

Edge::Edge(const Node& n1, const Node& n2) : 
    _startNode(n1), _endNode(n2),
    _path(createPath(n1,n2)), 
    _weight(abs(n2.getCoord()[0] - n1.getCoord()[0]) + abs(n2.getCoord()[1] - n1.getCoord()[1])){}

std::vector<Node> Edge::getNodes() const{
    return {_startNode, _endNode};
}

int Edge::getWeight() const{
    return _weight;
}

std::queue<Node> Edge::getPath() const{
    return _path;
}

Node Edge::getNextStep() const{
    return _path.front();
}

Node Edge::step(){
    _path.pop();
    if((_path.front().getCoord()[0] == _endNode.getCoord()[0]) && (_path.front().getCoord()[1] == _endNode.getCoord()[1])){
        Node lastStep = _path.front();
        restorePath();
        return lastStep;
    } else{
        return _path.front();
    }
}

void Edge::restorePath(){
    _path = createPath(_startNode,_endNode);
}

void Edge::printEdge() {
    std::cout << "{Edge between: ";
    _startNode.printNode();
    std::cout << "and ";
    _endNode.printNode();
    std::cout << "\nEdge weight: " << _weight << "}\n";
    //Optional
    restorePath();
    std::cout<< "{Path: ";
    _path.front().printNode();
    while(_path.size() > 2){
        step().printNode();
    }
    step().printNode();
    std::cout << "}" << std::endl;
}

std::queue<Node> Edge::createPath(const Node& startNode, const Node& endNode){
    int xCurr = startNode.getCoord()[0];
    int yCurr = startNode.getCoord()[1];
    int xEnd = endNode.getCoord()[0];
    int yEnd = endNode.getCoord()[1];
    int directionX = xEnd - xCurr;
    int directionY = yEnd - yCurr;
    std::queue<Node> steps;
    
    if(abs(directionX) > abs(directionY)){
        if(directionX>0){
            while(xCurr != xEnd){
                Node step(xCurr,yCurr);
                steps.push(step);
                xCurr++;
            } 
        } else {
            while(xCurr != xEnd){
                Node step(xCurr,yCurr);
                steps.push(step);
                xCurr--;
            } 
        }

        if(directionY>0){
            while(yCurr != yEnd){
                Node step(xCurr,yCurr);
                steps.push(step);
                yCurr++;
            }
        } else {
            while(yCurr != yEnd){
                Node step(xCurr,yCurr);
                steps.push(step);
                yCurr--;
            }
        }
    } else {
        if(directionY>0){
            while(yCurr != yEnd){
                Node step(xCurr,yCurr);
                steps.push(step);
                yCurr++;
            }
        } else {
            while(yCurr != yEnd){
                Node step(xCurr,yCurr);
                steps.push(step);
                yCurr--;
            }
        }

        if(directionX>0){
            while(xCurr != xEnd){
                Node step(xCurr,yCurr);
                steps.push(step);
                xCurr++;
            } 
        } else {
            while(xCurr != xEnd){
                Node step(xCurr,yCurr);
                steps.push(step);
                xCurr--;
            } 
        }
    }
    Node end(xEnd,yEnd);
    steps.push(end);
    return steps;
};


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
*/