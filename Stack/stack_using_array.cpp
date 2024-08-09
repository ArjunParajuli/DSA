#include <iostream>
using namespace std;

class stack{
    public:
    int top;
    int size;
    int *arr;   // for dynamically creating array in heap
};

void push(stack *obj, int elm){     //we want to modify the actual stack so pass obj by pointer 
    if(obj->top == obj->size-1){
        cout << "Stack Overflow" << endl; 
    }else{
        //obj->top++;
        obj->arr[++obj->top] = elm;
    }
}

int pop(stack *obj){    //returns deleted elm else returns -1
    int x = -1;
    if(obj->top == -1){
        cout << "\nStack Underflow" << endl;
    }else{
        x = obj->arr[obj->top--];
    }
    return x;
}

void peek(stack *obj, int pos){
    if(pos < 1 || pos > obj->size){
        cout << "\nInvalid position\n";
        return;
    }
    cout << "Elm at position " << pos << " is "<< obj->arr[obj->top-pos+1] << endl;  //returns elm at that pos
}

void isEmpty(stack *obj){
    if(obj->top == -1)
        cout << "\nStack is Empty\n";
    else    
        cout << "\nStack is not Empty\n";
}

void isFull(stack *obj){
    if(obj->top == obj->size-1)
        cout << "\nStack is Full\n";
    else    
        cout << "\nStack is not Full\n";
}

void display(stack *obj){
    for(int i=obj->top;i>=0;i--)
        cout << " " << obj->arr[i] << " ";
    cout << endl;
}

int main(){
    stack obj;
    // cout << "Enter size of stack/Arrray: " << endl;
    // cin >> obj.size;
    obj.size = 5; 
    obj.arr = new int[obj.size];
    obj.top = -1;
    push(&obj, 10);
    push(&obj, 20);
    push(&obj, 30);
    push(&obj, 40);
    push(&obj, 50);
    display(&obj);

    // cout << pop(&obj);
    peek(&obj, 5);
    display(&obj);

    return 0;
}

// easy one
// class stack{
//   public:
//   int top=-1;
//   int st[n];
  
//   void push(int x){
//     if(top == n-1)
//         cout << "Stack overflow";
//     else{
//         st[++top] = x;
//     }
//   }
  
//   int pop(){
//     int poped = -1;
//     if(top == -1)
//         cout << "Stack underflow";
//     else{
//         poped = st[top];
//         st[top] = -1;
//         top--;
//     }
//     return poped;
//   }
  
//   void print(){
//     for(int i=0;i<=top;i++){
//         cout << st[i] << " ";    
//     }
//   }
  
// };