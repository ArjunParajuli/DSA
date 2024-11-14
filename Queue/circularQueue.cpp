#include <iostream>
using namespace std;

//optimized queue(we can reuse the vacant spaces left after dequeue opr)

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
        front = rear = 0;       //circular queue starts front and rear from 0
        arr = new int[size];
    }
    void enqueue(int x);
    void dequeue();
    void display();
};

void Queue :: enqueue(int x){
   if((rear+1)%size == front)           // it checks if rear is right after front or not(eg. when front=0, rear=size-1 i.e queue full)
        cout << "\nQueue is  full\n";
    else{
        rear = (rear+1)%size;       //moves rear one step ahead(eg. after 4(size-1), rear moves to 0 index again)
        arr[rear] = x;
    }
}

void Queue :: dequeue(){
    if(front == rear)
        cout << "\nQueue is empty\n";
    else{
        front = (front+1) % size;       // moves front to a step ahead
        int x = arr[front]; 
        cout << "\nDeleted elm is " << x << "\n";
     }
}

void Queue :: display(){
    int i = front+1;
    do{
        cout << arr[i] << " ";
        i = (i+1)%size;
    }while(i != (rear+1)%size);

    cout << endl;
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