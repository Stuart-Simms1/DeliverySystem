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