# Issue

## Question

Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?

## Solution

遍歷 linked list
用 set 儲存已經出現過的值

原本: 如果不能用 temporary buffer, 那就得每一次都檢查已經建立的有沒有與之重複
更好: 如果不能用 temporary buffer, 那就得每一次檢查全部是否與現有的重複，有的話移除 (use two-pointer approach)
