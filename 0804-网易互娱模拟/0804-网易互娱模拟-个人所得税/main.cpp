//
//  main.cpp
//  0804-网易互娱模拟-个人所得税
//  计算个人所得税，现行税法
//
//  Created by 刘文斌 on 2019/8/4.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//提交：测试用例通过率100%

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int m,n;
    float f=0.0f;
    scanf("%d",&m);
    for (int i=0; i<m ; i++) {
        scanf("%d",&n);
        if(n<=5000){
            f = 0;
        }else{
            n = n-5000;
            if(n>80000){
                f = (n-80000)*0.45+20840;
            }else if(n>55000){
                f = (n-55000)*0.35+12090;
            }else if(n>35000){
                f = (n-35000)*0.3+6090;
            }else if(n>25000){
                f = (n-25000)*0.25+3590;
            }else if(n>12000){
                f = (n-12000)*0.2+990;
            }else if(n>3000){
                f = (n-3000)*0.1+90;
            }else{
                f = n*0.03;
            }
        }
        printf("%d\n",int(f+0.5f));
    }
    return 0;
}

