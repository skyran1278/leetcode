# Issue

## Question

Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C

## Solution

1. memo node address in hash table, if node address is already in hash table, return the node
2. use two pointers, one is fast, another is slow, if they meet, there is a loop

slowRunner speed is 1; fastRunner speed is 2; enter to loop size is k; loop size is loopSize;

collide issue: if slowRunner is on t, fastRunner is on t + 1; previous step, slowRunner is on t - 1, fastRunner is on t - 1;

after k steps when slowRunner on the loop of start position k + 1, and fastRunner is on (2k + 1 - k) % loopSize
between slowRunner and fastRunner is k % loopSize steps
both CollisionSpot and LinkedListHead are k nodes from the start of the loop.

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 1 走到 1 重合
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 走到 9 重合
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 走到 8 重合
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 4 -> 5 -> 6 -> 7 走到 7 重合
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 5 -> 6 走到 6 重合
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 6 -> 7 -> 8 -> 9 -> 6 -> 7 -> 8 -> 9 走到 9 重合
