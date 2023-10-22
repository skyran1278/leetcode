import { Node } from '../linkedList';

export const loopDetection = <T>(list: Node<T> | null): Node<T> | null => {
  let fastRunner: Node<T> | null = list;
  let slowRunner = fastRunner;
  while (slowRunner && fastRunner && fastRunner.next) {
    slowRunner = slowRunner.next;
    fastRunner = fastRunner.next.next;
    if (slowRunner === fastRunner) {
      break;
    }
  }

  if (!fastRunner || !fastRunner.next) {
    return null;
  }

  slowRunner = list;
  while (slowRunner && fastRunner) {
    if (slowRunner === fastRunner) {
      return slowRunner;
    }
    slowRunner = slowRunner.next;
    fastRunner = fastRunner.next;
  }

  return null;
};
