# Issue

## Question

Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the inter­secting node. Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.

## Solution

1. O(n^2): for loop two linked lists, if the node is the same, then they are intersecting.
2. O(n): if using c++, can remember the address of each node, and then compare the address.
3. O(n): if the two linked lists are intersecting, then the last node of the two linked lists must be the same. So we can reverse the two linked lists, and then compare two linked lists from the end.
4. O(n): Compare the tails. If they are different (by reference, not by value), return immediately. There is no intersection. On the longer linked list, advance its pointer by the difference in lengths.
