# Lab 33: Heap

In this lab, you are to implement a heap-based priority queue from the ground up. Although a heap is a kind of binary tree, and could be built using the BST class of Lab 30, heaps are always complete binary trees and can therefore be implemented more easily as an array or vector.

## Objective

Start with the provided `PriorityQueue` class, which exposes the priority queue ADT functions `insert`, `getMinimum`, `removeMinimum`, and so on. Fill in the missing functions by implementing a _min-heap_, where the smallest element is always at the top of the heap (the root). The heap should be built with an array or vector, and it should be in the private scope of the class (not directly accessible to external clients).

Be sure that `insert` and `removeMinimum` run in `O(log n)` time, and `getMinimum` runs in constant time.

When you have finished, verify that all unit tests pass. You can use `main` to debug your implementation.

## Hints

To implement the heap as an array/vector, refer to Section 8.3.2 in the textbook ("A Vector Representation of a Complete Binary Tree") and pay close attention to the equations for computing the left and right child indices from a node index. (How would you convert a node index to its parent index?)

Remember that the first element (index 0) of an array/vector-based heap is unused. Watch out for [off-by-one errors](https://en.wikipedia.org/wiki/Off-by-one_error), perhaps the most common error in all of software!

For `insert`, refer to Example 8.16 in the textbook, which is rewritten here in pseudocode:

    Algorithm Insert(E, H):
        H.size ← H.size + 1
        H[size] ← E
        i ← size
        while i is not the root index do
            parent ← index of i's parent
            if H[i] is not less than H[parent] then
                break
            swap H[i] with H[parent]
            i ← parent

For `removeMinimum`, refer to Example 8.17 in the textbook, which is rewritten here in pseudocode:

    Algorithm RemoveMin(H):
        H[1] ← H[size]
        H.size ← H.size - 1
        i ← 1
        while H[i] has a left child do
            child ← index of H[i]'s left child
            if H[i] has a right child and it is less than the left child then
                child ← index of H[i]'s right child
            if H[child] is less than H[i] then
                swap H[i] with H[child]
                i ← child
            else
                break

You may find implementing these functions easier if you first add the following private helper functions:

* `void bubbleUp(int i)`: performs the loop of `insert` (a.k.a. up-heap bubbling)
* `void bubbleDown(int i)`: performs the loop of `removeMinimum` (a.k.a. down-heap bubbling)
* `bool isLess(int i, int j)`: returns whether the element at index i is less than the element at index j
* `void swap(int i, int j)`: swaps the element at index i with the element at index j
* `int getParent(int i)`, `int getLeft(int i)`, `int getRight(int i)`: returns the index of i that corresponds to the given relation (note these return an _index_ into the heap, not a _value_ in the heap)
* `bool isRoot(int i)`, `bool hasLeft(int i)`, `bool hasRight(int i)`: returns whether the given index is a root, has a left child, or has a right child, respectively
