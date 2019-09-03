//
//  main.cpp
//  0831-新浪笔试
//
//  Created by 刘文斌 on 2019/8/31.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//topN
int topN(int * arr,int * tmp,int m,int k,int a,int b){
    int result = 0;
    if(m>k){
        for(int i=a;i<=b;i++){
            result = result + arr[i];
        }
        return result;
    }
    for(int i=a,j=0;i<=b;i++){
        tmp[j++] = arr[i];
    }
    
    for(int i=0;i<m;i++){//找出前m个数
        int p = 0,t=0;
        for(int j=0;j<=k;j++){
            if(tmp[j]>p){
                p = tmp[j];
                t = j;
            }
        }
        result += p;
        tmp[t] = 0;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int * arr = (int *)malloc(sizeof(int)*n);
    int * tmp = (int *)malloc(sizeof(int)*k);
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    int result = 0;
    //以k为窗口大小进行滑动
    for (int i=0; i<n-k; i++) {
         //每次滑动取top（m)的和，更新结果
        int sum = topN(arr,tmp,m,k,i,i+k);
        if(sum>result){
            result = sum;
        }
    }
    //输出结果
    printf("%d\n",result);
    return 0;
}


