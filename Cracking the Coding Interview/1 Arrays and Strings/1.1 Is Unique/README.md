# Issue

## Question

Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

## Solution

The key consideration is the range of possible characters: ASCII with 256 possible characters or Unicode with 65,536 possible characters.

1. **Using a key-value pair:** This approach offers O(1) time complexity for lookups.
2. **Using an array for all characters:** If additional data structures are allowed, you can create an array to track characters. This would provide O(n) time complexity.
3. **In-place comparison:** If additional data structures are not allowed, compare each character with the rest of the string using a nested loop. This results in O(n²) time complexity.
4. **Sorting the string:** You can sort the string in O(n log n) time and then check for adjacent duplicates in O(n) time.
