//
//  main.cpp
//  0811-字节跳动-二进制加密解码
//
//  Created by 刘文斌 on 2019/8/11.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//题目：一个长度为N多二进制串，向右移动0-k-1次，异或后得到一个新的长度为N+K-1的串
//输入该串，得到
//通过率50%，已改动：int j=0；修改为int j=1%k；
#include <stdio.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,k;
    char ch,tmp,s[1000001];//s记录k内包含（叠加）的字符,tmp记录s内所有字符异或的结果
    scanf("%d%d",&n,&k);getchar();
    s[0] = getchar();tmp = s[0];//初始化第一个字符及tmp
    printf("%c",s[0]);//输出第一个字符
    
    int j=1%k;//s中下一个要放元素的位置，环形数据结构，大于等于k之后k指向s中最前面的元素
    for (int i=1; i<n; i++) {
        ch = getchar();
        if(i>=k){
            tmp = tmp==s[j]?'0':'1';    //tmp排除掉k内最前面的字符
        }
        //tmp和当前输入字符异或得到当前值
        s[j] = ch==tmp?'0':'1';        //保存当前值
        tmp = s[j]==tmp?'0':'1';       //更新tmp值
        printf("%c",s[j]);
        j = (j+1)%k;                   //j后移到下一个最前
    }
    printf("\n");
    return 0;
}
