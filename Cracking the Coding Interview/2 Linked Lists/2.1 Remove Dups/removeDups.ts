export const removeDups = (head: Node): void => {
  return;
};

export class Node {
  public value: number;
  public next: Node | null;

  constructor(value: number) {
    this.value = value;
    this.next = null;
  }
}
