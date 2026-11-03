class Solution(object):
    def maxProduct(self, nums):
        res = nums[0]
        curr_min = 1
        curr_max = 1

        for n in nums:
            if n == 0:
                curr_min = 1
                curr_max = 1
                res = max(res, 0)
                continue

            temp = curr_max * n
            curr_max = max(n * curr_max, n * curr_min, n)
            curr_min = min(temp, n * curr_min, n)
            res = max(res, curr_max)

        return res