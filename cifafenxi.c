#include <stdio.h>                  /*����I/O�����õ�ĳЩ��ͱ���*/
#include <string.h>                 /*�����ַ����⺯��*/
#include <conio.h>                  /*�ṩ�й���Ļ���ڲ�������*/
#include <ctype.h>                  /*���ຯ��*/
char prog[80],
     token[8];                     /*��Ź��ɵ��ʷ��ŵ��ַ���*/
char ch;
int syn,                           /*��ŵ����ַ����ֱ���*/
      n,
    sum,                           /*��������͵���*/
    m,p;                           /*p�ǻ�����prog��ָ�룬m��token��ָ��*/
char *rwtab[7]={"begin","end","if","then","else","while","do"};
void scaner(){
    m=0;ac
    sum=0;
    for(n=0;n<8;n++)
        token[n]=NULL;
    ch=prog[p++];
    while(ch==' ')
        ch=prog[p++];
    if(isalpha(ch))    /*chΪ��ĸ�ַ�*/{
        while(isalpha(ch)||isdigit(ch))    /*ch Ϊ��ĸ�ַ����������ַ�*/{
           token[m++]=ch;
           ch=prog[p++];}
        token[m++]='\0';
        ch=prog[p--];
        syn=10;
        for(n=0;n<6;n++)
            if(strcmp(token,rwtab[n])==0)    /*�ַ����ıȽ�*/{
                syn=n+1;
                break;}}
    else
        if(isdigit(ch))    /*ch�������ַ�*/{
            while(isdigit(ch))    /*ch�������ַ�*/{
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
