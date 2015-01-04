#include <iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct link
{
    int v;//vΪ�ڵ���
    link * next;
};
struct node
{
    int indegree;//���
    char element;
    struct link* firstedge;
};//ͷ���
struct Adgraph
{
    int n,e;
    struct node Ad[101];
};//�ڽӱ�
void create(struct Adgraph* G)
{
    int k,i,j;
    cin >> G->n >> G->e;//�ڵ�ͱ�
    for (k=1; k<=G->n; k++)
    {
        cin >> G->Ad[k].element;
        G->Ad[k].firstedge=NULL;
        G->Ad[k].indegree=0;
    }//ͷ���ĳ�ʼ��
    for(k=1; k<=G->e; k++)
    {
        cin >> j >> i;
        G->Ad[i].indegree++;
        link* p=new link;
        p->v=i;
        p->next=G->Ad[j].firstedge;
        G->Ad[j].firstedge=p;//�ڱ�ͷ����
    }
    for(i=1; i<=G->n; i++)
    {
        cout << G->Ad[i].element;
        link *m=G->Ad[i].firstedge;
        while(m!=NULL)
        {
            printf("->%c",G->Ad[m->v].element);
            m=m->next;
        }
        printf("->^\n");
    }//�ڽӱ��ӡ
    printf("\n");
}
void topsort(Adgraph* G)
{
    queue<int> Q;
    int x,count=0;
    for(int i=1; i<=G->n; i++)
        if(G->Ad[i].indegree==0) Q.push(i);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
//        cout << G->Ad[x].element;
        cout << x ;
        count++;
        link *m=G->Ad[x].firstedge;
        while(m!=NULL)
        {
            if((--G->Ad[m->v].indegree)==0) Q.push(m->v) ;
            m=m->next;
        }
    }
    if (count<G->n) cout<<"ͼ���л�·" << endl;
}
int main()
{
    struct Adgraph G;
    create(&G);
    topsort(&G);
    return 0;
}
//10 11
//a b c d e f g h i j
//1 10
//8 1
//9 8
//9 6
//6 7
//6 5
//5 2
//5 3
//4 5
//4 3
//4 2
