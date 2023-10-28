#pragma once

#include <memory>
#include <stdexcept>

template <typename E>
class PriorityQueue
{
public:

    // Initializes the priority queue with the given maximum number of elements.
    // The size of the queue cannot exceed this initial capacity.
    PriorityQueue(int capacity) {
        this->capacity = capacity;
        this->heap = std::make_unique<E[]>(capacity + 1);
        this->size = 0;
    }

    // Returns the number of elements in the queue.
    int getSize() const {
        return size;
    }

    // Returns true if the queue has no elements, false otherwise.
    bool isEmpty() const {
        return size == 0;
    }

    // Returns a reference to the minimum element in the queue. Throws an
    // exception if the queue has no elements.
    const E& getMinimum() const {
        if (isEmpty()) {
            throw std::runtime_error("Priority queue is empty");
        }

        return heap[1];
    }

    // Inserts the given element into the queue, or throws an exception if
    // doing so would exceed the capacity of the queue.
    void insert(const E& e) {
        if (size == capacity) {
            throw std::runtime_error("Priority queue is at capacity");
        }

        size++;
        heap[size] = e;
        bubbleUp(size);
    }

    // Removes the smallest element from the queue, or throws an exception if
    // the queue has no elements.
    void removeMinimum() {
        if (isEmpty()) {
            throw std::runtime_error("Priority queue is empty");
        }

        heap[1] = heap[size];
        size--;
        bubbleDown(1);
    }

private:

    int capacity;
    int size;
    std::unique_ptr<E[]> heap;

    void bubbleUp(int i) {
        while (!isRoot(i)) {
            int parent = getParent(i);
            if (!isLess(i, parent)) {
                break;
            }
            swap(i, parent);
            i = parent;
        }
    }

    void bubbleDown(int i) {
        while (hasLeft(i)) {
            int child = getLeft(i);
            if (hasRight(i) && isLess(getRight(i), child)) {
                child = getRight(i);
            }
            if (isLess(child, i)) {
                swap(i, child);
                i = child;
            } else {
                break;
            }
        }
    }

    bool isLess(int i, int j) const {
        return heap[i] < heap[j];
    }

    void swap(int i, int j) const {
        E tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }

    int getParent(int i) const {
        return i / 2;
    }

    int getLeft(int i) const {
        return i * 2;
    }

    int getRight(int i) const {
        return i * 2 + 1;
    }

    bool isRoot(int i) const {
        return i == 1;
    }

    bool hasLeft(int i) const {
        return getLeft(i) <= size;
    }

    bool hasRight(int i) const {
        return getRight(i) <= size;
    }
};
