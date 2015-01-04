//file��AVL.h
#ifndef _BST_H_HITHUMING_INCLUDE_
#define _BST_H_HITHUMING_INCLUDE_
#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
template <class T>
class AVL;
template<class T>
class node
{
public:
    node():lchild(NULL),rchild(NULL){};
    node(T p)
    {
        this->data=p;
        lchild=NULL;
        rchild=NULL;
    };
    ~node(){delete this;};
    T return_data(){return data;};
    node<T>* return_lc(){ return lchild;};
    node<T>* return_rc(){ return rchild;};
    friend class AVL<T>;//��Ԫ~~
private:
    T data;
    int bf;//�ڵ��ƽ������
    node<T> *lchild, *rchild;
};
template <class T>
class AVL
{
public:
    AVL():flag(false),root(NULL) {};
    ~AVL() {};
    void Create();
    void Insert(node<T>* &t,T key);
    void Leftrotation(node<T>* &t);
    void Rightrotation(node<T>* &t);
    node<T>* return_rt(){return root;}
    void level_order(node<T>* t);
    void in_order(node<T>* t);
private:
    bool flag;
//������Ƿ񳤸���������ĺ�ֽС�İ���
//�����Ǹ����ԣ��ҿ�������һƪ���Ͳ�֪������˼·Ҫ��ǵ������Ƿ񳤸�����
//���ǹ�����������˼·ͦ��ʡ�ռ�ģ����е��㷨������߶���ƽ�����ӣ�
//���е���������һ�����ڵ㣬��֪�����Ҿ�������˼·���Ǻܺ����ģ�
    node<T>* root;
};
template <class T>
void AVL<T>::in_order(node<T>* t)
{
    if(t!=NULL)
        {
           in_order(t->lchild);
           cout <<t->data << " ";
           in_order(t->rchild);
        }
}
template <class T>
void AVL<T>::level_order(node<T>* t)
{
    queue<node<T>*> q;
    node<T>* p;
    if(t==NULL)  return ;
    q.push(t);
    while(!q.empty())
    {
        p=q.front();
      cout << p->data << " " ;
      if(p->lchild)
          q.push(p->lchild);
      if(p->rchild)
        q.push(p->rchild);
      q.pop();
    }
}
template <class T>
void AVL<T>::Create()
{
    node<T>* F=NULL;
    T m;
    while(cin >> m&&m!=0)
    {
        flag=false;
        Insert(F,m);
    }//���ò��ϵĲ���������
    root=F;
}
template <class T>
void AVL<T>::Insert(node<T>* &t,T key)
{
    if(t==NULL)
    {
        t=new node<T>;
        t->data=key;
        t->lchild= t->rchild=NULL;
        t->bf=0;//�ն�����������ڵ��ƽ������Ϊ0
    }
    else if(key<t->data)
    {
        Insert(t->lchild,key);//��ǰ����ͨBST��Ӧ������
        if(flag)//���������п�����Ҫƽ�⻯����
        {
            switch(t->bf)
            {
            case 1:
                Leftrotation(t);
                //����ǰ��ߵ����ߣ���Ӧ����LL(���������������ϲ���),LR(����������������),������תƽ��
                flag=false;
                break;
            case 0:
                //����֮ǰ�����������
                t->bf=1;//t��ƽ������+1�����������ڵ��ƽ�������ǲ���ģ�
                flag=true;
                break;
            case -1:
                //����֮ǰ�ұ߱���߸�
                t->bf=0;
                flag=false;
                break;
            }
        }
    }
    else if(key>t->data)
    {
        Insert(t->rchild,key);//��ǰ����ͨBST��Ӧ������
        if(flag)//���������п�����Ҫƽ�⻯����
        {
            switch(t->bf)
            {
            case 1:
//                      ԭ����߱��ұ߸ߣ�����һ����~
                t->bf=0;
                flag=false;
                break;
            case 0:
                //����֮ǰ�����������
                t->bf=-1;//t��ƽ������-1�����������ڵ��ƽ�������ǲ���ģ�
                flag=true;
                break;
            case -1:
                //����֮ǰ�ұ߱���߸�,��ӦRL,RR�����������ת��
                Rightrotation(t);
                flag=false;
                break;
            }
        }
    }
    else flag=false;//��ȣ�BST���ǲ�������ֵģ�
}
template <class T>
void AVL<T>::Leftrotation(node<T>* &t)
{
    node<T> *lc,*gc;
    lc=t->lchild;
    if(lc->bf==1)//LL
    {
        t->lchild=lc->rchild;
        lc->lchild=t;
        t->bf=0;
        t=lc;
    }
    else//LR
    {
        gc=lc->rchild;
        lc->rchild=gc->lchild;
        gc->lchild=lc;
        t->lchild=gc->rchild;
        gc->rchild=t;
        switch(gc->bf)
        {
        case 1:
            t->bf=-1;
            lc->bf=0;
            break;
        case -1:
            t->bf=0;
            lc->bf=1;
            break;
        case 0:
            t->bf=lc->bf=0;
            break;
        }
        t=gc;
    }
    t->bf=0;
    flag=false;
}
template <class T>
void AVL<T>::Rightrotation(node<T>* &t)
{
    node<T> *rc,*gc;
    rc=t->rchild;
    if(rc->bf==-1)//RR
    {
       t->rchild=rc->lchild;
       rc->lchild=t;
       t->bf=0;
       t=rc;
    }
    else//RL
    {
        gc=rc->lchild;
        rc->lchild=gc->rchild;
        gc->rchild=rc;
        t->rchild=gc->lchild;
        gc->lchild=t;
        switch(gc->bf)
        {
        case 1:
            t->bf=0;
            rc->bf=-1;
            break;
        case -1:
            t->bf=1;
            rc->bf=0;
            break;
        case 0:
            t->bf=rc->bf=0;
            break;
        }
        t=gc;
    }
    t->bf=0;
    flag=false;
}
#endif




