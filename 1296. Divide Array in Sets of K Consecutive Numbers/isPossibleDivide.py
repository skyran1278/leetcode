class Solution:
  def isPossibleDivide(self, nums: List[int], k: int) -> bool:
    if len(nums) % k != 0:
      return False

    nums.sort()
    c = Counter(nums)

    for n in c:
      num = c[n]
      if num == 0:
        continue
      for i in range(k):
        if c[n + i] == 0:
          return False
        c[n + i] -= num
    return True
