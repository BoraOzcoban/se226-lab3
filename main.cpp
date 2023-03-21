#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else {
            Node* temp = front;
            int val = temp->data;
            front = front->next;
            delete temp;
            size--;
            return val;
        }
    }

    int top() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else {
            return front->data;
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "Top element: " << q.top() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Queue Size: " << q.getSize() << endl;

    return 0;
}
