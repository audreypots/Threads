#include <iostream>
class FruitCommands
{
public:
    FruitCommands()
    {
    }
    ~FruitCommands()
    {
    }
    
    virtual void display() { cout << "some fruit command" << endl; };

};

class Banana: public FruitCommands 
{
public:
    void display () { cout << "Banana" << endl; };
};

class Apple: public FruitCommands
{
public:
    void display () { cout << "Apple" << endl; };
};

class Orange: public FruitCommands
{
public:
    void display () { cout << "Orange" << endl; };
};

class Unknown: public FruitCommands
{
public:
    void display () { cout << "Unknown command" << endl; };
};
