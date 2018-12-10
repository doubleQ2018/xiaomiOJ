# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    nums = [int(i) for i in line.rstrip().split(",")]
    n = len(nums)
    for i in range(n):
        if nums[i] <= 0 or nums[i] > n:
            continue
        while (nums[i] != i+1 and nums[i] > 0 and nums[i] <= n):
            p = nums[i]
            nums[i], nums[p-1] = nums[p-1], nums[i]
    ans = n+1
    for i in range(n):
        if nums[i] != i+1:
            ans = i+1
            break
    return str(ans)