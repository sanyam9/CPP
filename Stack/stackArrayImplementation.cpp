#include <iostream>
using namespace std;
class stack{
    int *arr;
    int top;
    int n;
    
    public:
        stack(int s){
            arr = new int[s];
            n = s;
            top = -1;
        }
        
        bool isEmpty(){
            return top==-1;
        }
        
        bool isFull(){
            return top==n-1;
        }
        
        int peek(){
            if(!isEmpty())
                return arr[top];
        }
        
        void push(int a){
            if(!isFull()){
                top++;
                arr[top]=a;
            }
            else
            	cout<<"Overflow\n";
        }
        
        int pop(){
            if(!isEmpty()){
                int temp = arr[top];
                top--;
                return temp;
            }
        }
        
        void display(){
            if(!isEmpty()){
                for(int i = top ; i>=0; i--)
                    cout<<arr[i]<<endl;
            }
            else
				cout<<"Underflow\n";
        }
};
int main()
{
    int n,ch,a,f=1;
    cout<<"Enter size of the stack\n";
    cin>>n;
    stack s(n);
    cout<<"1.Push\n2.Pop\n3.Peek\n4.Display stacks elements\n5.Quit\n";
    while(f){
        cout<<"Choose an operation\n";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter the element to be inserted\n";
                    cin>>a;
                    s.push(a);
                    break;
            case 2: if(!s.isEmpty())
						cout<<s.pop()<<" is popped out!\n";
					else
						cout<<"Underflow\n";
                    break;
            case 3: if(!s.isEmpty())
						cout<<s.peek()<<" is the top element\n";
					else
						cout<<"Underflow\n";
                    break;
            case 4: s.display();
                    break;
            case 5: f=0;
                    break;
        }
    }
    return 0;
}

