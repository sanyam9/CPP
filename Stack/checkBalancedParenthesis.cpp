#include <iostream>
using namespace std;

struct node{
char data;
node * next;
};

class stack{
    node * top;

    public:
        stack(){
            top = NULL;
        }
        
        void push(int a){
            node * temp = new node;
            temp->data = a;
            temp->next = NULL;
            if(!top)
                top = temp;
            else{
                temp->next = top;
                top = temp;
            }
        }
        
        char pop(){
                int temp = top->data;
                top=top->next;
                return temp;
        }
};
int main()
{
    string s;
    stack st;
    cout<<"Enter the expression\n";
    getline(cin,s);
    int i = 0;
    while(s[i]){
        if(s[i]=='[' || s[i]=='(' || s[i]=='{')
            st.push(s[i]);
        else{
            switch(s[i]){
                case ']':   if(st.pop()!='['){
                                cout<<"Unbalanced Expression\n";
                                return 0;
                            }
                            break;
                case ')':   if(st.pop()!='('){
                                cout<<"Unbalanced Expression\n";
                                return 0;
                            }
                            break;
                case '}':   if(st.pop()!='{'){
                                cout<<"Unbalanced Expression\n";
                                return 0;
                            }
                            break;
            }
        }
        i++;
    }
    cout<<"Balanced Expression\n";

    return 0;
}

