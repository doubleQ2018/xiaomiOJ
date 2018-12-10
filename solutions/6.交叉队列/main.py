# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    a, b, c = line.rstrip().split(",")
    la = len(a)
    lb = len(b)
    lc = len(c)
    if la + lb != lc:
        return "false"
    dp = [[False for i in range(la+1)] for j in range(lb+1)]
    dp[0][0] = True
    for i in range(la):
        if a[i] == c[i]:
            dp[i+1][0] = True
        else:
            break
    for i in range(lb):
        if b[i] == c[i]:
            dp[0][i+1] = True
        else:
            break
    for i in range(la):
        for j in range(lb):
            dp[i+1][j+1] = ((a[i] == c[i+j+1] and dp[i][j+1]) or (b[j] == c[i+j+1] and dp[i+1][j]))
    ans = dp[la][lb]
    return "true" if ans else "false"