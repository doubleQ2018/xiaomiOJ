# Author : Qi Zhang
# Date   : 2018-11-22

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    line = line.split(";")
    k = int(line[0])
    nums = [int(i) for i in line[1].split(",")]
    l = max(nums)
    r = sum(nums)
    while l < r:
        mid = (l + r) / 2
        count = 0
        sums = 0
        for val in nums:
            sums += val
            if sums > mid:
                count += 1
                sums = val
            elif sums == mid:
                count += 1
                sums = 0
            else:
                continue
        if sums > mid:
            count += 2
        elif sums > 0:
            count += 1

        #print "target = %d, count = %d" %(mid, count)
        if count == k:
            r = mid
        elif count > k:
            l = mid+1
        else:
            r = mid-1
    return str(r)
