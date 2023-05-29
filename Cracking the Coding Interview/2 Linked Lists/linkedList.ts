export class Node {
  public value: number;
  public next: Node | null;

  constructor(value: number) {
    this.value = value;
    this.next = null;
  }
}

// Helper function to convert an array to a linked list
export const arrayToLinkedList = (arr: number[]) => {
  const head = new Node(arr[0]);
  let current = head;
  for (let i = 1; i < arr.length; i++) {
    const newNode = new Node(arr[i]);
    current.next = newNode;
    current = newNode;
  }
  return head;
};

// Helper function to convert a linked list to an array
export const linkedListToArray = (head: Node | null) => {
  const arr = [];
  let current = head;
  while (current !== null) {
    arr.push(current.value);
    current = current.next;
  }
  return arr;
};
