//
//  main.cpp
//  Test
//
//  Created by 刘文斌 on 2019/8/9.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

int m,n;
char ** a;

int dg(int i,int j){
    int sum=0;
    a[i][j]='2';//已访问
    
    //探测临接节点
    if(i-1>=0&&a[i-1][j]=='1'){    sum +=dg(i-1,j)+1;}            //上
    if(i+1< m&&a[i+1][j]=='1'){    sum +=dg(i+1,j)+1;}            //下
    if(j-1>=0&&a[i][j-1]=='1'){    sum +=dg(i,j-1)+1;}            //左
    if(j+1< n&&a[i][j+1]=='1'){    sum +=dg(i,j+1)+1;}            //右
    
    if(i-1>=0&&j-1>=0&&a[i-1][j-1]=='1'){    sum +=dg(i-1,j-1)+1;}            //左上
    if(i-1>=0&&j+1< n&&a[i-1][j+1]=='1'){    sum +=dg(i-1,j+1)+1;}            //右上
    if(i+1< m&&j+1< n&&a[i+1][j+1]=='1'){    sum +=dg(i+1,j+1)+1;}            //右下
    if(i+1< m&&j-1>=0&&a[i+1][j-1]=='1'){    sum +=dg(i+1,j-1)+1;}            //左下
    
    return sum;
}

int main(){
    int max = 0,sum = 0,tmp = 0;            //max团最大值，sum团数量
    scanf("%d%d",&m,&n);getchar();
    
    //分配空间
    a = (char **)malloc(sizeof(char*)*m);
    for(int i=0 ;i<m ;i++){ a[i] = (char *)malloc(sizeof(char)*n); }
    
    //输入数据
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){ a[i][j] = (char)getchar(); getchar(); }
    }
    
    //深度递归
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='1'){                   //找到一个新团
                sum = sum + 1;                  //团数量更新
                tmp = dg(i,j)+1;                //以当前未访问的点进行扩展
                max = tmp>max?tmp:max;          //更新最大团数量
            }
        }
    }
    
    //输出结果
    printf("%d,%d",sum,max);
    
    //释放空间
    for(int i=0;i<m;i++){free(a[i]); }
    free(a);
    return 0;
}



