# Issue

## Question

Partition: Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.
EXAMPLE
Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition=5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

## Solution

1. 可以用笨方法, 先把小於 x 的 node 挑出來, 再把大於等於 x 的 node 挑出來, 最後再把兩個 list 接起來
2. Elements bigger than the pivot element are put at the tail and elements smaller are put at the head.
