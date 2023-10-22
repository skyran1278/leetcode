import { arrayToLinkedList, createLinkedList } from '../linkedList';
import { loopDetection } from './loopDetection';

describe('loopDetection', () => {
  it('should return the start of the loop', () => {
    // Create a circular linked list with a loop
    const list = arrayToLinkedList(['A', 'B', 'C', 'D', 'E']);

    if (!list?.next?.next?.next?.next) {
      return;
    }
    const commonNode = list?.next?.next;
    list.next.next.next.next.next = commonNode;

    const result = loopDetection(list);

    expect(result).toBe(commonNode);
  });

  it('should return null for a non-circular linked list', () => {
    // Create a non-circular linked list
    const list = arrayToLinkedList(['A', 'B', 'C', 'D', 'E']);

    const result = loopDetection(list);

    expect(result).toBe(null);
  });

  it('should return null for an empty linked list', () => {
    // An empty list cannot have a loop
    const result = loopDetection(null);

    expect(result).toBe(null);
  });

  it('should handle large circular linked lists', () => {
    // Create a large circular linked list with a loop
    const list = createLinkedList(1000);

    if (!list.next?.next?.next?.next?.next?.next?.next?.next?.next?.next) {
      return;
    }

    const commonNode = list.next.next.next.next.next.next.next.next.next.next;

    // Connect the last node to the common node to create a loop
    let current = list;
    while (current.next) {
      current = current.next;
    }
    current.next = commonNode;

    const result = loopDetection(list);

    expect(result).toBe(commonNode);
  });
});
