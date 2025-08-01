//Graph.hpp - Graph class represents the underlying structure of the world
/*includes a vector of Nodes _nodes representing all the nodes in the graph
 - a vector of Edges _edges representing all the edges between the nodes
 - a constructor function
 - a function to return the _nodes vector
 - a function to return the _edges vector
 - a function to push an Edge to the vector _edges
 - a function to push a Node to the vector _nodes
 - a function that computes the shortest path between two nodes
 - potentially a function that computes the shortest path on a loop between multiple nodes
 

 - potentially a function compute all shortest paths to all nodes from a single starting node (the store node) i.e.dijkstra's algorithm in full
 - potentially a data member (maybe a set?) to store all these shortest paths;
*/
#include <Edge.hpp>

class Graph{
 public:
    //Class Graph constructor
    Graph(const std::vector<Node>& nodes, const std::vector<Edge>& edges);

    //getter for _nodes
    std::vector<Node> getNodes() const;

    //getter for _edges
    std::vector<Edge> getEdges() const;

    //function to push a node to the graph
    void pushNode(const Node& node);

    //function to push an edge to the graph
    void pushEdge(const Edge& edge);

    //function to find the shortest path between two nodes
    std::queue<Edge> findShortestPath(const Node& startNode, const Node& endNode); 

 private:
    std::vector<Node> _nodes;
    std::vector<Edge> _edges;
    //std::vector<std::vector<Edge> > _dijsktraPaths;
};