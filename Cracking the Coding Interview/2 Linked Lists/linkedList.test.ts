import { Node, createLinkedList, linkedListToArray } from './linkedList';

describe('createLinkedList', () => {
  it('should create an empty linked list when length is 0', () => {
    expect(() => {
      createLinkedList(0);
    }).toThrow(new Error('Invalid linked list length'));
  });

  it('should create a linked list with a single node when length is 1', () => {
    const result = createLinkedList(1);
    expect(result).toEqual(new Node(1));
  });

  it('should create a linked list with the specified length', () => {
    const length = 5;
    const result = createLinkedList(length);
    const expectedValues = Array.from({ length }, (_, i) => i + 1);

    // Convert the linked list to an array for comparison
    const resultArray = linkedListToArray(result);

    expect(resultArray).toEqual(expectedValues);
  });

  it('should handle large lengths', () => {
    const length = 1000;
    const result = createLinkedList(length);

    // Check if the length of the linked list is as expected
    let current: Node | null = result;
    let count = 0;
    while (current) {
      count++;
      current = current.next;
    }

    expect(count).toBe(length);
  });
});
