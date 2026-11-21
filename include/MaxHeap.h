#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "Patient.h"
#include <vector>
#include <cstddef>

// A custom max-heap. Higher medical priority comes first.
// Patients with equal priority are served in registration order (FIFO).
class MaxHeap {
private:
    std::vector<Patient> heap;

    static bool hasHigherPriority(const Patient& a, const Patient& b);
    void heapifyUp(std::size_t index);
    void heapifyDown(std::size_t index);

public:
    void insert(const Patient& patient);
    bool empty() const;
    std::size_t size() const;
    const Patient* peek() const;
    bool removeTop(Patient& removedPatient);
    void clear();
};

#endif
