//Basket.cpp includes the Basket.hpp header file and contains the implementation of the Basket class
#include <Basket.hpp>

Basket::Basket(const std::string& name, const std::string& content) : _name(name), _content(content){};

std::string Basket::getName() const{
    return _name;
}

std::string Basket::getContent() const{
    return _content;
}

void Basket::printBasket() const{
    std::cout << "Ordered by: " << _name << "\n";
    std::cout << "Contents: " << _content << "\n";
}