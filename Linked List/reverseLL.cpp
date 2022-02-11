#include <iostream>

using namespace std;

int main()
{   
    struct node{
        int data;
        node * next;
    } *head = NULL;
    int n,a;
    cout<<"Enter number of nodes\n";
    cin>>n;
    
    while(n){
        cout<<"Enter data\n";
        cin>>a;
        
        node * temp = new node;
        temp->data=a;
        temp->next=NULL;
        if(head==NULL)
            head=temp;
        else{
            node * temp1 = head;
            while(temp1->next!=NULL)
                temp1=temp1->next;
            temp1->next=temp;    
        }
        n--;
    }
    
    if(head==NULL)
    cout<<"List is empty\n";
    else{
        cout<<"Original List:\n";
        node * temp = head;
        while(temp->next!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;}
        cout<<temp->data<<endl;    
    
        node * end = NULL;
        node * start = head;
        do{
            temp = start;
            while(temp->next!=end)
                temp=temp->next;
            end = temp;
            int t;
            t=end->data;
            end->data = start->data;
            start->data= t;
            start=start->next;
        }while(end->next!=start && start!=end);
        
        cout<<"Reversed List:\n";
        temp = head;
        while(temp->next!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;}
        cout<<temp->data;  
        
    }
    return 0;
}
