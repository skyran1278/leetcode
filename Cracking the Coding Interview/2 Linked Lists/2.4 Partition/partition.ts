import { Node, arrayToLinkedList } from '../linkedList';

export const partition = (
  head: Node<number> | null,
  partitionValue: number,
): Node<number> | null => {
  if (head == null) {
    return null;
  }
  let current: Node<number> | null = head;
  const lessThanPartitionValues: number[] = [];
  const greaterThanPartitionValues: number[] = [];
  while (current != null) {
    if (current.value >= partitionValue) {
      greaterThanPartitionValues.push(current.value);
    } else {
      lessThanPartitionValues.push(current.value);
    }
    current = current.next;
  }
  return arrayToLinkedList(
    lessThanPartitionValues.concat(greaterThanPartitionValues),
  );
};

export const partition2 = (
  node: Node<number> | null,
  partitionValue: number,
): Node<number> | null => {
  if (node == null) {
    return null;
  }
  let head = node;
  let tail = node;
  while (node != null) {
    const next: Node<number> | null = node.next;
    if (node.value < partitionValue) {
      node.next = head;
      head = node;
    } else {
      tail.next = node;
      tail = node;
    }
    node = next;
  }
  tail.next = null;
  return head;
};
