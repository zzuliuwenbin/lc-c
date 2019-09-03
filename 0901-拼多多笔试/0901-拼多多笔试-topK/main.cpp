//
//  main.cpp
//  0901-拼多多笔试-topK
//
//  Created by 刘文斌 on 2019/9/1.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,x;
    int max = 0;
    float sz[51][51]={0};
    
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",x);
        max = x>max?x:max;
        for(int j=1;j<=x;j++){
            sz[i][j] = 1.0/x;
        }
    }
    for (int i=1; i<=max; i++) {
        int sum = 0;
        for(int j=1;j<=n;j++){
            if(sz[j][i]!=0){
                sum++;
            }
        }
        for(int j=1;j<=n;j++){
            sz[0][i] += sz[j][i];
        }
        sz[0][i] /=sum;
    }
    
    return 0;
}
