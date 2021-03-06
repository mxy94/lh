#include <stdio.h>                  /*定义I/O库所用的某些宏和变量*/
#include <string.h>                 /*定义字符串库函数*/
#include <conio.h>                  /*提供有关屏幕窗口操作函数*/
#include <ctype.h>                  /*分类函数*/
char prog[80],
     token[8];                     /*存放构成单词符号的字符串*/
char ch;
int syn,                           /*存放单词字符的种别码*/
      n,
    sum,                           /*存放整数型单词*/
    m,p;                           /*p是缓冲区prog的指针，m是token的指针*/
char *rwtab[7]={"begin","end","if","then","else","while","do"};
void scaner(){
    m=0;ac
    sum=0;
    for(n=0;n<8;n++)
        token[n]=NULL;
    ch=prog[p++];
    while(ch==' ')
        ch=prog[p++];
    if(isalpha(ch))    /*ch为字母字符*/{
        while(isalpha(ch)||isdigit(ch))    /*ch 为字母字符或者数字字符*/{
           token[m++]=ch;
           ch=prog[p++];}
        token[m++]='\0';
        ch=prog[p--];
        syn=10;
        for(n=0;n<6;n++)
            if(strcmp(token,rwtab[n])==0)    /*字符串的比较*/{
                syn=n+1;
                break;}}
    else
        if(isdigit(ch))    /*ch是数字字符*/{
            while(isdigit(ch))    /*ch是数字字符*/{
                sum=sum*10+ch-'0';
                ch=prog[p++];}
            ch=prog[p--];
            syn=11;}
        else
            switch(ch){
                case'<':m=0;token[m++]=ch;ch=prog[p++];
                        if(ch=='>'){
                            syn=18;
                            token[m++]=ch;}
                        else if(ch=='='){
                            syn=17;
                            token[m++]=ch;}
                            else{
                                 syn=19;
                                 ch=prog[p--];}
                        break;
                case'>':m=0;token[m++]=ch;ch=prog[p++];
                        if(ch=='='){
                            syn=24;
                            token[m++]=ch;}
                        else{
                            syn=23;
                            ch=prog[p--];}
                        break;
             case':':m=0;token[m++]=ch;ch=prog[p++];
                     if(ch=='='){
                         syn=22;
                         token[m++]=ch;}
                     else{
                         syn=21;
                         ch=prog[p--];}
                     break;
             case'+':syn=13;token[0]=ch;break;
             case'-':syn=14;token[0]=ch;break;
             case'*':syn=15;token[0]=ch;break;
             case'/':syn=16;token[0]=ch;break;
             case';':syn=23;token[0]=ch;break;
             case'#':syn=0;token[0]=ch;break;
             default:syn=-1;}}
void main()
{

    p=0;
    printf("please input string:\n");
    do {
           ch=getchar();
           prog[p++]=ch;
       }while(ch!='#');

    p=0;
    do{
        scaner();
        switch(syn){
            case 11: printf("(%d,%d)\n",syn,sum);break;
            case -1: printf("INPUT ERROR;\n");break;
            default: printf("(%d,%s)\n",syn,token);
}
     }while(syn!=0);
    getch();
}
