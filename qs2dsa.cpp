#include <iostream>
using namespace std;

class LinkedList {
public:
    struct node {
        int data;
        node *next;
        node(int v) { data=v; next=nullptr; }
    };

    node *head;

    LinkedList() { head=nullptr; }

    void insertatend(int n) {
        node *newnode=new node(n);
        if(head==NULL) {
            head=newnode;
            return;
        }
        node *temp=head;
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newnode;
    }

    int countnodes(node *h) {
        int count=0;
        node *temp=h;
        while(temp!=NULL) {
            count++;
            temp=temp->next;
        }
        return count;
    }

    // split into 2 halves
    pair<node*,node*> splitlist(node *&h,node *&first,node *&second) {
        if(h==NULL) return {nullptr,nullptr};
        int half=countnodes(h)/2;
        first=h;
        node *temp=h;
        for(int i=1;i<half;i++) {
            temp=temp->next;
        }
        second=temp->next;
        temp->next=NULL;
        return {first,second};
    }

    // insertion sort with pointer adjustment (descending)
    node* sort(node *h) {
        if(h==NULL || h->next==NULL) return h;

        node *sorted=NULL; // new sorted list
        while(h!=NULL) {
            node *current=h;
            h=h->next;

            if(sorted==NULL || current->data >= sorted->data) {
                current->next=sorted;
                sorted=current;
            } else {
                node *temp=sorted;
                while(temp->next!=NULL && temp->next->data > current->data) {
                    temp=temp->next;
                }
                current->next=temp->next;
                temp->next=current;
            }
        }
        return sorted;
    }

    void display(node *h) {
        node *temp=h;
        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main() {
    LinkedList l;
    LinkedList::node *first=nullptr;
    LinkedList::node *second=nullptr;

    l.insertatend(47);
    l.insertatend(33);
    l.insertatend(12);
    l.insertatend(89);
    l.insertatend(21);
    l.insertatend(50);
    l.insertatend(65);
    l.insertatend(30);

    cout<<"Original list:"<<endl;
    l.display(l.head);

    l.splitlist(l.head,first,second);

    cout<<"First half:"<<endl;
    l.display(first);
    cout<<"Second half:"<<endl;
    l.display(second);

    first=l.sort(first);
    second=l.sort(second);

    cout<<"Sorted First half (descending):"<<endl;
    l.display(first);
    cout<<"Sorted Second half (descending):"<<endl;
    l.display(second);

    return 0;
}
