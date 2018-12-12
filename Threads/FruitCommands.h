#include <iostream>

class FruitCommands
{
public:
    FruitCommands() 
    {
    }
    
    virtual ~FruitCommands() 
    {
    }
    
    virtual void display() 
    { 
        cout << "some fruit command" << endl; 
    }
};

class Banana: public FruitCommands 
{
public:
    Banana() 
    {
    }
    
    ~Banana() 
    {
    }
    
    void display() 
    { 
        cout << "Banana" << endl; 
    }
};

class Apple: public FruitCommands
{
public:
    Apple()
    {
    }
    
    ~Apple()
    {
    }
    
    void display()
    { 
        cout << "Apple" << endl; 
    }
};

class Orange: public FruitCommands
{
public:
    Orange()
    {
    }
    
    ~Orange()
    {
    }
    
    void display() 
    { 
        cout << "Orange" << endl; 
    }
};

class Exit: public FruitCommands
{
public:
    Exit() 
    {
    }
    
    ~Exit() 
    {
    }
    
    void display() 
    {
        cout << "terminating..." << endl;
    }
};

class Unknown: public FruitCommands
{
public:
    Unknown() 
    {
    }
    
    ~Unknown() 
    {
    }
    
    void display() 
    { 
        cout << "Unknown command" << endl; 
    }
};
