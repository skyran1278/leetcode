import { Node, removeDups } from './removeDups';

describe('removeDups', () => {
  it('removes duplicates from an unsorted linked list', () => {
    // Create the linked list
    const node1 = new Node(1);
    const node2 = new Node(2);
    const node3 = new Node(3);
    const node4 = new Node(2);
    const node5 = new Node(4);
    const node6 = new Node(1);

    node1.next = node2;
    node2.next = node3;
    node3.next = node4;
    node4.next = node5;
    node5.next = node6;

    // Call the removeDups function
    removeDups(node1);

    // Verify the linked list after removing duplicates
    expect(node1.value).toBe(1);
    expect(node1.next?.value).toBe(2);
    expect(node1.next?.next?.value).toBe(3);
    expect(node1.next?.next?.next?.value).toBe(4);
    expect(node1.next?.next?.next?.next).toBe(null);
  });

  it('does not modify a linked list without duplicates', () => {
    // Create the linked list
    const node1 = new Node(1);
    const node2 = new Node(2);
    const node3 = new Node(3);
    const node4 = new Node(4);

    node1.next = node2;
    node2.next = node3;
    node3.next = node4;

    // Call the removeDups function
    removeDups(node1);

    // Verify the linked list remains unchanged
    expect(node1.value).toBe(1);
    expect(node1.next?.value).toBe(2);
    expect(node1.next?.next?.value).toBe(3);
    expect(node1.next?.next?.next?.value).toBe(4);
    expect(node1.next?.next?.next?.next).toBe(null);
  });
});
