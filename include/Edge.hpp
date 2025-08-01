//Edge.hpp - Edge class represents an edge between two nodes in the graph
/*It contains two nodes, _node1 and _node2, which it connects on either end
- an integer _weight which is a measure of the distance between the two nodes
- possibly a Path _path which contains the pixels along the edge
- a constructor function
- a function to return the end nodes
- a function to print the edge for testing

*/

#include <Node.hpp>

class Edge{
 public:
    //Class Edge constructor, accepting the two end nodes as arguments
    Edge(const Node& n1, const Node& n2);

    //getter function for the nodes
    std::vector<Node> getNodes() const;

    //getter function for the weight
    int getWeight() const;

    //getter function for the path (not sure if I need it yet)
    // Path getPath() const;

    //print function for testing
    void printEdge() const;

 private:
    const Node _node1;
    const Node _node2;
    const int _weight;
    //const Path _path;
};