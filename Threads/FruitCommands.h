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
    
    static FruitCommands* createCommand(string command);
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

FruitCommands* FruitCommands::createCommand(string command)
{
    if(command == "apple")
        return new Apple();
    if(command == "banana")
        return new Banana();
    if(command == "orange")
        return new Orange();
    if(command == "exit")
        return new Exit();

    return new Unknown();
}