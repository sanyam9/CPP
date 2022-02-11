#include <iostream>

using namespace std;
struct node{
    int data;
    node * next;
} *head = NULL, *head1 = NULL;

void insertNode(int a){
    node * temp = new node;
    temp->next = temp;
    temp->data = a;
    
    if (head == NULL)
        head = temp;
    else {
        node * trav = head;
        while(trav->next!= head)
            trav = trav->next;
        temp->next = trav->next;
        trav->next = temp;
    }
}

int main()
{   int a;
    char ch;
    
    while(1){
        cout<<"Do you want to nodes?(Y/N)\n";
        cin>>ch;
        if(ch=='Y' || ch== 'y'){
        cout<<"Enter Node "<<endl;
        cin>>a;
        insertNode(a);}
        else
        break;
    }
    if (head == NULL)
     cout<<"List is empty\n";
    else{
        if(head->next==head)
            cout<<"Only 1 node:\n"<<head->data;
        else{
            cout<<"Original List:\n";
            node * temp = head;
            while(temp->next!=head){
                cout<<temp->data<<" -> ";
                temp=temp->next;}
            cout<<temp->data<<endl;
            
            node * temp1 = head;
            node * temp2 = head;
            while(temp1->next!=head && temp1->next->next!=head){
                temp2=temp2->next;
                temp1=temp1->next->next;
            }
            head1 = temp2->next;
            if(temp1->next==head)
                temp1->next = head1;
            else
                temp1->next->next = head1;
            temp2->next = head;
        
        cout<<"First List:\n";
        temp = head;
        while(temp->next!=head){
            cout<<temp->data<<" -> ";
            temp=temp->next;}
        cout<<temp->data<<endl;
        cout<<"Second List:\n";
        temp = head1;
        while(temp->next!=head1){
            cout<<temp->data<<" -> ";
            temp=temp->next;}
        cout<<temp->data;
        }
    }
    return 0;
}

