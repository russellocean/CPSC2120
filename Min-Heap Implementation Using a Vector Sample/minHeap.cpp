#include "minHeap.h"

void minHeap::siftUp(int pos) {
    if (pos <= 0) return; // Base case: already at the root

    int parentPos = (pos - 1) / 2;
    if (heap[pos] < heap[parentPos]) {
        swap(heap[pos], heap[parentPos]);
        siftUp(parentPos);
    }
}

void minHeap::siftDown(int pos) {
    int leftChildPos = 2 * pos + 1;
    int rightChildPos = 2 * pos + 2;
    int minPos = pos;

    if (leftChildPos < heap.size() && heap[leftChildPos] < heap[minPos]) {
        minPos = leftChildPos;
    }

    if (rightChildPos < heap.size() && heap[rightChildPos] < heap[minPos]) {
        minPos = rightChildPos;
    }

    if (minPos != pos) {
        swap(heap[pos], heap[minPos]);
        siftDown(minPos);
    }
}

minHeap::minHeap(vector<int> data) {
    heap = data;
    for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
        siftDown(i);
    }
}

void minHeap::insert(int value) {
    heap.push_back(value);
    siftUp(heap.size() - 1);
}

int minHeap::removeMin() {
    int minVal = heap.front();
    heap.front() = heap.back();
    heap.pop_back();
    siftDown(0);

    return minVal;
}