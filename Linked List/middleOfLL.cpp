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
    	int count=1;
        cout<<"Original List:\n";
        node * temp = head;
        while(temp->next!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
			count++;}
        cout<<temp->data<<endl;
        count=count/2 +1;

        temp=head;
        int t =1;
        while(temp!=NULL && t!=count){
            temp=temp->next;
            t++;}
        cout<<"Middle of the list is: "<<temp->data;    
    
		}
	return 0;
}
