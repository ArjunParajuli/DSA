#include <iostream>
using namespace std;

// To perform all the operations our head of the linked list would act as the top of the stack

class Node{
    public:
    int data;
    Node * next;
};

class Stack{
    private:
    Node * top;
    public:
    Stack() : top(NULL) {}
    void push(int x);
    void pop();
    void display();
    int isEmpty();
    int isFull();
};

void Stack :: push(int x){
    Node * temp = new Node;     // creating a node
    if(temp == NULL)
        cout << "\nStack is full\n";
    else{
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

void Stack :: pop(){
    if(top == NULL)
        cout << "\nStack is Empty\n";
    else{
        int x = top->data;
        Node *p = top;
        top = top->next;
        delete(p);
        cout << "Deleted elm is " << x << endl;
    }
}

void Stack :: display(){
    if(top == NULL)
        cout << "\nStack is empty\n";
    else{
        Node * p = top;
        while(p != NULL){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int Stack :: isEmpty(){
    return ((top) ? 0 : 1);  
}
int Stack :: isFull(){
   Node * temp = new Node;
   return (temp==NULL) ? 1 : 0;
}

int main(){
    Stack obj;
    // obj.push(1);
    // obj.push(2);
    // obj.push(3);
    // obj.pop();
    // obj.display();
    cout << obj.isEmpty();

    return 0;
}