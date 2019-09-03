//
//  main.cpp
//  0831-华为-二进制比特出现次数
//
//  Created by 刘文斌 on 2019/8/31.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int k=-1,sum = 0;
    int num;
    scanf("%d",&num);
    int bt[32],ad = 1;
    for(int i=31;i>=0;i--){
        if((num&ad)==0){
            bt[i] = 0;
        }else{
            bt[i] = 1;
        }
        ad = ad<<1;
    }
    for(int i=31;i>=2;i--){
        if(bt[i]==1&&bt[i-1]==0&&bt[i-2]==1){
            sum++;
            if(k==-1){
                k = 31-i;
            }
        }
    }
    printf("%d %d\n",sum,k);
    return 0;
}
