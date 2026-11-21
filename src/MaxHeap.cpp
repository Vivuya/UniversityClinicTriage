#include "MaxHeap.h"
#include <utility>

bool MaxHeap::hasHigherPriority(const Patient& a, const Patient& b) {
    if (a.priority != b.priority) {
        return a.priority > b.priority;
    }
    return a.registrationOrder < b.registrationOrder;
}

void MaxHeap::heapifyUp(std::size_t index) {
    while (index > 0) {
        const std::size_t parent = (index - 1) / 2;
        if (!hasHigherPriority(heap[index], heap[parent])) {
            break;
        }
        std::swap(heap[index], heap[parent]);
        index = parent;
    }
}

void MaxHeap::heapifyDown(std::size_t index) {
    while (true) {
        const std::size_t left = 2 * index + 1;
        const std::size_t right = 2 * index + 2;
        std::size_t best = index;

        if (left < heap.size() && hasHigherPriority(heap[left], heap[best])) {
            best = left;
        }
        if (right < heap.size() && hasHigherPriority(heap[right], heap[best])) {
            best = right;
        }
        if (best == index) {
            break;
        }
        std::swap(heap[index], heap[best]);
        index = best;
    }
}

void MaxHeap::insert(const Patient& patient) {
    heap.push_back(patient);
    heapifyUp(heap.size() - 1);
}

bool MaxHeap::empty() const {
    return heap.empty();
}

std::size_t MaxHeap::size() const {
    return heap.size();
}

const Patient* MaxHeap::peek() const {
    return heap.empty() ? nullptr : &heap.front();
}

bool MaxHeap::removeTop(Patient& removedPatient) {
    if (heap.empty()) {
        return false;
    }

    removedPatient = heap.front();
    if (heap.size() == 1) {
        heap.pop_back();
        return true;
    }

    heap.front() = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return true;
}

void MaxHeap::clear() {
    heap.clear();
}
