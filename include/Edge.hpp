//Edge.hpp - Edge class represents an edge between two nodes in the graph
/*It contains two nodes, _startNode and _endNode, which it connects on either end
- an integer _weight which is a measure of the distance between the two nodes
- a queue _path which contains the pixels along the edge
- a constructor function
- a function to return the end nodes
- a function that returns the whole _path
- a function that returns the next step in the _path
- a function that returns the next step and pops the current step in the _path
- a function to print the edge for testing

*/
#include <Node.hpp>
#include <queue>

class Edge{
 public:
    //Class Edge constructor, accepting the two end nodes as arguments
    Edge(const Node& n1, const Node& n2);

    //getter function for the nodes
    std::vector<Node> getNodes() const;

    //getter function for the weight
    int getWeight() const;

    //getter function for the path (not sure if I need it yet)
    std::queue<Node> getPath() const;

    //getter for the next step in the path
    Node getNextStep() const;  

    //function that returns the next step and also pops it from the queue
    Node step();

    //print function for testing
    void printEdge();

 private:
    //function that creates a queue of the nodes between the start and end Nodes.
    std::queue<Node> createPath(const Node& startNode, const Node& endNode);

    //function that restores _path to the full path between _startNode and endNode
    void restorePath();

 private:
    const Node _startNode;
    const Node _endNode;
    const int _weight;
    std::queue<Node> _path;
};