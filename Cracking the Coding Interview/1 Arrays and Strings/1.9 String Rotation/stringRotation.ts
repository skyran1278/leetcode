export const stringRotation = (s1: string, s2: string): boolean => {
  if (s1.length !== s2.length) return false;
  return isSubstring(s1 + s1, s2);
};

const isSubstring = (s1: string, s2: string): boolean => {
  return s1.includes(s2);
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// where n is the length of the string
