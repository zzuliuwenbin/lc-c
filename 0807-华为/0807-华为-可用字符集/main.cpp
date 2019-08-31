//
//  main.cpp
//  0807-华为-可用字符集
//
//  Created by 刘文斌 on 2019/8/7.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int set[60]={0};
    int index[60];
    char ch;int num,k=0;
    while(1){
        scanf("%c:%d",&ch,&num);
        set[ch-'A'] = num;              //记录字符个数
        index[k++] = ch-'A';            //记录输入顺序
        ch = getchar();
        if(ch=='@'){
            break;
        }
    }
    int t;
    while(1){
        t = scanf("%c:%d",&ch,&num);
        if(t!=2){                       //输入终止，@后面没有字符的情况
            break;
        }
        set[ch-'A'] -= num;             //更新剩余字符数量
        ch = getchar();
        if(ch=='\n'){                   //输入终止
            break;
        }
    }
    int n=0;                            //剩余字符数量
    //一共k个字符，循环k次即可
    for (int i=0; i<k; i++) {           //两次循环，方便输出逗号以及回车
        if(set[index[i]]>0){
           n++;
        }
    }
    
    int j=0;                            //方便最后一个输出
    
    for (int i=0; i<k; i++) {           //前n-1个带逗号
        if(n<=1){
            break;
        }
        if(set[index[i]]>0){
            printf("%c:%d,",index[i]+'A',set[index[i]]);
            n--;
        }
        j=i;                            //记录当前进行的位置
    }
    if(n==1){
        for (int i=j+1; i<k; i++) {       //第n个是换行
            if(set[index[i]]>0){
                printf("%c:%d\n",index[i]+'A',set[index[i]]);
                break;                      //只有一个
            }
        }
    }else{
        printf("\n");//无剩余
    }
    return 0;
}
