#include <iostream>
using namespace std;

struct Node{
    int info;
    Node * next;
};

typedef Node * Pnode;
typedef Node * LinkedList;

void initList(LinkedList & list){
    list = NULL;


}

int isEmpty(LinkedList list){
    return (list == NULL);
}

//bo sung phan tu dau ds
void insertBegin(LinkedList & list,int k){
    Node * newNode = new Node;
    newNode->info = k;
    if (isEmpty(list)){
        list = newNode;
        newNode->next = NULL;
        return;
    }
    newNode->next = list;
    list = newNode;

}

void insertBefore(LinkedList & list, int k, Pnode p){
    Node * newNode = new Node;
    newNode->info = k;
    if (isEmpty(list)){
        list = newNode;
        newNode->next = NULL;
        return;
    }
    if (p==NULL){
        return;
    }
    Node * ptr = list;
    while(ptr && ptr->next != p){
        ptr= ptr->next;
    }
    newNode->next = p;
    ptr->next = newNode;

}

void insertBefore2(LinkedList *list, int i, Pnode p){
    //
    Node * newNode = new Node;
    newNode->info = k;
    if (isEmpty(list)){
        list =newNode;
        newNode->next = NULL;
        return;
    }
    if(p==NULL){
        return;
    }

    newNode->info = p->info;
    p->info = k;
    newNode->next = p->next
    p->next = newNode;
}


void insertAfer(LinkedList & list, int k, Pnode p){
    Node * newNode = new Node;
    newNode->info = k;
    if (isEmpty(list)){
        list = newNode;
        newNode->next = NULL;
        return;
    }
    if (p==NULL){
        return;
    }
    newNode->next = p->next;
    p->next = newNode;
}

void display(LinkedList list){
    Node * ptr = list;
    if (isEmpty(list)){
        cout<<"Empty list"<<endl;
    }
    cout<< "list: "<<endl;
    while (ptr){
        cout<<ptr->info<<endl;
        ptr = ptr->next;
    }
}

Node * search(LinkedList list, int k){
    Node *ptr = list;
    while (ptr){
        if (ptr->info==k){
            return ptr;
        }
        else{
            ptr = ptr->next;
        }
    }
    return NULL;
    
}

int main(){
    LinkedList l;
    initList(l);
    insertBegin(l, 11);
    insertBegin(l, 12);
    insertBegin(l, 13);
    insertBegin(l, 14);
    insertBegin(l, 15);
    insertBegin(l, 16);
    insertBegin(l, 17);
    insertBegin(l, 18);
    display(l);

    //bo sung 88 sau 44
    Node *tmp = search(l, 14);
    insertAfer(l, 88, tmp);
    display(l);


    tmp = search(l, 15);
    insertAfer(l,99, tmp);
    display(l);


}