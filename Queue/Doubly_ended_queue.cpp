#include<iostream>
#include<queue>
using namespace std;

// Doubly Ended Queue (push and pop from both sides)

class Deque{
    public:
    int * queue;
    int N;
    int rear;
    int front;

    Deque(int size){
        queue = new int[size];
        N = size;
        front=-1;
        rear=-1; 
    }
};

void push_back(int elm){
     if(rear == N-1){
		printf("Queue is full\n");
	}else if(front == -1 && rear == -1){
		front=rear=0;
		queue[rear] = elm;
	}else{
		rear++;
		queue[rear] = elm;
	}
}

void push_front(int elm){
     if(front == 0){
		printf("Queue overflow\n");
	}else if(front == -1 && rear == -1){
		front++;
        rear++;
		queue[front] = elm;
	}else{
        front--;
        queue[front] = elm;
    }
}

void pop_front(){
     if(front == -1 && rear == -1){
		printf("Queue is empty");
	}else if(front == rear){
		front=rear=-1;
	}else{
		printf("The dequeued element is %d\n",queue[front]);
		front++;
	}
}

void pop_back(){
     if(front == -1 && rear == -1){
		printf("Queue is empty");
     }else if(front == rear){
		front=rear=-1;
     }else{
        rear--;
     }
}

int main(){
    Deque(5);

    return 0;
}