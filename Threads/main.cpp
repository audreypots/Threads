#include <stdio.h>
#include "CircularQueue.h"

int main(int argc, char **argv)
{
	printf("hello world\n");
    
    CircularQueue q;
    
    // Fails because front = -1
    q.remove();
    
    q.add("banana");
    q.add("banana");
    q.add("banana");
    q.add("banana");
    q.add("banana");
    
    // Fails to enqueue because front == 0 && rear == SIZE - 1
    q.add("banana");
    
    
    //string command = q.remove();
    
    //if( command != "")
    //   cout << endl << "deleted command is " << command;
    
    //q.displayQueue();
    q.add("apple");
    
    
    // Fails to enqueue because front == rear + 1
    q.add("banana");
    
    //q.displayQueue();
	return 0;
}
