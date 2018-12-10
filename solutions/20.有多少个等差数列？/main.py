# 此处可 import 模块
import collections
"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    A = [int(i) for i in line.strip().split()]
    n = len(A)
    res = 0
    dp = [collections.Counter() for i in range(len(A))]
    for i in range(len(A)):
        for j in range(i):
            diff = A[i]-A[j]
            dp[i][diff] += 1
            if not diff in dp[j]:continue
            dp[i][diff] += dp[j][diff]
            res += dp[j][diff]
    return str(res+n*(n-1)/2)