#include <iostream>
using namespace std;
struct node{
    int data;
    node * next;
};
class stack{
    node * top;
    public:
        stack(){
            top = NULL;
        }
        
        bool isEmpty(){
            return top==NULL;
        }
        
        int peek(){
            if(!isEmpty())
                return top->data;
        }
        
        void push(int a){
            node * temp = new node;
            temp->data = a;
            temp->next = NULL;
            if(isEmpty())
                top = temp;
            else{
                temp->next = top;
                top = temp;
            }
        }
        
        int pop(){
            if(!isEmpty()){
                int temp = top->data;
                top=top->next;
                return temp;
            }
        }
        
        void display(){
            if(!isEmpty()){
                node * temp = top;
                while(temp){
                    cout<<temp->data<<endl;
                    temp=temp->next;
                }
            }
            else
				cout<<"Underflow\n";
        }
};
int main()
{
    int ch,a,f=1;
    stack s;
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

