//Customer.cpp - includes Customer.hpp header for class Customer and derived class Store and contains the implementation for those classes
#include <Customer.hpp>

Customer::Customer(const std::string& name, const Node& location) : _name(name), _location(location) {};

std::string Customer::getName() const{
    return _name;
}

Node Customer::getLocation() const{
    return _location;
}

std::queue<Basket> Customer::getOrdered() const{
    return _ordered;
}

std::vector<Basket> Customer::getDelivered() const{
    return _received;
}

void Customer::order(Basket& basket){
    if(_ordered.size()<2){
        _ordered.push(basket);
    } else{
        throw std::logic_error("Cannot order more than 2 baskets per customer. Customer name: " + _name);
    }
}

void Customer::deliver(Basket& basket){
    if((_ordered.front().getName() == basket.getName()) && (_ordered.front().getContent() == basket.getContent())){
        _ordered.pop();
        _received.push_back(basket);
    } else{
        throw std::logic_error("Cannot deliver basket, basket does not match. Customer name: " + _name);
    }
}

void Customer::printCustomer() const{
    std::cout << "{Customer Name: " << _name << "\n";
    std::cout << "Customer location: ";
    _location.printNode();
    std::cout << "\nCustomer Ordered Baskets: ";
    
    std::queue<Basket> printableQ = _ordered;
    while(!printableQ.empty()){
        printableQ.front().printBasket();
        printableQ.pop();
    }
    std::cout << "Customer received Baskets: ";
    for(Basket basket : _received){
        basket.printBasket();
    }
    std::cout << "}" <<std::endl;
};




Store::Store(const std::string& name,const Node& location): Customer(name,location){};

void Store::order(Basket& basket){
    _received.push_back(basket);
}

void Store::deliver(Basket& basket){
    if((_received.back().getName() == basket.getName()) && (_received.back().getContent() == basket.getContent())){
        _received.pop_back();
    } else{
        throw std::logic_error("Didn't sort received orders vector properly, basket is not at the back");
    }
}

void Store::updateWarehouseVector(std::vector<Basket> received){
    _received.swap(received);
};

//Tests run in main.cpp ALL TESTS PASSED
/*
#include <Customer.hpp>

int main(){
    int xCoord = 1;
    int yCoord = 2;
    Node location(xCoord,yCoord);
    std::string name = "Stuart";
    std::string content = "My Groceries";
    Basket order(name,content);
    std::string STORENAME = "Store";
    Node STORENODE(5,5);

    Customer testCustomer(name,location); //should construct a customer with _name name and _ location location, empty _ordered and _received
    std::string testName = testCustomer.getName();  //should return name
    Node testLocation = testCustomer.getLocation(); //should return location
    std::queue<Basket> testOrdered = testCustomer.getOrdered(); //should return an empty queue
    std::vector<Basket> testDelivered = testCustomer.getDelivered();    //should return an empty vector
    testCustomer.order(order); //should push order to the _ordered queue
    testCustomer.printCustomer(); //should print"{Customer Name: name
                                  //             Customer Location: location
                                  //             Customer Ordered Baskets:{order}
                                  //             Customer received Baskets:
    testCustomer.deliver(order);
    testCustomer.printCustomer(); //should print"{Customer Name: name
                                  //             Customer Location: location
                                  //             Customer Ordered Baskets:
                                  //             Customer received Baskets:{order}

    Store testStore(STORENAME,STORENODE);//should construct a store with _name STORENAME and _location STORENODE
    testStore.order(order); //should push order to the received vector
    testStore.printCustomer(); //should print"{Customer Name: STORENAME
                                //             Customer Location: STORENODE
                                //             Customer Ordered Baskets:
                                //             Customer received Baskets:{order}
    testStore.deliver(order); // should pop the order from the _received vector
    testStore.printCustomer(); //should print"{Customer Name: name
                                  //             Customer Location: location
                                  //             Customer Ordered Baskets:
                                  //             Customer received Baskets:

    testCustomer.order(order);
    testCustomer.order(order);
    try{
        testCustomer.order(order);//should throw an exception
    } catch(std::logic_error e){
        std::cout<< e.what() << std::endl;
    }

    std::string differentName = "Moa";
    std::string differentContent = "Her Groceries";
    Basket differentOrder(differentName,differentContent);
    testStore.order(differentOrder);
    try{
        testStore.deliver(order);//should throw an exception
    } catch(std::logic_error err){
        std::cout << err.what() <<std::endl;
    }

}
*/