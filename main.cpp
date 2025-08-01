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
