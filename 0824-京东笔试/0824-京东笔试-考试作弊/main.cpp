//
//  main.cpp
//  0824-京东笔试-考试作弊
//
//  Created by 刘文斌 on 2019/8/24.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//通过率36%
//思路：500×500数组记录每个人的关系，bg[10001]记录每个人的关系数量
//每次从bg里面找最大值，剔除，把此人的关系删除，并把与ta有关系的人的关系数量对应减少1
//循环直到m为 0 停止

#include <stdio.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m,bg[10001]={0},tmp1,tmp2,out[500];//人数，关系数，每个人的关系数，剔除的人
    bool gx[501][501];//男生（行）和女生（列）的关系
    scanf("%d%d",&n,&m);
    for(int i=1;i<501;i++){
        for (int j=1; j<501; j++) {
            gx[i][j] = false;
        }
    }
    //把每个人的关系数量记录下来
    for(int i=0;i<m;i++){
        scanf("%d%d",&tmp1,&tmp2);
        bg[tmp1]++;bg[tmp2]++;
        if(tmp1>n){
            gx[tmp2][tmp1-n] = true;
        }else{
            gx[tmp1][tmp2-n] = true;
        }
    }
    //每次挑关系最多的人剔除，并记录剔除的人
    //更新关系数组，直到关系为空
    int p = 0;
    while(true){
        //找到拥有最大关系值的人
        int wz = 0,he = 0;
        for(int i=2*n;i>=1;i--){//倒序找，保证找到的是关系最大的，且序号最小的
            if(bg[i]>=he){//关系数量相同也更新
                wz = i;
                he = bg[i];
            }
        }
        out[p++] = wz;//记录要剔除的人编号
        //更新m，剩余的男女关系数量
        m = m - he;
        if(m<=0){//没有剩余了则输出
            //输出out
            printf("%d\n",p);
            for(int j=0;j<p;j++){
                int oo = 2*n+1;
                int ow = 501;
                for (int k=0; k<p; k++) {//找到最小的序号输出
                    if(out[k]<oo&&out[k]!=0){
                        oo = out[k];
                        ow = k;
                    }
                }
                out[ow] = 0;//已经输出的剔除
                printf("%d",oo);
                if(j<p-1){
                    printf(" ");
                }
            }
            printf("\n");
            break;
        }
        //更新关系表和关系数量表
        bg[wz] = 0;
        if(wz>n){//剔除的女生
            for(int j=1;j<=n;j++){
                if(gx[j][wz-n]==true){
                    bg[j]--;
                    gx[j][wz-n]=false;
                }
            }
        }else{//剔除的男生
            for(int j=1;j<=n;j++){
                if(gx[wz][j]==true){
                    bg[j+n]--;
                    gx[wz][j]=false;
                }
            }
        }
    }
    return 0;
}
