import { arrayToLinkedList, linkedListToArray } from '../linkedList';
import { deleteMiddleNode } from './deleteMiddleNode';

describe('deleteMiddleNode', () => {
  it('deletes the middle node correctly when the list has odd length', () => {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const middleNode = head.next?.next ?? null; // node with value 3
    const expectedOutput = [1, 2, 4, 5];

    deleteMiddleNode(middleNode);

    expect(linkedListToArray(head)).toEqual(expectedOutput);
  });

  it('deletes the middle node correctly when the list has even length', () => {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    const head = arrayToLinkedList([1, 2, 3, 4, 5, 6]);
    const middleNode = head.next?.next?.next ?? null; // node with value 4
    const expectedOutput = [1, 2, 3, 5, 6];

    deleteMiddleNode(middleNode);

    expect(linkedListToArray(head)).toEqual(expectedOutput);
  });

  it('returns false when the node is the last node in the list', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const lastNode = head.next?.next ?? null; // node with value 3

    const result = deleteMiddleNode(lastNode);

    expect(result).toBe(false);
    expect(linkedListToArray(head)).toEqual([1, 2, 3]); // The list remains unchanged
  });

  it('returns false when the node is null', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);

    const result = deleteMiddleNode(null);

    expect(result).toBe(false);
    expect(linkedListToArray(head)).toEqual([1, 2, 3]); // The list remains unchanged
  });
});
