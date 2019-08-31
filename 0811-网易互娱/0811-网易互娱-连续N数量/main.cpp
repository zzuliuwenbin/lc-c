//
//  main.cpp
//  0811-网易互娱-连续N数量
//
//  Created by 刘文斌 on 2019/8/12.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//一串大写字母中，可以修改0-2个字母，使得连续的N的数量最大，返回最大值
//思路：把连续的非N多数量变成-n，连续的N多数量变成n,这样就转变成了正负相交替的整数，找出-2，-1的位置进行检测即可
//情况分类：0、边界条件：数组长度为1、2、3，可直接得出结论
//情况分类：1、开头和结尾的地方，如果是-1，-2，则加上他们挨着的正数，作为初始值
//情况分类：2、遍历一遍正数，如果值大于当前最大值或者前后有小于等于-3的负数，则更新，针对无法通过修改连接连个N串的情况
//情况分类：3、把开头和结尾的负数去掉（前面已处理），i从start+1到end-1（实际数组索引）进行走两步的遍历
//           如果当前值为-2，前后俩数和+2，如果大于最大值，更新最大值；
//           如果等于-1，前后俩数和+1，如果大于最大值，更新最大值；
//                 上述判断的基础上，如果i小于end-3（后面还有一个负数间隔的数），且后面的负数还等于-1，再累加最大值为最大值+1+后面的数
//输出最大值
//通过率0%
#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    for (int i=0;i<t;i++) {
        int k=0;char ch;
        int num[5000];
        int isN = 0,noN = 0;
        //把数据转为一串正负相间的整数
        while(1){
            while((ch = getchar())=='N'){ isN++; }
            if(isN>0){ num[k++]=isN; isN = 0; noN=-1;}
            if(ch=='\n'){ break; }
            
            while((ch = getchar())!='N'&&ch!='\n'){ noN--; }
            if(noN<0){ num[k++] = noN; noN = 0; isN = 1;}
            if(ch=='\n'){ break; }
        }
        int len = 0;
        //情况0，数组长度小于等于3的直接得出结论
        
        //情况1，检测开头结尾，初始化最大值
        
        //情况2，检测无法通过修改连接N串的情况
        
        //情况3，正常处理连接
        int start = num[0]>0?0:1;
        int end = num[k-1]>0?k-1:k-2;
        
        for(int i=start+1;i<end;i=i+2){
            if(num[i]<-2){
                continue;
            }
            if(num[i]==-2){//负二只能衔接一个串
                if(num[i-1]+num[i+1]>len){
                    len =num[i-1]+num[i+1];
                }
            }else{
                if(i<=end-3&&num[i+2]==-1){
                    if(num[i-1]+num[i+1]+num[i+3]>len){
                        len = num[i-1]+num[i+1]+num[i+3];
                    }
                }
            }
        }
        printf("%d\n",len+2);
    }
}
