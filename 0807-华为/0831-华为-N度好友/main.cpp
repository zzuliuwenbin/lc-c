//
//  main.cpp
//  0831-华为-N度好友
//
//  Created by 刘文斌 on 2019/8/31.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int t,m,i,n;
    scanf("%d",&t);
    for(int c=0;c<t;c++){//t组测试用例
        int gx=0;       //输入关系数量
        int fw[50]={0}; //是否已访问的表
        int r[50][50];  //好友关系表
        int result[51]; //n度好友的id存放表,0号表示数量
        int resulttmp[51];//临时存放n度好友,0号表示数量
        int tuijianzhi[50]={0};//关系推荐值
        int outarr[50]= {0};
        scanf("%d%d%d",&m,&i,&n);
        scanf("%d",&gx);
        if(n>=m||i>=m||gx==0){
            printf("-1\n");
            continue;
        }
        int t1,t2,t3;
        for(int j=0;j<m;j++){//初始化数组
            fw[j] = 0;
            result[j] = 0;
            tuijianzhi[j] = 0;
            outarr[j] = 0;
            for(int ttt=0;ttt<m;ttt++){
                r[j][ttt] = 0;
            }
        }
        for(int j=0;j<gx;j++){
            scanf("%d%d%d",&t1,&t2,&t3);
            r[t1][t2] = t3;
            r[t2][t1] = t3;
        }
        
        //广度优先遍历查找N度好友
        result[0] = 1;result[1]=i;fw[i]=1;
        for(int j=0;j<n;j++){
            resulttmp[0] = 0;//j+1度好友初始数量
            for(int q=1;q<=result[0];q++){
                int dq = result[q];//当前查找的人
                //printf("当前查找的人%d\n",dq);
                for(int p=0;p<m;p++){//查找全部j+1度好友
                    if(r[dq][p]>0&&fw[p]==0){//有关系且未访问
                        resulttmp[0]++;
                        resulttmp[resulttmp[0]] = p;//新的j+1度好友
                        tuijianzhi[p] = tuijianzhi[p]+r[dq][p];
                        fw[p] = 1;
                        //printf("%d度好友：%d\n",j+1,p);
                    }
                }
            }
            //所有j+1度好友找到后，把id搬到result里面
            for(int q=0;q<=resulttmp[0];q++){
                result[q] = resulttmp[q];
            }
        }
        
        //按推荐值降序，id升序输出
        if(result[0]==0){
            printf("-1\n");
        }else{
            for (int p = 1; p<=result[0]; p++) {
                outarr[result[p]]=tuijianzhi[result[p]];
            }
            for (int pp = 0; pp<result[0]; pp++) {//n度好友数量
                int tjz = 0,wz = -1;
                for (int p = m-1; p>=0; p--) {//找推荐值最大的id
                    if(outarr[p]!=0&&outarr[p]>=tjz){
                        tjz = outarr[p];
                        wz = p;
                    }
                }
                printf("%d ",wz);
                outarr[wz] = 0;
            }
            printf("\n");
        }
    }
    return 0;
}
