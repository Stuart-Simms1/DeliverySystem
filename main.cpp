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
