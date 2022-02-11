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
    else{int count = 1;
        cout<<"Original List:\n";
        node * temp = head;
        node * end = NULL;
        while(temp->next!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
            count++;
        }
        cout<<temp->data<<endl;
        end = temp;
        cout<<"Enter k\n";
        int k;
        cin>>k;
        int cnt=1;
        temp = head;
        while(temp){
            if(cnt == count-k){
                end->next=head;
                head = temp->next;
                temp->next = NULL;
                break;
            }
            cnt++;
            temp=temp->next;
        }
        cout<<"Rotated List:\n";
        temp = head;
        while(temp->next!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;}
        cout<<temp->data;  
        
    }
    return 0;
}
