#include <iostream>

using namespace std;
struct node{
    int data;
    node * next;
} * head = NULL;

void insertNode(int a){
    node * temp = new node;
    temp->next = temp;
    temp->data = a;
    
    if (head == NULL)
        head = temp;
    else {
        node * trav = head;
        while(trav->next!=head)
            trav = trav->next;
        trav->next = temp;
        temp->next = head;
    }
}

int main()
{   int n,a;
    cout<<"Enter number of nodes\n";
    cin>>n;
    
    for(int i=0;i<n;i++){
        cout<<"Enter Node "<<i+1<<endl;
        cin>>a;
        insertNode(a);
    }
    cout<<"Output:\n";
    if(head==NULL)
        cout<<"Empty List\n";
    else{
        node * temp = head;
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<' '<<temp->next->data;
        
    }
    return 0;
}

