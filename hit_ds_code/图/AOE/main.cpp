//Topsort And AOE
#include <iostream>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;
struct link
{
    int v;//�¼����
    int count;//��ı��
    int weight;//���ʱ��
    link * next;
};
struct node
{
    int indegree;//���
    char element;//�¼�
    struct link* firstedge;
};//ͷ���
struct Adgraph
{
    int n,e;
    struct node Ad[101];
};//�ڽӱ�
void Create_AOE(struct Adgraph* G)
{
    int k,i,j,t;
    cin >> G->n >> G->e;//�ڵ�ͱ�
    for (k=1; k<=G->n; k++)
    {
        cin >> G->Ad[k].element;
        G->Ad[k].firstedge=NULL;
        G->Ad[k].indegree=0;
    }//ͷ���ĳ�ʼ��
    printf("������������(�¼����),�ߵ�Ȩֵ(�ʱ��)\n");
    for(k=1; k<=G->e; k++)
    {
        cin >> j >> i >> t;
        G->Ad[i].indegree++;
        link* p=new link;
        p->v=i;
        p->weight=t;
        p->next=G->Ad[j].firstedge;
        G->Ad[j].firstedge=p;//�ڱ�ͷ����
    }
    printf("AOE���繹�����\n-----�˼��ǻ������ķָ���-----\n��ӡ�ڽӱ�\n");
    for(i=1; i<=G->n; i++)
    {
        cout << G->Ad[i].element;
        link *m=G->Ad[i].firstedge;
        while(m!=NULL)
        {
            printf("->%c,%d",G->Ad[m->v].element,m->weight);
            m=m->next;
        }
        printf("->^\n");
    }//�ڽӱ��ӡ
    printf("\n");
}
void Criticalpath(Adgraph* G)//GΪ��Ȩֵ���ڽӱ�
{
    queue<int> Q;
    stack<int> S;
    int i,j,k,count=0,ve[101],vl[101],ae,al;
    //ʱ������緢��ʱ���������ʱ�䣬������緢��ʱ���������ʱ��
    //m��������,�ж��Ƿ��л�·
    for(i=1; i<=G->n; i++)ve[i]=0; //����ÿ���¼������緢��ʱ�䶼Ϊ0
    for(i=1; i<=G->n; i++)
        if(G->Ad[i].indegree==0) Q.push(i);
    //�����Ϊ0�Ķ������
    printf("Topsort:");
    while(!Q.empty())
    {
        j=Q.front();
        Q.pop();
        count++;
        cout << G->Ad[j].element;
//               cout << j ;
        S.push(j);//��������������±�����ջ
        link *p=G->Ad[j].firstedge;
        while(p!=NULL)
        {
            k=p->v;
            G->Ad[k].indegree--;
            if(ve[j] + p->weight > ve[k])
                ve[k] = ve[j] + p->weight;
            if(G->Ad[k].indegree==0) Q.push(k) ;
            p=p->next;
        }
    }//��topsort������ķ���ʱ��
    printf("\n");
    if(count<G->n)
    {
        printf("�л�·��\n");
        return;
    }
    for(i=1; i<=G->n; i++) //Ϊ���¼�v(i)����ٷ���ʱ��vl[i]�ó�ֵ
        vl[i]=ve[G->n];
    printf("Opp_Topsort:");
    while(!S.empty())//���������е�����ȡ����
    {
        j=S.top();
        S.pop();//��ջ
        cout << G->Ad[j].element;
        link *p=G->Ad[j].firstedge;
        while(p!=NULL)
        {
            k=p->v;
            if((vl[k] - p->weight)<vl[j])
                vl[j]=vl[k]-p->weight;  //�޸�vl[j]
            p=p->next;
        }
    }
    printf("\nActivity<EnventA->EnventB>      AE     AL    Share time  Is Criticalpath?:\n");
    for(j=1; j<=G->n; j++) //ɨ�趥���
    {
        link *p=G->Ad[j].firstedge;
        while(p!=NULL)
        {
            k=p->v;
            ae=ve[j];
            al=vl[k]-p->weight;
            printf("<�¼�%c,�¼�%c>\t\t\t%d\t%d\t%d    \t",G->Ad[j].element,G->Ad[k].element,ae,al,al-ae);
            if(al==ae)//�ؼ��
                printf("Yes");
                else printf("No");
            printf("\n");
            p=p->next;
        }
    }
}
int main()
{
    struct Adgraph G;
    Create_AOE(&G);
    Criticalpath(&G);
    return 0;
}

