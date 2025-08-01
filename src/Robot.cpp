//Robot.cpp - include the Robot.hpp header file and contains the implementation of the Robot class
#include <Robot.hpp>

Robot::Robot(const Node& startingPosition, const std::queue<Basket>& inventory, const int capacity) : 
                                    _position(startingPosition), _inventory(inventory), _capacity(capacity){};

Node Robot::getPosition() const{
    return _position;
}

std::queue<Basket> Robot::getInventory() const{
    return _inventory;
}

Basket Robot::getFront() const{
    return _inventory.front();
}

void Robot::pickUp(const Basket& order){
    if(_inventory.size()<_capacity){
        _inventory.push(order);
    } else{
        throw std::logic_error("Robot cannot pick up order because it is full! Customer name: " + order.getName());
    }
}

void Robot::deliver(const Basket& order){
    if((_inventory.front().getName() == order.getName()) && (_inventory.front().getContent() == order.getContent())){
        _inventory.pop();
    } else{
        throw std::logic_error("Robot cannot deliver this order because it doesn't match the top of its inventory. Customer name: " + order.getName());
    }
}

void Robot::printRobot() const{
    std::cout<< "{Robot capacity: " << _capacity << "\nRobot position: ";
    _position.printNode();
    std::cout << "\nRobot inventory: ";
    std::queue<Basket> printableQ = _inventory;
    while(!printableQ.empty()){
        printableQ.front().printBasket();
        printableQ.pop();
    }
    std::cout << "}" << std::endl;
}