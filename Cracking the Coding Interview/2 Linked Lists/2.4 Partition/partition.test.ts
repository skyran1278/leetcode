import { arrayToLinkedList, linkedListToArray } from '../linkedList';
import { partition } from './partition';

describe('partition', () => {
  it('partitions the linked list correctly', () => {
    // Create a linked list: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1
    const head = arrayToLinkedList([3, 5, 8, 5, 10, 2, 1]);
    const partitionValue = 5;
    const expectedOutput = [3, 2, 1, 5, 8, 5, 10];

    const newHead = partition(head, partitionValue);

    expect(linkedListToArray(newHead)).toEqual(expectedOutput);
  });

  it('returns the original linked list when all nodes are less than the partition value', () => {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const partitionValue = 10;

    const newHead = partition(head, partitionValue);

    expect(linkedListToArray(newHead)).toEqual([1, 2, 3, 4, 5]); // The list remains unchanged
  });

  it('returns the original linked list when all nodes are greater than or equal to the partition value', () => {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const partitionValue = 0;

    const newHead = partition(head, partitionValue);

    expect(linkedListToArray(newHead)).toEqual([1, 2, 3, 4, 5]); // The list remains unchanged
  });

  it('returns null when the linked list is empty', () => {
    const head = null;
    const partitionValue = 5;

    const newHead = partition(head, partitionValue);

    expect(newHead).toBeNull();
  });
});
