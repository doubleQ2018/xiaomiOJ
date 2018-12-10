# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    nums = [int(i) for i in line.split(",")]
    nums = sorted(nums)
    ans = 0
    for i in range(len(nums)):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        target = -nums[i]
        l = i+1
        r = len(nums)-1
        while l < r:
            if nums[l] + nums[r] == target:
                ans += 1
                while(l < r and nums[l] == nums[l+1]):
                    l += 1
                l += 1
                while(l < r and nums[r] == nums[r-1]):
                    r -= 1
                r -= 1
            elif nums[l] + nums[r] < target:
                l += 1
            else:
                r -= 1
    return str(ans)