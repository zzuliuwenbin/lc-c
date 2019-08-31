//
//  main.cpp
//  0804-网易雷火-图文混排
//
//  Created by 刘文斌 on 2019/8/4.
//  Copyright © 2019 刘文斌. All rights reserved.
//

//提交：测试用例通过率0%，可能有细节错误

#include <stdio.h>
#include <string.h>
//全局的方便使用
int W,XE,YE,XC,YC,PX,PY;        //全局常量值
int XY[20][2];                  //表情包的长宽
char input[10000];              //输入的字符串
int x=0,y=0;                    //当前坐标
long len;                       //输入字符串的长度
char ch;                        //临时存储判断
int high=0;                     //当前行高


//把s十六进制的两位转换ASCII
char chtoASC(char a,char b){
    if(a=='\n'||a==0){
        return -1;//预读时字符串已经结束了
    }
    char ia,ib;
    
    if(a>'9'){
        ia = a - 55;
    }else{
        ia = a - 48;
    }
    if(b>'9'){
        ib = b - 55;
    }else{
        ib = b - 48;
    }
    return ia*16+ib;
}


//从x，y的位置放一个宽k,高g的符号
void move(int k,int g){
    //宽度是否够
    if(x+PX+k<W){//宽度足够，更新宽和高
        x = x+PX+k;
        if(g>high){//高度不够，把差距补上
            y = y+g-high;
        }
        
    }else{//宽度不够，换行更新，行前不用留PX
        y = y+PY+g; //更新高度
        x = k;      //更新宽度
        high = g;   //当前行高
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d%d%d%d%d%d%d",&W,&XE,&YE,&XC,&YC,&PX,&PY);
    for(int i=0;i<20;i++){
        scanf("%d%d",&XY[i][0],&XY[i][1]);
    }
    getchar();
    gets(input);
    len = strlen(input);
    char t1,t2;//用于预读
    for(int i=0;i<len;i=i+2){
        ch = chtoASC(input[i], input[i+1]);
        if(ch=='#'){//“#”井号
            t1 = chtoASC(input[i+2], input[i+3]);//预读
            if(t1==-1){//字符#，英文字符，不用处理
                move(XE,YE);
                break;
            }else if(t1 == '#'){//##处理,英文符号，i移动一对
                move(XE,YE);i=i+2;
            }else if(t1=='r'){//#r处理,x回到0，y根据是否换行在开头确定变化,i移动一对
                if(x==0){
                    y=y+YE+PY;  //行间距+英文字符宽度
                }else{
                    y=y+PY;     //移动到相当于0，0的位置，后面的字符会处理好行高
                }
                high = 0;       //后面的数据按需进行扩展高度
                x=0;
                i=i+2;
            }else if(t1=='1'){//#1x处理
                t2 = chtoASC(input[i+4], input[i+5]);//预读
                if(t2==-1){//表情包#1,i移动一对
                    move(XY[1][0],XY[1][1]);i=i+2;
                }else{
                    if(t2>='0'&&t2<='9'){//某个表情包#1x,i移动两对
                        move(XY[t2-'0'+10][0],XY[t2-'0'+10][1]);i=i+4;
                    }else{//表情包#1,后面的是不合适的字符，i移动一对，后面的交给下一次循环
                        move(XY[1][0],XY[1][1]);i=i+2;
                    }
                }
            }else if(t1>='0'&&t1<='9'){//某个表情包#x，i移动一对
                move(XY[t1-'0'][0],XY[t1-'0'][1]);i=i+2;
            }else{//不正常的输入，处理掉井号，字符留给下一个循环，一个#，i交给for移动
                move(XE,YE);
            }
        }else if(ch<128){//英文
            move(XE,YE);
        }else{//其它按照中文符号处理，中文占用三个字节，移动两对
            move(XC,YC);i=i+4;
        }
    }
    printf("%d %d",x,y);
    return 0;
}
