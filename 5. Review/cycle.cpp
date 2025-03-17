#include<iostream>

using namespace std;

struct Node{
    int info;
    Node * next;
};

struct CycleLL{
    Node * last;
};

void initCycleLL(CycleLL *cl){
    cl->last = NULL;
}

void insertBegin(CycleLL *cl, int data){
    Node * newNode = new Node;
    newNode->info = data;
    if (cl->last == NULL){
        cl->last = newNode;
        cl->last->next = cl->last;
    }
    newNode->next = cl->last->next;
    cl->last->next = newNode;
}

void display(CycleLL *cl){
    if(cl->last == NULL){
        cout << "List empty" << endl;
        return;
    }
    Node * tmp = cl->last->next;
    while(tmp != cl->last){
        cout << tmp->info << endl;
        tmp = tmp->next;
    }
    cout << cl->last->info << endl;
    return;
}

int main(){
    CycleLL cl;
    initCycleLL(&cl);
    insertBegin(&cl, 1);
    insertBegin(&cl, 2);
    insertBegin(&cl, 3);
    insertBegin(&cl, 4);
    insertBegin(&cl, 5);
    display(&cl);
}