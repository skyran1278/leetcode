import { Node } from '../linkedList';

// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
export const returnKthToLast = (head: Node | null, k: number): Node | null => {
  if (head == null) {
    return null;
  }

  let pointer1: Node | null = head;
  let pointer2: Node | null = head;

  for (let i = 0; i < k; i++) {
    if (pointer2 == null) {
      return null;
    }
    pointer2 = pointer2.next;
  }

  while (pointer2 != null && pointer1 != null) {
    pointer1 = pointer1.next;
    pointer2 = pointer2.next;
  }

  return pointer1;
};

// Time: O(n)
// Space: O(1)
// where n is the length of the linked list

export const returnKthToLast2 = (head: Node | null, k: number): Node | null => {
  let i = 0;
  const counter = (node: Node | null): Node | null => {
    if (node == null) {
      return null;
    }
    const nd = counter(node.next);
    i += 1;
    if (i === k) {
      return node;
    }
    return nd;
  };
  return counter(head);
};

// Time: O(n)
// Space: O(n)
// where n is the length of the linked list
