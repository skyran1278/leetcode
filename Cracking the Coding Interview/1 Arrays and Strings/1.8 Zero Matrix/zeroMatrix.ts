// Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
// easy: 先記起來要改的 row 和 column, 再一次性改, O(MxN)
export const zeroMatrix = (matrix: number[][]): number[][] => {
  const zeroRows: number[] = [];
  const zeroColumns: number[] = [];

  for (let i = 0; i < matrix.length; i++) {
    const row = matrix[i];
    for (let j = 0; j < row.length; j++) {
      const element = row[j];
      if (element === 0) {
        zeroRows.push(i);
        zeroColumns.push(j);
      }
    }
  }

  for (let i = 0; i < matrix.length; i++) {
    const row = matrix[i];
    for (let j = 0; j < row.length; j++) {
      if (zeroRows.includes(i) || zeroColumns.includes(j)) {
        matrix[i][j] = 0;
      }
    }
  }

  return matrix;
};
