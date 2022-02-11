#include <iostream>

using namespace std;

struct node{
    int data;
    node * next = NULL;
}*head = NULL;

void insertNode(int a){
    node * temp = new node;
    temp->data = a;
    temp->next = NULL;
    if(head == NULL)
        head = temp;
    else{
        temp->next = head;
        head = temp;
    }
}

bool circular(){
    node * temp = head;
    while(temp->next!=NULL && temp->next!=head)
        temp=temp->next;
    if (temp->next == head)
        return true;
    return false;
}

void makeCircular(){
    if (!circular()){
    node * temp = head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next = head;    
    }   
}


int main()
{   char ch;
    int a;
    while(1){
        cout<<"Do you want to add node? (Y/N)\n";
        cin>>ch;
        if(ch=='y' || ch=='Y'){
            cout<<"Enter node\n";
            cin>>a;
            insertNode(a);
        }
        else
        break;
    }
    
    circular() ? cout<<"Circular\n" : cout<<"Not Circular\n";
    
    makeCircular();
    
    circular() ? cout<<"Circular\n" : cout<<"Not Circular\n";

    return 0;
}
