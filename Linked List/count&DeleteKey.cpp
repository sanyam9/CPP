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
        node *temp = head;
        while(temp->next!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;}
        cout<<temp->data;    
    
        int key,count=0;
        cout<<"\nEnter key\n";
        cin>>key;
        
        temp = head;
        node * pre = NULL;
        while(temp){
            if(temp==head && temp->data==key){
                count++;
                head=head->next;
            }
            else if(temp->data==key){
                count++;
                pre->next=temp->next;
            }  
            pre = temp;
            temp=temp->next;
        }
        cout<<"Count: "<<count<<endl;
        if(head==NULL)
            cout<<"List is empty\n";
        else{
            cout<<"New list:\n";
            node * temp = head;
            while(temp->next!=NULL){
                cout<<temp->data<<" -> ";
                temp=temp->next;}
            cout<<temp->data;
        }    
    }
    return 0;
}
