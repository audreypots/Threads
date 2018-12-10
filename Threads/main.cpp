#include <stdio.h>
#include "CircularQueue.h"

int main(int argc, char **argv)
{
	printf("hello world\n");
    
    CircularQueue q;
    
    // Fails because front = -1
    q.deQueue();
    
    q.enQueue("banana");
    q.enQueue("banana");
    q.enQueue("banana");
    q.enQueue("banana");
    q.enQueue("banana");
    
    // Fails to enqueue because front == 0 && rear == SIZE - 1
    q.enQueue("banana");
    
    
    q.display();
    
    string command = q.deQueue();
    
    if( command != "")
       cout << endl << "deleted command is " << command;
    
    q.display();
    
    q.enQueue("apple");
    
    q.display();
    
    // Fails to enqueue because front == rear + 1
    q.enQueue("banana");
    
	return 0;
}
