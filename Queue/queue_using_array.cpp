#include <iostream>
using namespace std;

class Queue{
    private:
    int size;
    int front;      // points before the first elm(the counter who stays before the 1st guy in a queue) 
    int rear;       // points to the last elm
    int * arr;
    public:
    Queue(){
        cout << "Enter the size of your array \n";
        cin >> size;
        front = rear = -1;
        arr = new int[size];
    }
    void enqueue(int x);
    void dequeue();
    void display();
};

void Queue :: enqueue(int x){
    if(rear == size-1)
        cout << "\nQueue is Full\n";
    else{
        arr[++rear] = x;        // rear is used for inserting
    }
}

void Queue :: dequeue(){
    int x = -1;
    if(front == rear)
        cout << "\nQueue is empty\n";
    else{
        front++;                // front is used for deleting an elm
        x = arr[front];
        cout << "\nDeleted elm is " << x << endl;
    }
}

void Queue :: display(){
    if(front == rear)
        cout << "\nQueue is empty\n";
    else{
        for(int i=front+1;i<=rear;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main(){
    Queue obj;
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.dequeue();
    obj.display();


    return 0;
}