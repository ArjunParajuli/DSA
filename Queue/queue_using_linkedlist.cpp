#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
};

class Queue{
    Node * front;
    Node * rear;
    public:
    Queue() : front(NULL), rear(NULL) {}
    void enqueue(int x);
    void dequeue();
    void display();
};

void Queue :: enqueue(int x){
    Node * temp; 
    temp = new Node;      
    if(temp == NULL)        // heap is full 
        cout << "\nQueue is full\n";
    else{
        temp->data = x;
        temp->next = NULL;
        if(front == NULL)   //first node
            front = rear = temp;
        else{
            rear->next = temp;
            rear = temp;
        }
    }
}

void Queue :: dequeue(){
    if(front == NULL)
        cout << "\nQueue is empty\n";
    else{
        Node * p = front;
        int x = front->data;
        front = front->next;
        cout << "\nDeleted elm is " << x << endl;
        delete (p);
    }
}

void Queue :: display(){
    Node * p = front;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
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