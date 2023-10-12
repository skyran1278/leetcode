/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
export const floodFill = (
  image: number[][],
  sr: number,
  sc: number,
  color: number
): number[][] => {
  const value = image[sr][sc];

  if (value === color) {
    return image;
  }

  const queue: [number, number][] = [];
  queue.push([sr, sc]);

  while (queue.length !== 0) {
    // eslint-disable-next-line @typescript-eslint/no-non-null-assertion
    const [sr, sc] = queue.pop()!;
    if (sr - 1 >= 0 && image[sr - 1][sc] === value) {
      queue.push([sr - 1, sc]);
    }
    if (sc - 1 >= 0 && image[sr][sc - 1] === value) {
      queue.push([sr, sc - 1]);
    }
    if (sr + 1 < image.length && image[sr + 1][sc] === value) {
      queue.push([sr + 1, sc]);
    }
    if (sc + 1 < image[sr].length && image[sr][sc + 1] === value) {
      queue.push([sr, sc + 1]);
    }
    image[sr][sc] = color;
  }
  return image;
};
