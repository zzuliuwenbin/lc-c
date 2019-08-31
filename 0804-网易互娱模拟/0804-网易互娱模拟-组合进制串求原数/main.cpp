//
//  main.cpp
//  0804-网易互娱模拟-组合进制串求原数
//  给定俩进制x，y（2到16进制）和一个字符串，字符串是某个数的x，y进制无缝拼接成的
//  求这个数
//
//  Created by 刘文斌 on 2019/8/6.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//提交：测试用例通过率100%

#include <stdio.h>
#include <string.h>
int data[17][32];//方便快速计算n进制

void init(){
    long long int f;
    for(int i=2;i<17;i++){
        f = 1;
        for(int j=1;;j++){
            data[i][j] = (int)f;
            f = f*i;
            if(f>2147483647){
                break;
            }
        }
    }
}

char chtoint(char a){
    int d = 0;
    if(a>'9'){
        d = a - 55;
    }else{
        d = a - 48;
    }
    return d;
}

//把字符串的值计算出来
int compute(char * s,int start,int end,int x){
    int result = 0;
    int k = 1;
    for (int i=end; i>=start; i--,k++) {
        result = result + chtoint(s[i])*data[x][k];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int t,x,y,p,len;
    char s[64];
    init();
    scanf("%d",&t);
    getchar();
    for (int i=0; i<t; i++) {
        scanf("%d%d%s",&x,&y,s);
        len = (int)strlen(s)-1;
        int t1 = 0,t2 = 0,k=0;
        k = x<y?1:-1;       //循环进行的方向
        p = len/2;
        while(p<=len&&p>=0){
            t1 = compute(s, 0, p, x);
            t2 = compute(s, p+1, len, y);
            if(t1==t2){     //必有结果
                printf("%d\n",t1);
                break;
            }
            p = p + k;
        }
    }
    return 0;
}
