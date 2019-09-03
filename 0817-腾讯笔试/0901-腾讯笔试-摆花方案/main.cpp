//
//  main.cpp
//  0901-腾讯笔试-摆花方案
//
//  Created by 刘文斌 on 2019/9/1.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>
int C(int a,int b) {
    if(a==0){
        return 1;
    }
    long long t1 = 1, t2 = 1;
    for(int i=b,j=1;i>b-a;i--) {
        t1 = t1*i;t2 = t2*j;j++;
        if(t1%t2==0) {//计算到结尾再求结果会溢出，用t1如果用int，在第43个测试用例时依旧溢出了
            t1 = t1/t2;
            t2 = 1;
        }
    }
    return (int)(t1/t2);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t,k;
    int a,b,h,max;
    scanf("%d%d",&t,&k);
    for (int i=0; i<t; i++) {
        int result = 0;
        scanf("%d%d",&a,&b);
        if(k==0){
            for(int tt=a;tt<=b;tt++){
                int jc = 1;
                for(int j=1;j<=tt;j++){
                    jc = (jc * j)%1000000007;
                }
                result = (result+jc)%1000000007;
            }
            printf("%d\n",result);
            continue;
        }
        if(a<k){
            result = k-a;//小于k的都只能是红花
            a = k;//k之前的不需要查找
        }
        for (int j=a; j<=b; j++) {
            max = j/k;//最大白花组数
            for(int p = 0;p<=max;p++){//每一种白花情况，求组合数
                h = j - p*k;
                result = (result + C(h,p+h))%1000000007;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
