#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    if (Q.head == -1 && Q.tail == -1) {
        return true;
    } else {
        return false;
    }
}

bool isFullQueue(Queue Q) {
    if (Q.tail == MAKSIMAL - 1) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q) == true) {
        cout << "Queue sudah penuh!" << endl;
    } else {
        if (isEmptyQueue(Q) == true) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q) == true) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        Q.head++;
        if (Q.head > Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q) == true) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
