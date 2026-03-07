import {
  Node,
  arrayToLinkedList,
  createLinkedList,
  linkedListToArray,
  reverseLinkedList,
} from './linkedList';

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

  it('should throw for negative length', () => {
    expect(() => createLinkedList(-1)).toThrow('Invalid linked list length');
  });
});

describe('arrayToLinkedList', () => {
  it('should convert a single-element array', () => {
    const result = arrayToLinkedList([42]);
    expect(result.value).toBe(42);
    expect(result.next).toBeNull();
  });

  it('should convert a multi-element array', () => {
    const result = arrayToLinkedList([1, 2, 3]);
    expect(linkedListToArray(result)).toEqual([1, 2, 3]);
  });

  it('should work with strings', () => {
    const result = arrayToLinkedList(['a', 'b', 'c']);
    expect(linkedListToArray(result)).toEqual(['a', 'b', 'c']);
  });
});

describe('linkedListToArray', () => {
  it('should return empty array for null', () => {
    expect(linkedListToArray(null)).toEqual([]);
  });

  it('should convert a single node', () => {
    expect(linkedListToArray(new Node(7))).toEqual([7]);
  });
});

describe('reverseLinkedList', () => {
  it('should return null for null input', () => {
    expect(reverseLinkedList(null)).toBeNull();
  });

  it('should reverse a single node', () => {
    const node = new Node(1);
    const result = reverseLinkedList(node);
    expect(linkedListToArray(result)).toEqual([1]);
  });

  it('should reverse a multi-node list', () => {
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const result = reverseLinkedList(head);
    expect(linkedListToArray(result)).toEqual([5, 4, 3, 2, 1]);
  });

  it('should reverse a two-node list', () => {
    const head = arrayToLinkedList([1, 2]);
    const result = reverseLinkedList(head);
    expect(linkedListToArray(result)).toEqual([2, 1]);
  });
});
