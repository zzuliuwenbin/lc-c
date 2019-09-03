//
//  main.cpp
//  0901-腾讯笔试-学习状态评分
//
//  Created by 刘文斌 on 2019/9/1.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int w[100000];
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&w[i]);
    }
    long long max = 0;//最大评分
    for(int i=0;i<n;i++){
        long long sum = 0,min = 1000000;
        for (int j=i+1; j<n; j++) {
            if(w[j]<min){
                min = w[j];
            }
            sum += w[j];
            if(sum * min>max){
                max = sum * min;
            }
        }
    }
    printf("%lld",max);
    return 0;
}
