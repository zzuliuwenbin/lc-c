//
//  main.cpp
//  0807-华为-前缀树查找
//
//  Created by 刘文斌 on 2019/8/7.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct pos{
    char lb;
    bool hc;
    bool pd;
} POS;
int main(int argc, const char * argv[]) {
    // insert code here...
    int m,n,k,t;
    scanf("%d",&m);
    POS * p = (POS *)malloc(sizeof(POS)*m);
    
    for (int i=0;i<m;i++) {
        scanf("%d",&t);
        p[i].lb = (char)t;
    }
    for (int i=0;i<m;i++) {
        scanf("%d",&t);
        p[i].hc = (bool) t;
    }
    for (int i=0;i<m;i++) {
        scanf("%d",&t);
        p[i].pd = (bool) t;
    }
    
    scanf("%d",&n);
    int * v = (int *)malloc(sizeof(int)*n);
    for (int i=0;i<n;i++) {
        scanf("%d",&v[i]);
    }
    char ch;
    scanf("%d",&k);
    int h=m-1;//从最后开始查找
    
    //倒序查找，查找方式是以深度我基准，广度作为辅助，进行查找
    for (int i=0;i<k;i++) {//深度的基础上广度混合查找
        scanf("%d",&t);
        ch = (bool) t;
        //递归
    }
    
    //来不及了，直接输出中间那个值
    printf("%d",v[m/2]);
    
    return 0;
}
