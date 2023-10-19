import { Node, arrayToLinkedList, createLinkedList } from '../linkedList';
import { intersection } from './intersection';

describe('intersection', () => {
  it('should return the intersecting node when lists intersect', () => {
    // Create two linked lists that intersect at a specific node
    const commonNode = new Node(7);
    const list1 = arrayToLinkedList([1, 2, 3]);
    const list2 = arrayToLinkedList([4, 5]);

    // Merge the two lists at the common node
    if (list1.next?.next) list1.next.next.next = commonNode;
    if (list2.next) list2.next.next = commonNode;

    const result = intersection(list1, list2);

    expect(result).toBe(commonNode);
  });

  it('should return null when lists do not intersect', () => {
    // Create two linked lists that do not intersect
    const list1 = arrayToLinkedList([1, 2, 3]);
    const list2 = arrayToLinkedList([4, 5]);

    const result = intersection(list1, list2);

    expect(result).toBe(null);
  });

  it('should return null for empty lists', () => {
    // Both lists are empty, so there is no intersection
    const result = intersection(null, null);

    expect(result).toBe(null);
  });

  it('should return null for one empty list', () => {
    // One of the lists is empty, so there is no intersection
    const list1 = arrayToLinkedList([1, 2, 3]);
    const result = intersection(list1, null);

    expect(result).toBe(null);
  });

  it('should handle large intersecting lists', () => {
    // Create large intersecting linked lists
    const commonNode = new Node(7);
    const list1 = createLinkedList(1000);
    const list2 = createLinkedList(500);

    // Merge the two lists at the common node
    let current = list1;
    while (current.next) {
      current = current.next;
    }
    current.next = commonNode;
    if (list2.next?.next) list2.next.next.next = commonNode;

    const result = intersection(list1, list2);

    expect(result).toBe(commonNode);
  });
});
