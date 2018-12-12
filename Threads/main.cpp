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

    thread thread1 (commandInputThread, &qc);
    thread thread2 (displayThread, &qc);

    thread1.join();
    thread2.join();

    cout << "threads are joined, exit!" << endl;    

    return 0;
}
