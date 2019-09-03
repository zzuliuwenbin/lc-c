//
//  main.cpp
//  0901-腾讯-多大宝箱数
//
//  Created by 刘文斌 on 2019/9/1.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    int result = 0;//结果
    int bxji = 0;
    int bxou = 0;
    int ysji = 0;
    int ysou = 0;
    int tmp;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        if(tmp%2==0){
            bxou++;
        }else{
            bxji++;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d",&tmp);
        if(tmp%2==0){
            ysou++;
        }else{
            ysji++;
        }
    }
    result = bxou>ysji?ysji:bxou;
    result = result + (bxji>ysou?ysou:bxji);
    printf("%d",result);
    return 0;
}
