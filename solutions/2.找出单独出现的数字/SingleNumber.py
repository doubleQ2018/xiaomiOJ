# Author : Qi Zhang
# Date   : 2018-11-22

def solution(line):
    # 缩进请使用 4 个空格，遵循 PEP8 规范
    # 返回处理后的结果
    nums = [int(i) for i in line.rstrip().split()]
    cur = nums[0]
    count = 1
    for i in nums[1:]:
        if count == 0:
            cur = i
            count = 1
        else:
            if cur == i:
                count += 1
            else:
                count -= 1
    return str(cur)
