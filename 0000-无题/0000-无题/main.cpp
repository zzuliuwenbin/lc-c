//
//  main.cpp
//  0000-无题
//
//  Created by 刘文斌 on 2019/8/12.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>
int funcmax(int i,int j,int k)//求最大值
{
    if(i >= j && i >= k)
        return i;
    if(j >= i && j >= k)
        return j;
    return k;
}
int funcmin(int i,int j,int k)//求最小值
{
    if(i <= j && i <= k)
        return i;
    if(j <= i && j <= k)
        return j;
    return k;
}
int main(int argc, const char * argv[]) {
    int c,t;//测试用例,角色数量
    int role[1000];
    scanf("%d",&c);
    for(int i=0;i<c;i++){
        scanf("%d",&t);
        for(int j=0;j<t;j++){
            scanf("%d",&role[j]);
        }
        if(t<3){
            printf("0\n");
            continue;
        }
        int a=0,b=1,c=2,sum=0;
        while(a<t&&b<t&&c<t){
            int tmpsum = role[a] + role[b] + role[c];
            //找到三个里面最小的，sum累加上去
            int min = funcmin(role[a],role[b],role[c]);
            sum = sum + min;
            //找到三个里面最大的，放到c的位置
            int max = funcmax(role[a],role[b],role[c]);
            role[c] = max - min;
            //把另一个数放到b的位置
            role[b] = tmpsum - max - min - min;
            //a，b，c分别加一
            a++;b++;c++;
        }
        printf("%d\n",sum);
    }
    
    
    return 0;
}
