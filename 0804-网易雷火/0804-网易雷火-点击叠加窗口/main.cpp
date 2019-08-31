//
//  main.cpp
//  0804-网易雷火-点击叠加窗口
//
//  Created by 刘文斌 on 2019/8/4.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//提交：测试用例通过率100%

#include <stdio.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    int w,h;                    //临时存放宽高
    int x,y;                    //点击的坐标
    int index[1000];            //窗口层次
    int windows[1000][4];       //窗口，存放实际坐标
    scanf("%d%d",&n,&m);
    for (int i=0;i<n ; i++) {
        scanf("%d%d%d%d",&windows[i][0],&windows[i][1],&w,&h);
        windows[i][2] = windows[i][0]+w;
        windows[i][3] = windows[i][1]+h;
        index[i] = n-i-1;
    }
    //printf("here1");
    for (int j=0;j<m ; j++) {
        //printf("here2");
        scanf("%d%d",&x,&y);
        //检测点中的窗口，并输出
        int k;
        //按照index的顺序遍历窗口
        for (k=0; k<n; k++) {
            int c = index[k];
            //printf("%d,%d\t",k,c);
            if(x>=windows[c][0]&&x<=windows[c][2]&&y>=windows[c][1]&&y<=windows[c][3]){//命中
                printf("%d\n",c+1);//窗口从一开始计数
                break;
            }
        }
        //printf("k=%d\n",k);
        //更新窗口层次
        if(k==n){//未命中
            printf("-1\n");
        }else{//
            int temp = index[k];
            for(int t=k;t>0;t--){
                index[t] = index[t-1];
            }
            index[0] = temp;
        }
    }
    return 0;
}

