export function isPowerOfFour(n: number): boolean {
  if (n <= 0) return false;
  return Number.isInteger(Math.log2(n) / 2);
}
