//
//  main.cpp
//  0804-网易互娱模拟-字符串缩写
//  给定由大写字母组成的串，如果有连续大于等于四个是升序的，如ABCDE，则缩写为A-E，其它原样输出
//  Created by 刘文斌 on 2019/8/4.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//提交：测试用例通过率100%

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int t,k,p;
    char ch,s[26];
    scanf("%d",&t);
    getchar();                                  //回车
    for (int i=0; i<t; i++) {
        k = 0;
        s[k] = getchar();                       //放入一个字符
        while((ch = getchar())!='\n'){
            if(ch==s[k]+1){                     //连接的上则入库
                k++;
                s[k] = ch;
            }else{                              //连接不上则出库
                if(k>=3){                       //库中如果已经可以缩写则缩写
                    putchar(s[0]);
                    putchar('-');
                    putchar(s[k]);
                }else{                          //不能缩写原样输出
                    p = 0;
                    while(p<=k){
                        putchar(s[p++]);
                    }
                }
                k = 0;                          //重新开始新的一轮探测
                s[k] = ch;
            }
        }
        //这种边界条件遇到很多次，值得思考，while循环结束条件导致库存被忽略。
        if(k>=3){                               //把滞留在库中的输出
            putchar(s[0]);
            putchar('-');
            putchar(s[k]);
        }else{                                  //不能缩写原样输出
            p = 0;
            while(p<=k){
                putchar(s[p++]);
            }
        }
        putchar('\n');
        
    }
    return 0;
}

