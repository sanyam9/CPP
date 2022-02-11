#include <iostream>
using namespace std;
struct node{
    int data;
    node * next;
};
node * head = NULL;
node * tail = NULL;

void insertBegin(int a){
    node * temp = new node;
    temp->data = a;
    temp->next =head;
    if(!head){
        head = temp;
        tail = temp;
    }
    else
        head = temp;
}

void insertEnd(int a){
    node * temp = new node;
    temp->data = a;
    temp->next = NULL;
    
    if(head==NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void insertMid(int a){
    node *temp = new node;
    temp->data = a;
    temp->next = NULL;
    if(head==NULL){
        cout<<"List was empty\n";
        head=temp;
        tail=temp;
        cout<<"Element inserted\n";
    }
    else{
        int x,ch;
        cout<<"Choose an option:-\n1. After node 'x'.\n2. Before node 'x'.\n";
        cin>>ch;

        if(ch==1){
            cout<<"Enter 'x'\n";
            cin>>x;
            if(tail->data==x){
                tail->next = temp;
                tail = temp;
            }
            else{
                node *temp1 = head;
                while(temp1!=NULL && temp1->data!=x)
                    temp1=temp1->next;
                if(temp1==NULL)
                    cout<<"Node "<<x<<" not found!\n";
                else{
                    temp->next=temp1->next;
                    temp1->next=temp;
                }
            }
        }
        else if(ch==2){
            cout<<"Enter 'x'\n";
            cin>>x;
            node *temp1 = head;
            node *pre = NULL;
            
            while(temp1!=NULL && temp1->data!=x){
                pre=temp1;
                temp1=temp1->next;
            }
            if(temp1==NULL)
                cout<<"Node "<<x<<" not found!\n";
            else{
                if(temp1==head){
                    temp->next=head;
                    head=temp;
                    delete pre;
                }
                else{
                    temp->next=pre->next;
                    pre->next=temp1;
                }
            }   
        }
        else{
            cout<<"Invalid Option\n";
            insertMid(a);}
    }
}

void deleteBegin(){
    if(head==NULL)
        cout<<"List is empty\n";
    else{
        node*temp = head;
        head = temp->next;
        delete temp;
    }
}

void deleteEnd(){
	if(head==NULL)
		cout<<"List is empty\n";
	else{
		node *temp = head;
		node *pre = NULL;
		while(temp!=tail){
			pre = temp;
			temp=temp->next;
		}
		if (temp==head){
			head = NULL;
			tail = NULL;
			delete temp,pre;
		}
		else {
			tail = pre;
			tail->next = NULL;
			delete temp;
		}
	}	
}

void deleteMid(int a){
    if (head==NULL)
        cout<<"List is empty\n";
    else{
        node *temp = head;
        node *pre = NULL;
        while(temp!=NULL && temp->data!=a){
            pre = temp;
            temp=temp->next;
        }
        if (temp == NULL){
            cout<<"Element not found!\n";
            delete temp,pre;}
        else if (temp == head)
            deleteBegin();
        else if (temp == tail)
            deleteEnd();
        else {
            pre->next = temp->next;
            delete temp;
        }     
    }
}

void search(int a){
    int count = 1;
    if(head == NULL)
        cout<<"List is empty\n";
    else{
        node *temp = head;
        while(temp!=NULL){
            if(temp->data == a){
                cout<<"Element found at position: "<<count<<endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    if(temp==NULL)
        cout<<"Element not found!\n";
    }
}

void display(){
    if(head==NULL)
        cout<<"List is empty\n";
    else{
        node*temp = head;
        while(temp!=NULL){
            cout<<temp->data<<' ';
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main(){
	cout<<"(a) Insertion at the beginning.\n(b) Insertion at the end.\n(c) Insertion in between\n(d) Deletion from the beginning\n(e) Deletion from the end.\n(f) Deletion of a specific node.\n(g) Search for a node.\n(h) Display all the node values.\n(i) Exit\n";
	char choice;
	int a;
	int t=1;
	while(t){
	    cout<<"Enter a choice:\n";
	    cin>>choice;
	    switch(choice){
	        case 'a': cout<<"Enter the number to be inserted\n";
	                  cin>>a;
	                  insertBegin(a);
	                  break;
	        case 'b': cout<<"Enter the number to be inserted\n";
	                  cin>>a;
	                  insertEnd(a);
	                  break;
	        case 'c': cout<<"Enter the number to be inserted\n";
	                  cin>>a;
	                  insertMid(a);
	                  break;
	        case 'd': deleteBegin(); 
	                  break;
	        case 'e': deleteEnd();
	                  break;
	        case 'f': cout<<"Enter the number to be deleted\n";
	                  cin>>a;    
	                  deleteMid(a);
	                  break;
	        case 'g': cout<<"Enter the number to be searched\n";
	                  cin>>a;
	                  search(a);
	                  break;
	        case 'h': display();
	                  break;
	        case 'i': t = 0;
	                  break;
	        default: cout<<"Invalid Choice!\n";          
	    }
	}    
    return 0;
}

