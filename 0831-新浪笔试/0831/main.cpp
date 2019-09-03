//
//  main.cpp
//  0831
//
//  Created by 刘文斌 on 2019/8/31.
//  Copyright © 2019 刘文斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,k;
    scanf("%d%d",&n,&k);
    int * arr = (int *)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    int count=0;
    for (int i=0; i<n-1; i++) {
        for(int j=n-i+1;j<n;j++){
            if(arr[i]-arr[j]<=k||arr[j]-arr[i]<=k){
                count++;
            }else{
                continue;
            }
        }
    }
    printf("%d",count);
    return 0;
}

