//
//  main.cpp
//  0811-字节跳动
//
//  Created by 刘文斌 on 2019/8/11.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//给定n组闹钟（时，分），起床到教室时间x（分），上课时间（时，分），求n组闹钟里面最晚起床时间
//通过率80%
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int naoz[100][2];//闹钟
    int x;
    int s,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&naoz[i][0],&naoz[i][1]);
    }
    scanf("%d",&x);
    scanf("%d%d",&a,&b);
    s = a*60+b; //上课时间分钟数
    s = s-x;    //最晚闹钟分钟数
    int tmp=-1;
    for(int i=0;i<n;i++){
        if(naoz[i][0]*60+naoz[i][1]<=s){//满足不迟到
            if(naoz[i][0]*60+naoz[i][1]>tmp){//满足更晚
                tmp = naoz[i][0]*60+naoz[i][1];
            }
        }
    }
    printf("%d %d\n",tmp/60,tmp%60);
    return 0;
}
