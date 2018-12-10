# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    n = int(line.strip())
    #ans = np.array([0]).astype(np.int32)[0]
    ans = 0
    p = 0
    while n > 0:
        if n % 2 == 1:
            ans += (1 << (31-p))
        n /= 2
        p += 1
	return str(ans) 