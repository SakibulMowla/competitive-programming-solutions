#include <bits/stdc++.h>

using namespace std;

struct PriorityQueue {
    vector<int> heap;
    int heapSize;

    PriorityQueue() {
        heapSize = 0;
        heap = vector <int> (1000000);
        heap[0] = numeric_limits <int> :: min();
    }

    void push(int element) {
        heapSize++;
        heap[heapSize] = element;
        int now = heapSize;
        while (heap[now/2] > element) {
            heap[now] = heap[now/2];
            now /= 2;
        }
        heap[now] = element;
    }

    void pop() {
        int lastElement, child, now;
        lastElement = heap[heapSize--];
        for(now = 1; now * 2 <= heapSize; now = child) {
            child = now * 2;
            if(child != heapSize && heap[child+1] < heap[child]) {
                child++;
            }
            if(lastElement > heap[child]) {
                heap[now] = heap[child];
            } else {
                break;
            }
        }
        heap[now] = lastElement;
        return;
    }

    int top() {
        return heap[1];
    }
};

int main() {
    PriorityQueue PQ;

    PQ.push(1);
    PQ.push(3);
    PQ.push(-1);
    cout << PQ.top() << endl;
    PQ.pop();
    cout << PQ.top() << endl;

    return 0;
}
