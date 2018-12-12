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
    
    virtual void display() { cout << "Fruit Command" << endl; };

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
