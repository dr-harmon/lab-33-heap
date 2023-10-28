#pragma once

template <typename E>
class PriorityQueue
{
public:

    // Initializes the priority queue with the given maximum number of elements.
    // The size of the queue cannot exceed this initial capacity.
    PriorityQueue(int capacity) {
    }

    // Returns the number of elements in the queue.
    int getSize() const {
        return 0;
    }

    // Returns true if the queue has no elements, false otherwise.
    bool isEmpty() const {
        return false;
    }

    // Returns a reference to the minimum element in the queue. Throws an
    // exception if the queue has no elements.
    const E& getMinimum() const {
    }

    // Inserts the given element into the queue, or throws an exception if
    // doing so would exceed the capacity of the queue.
    void insert(const E& e) {
    }

    // Removes the smallest element from the queue, or throws an exception if
    // the queue has no elements.
    void removeMinimum() {
    }
};
