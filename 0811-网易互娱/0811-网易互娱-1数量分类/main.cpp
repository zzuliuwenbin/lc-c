//
//  main.cpp
//  0811-网易互娱-1数量分类
//
//  Created by 刘文斌 on 2019/8/11.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//
#include <stdio.h>
int main(int argc, const char * argv[]) {
    int test[32];
    int clas[32];
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<32;i++){             //初始化按位与测试数组
        test[i]=1<<i;
    }
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        for(int c=0;c<32;c++){
            clas[c]=0;
        }
        int s=0;                        //1的数量计数
        for(int j=0;j<n;j++){
            int sum=0,tmp;
            scanf("%d",&tmp);
            for(int k=0;k<32;k++){
                if((tmp&test[k])>0){
                    sum++;
                }
            }
            if(clas[sum]==0){
                s++;
                clas[sum]=1;
            }
        }
        printf("%d\n",s);
    }
    return 0;
}
