//
//  main.cpp
//  积木表面积计算
//
//  Created by 刘文斌 on 2019/8/20.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//输入m，n表示区域大小，然后输入m*n个数，表示每个位置叠加的大小为1³的方块数量
//求方块的总表面积

//思路 从1到m分别求出叠加的每一行的表面积，从1到n分别求出叠加的列的表面积
//总的表面积减去叠加部分的二倍，既是结果
#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n,m;
    int arr[1000][1000]={0};
    scanf("%d%d",&n,&m);
    int z = 0;
    for(int i=0;i<n;i++){
        for (int j=0; j<m; j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0){
                z = z + arr[i][j] * 4 + 2;//总表面积
            }
        }
    }
    //计算行重叠部分表面积总和
    int cd = 0,tmp;
    for(int i=0;i<n-1;i++){
        for (int j=0; j<m; j++) {
            tmp = arr[i][j]<arr[i+1][j]?arr[i][j]:arr[i+1][j];
            cd += tmp;
        }
    }
    //计算列重叠部分总和
    for(int j=0;j<m-1;j++){
        for (int i=0; i<n; i++) {
            tmp = arr[i][j]<arr[i][j+1]?arr[i][j]:arr[i][j+1];
            cd += tmp;
        }
    }
    printf("%d\n",z-cd*2);
    return 0;
}
