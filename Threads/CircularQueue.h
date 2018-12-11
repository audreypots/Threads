#include <iostream>
#define SIZE 5

using namespace std;

class CircularQueue {
    
private:
    int front, back;
    string items[SIZE];
    
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
    
    void add(string item){
        if(isFull())
        {
            front = (front + 1) % SIZE;
        } 
        else 
        {
            if(front == -1) 
                front = 0;
        }
        back = (back + 1) % SIZE;
        items[back] = item;
    }
    
    string remove()
    {
        string item = "";
        if(!isEmpty())
        {
            item = items[front];
            if(front == back)
                resetCircularQueue();
            else 
                front=(front+1) % SIZE;
        }
        return item;
    }

    string getRawQueue()
    {
        int i;
        string rawQueue = "";
        cout << "is Empty: " << isEmpty();
        if(!isEmpty()) 
        {
            for(i = 0; i < SIZE; i++)
                rawQueue += items[i];
        }
        return rawQueue;
    }
};
