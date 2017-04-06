#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define N 10000

struct point
{
    double x,y;
};

point node[N * 2];
point d[N];
point c[N];
point b[N];
int compare(point a, point b)       //�Ƚ�����֮���yֵ
{
    return a.y < b.y;
}
int compare1(point a, point b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
double min(double a, double b)  //��a��b���߽�Сֵ
{
    return a > b? b:a;
}

double dx(double x1, double x2)
{
    if((x1 - x2) > eps && (x1 - x2) < eps)
    {
        return 0;
    }
    else if(x1 > x2)
    {
        return x1 - x2;
    }
    else if(x1 < x2)
    {
        return x2 - x1;
    }
}

double ds(point a, point b)     //������֮��ľ���
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
/**
* ���������
* ���������
* 1.���Ӽ�S1��
* 2.���Լ�S2��
* 3.�����������ֱ����Ӽ�S1��S2��
*/
double closestPoints(point node[], int n)
{
    int i, j;
    int Dist = 99999;       //�������
    if(n < 2)                //ֻ��һ���㣬�����������
        return 0;
    int m = (n - 1) / 2;    //m�Ǹ����������λ��
    for(i = m + 1; i < n; i++)
    {
        b[i].x = node[i].x;
        b[i].y = node[i].y;
    }
    //����Ϊ���������⣬�ݹ����������
    double d1 = closestPoints(node, m + 1);     //�õ�S1�е��������d1
    double d2 = closestPoints(b, n - m - 1);    //�õ�S2�е��������d2
    double dm = min(d1, d2);                    //���d1��d2����֮���Сֵ
    int f,p;        //��¼��ĸ���
    p = 0;
    for(i = 0; i <= m; i++)              //�ҳ�S1����x=m�ľ���С��dm�����е㣬�����ڽṹ��c����
    {
        if(dx(node[i].x,node[m].x) < dm)
        {
            c[p].x = node[i].x;
            c[p].y = node[i].y;
            p++;
        }
    }
    f=0;
    for(i = m + 1; i < n; i++)           //�ҳ�S2����x=m�ľ���С��dm�����е㣬�����ڽṹ��d����
    {
        if(dx(node[i].x, node[m].x) < dm)
        {
            d[f].x = node[i].x;
            d[f].y = node[i].y;
            f++;
        }
    }

    sort(c, c+p,compare);   //����y�������ֵ��������
    sort(d, d+f,compare);
    double ret = Dist;
    for(i = 0; i < p; i++)       //�����ȽϷֱ���S1��S2������֮��ľ���
    {
        for(j = 0; j < f; j++)
        {
            double ans = ds(c[i], d[j]);
            ret = min(ret, ans);        //�ó�����Ծ���
        }
    }
    return min(ret, dm);        //���ص�����������ǰ�������ν�Сֵ
}
int main(void)
{
    int n,i;
    for(int w=0;w<6;w++)
    {
        cout<<"�����������Ŀ��"<<endl;
        cin>>n;
        srand((unsigned)time(NULL));
        for(i=0;i<n;i++)
        {
            node[i].x=rand()/(double)(RAND_MAX/10000);
            node[i].y=rand()/(double)(RAND_MAX/10000);
        }
        sort(node,node+n,compare);
        clock_t start,end;
        start=clock();
        closestPoints(node,n);               //ϵͳ����ʮ�η��η�������
        closestPoints(node,n);
        closestPoints(node,n);
        closestPoints(node,n);
        closestPoints(node,n);
        closestPoints(node,n);
        closestPoints(node,n);
        closestPoints(node,n);
        closestPoints(node,n);
        closestPoints(node,n);
        end=clock();
        cout<<"���η����������ʱΪ"<<double(end-start)/CLOCKS_PER_SEC<<"ms"<<endl;

    }
    system("pause");
    return 0;
}
