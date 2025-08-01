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
    std::cout << "{Ordered by: " << _name << "\n";
    std::cout << "Contents: " << _content << "}\n";
}

//Tests run in main.cpp ALL TESTS PASSED
/*
#include <Basket.hpp>

int main(){
    std::string name = "Stuart";
    std::string content = "My Groceries";

    Basket testBasket(name,content);    //should construct a Basket with _name name and _content content
    std::string testName = testBasket.getName();    //should return name
    std::string testContent = testBasket.getContent(); //should return content
    testBasket.printBasket(); //should print: "Ordered by: name
                              //               Contents: content "
}
*/