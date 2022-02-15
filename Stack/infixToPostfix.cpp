#include <iostream>
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

char peek(){
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

bool isOperator(char a){
    if(a=='^' || a=='+'|| a=='-' || a=='*'|| a=='/')
        return true;
    return false;
}
int main()
{
    string s;
    cout<<"Enter the Infix expression\n";
    getline(cin,s);
    int i = 0;
    push('(');
    s = s + ')';
    cout<<"Postfix Expression:-\n";
    while(s[i]){
        if(s[i]=='(')
            push(s[i]);
        else if(s[i]==')'){
            char t = pop();
            while(t!='('){
                cout<<t;
                t=pop();
            }
        }
        else if(isOperator(s[i])){
            if(priority(s[i])>priority(peek()))
                push(s[i]);
            else{
                while(priority(s[i])<=priority(peek()))
                    cout<<pop();
                push(s[i]);
            }
        }
        else
            cout<<s[i];
        i++;
    }
    return 0;
}

