import { Node } from '../linkedList';

// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
export const returnKthToLast = (head: Node | null, k: number): Node | null => {
  if (head == null) {
    return null;
  }

  let kPointer: Node | null = head;
  let lastPointer: Node | null = head;

  for (let i = 0; i < k; i++) {
    if (lastPointer == null) {
      return null;
    }
    lastPointer = lastPointer.next;
  }

  while (lastPointer != null && kPointer != null) {
    kPointer = kPointer.next;
    lastPointer = lastPointer.next;
  }

  return kPointer;
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
