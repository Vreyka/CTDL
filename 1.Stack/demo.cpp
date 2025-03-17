#include <iostream>
using namespace std;
const int MAX = 50;
 
struct Stack {
    int data[MAX];
    int size;
};
 
void initStack(Stack& s) {
    s.size = 0;
}
 
int isFull(Stack s) {
    return (s.size == MAX);
}
 
int isEmpty(Stack s) {
    return (s.size == 0);
}
 
void push1(Stack& s, int x) {
    if (isFull(s)) {
        cout << "\n ngan xep day!";
        return;
    }
    s.data[s.size] = x;
    s.size++;
}
 
void hienThi(Stack s) {
    for (int i = 0; i < s.size; i++)
        cout << s.data[i] << "\t";
}
 
int main()
{
    Stack s;
    initStack(s);   
    push1(s, 1);
    push1(s, 2);
    hienThi(s);
}