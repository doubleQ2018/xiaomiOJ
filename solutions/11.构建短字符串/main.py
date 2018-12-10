# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    x, y = line.rstrip().split()
    def do(s):
        d = {}
        for c in s:
            if d.has_key(c):
                d[c] += 1
            else:
                d[c] = 1
        return d
    dx = do(x)
    dy = do(y)
    ans = True
    for c in dx:
        if dy.has_key(c) and dy[c] >= dx[c]:
            continue
        else:
            ans = False
            break
    return "true" if ans else "false"