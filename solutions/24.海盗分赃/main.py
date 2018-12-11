# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    nums = [int(i) for i in line.strip().split(",")]
    sums = sum(nums)
    if sums % 2 != 0:
        return "false"
    target = sums / 2
    dp = [False for i in range(target+1)]
    dp[0] = True
    for val in nums:
        for j in range(target, val-1, -1):
            dp[j] = (dp[j] or dp[j-val])

    return "true" if dp[target] else "false"