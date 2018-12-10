# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    line = line.split(";")
    target = int(line[0])
    w = [int(i) for i in line[1].split(",")]
    v = [int(i) for i in line[2].split(",")]
    dp = [[0 for i in range(target+1)] for j in range(len(w)+1)]
    ans = 0
    for i in range(len(w)):
        ww = w[i]
        vv = v[i]
        for j in range(1, target+1):
            if j >= ww:
                dp[i+1][j] = max(dp[i][j], dp[i][j-ww] + vv)
            else:
                dp[i+1][j] = dp[i][j]

    return str(dp[len(w)][target])