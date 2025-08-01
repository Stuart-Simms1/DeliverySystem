//Node.hpp - Node class represents a node in the graph in the world
/*It contains a vector _coord containing an (x,y) coordinate
- a constructor for the class
- a function that returns the coordinate
- a function that prints the coordinate for testing
*/
#include <vector>
#include <iostream>

class Node{
 public:
    //Class Node constructor, accepts an (x,y) coordinate and stores it as vector member _coord
    Node(const int xCoord, const int yCoord);
    //getter function for the member _coord
    std::vector<int> getCoord() const;
    //print function to display the Node's _coord
    void printCoord() const;
 private:
    const std::vector<int> _coord;
};