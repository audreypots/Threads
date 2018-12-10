#include <iostream>
#define SIZE 5

using namespace std;

class CircularQueue {
private:
    int front, back;
    string commands[SIZE];
    
    void resetCircularQueue()
    {
        front = -1;
        back = -1;
    }
    
public:
    CircularQueue()
    {
         resetCircularQueue();
    }
    
    bool isEmpty()
    {
        if(front == -1) 
            return true;
        else 
            return false;
    }
    
    bool isFull()
    {
        if(front == 0 && back == SIZE - 1)
            return true;
        if(front == back + 1) 
            return true;
        return false;
    }
    
    void enQueue(string command){
        if(isFull())
        {
            cout << "Queue is full";
        } 
        else 
        {
            if(front == -1) 
                front = 0;
            back = (back + 1) % SIZE;
            commands[back] = command;
            cout << endl << "inserted the command" << command << endl;
        }
    }
    
    string deQueue()
    {
        string command;
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return "";
        } 
        else 
        {
            command = commands[front];
            if(front == back)
            {
                front = -1;
                back = -1;
            } 
            else 
            {
                front=(front+1) % SIZE;
            }
            return(command);
        }
    }
    
    void display()
    {
        /* Function to display status of Circular Queue */
        int i;
        if(isEmpty()) {
            cout << endl << "Empty Queue" << endl;
        }
        else
        {
            cout << "Front -> " << front;
            cout << endl << "Items -> ";
            for(i=front; i!=back;i=(i+1)%SIZE)
                cout << commands[i];
            cout << commands[i];
            cout << endl << "Rear -> " << back;
        }
    }
    
};
