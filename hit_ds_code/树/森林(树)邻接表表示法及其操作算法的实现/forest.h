#ifndef FOREST_H_INCLUDED
#define FOREST_H_INCLUDED
#define maxlength 10000
#include "stack.h"
#include "queue.h"
//#include<queue>
//#include<stack>
#include <iostream>
using namespace std;
template<typename T>//���������е�ÿ�����
class CTNode
{
public:
    CTNode()
    {
        next=0;
        child=0;
    }
    CTNode(int tmp)
    {
        next=0;
        child=tmp;
    }
    int child;//���ӽ��ı��
    T data;//(����)���ӽ�����Ϣ
    CTNode *next;
};
template<typename T>//���Ա��е�ÿ�����
class CTBox
{
public:
    CTBox()
    {
        flag=false;
        count=0;
        firstchild=NULL;
    }
    T data;//ÿ��������Ϣ
    int count;//ÿ����㺢�ӵĸ���
    bool flag;//��ɭ��ת��Ϊ������ʱ�õ�flag����
    CTNode<T> *firstchild;//ָ���һ�����ӽ���ָ��
};
template<typename T>//�������е�ÿ�����
class BTNode
{
public:
    BTNode()
    {
        firstchild=0;
        rightsib=0;
        rank=0;
    }
    BTNode(T value)
    {
        data=value;
        firstchild=0;
        rightsib=0;
        rank=0;
    }
    T data;
    BTNode<T> *firstchild,*rightsib;
    int rank;//��ʾ����������Ӧ��ɭ���иý�㰴����ı��
};
template<typename T>
class forest
{
public:
    forest();
    ~forest();
    void Number();
    void ClearBT(BTNode<T> *p);
    void CreateForest();//����ɭ�ֵ��ڽӱ�洢�ṹ
    void CreateBT();//����ɭ�ֵĶ�������洢�ṹ
    void TransformBTtoForest();//��������ת��Ϊɭ��
    void TransformForesttoBT();//��ɭ��ת��Ϊ������
    void Print();//��ӡɭ�ֵ��ڽӱ�洢�ṹ
    void Insert(int i,int j);//�����Ϊj�Ľ����뵽���Ϊi�Ľ��ĺ��������β��
    void Delete(CTNode<T>* p);//ɾ��p��ָ�������һ�����
    int Count(BTNode<T>* p);//������pΪ�����Ķ������Ľ�����
    void PreOrder(BTNode<T> *p);
    void InOrder(BTNode<T> *p);
    void PostOrder(BTNode<T> *p);
private:
    int n;//���ĸ���
    BTNode<T> *BT;//�������ĸ����
    int root[maxlength],num[maxlength];
    BTNode<T> *S[maxlength];
    CTBox<T> *Tree;
};
template<typename T>
forest<T>::forest()
{
    Tree=new CTBox<T> [maxlength];
    BT=NULL;
}
template<typename T>
forest<T>::~forest()
{
    delete []Tree;
    delete []root;
    delete []num;
    delete []S;
    ClearBT(BT);
}
template<typename T>//����ɭ�ֵ��ڽӱ�洢�ṹ
void forest<T>::CreateForest()
{
    delete []Tree;
    Tree=new CTBox<T> [maxlength];
    int a,b;
    T temp;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin.ignore(80,'\n');
        cin>>root[i]>>num[i];
        for(int j=1; j<=num[i]; j++)
        {
            cin.ignore(80,'\n');
            cin>>a>>temp;
            Tree[a].data=temp;
            while(cin>>b&&b)
                Insert(a,b);
        }
    }
}
template<typename T>//����ɭ�ֵĶ�������洢�ṹ
void forest<T>::CreateBT()
{
    BTNode<T> *p;
    int i;
    T temp;
    while(cin>>i>>temp&&i)
    {
        p=new BTNode<T>(temp);
        S[i]=p;
        if(i==1) BT=p;
        else if(i%2==0) S[i/2]->firstchild=p;
        else S[i/2]->rightsib=p;
    }
}
template<typename T>//��ӡɭ�ֵ��ڽӱ�洢�ṹ
void forest<T>::Print()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=root[i]; j<=root[i]+num[i]-1; j++)
        {
            cout<<j<<"."<<Tree[j].data<<"->";
            for(CTNode<T> *p=Tree[j].firstchild; p!=NULL; p=p->next)
                cout<<p->child<<"->";
            cout<<"^"<<endl;
        }
    }
}
template<typename T>
int forest<T>::Count(BTNode<T> *p)
{
    if(p)
    {
        int m=Count(p->firstchild);
        int n=Count(p->rightsib);
        return m+n+1;
    }
    else return 0;
}
template<typename T>
void forest<T>::Insert(int i,int j)//�����Ϊj�Ľ����뵽���Ϊi�ĺ��������β��
{
    if(!Tree[i].count)  Tree[i].firstchild=new CTNode<T>(j);
    else
    {
        CTNode<T>* tmp=Tree[i].firstchild;
        while(tmp->next)
            tmp=tmp->next;
        tmp->next=new CTNode<T>(j);
    }
    (Tree[i].count)++;
}
template<typename T>//��ɭ��ת��Ϊ������
void forest<T>::TransformForesttoBT()
{
    for(int i=1; i<=n; i++)
        for(int j=root[i]; j<=root[i]+num[i]-1; j++)
            S[j]=new BTNode<T>(Tree[j].data);
    for(int i=1; i<=n; i++)
    {
        if(i>1)S[root[i-1]]->rightsib=S[root[i]];
        for(int j=root[i]; j<=root[i]+num[i]-1; j++)
        {
            if(Tree[j].count>0)
            {
                S[j]->firstchild=S[Tree[j].firstchild->child];
                for(CTNode<T> *p=Tree[j].firstchild; p->next!=NULL; p=p->next)
                    S[p->child]->rightsib=S[p->next->child];
            }
        }
    }
    BT=S[1];
    PreOrder(BT);
    cout<<endl;
    InOrder(BT);
    cout<<endl;
}
template<typename T>//�Խ����б��
void forest<T>::Number()
{
    BTNode<T> *p=BT,*q;
    queue<BTNode<T>*> u;
    int tmp=0;
    while(p)
    {
        u.Enqueue(p);
        while(!u.Empty())
        {
            q=u.Front();
            q->rank=(++tmp);
            Tree[tmp].data=q->data;
            u.Dequeue();
            for(q=q->firstchild; q!=NULL; q=q->rightsib)
                u.Enqueue(q);
        }
        p=p->rightsib;
    }
}
template<typename T>//��������ת��Ϊɭ��
void forest<T>::TransformBTtoForest()
{
    delete []Tree;
    Tree=new CTBox<T> [maxlength];
    Number();
    BTNode<T> *p=BT,*pp;
    stack<BTNode<T>*> v;
    while(p||!v.empty())
    {
        if(p)
        {
            v.push(p);
            pp=p;
            for(p=p->firstchild; p!=NULL; p=p->rightsib)
                Insert(pp->rank,p->rank);
            p=pp->firstchild;
        }
        else
        {
            p=v.top()->rightsib;
            v.pop();
        }
    }
    n=0;
    for(p=BT; p!=NULL; p=p->rightsib)
    {
        root[++n]=p->rank;
        num[n]=Count(p->firstchild)+1;
    }
}
template<typename T>//ɾ��������
void forest<T>::ClearBT(BTNode<T>* tmp)
{
    if(tmp)
    {
        ClearBT(tmp->firstchild);
        ClearBT(tmp->rightsib);
        delete tmp;
    }
    else return;
}
template<typename T>
void forest<T>::PreOrder(BTNode<T> *p)
{
    if(p)
    {
        cout<<p->data;
        PreOrder(p->firstchild);
        PreOrder(p->rightsib);
    }
    else return;
}
template<typename T>
void forest<T>::InOrder(BTNode<T> *p)
{
    if(p)
    {
        InOrder(p->firstchild);
        cout<<p->data;
        InOrder(p->rightsib);
    }
    else return;
}
template<typename T>
void forest<T>::PostOrder(BTNode<T> *p)
{
    if(p)
    {
        PostOrder(p->firstchild);
        PostOrder(p->rightsib);
        cout<<p->data;
    }
    else return;
}
#endif // FOREST_H_INCLUDED
