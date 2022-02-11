#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;
    node * pre;
} * head = NULL;

void insertBegin(int a){
    node * temp = new node;
    temp->next = temp->pre = NULL;
    temp->data = a;
    
    if (head == NULL)
        head = temp;
    else{
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
}

void insertEnd(int a){
    node * temp = new node;
    temp->next = temp->pre = NULL;
    temp->data = a;
    
    if (head == NULL)
        head = temp;
    else {
        node * trav = head;
        while(trav->next!=NULL)
            trav = trav->next;
        trav->next = temp;
        temp->pre = trav;
    }
}

void insertMid(int a){
    if(head==NULL){
        cout<<"List is empty. Insert nodes first\n";
        return;
    }
    node *temp = new node;
    temp->next = temp->pre = NULL;
    temp->data = a;
    
    int x,ch;
    cout<<"Choose an option:-\n1. After node 'x'.\n2. Before node 'x'.\n";
    cin>>ch;
    
    if (ch==1){
        cout<<"Enter x\n";
        cin>>x;
        node * trav = head;
        while (trav && trav->data!=x)
            trav=trav->next;
        if(trav==NULL)
            cout<<x<<" not found!\n";
        else{
            temp->pre = trav;
            temp->next = trav->next;
            if(trav->next!=NULL)
                trav->next->pre = temp;
            trav->next = temp;
        }
    }
    else if (ch==2){
        cout<<"Enter x\n";
        cin>>x;
        node * trav = head;
        while (trav && trav->data!=x)
            trav=trav->next;
        if(trav==NULL)
            cout<<x<<" not found!\n";
        else{
            temp->pre = trav->pre;
            temp->next = trav;
            if(trav->pre!=NULL)
                trav->pre->next= temp;
            trav->pre = temp;
        }
    }
    else{
        cout<<"Invalid option\n";
        insertMid(a);
    }
}

void deleteBegin(){
    if(head==NULL)
        cout<<"List is empty\n";
    else{
        node * temp = head;
        if(head->next!=NULL)
            head->next->pre = NULL;
        head = head -> next;
        delete temp;
    }
}

void deleteEnd(){
    if(head == NULL)
        cout<<"List is empty\n";
    else{
        node * temp = head;
        while(temp->next!=NULL)
            temp=temp->next;
        if(temp->pre!=NULL)
            temp->pre->next = NULL;
        else 
            head = NULL;
        delete temp;
    }
}

void deleteNode(int a){
    if(head == NULL)
        cout<<"List is empty\n";
    else{
        node * temp = head;
        while(temp && temp->data!=a)
            temp=temp->next;
        if(temp == NULL)
            cout<<a<<" not found!\n";
        else{
            if(temp == head)
                deleteBegin();
            else if(temp->next==NULL)
                deleteEnd();
            else {
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
                delete temp;
            }
        }    
    }
}

void searchNode(int a){
    if(head==NULL)
        cout<<"List is empty\n";
    else{
        node *temp = head;
        int count = 1;
        while(temp && temp->data!=a){
            count++;
            temp=temp->next;
        }
        if(!temp)
            cout<<a<<" not found!\n";
        else
            cout<<a<<" found at Node #"<<count<<endl;
    }   
}
void display(){
    if(head==NULL)
        cout<<"List is empty\n";
    else{
        node *trav = head;
        while(trav->next!=NULL){
            cout<<trav->data<<" -> ";
            trav = trav->next;
        }
        cout<<trav->data<<endl;
    }
}
int main()
{
    cout<<"(a) Insertion at the beginning.\n(b) Insertion at the end.\n(c) Insertion in between\n(d) Deletion of a specific node.\n(e) Search for a node.\n(f) Display all the node values.\n(g) Exit\n";
	char choice;
	int a;
	int t=1;
	while(t){
	    cout<<"Enter a choice\n";
	    cin>>choice;
	    switch(choice){
	        case 'a' : cout<<"Enter the number to be inserted\n";
	                   cin>>a;
	                   insertBegin(a);
	                   break;
	        case 'b' : cout<<"Enter the number to be inserted\n";
	                   cin>>a;
	                   insertEnd(a);
	                   break;
	        case 'c' : cout<<"Enter the number to be inserted\n";
	                   cin>>a;
	                   insertMid(a);
	                   break;
	        case 'd' : cout<<"Enter the number to be deleted\n";
	                   cin>>a;
	                   deleteNode(a);
	                   break;
	        case 'e' : cout<<"Enter the node to be searched\n";
	                   cin>>a;
	                   searchNode(a);
	                   break;
	        case 'f' : display();
	                   break;
	        case 'g' : t = 0;
	                   break;
	        default : cout<<"Invalid Choice\n";
	    }
	}

    return 0;
}

