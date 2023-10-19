import { Node } from '../linkedList';

export const intersection = (
  list1: Node | null,
  list2: Node | null,
): Node | null => {
  let current = list1;
  const arr1 = [];
  while (current) {
    arr1.push(current);
    current = current.next;
  }

  current = list2;
  const arr2 = [];
  while (current) {
    arr2.push(current);
    current = current.next;
  }

  let sameNode: Node | null = null;
  while (arr1.length && arr2.length) {
    const node1 = arr1.pop() ?? null;
    const node2 = arr2.pop() ?? null;
    if (node1 === node2) {
      sameNode = node1;
    } else {
      return sameNode;
    }
  }
  return sameNode;
};
