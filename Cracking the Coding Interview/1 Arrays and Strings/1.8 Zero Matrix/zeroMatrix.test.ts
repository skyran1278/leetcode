import { zeroMatrix } from './zeroMatrix';

describe('zeroMatrix', () => {
  it('should set rows and columns to 0 when there are zeros in the matrix', () => {
    const matrix = [
      [1, 2, 3],
      [4, 0, 6],
      [7, 8, 9],
    ];

    const expectedMatrix = [
      [1, 0, 3],
      [0, 0, 0],
      [7, 0, 9],
    ];

    expect(zeroMatrix(matrix)).toEqual(expectedMatrix);
  });

  it('should not modify the matrix if there are no zeros', () => {
    const matrix = [
      [1, 2, 3],
      [4, 5, 6],
      [7, 8, 9],
    ];

    const expectedMatrix = [
      [1, 2, 3],
      [4, 5, 6],
      [7, 8, 9],
    ];

    expect(zeroMatrix(matrix)).toEqual(expectedMatrix);
  });

  it('should handle empty matrix', () => {
    const matrix: number[][] = [];

    expect(zeroMatrix(matrix)).toEqual([]);
  });

  it('should handle matrix with all zeros', () => {
    const matrix = [
      [0, 0, 0],
      [0, 0, 0],
      [0, 0, 0],
    ];

    const expectedMatrix = [
      [0, 0, 0],
      [0, 0, 0],
      [0, 0, 0],
    ];

    expect(zeroMatrix(matrix)).toEqual(expectedMatrix);
  });
});
