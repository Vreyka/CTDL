#include<iostream>

using namespace std;

struct Node {
    int info;
    Node *next;
    Node *prev;
};

struct DoubleLinkedList {
    Node *l;
    Node *r;
};

void initDoubleLinkedList(DoubleLinkedList *dl){
    dl->l = NULL;
    dl->r = NULL;
}

int isEmpty(DoubleLinkedList *dl){
    return (dl->l == NULL);
}

Node * createNode(int data){
    Node *newNode = new Node;
    newNode->info = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node * search(DoubleLinkedList *dl, int data){
    if (isEmpty(dl)){
        return NULL;
    }
    Node *ptr = dl->l;
    while(ptr!=NULL && ptr->info!=data){
        ptr = ptr->next;
    }
    return ptr;
}

void insertBegin(DoubleLinkedList *dl, int data){
    Node *newNode = createNode(data);
    if (isEmpty(dl)){
        dl->l = dl->r = newNode;
        return;
    }
    newNode->next = dl->l;
    dl->l->prev = newNode;
    dl->l = newNode;
    return;
}

void insertAfter(DoubleLinkedList *dl, int data, Node *p ){
    Node *newNode = createNode(data);
    if (isEmpty(dl)){
        return;
    }
    if (p==NULL){
        return;
    }
    if(p == dl->r){
        p->next = newNode;
        newNode->prev = p;
        dl->r = newNode;
        return;
    }
    newNode->next = p->next;
    newNode->prev = p;
    newNode->next->prev = newNode;
    p->next = newNode;
}

void insertBefore(DoubleLinkedList *dl, int data, Node *p){
    Node *newNode = createNode(data);
    if (isEmpty(dl)){
        return;
    }
    if (p==NULL){
        return;
    }
    if(p == dl->l){
        newNode->next = dl->l; //p->prev = newNode;
        dl->l->prev = newNode; //newNode->next = p;
        dl->l = newNode;
        return;
    }
    newNode->next = p;
    newNode->prev = p->prev;
    newNode->prev->next = newNode;
    p->prev = newNode;

}

void DeleteBegin(DoubleLinkedList *dl){
    if (isEmpty(dl)){
        return;
    }
    if (dl->l == dl->r){
        delete dl->l;
        dl->l = dl->r = NULL;
        return;
    }
    Node * tmp = dl->l;
    dl->l = tmp->next;
    dl->l->prev = NULL;
    delete tmp;
}

void deleteCurrent(DoubleLinkedList *dl, Node *p){
    if (isEmpty(dl)){
        return;
    }
    if(p==NULL){
        return;
    }
    if(!isEmpty(dl) && dl->l == dl->r && p == dl->l){
        delete dl->l;
        dl->l = dl->r = NULL;
        return;
    }
    if (p == dl->l){
        // DeleteBegin(&dl);
        dl->l = dl->l->next;
        dl->l->prev = NULL;
        delete p;
        return;
    }

    if (p == dl->r){
        dl->r = p->prev;
        dl->r->next = NULL;
        delete p;
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    return;
}


void display(DoubleLinkedList *dl){
    if (isEmpty(dl)){  
        cout << "Empty list" << endl;
        return;
    }
    Node *ptr = dl->l;
    while (ptr!=NULL){
        cout << ptr->info << endl;
        ptr = ptr->next;
    }
}

int main(int argc, char **argv){
    DoubleLinkedList dl;
    initDoubleLinkedList(&dl);
    insertBegin(&dl, 1);
    insertBegin(&dl, 2);
    insertBegin(&dl, 3); 
    insertBegin(&dl, 4);
    insertBegin(&dl, 5);
    Node *tmp = search(&dl, 5);
    insertBefore(&dl, 66, tmp);
    deleteCurrent(&dl,tmp->prev);
    display(&dl);
}