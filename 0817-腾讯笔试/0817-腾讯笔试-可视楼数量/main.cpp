//
//  main.cpp
//  0817-腾讯笔试-可视楼数量
//
//  Created by 刘文斌 on 2019/8/17.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    scanf("%d",&n);
    int * arr = (int * )malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for (int j=i; j<n; j++) {
            
        }
    }
    free(arr);
    return 0;
}
