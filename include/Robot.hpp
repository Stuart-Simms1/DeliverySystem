//Robot.hpp - Robot class representing a robot that delivers the ordered baskets
/*It contains a Node _position which is the position of the robot in the world
 - an int _capacity which is the maximum number of orders the robot can deliver at once
 - // possibly a Path _path 
 - a queue of Baskets _inventory it is delivering
 - a constructor function
 - a function to return the _position
 - a function to return the _inventory
 - a function to return the front Basket in the _inventory
 - // possibly a function to return the _path
 - a function that can "pick up" a basket and push it to the _inventory
 - a function that can "deliver" a basket and pop it from the _inventory
 - // possibly a function that sets a new _path for the robot
 - // possibly a function that updates the _position of the robot to the next position in the _path
 - a function that prints the robot for testing purposes
*/
#include <Basket.hpp>
#include <Node.hpp>
#include <queue>
#include <exception>

class Robot{
 public:
    //Class Robot constructor
    Robot(const Node& startingPosition, const std::queue<Basket>& inventory, const int capacity);

    //getter for position
    Node getPosition() const;

    //getter for inventory
    std::queue<Basket> getInventory() const;

    //getter for the front Basket of _inventory
    Basket getFront() const;

    //function to push a basket to the inventory
    void pickUp(const Basket& order);

    //function to remove a basket from the inventory
    void deliver(const Basket& order);

    //printing function for testing purposes
    void printRobot() const;

 private:
    Node _position;
    std::queue<Basket> _inventory;
    const int _capacity;
};