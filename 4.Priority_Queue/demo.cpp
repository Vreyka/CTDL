//Cách 1: khi thêm phần tử vào hàng đợi, thì hàng đợi luôn được sắp xếp theo chiều giảm dần của độ ưu tiên
#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
 
// Định nghĩa một phần tử trong hàng đợi ưu tiên
struct Element {
    int data;     // Dữ liệu của phần tử
    int priority; // Mức độ ưu tiên của phần tử
};
 
// Định nghĩa hàng đợi ưu tiên
struct PriorityQueue {
    Element items[MAX]; // Mảng chứa các phần tử hàng đợi
    int size;                  // Kích thước hiện tại của hàng đợi
};
 
// Khởi tạo hàng đợi
void initializeQueue(PriorityQueue* pq) {
    pq->size = 0; // Khởi tạo kích thước hàng đợi bằng 0
}
 
// Kiểm tra hàng đợi có rỗng không
int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}
 
// Kiểm tra hàng đợi có đầy không
int isFull(PriorityQueue* pq) {
    return pq->size == MAX;
}
 
// Thêm phần tử vào hàng đợi ưu tiên
void enqueue(PriorityQueue* pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Hang doi day.\n");
        return;    
    }
 
    Element newElement;
    newElement.data = data;
    newElement.priority = priority;
 
    // Tìm vị trí để chèn phần tử mới vào dựa trên mức độ ưu tiên
    int i = pq->size - 1;
    while (i >= 0 && pq->items[i].priority < priority) {//nhỏ hơn hoặc bằng thì nếu 2 phần tử có cùng độ ưu tiên, phần tử vào sau sẽ xử lý trước
        pq->items[i + 1] = pq->items[i]; // Dịch chuyển phần tử có ưu tiên thấp hơn
        i--;
    }
    pq->items[i + 1] = newElement; // Chèn phần tử mới vào đúng vị trí
    pq->size++; // Tăng kích thước hàng đợi
}
 
// Xóa phần tử có mức độ ưu tiên cao nhất (ở đầu hàng đợi)
void dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hang doi rong.\n");
        return;
    }
  
    printf("Xoa phan tu co gia tri %d voi muc do uu tien %d.\n", pq->items[0].data, pq->items[0].priority);
 
    // Dịch chuyển các phần tử về phía trước
    for (int i = 0; i < pq->size - 1; i++) {
        pq->items[i] = pq->items[i + 1];
    }
    pq->size--; // Giảm kích thước hàng đợi
}
 
//Xóa phần tử đồng thời lấy ra phần tử đó
Element dequeue_(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hàng đợi rỗng.\n");
        // Trả về một phần tử mặc định khi hàng đợi rỗng
        Element defaultItem = { -1, -1 }; // Có thể dùng giá trị mặc định khác phù hợp
        return defaultItem;
    }
 
    // Lấy phần tử đầu tiên (có mức ưu tiên cao nhất)
    Element removedItem = pq->items[0];
 
    // Dịch chuyển các phần tử về phía trước
    for (int i = 0; i < pq->size - 1; i++) {
        pq->items[i] = pq->items[i + 1];
    }
    pq->size--; // Giảm kích thước hàng đợi
 
    // Trả về phần tử đã bị xóa
    return removedItem;
}
 
 
// Hiển thị các phần tử trong hàng đợi
void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hang doi rong.\n");
        return;
    }
 
    printf("Hang doi uu tien hien tai:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Phan tu: %d, do uu tien: %d\n", pq->items[i].data, pq->items[i].priority);
    }
}
 
int main() {
    PriorityQueue pq;
    initializeQueue(&pq);
 
    enqueue(&pq, 10, 2);  // Thêm phần tử 10 với ưu tiên 2
    enqueue(&pq, 20, 1);  // Thêm phần tử 20 với ưu tiên 1
    enqueue(&pq, 30, 3);  // Thêm phần tử 30 với ưu tiên 3
    display(&pq);
 
    dequeue(&pq); // Xóa phần tử ưu tiên cao nhất
    display(&pq);
 
    enqueue(&pq, 40, 2);  // Thêm phần tử 40 với ưu tiên 2
    display(&pq);
 
    return 0;
}