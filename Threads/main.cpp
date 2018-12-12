#include <stdio.h>
#include "CircularQueue.h"
#include "FruitCommands.h"
#include <iostream>       // std::cout
#include <thread>         // std::thread

void commandInputThread(CircularQueue * cq) 
{
    while(true)
    {
        string command;
        cin >> command;
        cq->add(command);
        if(command == "exit")
            break;
    }
}

void displayThread(CircularQueue *cq)
{
    while(true)
    {
        if(cq->isEmpty())
            continue;
        string command;
        FruitCommands *fCommand;
        command = cq->remove();
        if (command == "apple")
            fCommand = new Apple();
        else if (command == "banana")
            fCommand = new Banana();
        else if (command == "orange")
            fCommand = new Orange();
        else if (command == "exit")
            break;
        else
            fCommand = new FruitCommands();
        fCommand->display();
    }
}

int main(int argc, char **argv)
{
    CircularQueue qc;
    
    cout << "create the threads..." << endl;
    thread t1 (commandInputThread, &qc);
    thread t2 (displayThread, &qc);
    t1.join();
    t2.join();
    cout << "exit!" << endl;    

	return 0;
}
