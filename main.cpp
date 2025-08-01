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
