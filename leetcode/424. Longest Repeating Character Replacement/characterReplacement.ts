function characterReplacement(s: string, k: number): number {
  const counter: Record<string, number> = {};
  let start = 0;
  let maxCount = 0;
  let maxLength = 0;
  for (let end = 0; end < s.length; end++) {
    const char = s[end];
    if (!counter[char]) {
      counter[char] = 0;
    }
    counter[char]++;
    maxCount = Math.max(maxCount, counter[char]);
    if (end - start + 1 - maxCount > k) {
      counter[s[start]]--;
      start++;
    }
    maxLength = Math.max(maxLength, end - start + 1);
  }
  return maxLength;
}

export { characterReplacement };
