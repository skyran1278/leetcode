import { floodFill } from './floodFill'; // Replace with the actual module path

describe('floodFill', () => {
  it('should correctly fill the area when starting from a non-edge pixel', () => {
    const image = [
      [1, 1, 1],
      [1, 1, 0],
      [1, 0, 1],
    ];
    const sr = 1;
    const sc = 1;
    const color = 2;
    const expected = [
      [2, 2, 2],
      [2, 2, 0],
      [2, 0, 1],
    ];

    expect(floodFill(image, sr, sc, color)).toEqual(expected);
  });

  it('should not change the image if the starting pixel color matches the target color', () => {
    const image = [
      [0, 0, 0],
      [0, 0, 0],
    ];
    const sr = 0;
    const sc = 0;
    const color = 0;
    const expected = [
      [0, 0, 0],
      [0, 0, 0],
    ];

    expect(floodFill(image, sr, sc, color)).toEqual(expected);
  });

  it('should correctly fill the area when starting from a corner pixel', () => {
    const image = [
      [1, 1, 1],
      [1, 1, 0],
      [1, 0, 0],
    ];
    const sr = 0;
    const sc = 0;
    const color = 2;
    const expected = [
      [2, 2, 2],
      [2, 2, 0],
      [2, 0, 0],
    ];

    expect(floodFill(image, sr, sc, color)).toEqual(expected);
  });

  it('should handle a single-pixel image', () => {
    const image = [[1]];
    const sr = 0;
    const sc = 0;
    const color = 2;
    const expected = [[2]];

    expect(floodFill(image, sr, sc, color)).toEqual(expected);
  });

  it('should not change the image if the starting pixel is at an edge and different color', () => {
    const image = [
      [1, 1, 1],
      [1, 1, 0],
      [1, 0, 1],
    ];
    const sr = 0;
    const sc = 0;
    const color = 1;
    const expected = [
      [1, 1, 1],
      [1, 1, 0],
      [1, 0, 1],
    ];

    expect(floodFill(image, sr, sc, color)).toEqual(expected);
  });

  it('should handle a larger image (edge case)', () => {
    const image = Array(50).fill(Array(50).fill(1)) as number[][]; // A 50x50 grid of 1s
    const sr = 25;
    const sc = 25;
    const color = 2;
    const expected = Array(50).fill(Array(50).fill(2)); // A 50x50 grid of 2s

    expect(floodFill(image, sr, sc, color)).toEqual(expected);
  });
});
