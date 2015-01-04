//����ʽ�ӷ���
#include<iostream>
#include "list_link.h"
using namespace std;
struct polynode
{
    int coef;//ϵ��
    int exp;//ָ��
};
link <polynode> a,b,c;
void PolyAdd(link<polynode>a,link<polynode>b,link<polynode>c);
void show(link<polynode>x);
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    node<polynode>* m;
    polynode x;
//     printf("�������һ������ʽ\n");
    cin >> n >> x.coef >> x.exp;
    a.Insert(x,a.First());
    for(int i=1; i<=n-1; i++)
    {
        cin >> x.coef >> x.exp;
        m=a.First();
        while(m!=a.End())
        {
            if(a.Retrieve(m).exp>x.exp) m=a.Next(m);
            else break;
        }
        a.Insert(x,m);
    }
//    printf("������ڶ�������ʽ\n");
    cin >> n >> x.coef >> x.exp;
    b.Insert(x,b.First());
    for(int i=1; i<=n-1; i++)
    {
        cin >> x.coef >> x.exp;
        m=b.First();
        while(m!=a.End())
        {
            if(b.Retrieve(m).exp>x.exp) m=b.Next(m);
            else break;
        }
        b.Insert(x,m);
    }//�����ʱ��Ͱ�˳����룬ʡ������
    PolyAdd(a,b,c);
    show(a);
    printf("+");
    show(b);
    printf("=");
    show(c);
    return 0;
}
void show(link<polynode>x)
{
    node<polynode>  *i;
    i=x.First();
    while(i->next!=x.End())
    {
        printf("%dx^%d+",x.Retrieve(i).coef,x.Retrieve(i).exp);
        i=x.Next(i);
    }
    printf("%dx^%d",x.Retrieve(i).coef,x.Retrieve(i).exp);
}
void PolyAdd(link<polynode> a,link<polynode> b,link<polynode> c)
{
    polynode temp;
    node<polynode>*p1=a.First(),*i,*p2=b.First();//ָ��ڵ����͵�ָ��
    while(a.Next(p1)!=NULL&&b.Next(p2)!=NULL)
    {
        if(a.Retrieve(p1).exp>b.Retrieve(p2).exp)
        {
            c.Insert(a.Retrieve(p1),c.End());
            p1=a.Next(p1);
        }
        else if(a.Retrieve(p1).exp<b.Retrieve(p2).exp)
        {
            c.Insert(b.Retrieve(p2),c.End());
            p2=b.Next(p2);
        }
        else
        {
            temp.coef=a.Retrieve(p1).coef;
            temp.exp=a.Retrieve(p1).exp;
            temp.coef+=b.Retrieve(p2).coef;
            c.Insert(temp,c.End());
            p1=a.Next(p1);
            p2=b.Next(p2);
        }
    }
    if(p1!=a.End())
    {
        for(i=p1; i!=a.End(); i=a.Next(i))
            c.Insert(a.Retrieve(i),c.End());
    }
    if(p2!=b.End())
    {
        for(i=p2; i!=b.End(); i=b.Next(i))
            c.Insert(b.Retrieve(i),c.End());
    }
}

