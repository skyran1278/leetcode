# Issue

## Question

String Rotation: Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one call to isSubstring (e.g.,"waterbottle" is a rotation of"erbottlewat").

## Solution

- original
  first check if the strings are of equal length and not empty
  then search first string for the first character of the second string
  if found, check if the rest of the second string is a substring of the first string
  if not found, return false

- better
  replicate first string, check second string is substring of first string or not
