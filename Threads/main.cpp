#include <stdio.h>
#include <iostream>
#include <thread>
#include "CircularQueue.h"
#include "FruitCommands.h"

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
        FruitCommands *fCommand = NULL;

        command = cq->remove();

        fCommand = FruitCommands::createCommand(command);
     
        fCommand->display();

        delete fCommand;
        
        if(command == "exit")
            break;
    }
}

int main(int argc, char **argv)
{
    CircularQueue qc;

    cout << "create the threads..." << endl;
    cout << "you can now start entering fruit commands..." << endl;
    cout << "(type exit to terminate)" << endl;
    thread thread1 (commandInputThread, &qc);
    thread thread2 (displayThread, &qc);

    thread1.join();
    thread2.join();

    cout << "terminated!" << endl;    

    return 0;
}
