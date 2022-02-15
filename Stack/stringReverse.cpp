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
        
        void display(){
            if(top!=NULL){
                node * temp = top;
                while(temp){
                    cout<<temp->data;
                    temp=temp->next;
                }
            }
            else
				cout<<"Underflow\n";
        }
};
int main()
{
    string s;
    stack st;
    cout<<"Enter the string\n";
    getline(cin,s);
    int i = 0;
    while(s[i]){
        if(s[i]!=' ')
            st.push(s[i]);
        i++;
    }
    st.display();

    return 0;
}

