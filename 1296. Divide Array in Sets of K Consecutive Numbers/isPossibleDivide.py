from collections import Counter
from typing import List


class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k != 0:
            return False

        nums.sort()
        nums_dict = Counter(nums)

        for num in nums_dict:
            value = nums_dict[num]
            if value == 0:
                continue
            for i in range(k):
                if nums_dict[num + i] == 0:
                    return False
                nums_dict[num + i] -= value
        return True


s = Solution()

print(s.isPossibleDivide([1, 2, 3, 3, 4, 4, 5, 6], 4))
