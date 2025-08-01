//Customer.hpp - Customer class, and derived Store class, representing a Customer who can order from the store
/*it contains a Node _location which contains its (x,y) coordinate in the world
- a queue of Baskets _ordered with maximum size 2 which represents the baskets the customer has ordered from the store
- a queue of Baskets _received which represents the baskets the store has delivered
- a string _name which is the customer's name
- a Constructor function
- a function to return the name
- a function to return the location
- a funtion to return the ordered baskets
- a function to return the received baskets
- a function to order a new basket from the store
- a function to receive a basket that has been delivered
- a function to print the customer object for testing
*/
#include <Basket.hpp>
#include <Node.hpp>
#include <queue>
#include <exception>

class Customer{
 public:
    //Class Customer constructor accepting a string name and a Node location
    Customer(const std::string& name, const Node& location);

    //getter for the name
    std::string getName() const;

    //getter for the location
    Node getLocation() const;

    //getter for the ordered baskets
    std::queue<Basket> getOrdered() const;

    //getter for the received baskets
    std::vector<Basket> getDelivered() const;

    //function to order a basket from the store
    virtual void order(Basket& basket);

    //function to deliver a basket to the customer
    virtual void deliver(Basket& basket);

    //function to print out the customer for testing
    void printCustomer() const;

 protected:
    std::vector<Basket> _received = {};
 private:
    const std::string _name;
    const Node _location;
    std::queue<Basket> _ordered = {};
};

//Store class - represents the store in the world
/* inherits from Customer class all data members
- contains a constructor function
- overwrites the function order()
- overwrites the function deliver()
*/

class Store : public Customer{
 public:
    //Constructor
    Store(const std::string& name,const Node& location);
    
    //function to receive an order from a customer - overwrite of the Customer::order() function
    void order(Basket& basket);

    //function to deliver an order to a robot - overwrite of the Customer::deliver() function
    void deliver(Basket& basket);

    //function to update the received orders vector to set up for delivery.
    void updateWarehouseVector(const std::vector<Basket> received);
};