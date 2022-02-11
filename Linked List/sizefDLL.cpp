#include <iostream>

using namespace std;
struct node{
    int data;
    node * next;
    node * pre;
} * head = NULL;

void insertNode(int a){
    node * temp = new node;
    temp->next = temp->pre = NULL;
    temp->data = a;
    
    if (head == NULL)
        head = temp;
    else {
        node * trav = head;
        while(trav->next)
            trav = trav->next;
        temp->pre = trav;
        trav->next = temp;
    }
}

int main()
{   int a;
    char ch;
    
    while(1){
        cout<<"Do you want to add nodes?(Y/N)\n";
        cin>>ch;
        if(ch=='Y' || ch== 'y'){
        cout<<"Enter Node "<<endl;
        cin>>a;
        insertNode(a);}
        else
        break;
    }
    cout<<"Size of list:\n";
    int count = 0;
    if(head==NULL)
        cout<<0;
    else{
        node *temp = head;
        while(temp){
            count++;
            temp=temp->next;
        }
        cout<<count;
    }
    return 0;
}

