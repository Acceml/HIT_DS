#include <iostream>
#include<cstring>
#include<cstdio>
#define inf 1000
using namespace std;
struct graph
{
    int n,e;
    int mat[101][101];
};
struct graph  C;
void setgraph()
{
    int m,n,x;
    cin >> C.n >> C.e;
    for(int i=1; i<=C.n; i++)
        for(int j=1; j<=C.n; j++)
            C.mat[i][j]= inf;
    for(int i=1; i<=C.e; i++)
    {
        cin >> m >> n >> x;
        C.mat[m][n]=x;
        C.mat[n][m]=x;
    }//����ͼ
}
int prim()
{
    bool  visited[101];//����Ƿ���ʹ�
    int  p,i,j,ans=0,minw;//p���ڱ�ǵ�ǰ��С��Ȩֵ���ֵ�λ��,ansΪȨֵ,minwΪ��ǰ��С��Ȩֵ
    int low[101];//��ÿ�������СȨֵ
    memset(visited,false,sizeof(visited));
    visited[1]=true,p=1;
    for(i=2; i<=C.n; i++)
        low[i]=C.mat[p][i];
    //��ʼ��ʱ��ѡ�е�һ�����㣬��СȨֵ��Ϊ��һ�����㵽��������ľ���
    for(i=1; i<C.n; i++)
    {
        minw=inf;
        for(j=1; j<=C.n; j++)
            if(!visited[j]&&minw>low[j])
            {
                minw=low[j];
                p=j;
            }//�ҳ���СȨֵ�ĵ�
        visited[p]=true;//��������
        ans+=minw;
        for(j=1; j<=C.n; j++)
            if(!visited[j]&&low[j]>C.mat[p][j])
                low[j]=C.mat[p][j];
    }
    //����n-1�θ��£�������n��
    return ans;
}
int main()
{
    setgraph();
    cout << prim() << endl;
    return 0;
}


