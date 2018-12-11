# Author : Qi Zhang
# Date   : 2018-12-11

#coding:utf-8
import math
import types
import random

cnList = [ '零', '壹', '贰', '叁', '肆', '伍', '陆', '柒', '捌', '玖' ]
chnUnitSection = ["","万","亿","兆","京","垓"]
chnUnitChar = ["","拾","佰","仟"]
"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(num):
    if num == "0":
        return "零元整"
    result = ''
    z = 0

    for i in range(0,len(num)):
        s = num[i]
        s = int(s)
        weishu = len(num)-i
        if s:
            if z:
                result+=cnList[0]
            x_w = ( weishu-1 )%4
            result+=cnList[s]
            result+=chnUnitChar[x_w]
            z = 0
        else:
            z+=1
        if ( weishu-1 )%4==0 and z<4:
            b_w = chnUnitSection[weishu/4]
            result+=b_w
            z = 0
    return result + "元整"