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

//Tests run in main.cpp ALL TESTS PASSED
/*
#include <Robot.hpp>

int main(){
    int startingX = 5;
    int startingY = 5;
    Node startingNode(startingX,startingY);
    int capacity = 1;
    std::queue<Basket> emptyQ = {};

    Robot testRobot(startingNode, emptyQ, capacity);    // should construct a robot with _position startingNode, _inventory {}, _capacity 1

    std::string name = "Stuart";
    std::string content = "My Groceries";
    Basket order(name,content);
    testRobot.pickUp(order);    //should push order to _inventory

    Node testNode = testRobot.getPosition();    // should return _position = startingNode
    std::queue<Basket> testInventory = testRobot.getInventory();    //should return _inventory = order
    Basket testBasket = testRobot.getFront(); // should return order
    testRobot.deliver(order);   //should pop order from the _inventory
    testRobot.printRobot();     //should print {Robot capacity: 1
                                //              Robot position: (startingNode)
                                //              Robot inventory: }

    testRobot.pickUp(order);
    try{
        testRobot.pickUp(order);
    } catch(std::logic_error e){
        std::cout << e.what() << std::endl;
    }

    std::string differentName = "Moa";
    std::string differentContent = "Her Groceries";
    Basket differentOrder(differentName,differentContent);
    try{
        testRobot.deliver(differentOrder);
    } catch(std::logic_error err){
        std::cout << err.what() << std::endl;
    }
}
*/