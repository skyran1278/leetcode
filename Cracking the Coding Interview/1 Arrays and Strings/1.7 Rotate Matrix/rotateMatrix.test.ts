import { rotateMatrix } from './rotateMatrix'; // Replace 'your-module' with the actual module path

describe('rotateMatrix', () => {
  it('should rotate the matrix by 90 degrees', () => {
    const matrix = [
      [1, 2, 3],
      [4, 5, 6],
      [7, 8, 9],
    ];

    const expectedMatrix = [
      [7, 4, 1],
      [8, 5, 2],
      [9, 6, 3],
    ];

    rotateMatrix(matrix);
    expect(matrix).toEqual(expectedMatrix);
  });

  it('should rotate a 2x2 matrix by 90 degrees', () => {
    const matrix = [
      [1, 2],
      [3, 4],
    ];

    const expectedMatrix = [
      [3, 1],
      [4, 2],
    ];

    rotateMatrix(matrix);
    expect(matrix).toEqual(expectedMatrix);
  });

  it('should not modify an empty matrix', () => {
    const matrix: number[][] = [];

    rotateMatrix(matrix);
    expect(matrix).toEqual([]);
  });
});
