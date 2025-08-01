//Basket.hpp - Basket class represents a basket that has been ordered in the world
/* it contains a std::string _name of the customer who has ordered the basket
- a std::string _content which it is "holding" (this can be changed to an enum if things get more complicated)
- a constructor function
- a function to return the _name
- a funtion to return the _content
- a funtion to print the basket for testing
*/
#include<string>
#include<iostream>

class Basket{
 public:
    //Class Basket construtor accepting a string name and a string content
    Basket(const std::string& name, const std::string& content);

    //getter for the name
    std::string getName() const;

    //getter for the content
    std::string getContent() const;

    //printing function for testing
    void printBasket() const;

 private:
    const std::string _name;
    const std::string _content;

};