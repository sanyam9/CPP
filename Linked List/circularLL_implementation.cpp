#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;
} * head = NULL;

void insertBegin(int a){
    node * temp = new node;
    temp->next = temp;
    temp->data = a;
    
    if (head == NULL)
        head = temp;
    else{
        node * trav = head;
        while(trav->next!=head)
            trav=trav->next;
        trav->next = temp;
        temp->next = head;
        head = temp;
    }
}

void insertEnd(int a){
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

void insertMid(int a){
    if(head==NULL){
        cout<<"List is empty. Insert nodes first\n";
        return;
    }
    node *temp = new node;
    temp->next = NULL;
    temp->data = a;
    
    int x,ch;
    cout<<"Choose an option:-\n1. After node 'x'.\n2. Before node 'x'.\n";
    cin>>ch;
    
    if (ch==1){
        cout<<"Enter x\n";
        cin>>x;
        node * trav = head;
        while (trav->next!=head && trav->data!=x)
            trav=trav->next;
        if(trav->data!=x)
            cout<<x<<" not found!\n";
        else{
            temp->next = trav->next;
            trav->next = temp;
        }
    }
    else if (ch==2){
        cout<<"Enter x\n";
        cin>>x;
        node * trav = head;
        node * pre = NULL;
        while (trav->next!=head && trav->data!=x){
            pre = trav;
            trav=trav->next;}
        if(trav->data!=x)
            cout<<x<<" not found!\n";
        else{
            if (trav== head)
                insertBegin(a);
            else{
                temp->next = pre->next;
                pre->next = temp;
            }
        }
    }
    else{
        cout<<"Invalid option\n";
        insertMid(a);
    }
}


void deleteNode(int a){
    if(head == NULL)
        cout<<"List is empty\n";
    else{
        node * temp = head;
        node * pre = NULL;
        while(temp->next!=head && temp->data!=a){
            pre = temp;
            temp=temp->next;}
        if(temp->data!=a)
            cout<<a<<" not found!\n";
        else{
            if(head->next=head)
                head = NULL;
            else if(temp == head){
                node *trav = head;
                while(trav->next!=head)
                    trav=trav->next;
                trav->next = head->next;
                head = head->next;}
            else {
                pre->next = temp->next;
            }
            delete temp;
        }    
    }
}

void searchNode(int a){
    if(head==NULL)
        cout<<"List is empty\n";
    else{
        node *temp = head;
        int count = 1;
        while(temp->next!=head && temp->data!=a){
            count++;
            temp=temp->next;
        }
        if(temp->data!=a)
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
        while(trav->next!=head){
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

