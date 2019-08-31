//
//  main.cpp
//  0811-字节跳动-奖金发放
//
//  Created by 刘文斌 on 2019/8/11.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 0;//人数
    int y[1000] = {0};//入职年限
    int s[1000] = {0};//每人应发的薪酬
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&y[i]);
        s[i] = 100;//每人至少发100；
    }
    for (int i=0; i<n-1; i++) {
        if(y[i]<y[i+1]){//满足i向右问，只要年限大，就在原有基础上加100
            s[i+1] = s[i]+100;
        }
    }
    for (int i=n-2; i>=0; i--) {//检查i向左问
        if(y[i]>y[i+1]&&s[i]<s[i+1]+100){//奖金前面更新了，不能直接加，不满足大于100的才更新
            s[i] = s[i+1]+100;
        }
    }
    for (int i=1; i<n; i++) {
        s[0]+=s[i];
    }
    printf("%d\n",s[0]);
    return 0;
}

