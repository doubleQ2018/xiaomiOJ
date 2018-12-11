# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    line = line.rstrip().split()
    nums = [int(i) for i in line[0].split(",")]
    target = int(line[1])
    dp = [0 for i in range(target+1)]
    dp[0] = 1
    for j in range(target+1):
        for val in nums:
            if j >= val:
                dp[j] += dp[j - val]
    return int(dp[target])