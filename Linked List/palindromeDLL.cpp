#include <iostream>

using namespace std;

struct node{
    char ch;
    node * next;
    node * pre;
} * head = NULL;

void insertNode(char a){
    node * temp = new node;
    temp->ch = a;
    temp->next = temp->pre = NULL;
    
    if(head == NULL)
        head = temp;
    else {
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
}

bool palindrome(){
    node * tail = head;
    while(tail->next!=NULL)
        tail=tail->next;
    node * temp = head;
    
    while (head!=tail && tail->next!=head){
        if (head->ch != tail->ch)
            return false;
        head = head->next;
        tail = tail->pre;
    }
    return true;
    
}
int main()
{
    char op, a;
    while(1){
        cout<<"Do you want to add node?(Y/N)\n";
        cin>>op;
        if(op=='Y' || op=='y'){
            cout<<"Enter node\n";
            cin>>a;
            insertNode(a);
        }
        else
        break;
    }
    if (head == NULL)
        cout<<"List is empty";
    else
    palindrome() ? cout<<"Palindrome\n" : cout<<"Not a palindrome";
    return 0;
}
