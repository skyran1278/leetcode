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
