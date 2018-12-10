# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    s = line.rstrip()
    st = []
    ans = True
    for c in s:
        if c == '[' or c == '(' or c == '{':
            st.append(c)
        else:
            if c == ']':
                if len(st) > 0 and st[-1] == '[':
                    st.pop(-1)
                else:
                    ans = False
                    break
            if c == ')':
                if len(st) > 0 and st[-1] == '(':
                    st.pop(-1)
                else:
                    ans = False
                    break
            if c == '}':
                if len(st) > 0 and st[-1] == '{':
                    st.pop(-1)
                else:
                    ans = False
                    break
    if len(st) > 0:
        ans = False

    return "1" if ans else "0"