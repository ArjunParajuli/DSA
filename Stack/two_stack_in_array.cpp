#include<iostream>
#include<stack>
using namespace std;

// first stack start from start of arr and secons start from end of arr
class twoStacks
{
public:
    int * arr;
    int size;
    int top1, top2;
    twoStacks(int n=100)
    {
        size = n;
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
         for(int i=0;i<size;i++){
             arr[i]=0;
        }
    }
    //Function to push an integer into the stack1.
    void push1(int x)
    {   // stack full
        if(top2-top1 == 1) return;

        top1++;
        arr[top1]=x;
      
    }
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        if(top2-top1 == 1) return;

        top2--;
        arr[top2] = x;
       
    }
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1==-1){
            return -1;
        }
        else
        return arr[top1--];
    }
    //Function to remove an element from top of the stack2.
    int pop2()
    { 
        if(top2==size) return -1;
        else return arr[top2++];
    }

    void print(){
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void printStack(stack<int> st){
        if(st.empty())
            return;
        
        int temp = st.top();
        st.pop();
        printStack(st);
        st.push(temp);
        cout << st.top() << " ";
    }

int main(){
    twoStacks st(5);
    st.push1(1);
    st.push2(2);
    st.push2(3);
    st.print();

    return 0;
}