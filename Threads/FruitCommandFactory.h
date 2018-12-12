class FruitCommandFactory
{
public:
    FruitCommandFactory()
    {
    }
    
    ~FruitCommandFactory()
    {
    }
    
    FruitCommands* createFruitCommand(string command)
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
};
