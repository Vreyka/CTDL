#include <iostream>

using namespace std;

struct Document{
    string name;
    string content;
};


struct  Queue{
    Document data[MAX];
    int F;
    int R;
};



void initQueue(Queue* q){
    q.F = q.R = -1;

}
bool isFull(Queue* q){
    return (q.R == MAX -1);
}

bool isEmpty(Queue* q){
    return (q.F == q.R == -1);
}

void endQueue(Queue* q, k){
    if (isFull(q)){
        return;
    }
    if (isEmpty(q)){
        q.F = q.R = 0;
        q.data[q.R] = k
        return;
    }
    q.data[++q.R] = k;
}

int deQueue(Queue* q){
    if (isEmpty(q)){
        return -1;
    }
    int temp = q.data[q.F];

    if (q->F == q.R){
        q.F = q.R = -1;
    }
    q.F++;
    return temp;
}

/*
Printer

*/