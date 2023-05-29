# Issue

## Question

String Rotation: Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one call to isSubstring (e.g.,"waterbottle" is a rotation of"erbottlewat").

## Solution

- original
  we can ask what the rotation point is
  So, we need to check if there's a way to split s1 into x andy such that xy = s1 and yx = s2.
  first check if the strings are of equal length and not empty
  then search first string for the first character of the second string
  if found, check if the rest of the second string is a substring of the first string
  if not found, return false

- better
  Regardless of where the division between x andy is, we can see that yx will always be a substring of xyxy.That is, s2 will always be a substring ofs1s1.
  replicate first string, check second string is substring of first string or not
