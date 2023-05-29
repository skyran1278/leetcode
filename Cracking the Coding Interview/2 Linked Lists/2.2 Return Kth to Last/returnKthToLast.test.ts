import { Node, arrayToLinkedList } from '../linkedList';
import { returnKthToLast } from './returnKthToLast'; // Replace 'yourFile' with the actual file name

describe('returnKthToLast', () => {
  it('should return the kth to last element in a singly linked list', () => {
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const kthToLast = returnKthToLast(head, 2);
    expect(kthToLast?.value).toBe(4);
  });

  it('should return the head element when k is 0', () => {
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const kthToLast = returnKthToLast(head, 0);
    expect(kthToLast?.value).toBe(1);
  });

  it('should return null when k is greater than the linked list length', () => {
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const kthToLast = returnKthToLast(head, 6);
    expect(kthToLast).toBeNull();
  });

  it('should return the head element when the linked list has only one node', () => {
    const head = new Node(1);
    const kthToLast = returnKthToLast(head, 0);
    expect(kthToLast?.value).toBe(1);
  });

  it('should return null when the linked list is empty', () => {
    const head = null;
    const kthToLast = returnKthToLast(head, 2);
    expect(kthToLast).toBeNull();
  });

  it('should return the kth to last element when k is equal to the linked list length', () => {
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const kthToLast = returnKthToLast(head, 5);
    expect(kthToLast?.value).toBe(1);
  });
});
