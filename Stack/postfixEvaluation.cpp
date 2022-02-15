#include <iostream>
#include <math.h>
using namespace std;

struct stack{
    char data;
    stack * next;
}*top = NULL;

bool isEmpty(){
    return top==NULL;
}

void push(char a){
    stack *temp = new stack;
    temp->data = a;
    temp->next = NULL;
    if(isEmpty())
        top = temp;
    else{
        temp->next=top;
        top=temp;
    }
}

char pop(){
    char t = top->data;
    stack *temp = top;
    top = top->next;
    delete temp;
    return t;
}

int peek(){
    return top->data;
}

int priority(char a){
    if(a=='-' || a=='+')
        return 1;
    else if(a=='*' || a=='/')
        return 2;
    else if(a=='^')
        return 3;
    else 
        return 0;
}

void display(){
    stack *temp = top;
    while(temp){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

bool isOperand(char a){
    if(a=='^' || a=='+'|| a=='-' || a=='*'|| a=='/')
        return false;
    return true;
}
int main()
{
    string s;
    cout<<"Enter the Infix expression\n";
    getline(cin,s);
    int i = 0;
    cout<<"Post Evaluation:-\n";
    while(s[i]){
        if(isOperand(s[i]))
            push(s[i]);
        else{
            int a = pop()-48;
            int b = pop()-48;
            switch(s[i]){
                case '+':   push((b+a)+48);
                            break;
                case '-':   push((b-a)+48);
                            break;
                case '*':   push((b*a)+48);
                            break;
                case '/':   push((b/a)+48);
                            break;
                case '^':   push((pow(b,a))+48);
                            break;
            }
        }
        i++;
    }
    cout<<peek()-48;
    return 0;
}

