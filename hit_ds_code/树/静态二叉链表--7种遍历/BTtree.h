//file:BTtree.h
#ifndef _BTTREE_H_HUMING_INCLUDE_
#define _BTTREE_H_HUMING_INCLUDE_
#include<iostream>
#include<queue>
#include<stack>
#define maxlen 1002
using namespace std;
template <class T>
class treenode
{
public:
    treenode():lchild(-1),rchild(-1) {}; //���캯��
    ~treenode() {}; //��������
    T  data;
    int lchild,rchild;
};
template <class T>
class BTtree
{
public:
    BTtree():root(-1),nodenum(0) {}; //���캯������Ϊ�գ���ʼ��ʱ��û��Ԫ��
    ~BTtree() {};//����
    void pre_create();  //����������
    int Lchild(int  t);//�����Ҷ���λ��
    int Rchild(int t);  //���ض���λ��
    T elements(int t);  //�����±�����ӦԪ��
    bool Isempty();  //�п�
    int return_root();  //���ظ��ڵ��±�
    void pre_order(int t);//����ݹ�
    void in_order(int t);//����ݹ�
    void post_order(int t);//����ݹ�
    void nrec_pre_order(int t);//����ǵݹ�
    void nrec_in_order(int t);//����ǵݹ�
    void nrec_post_order(int t);//����ǵݹ�
    void level_order(int t);//�������
    //������������@
private:
    treenode<T> element[maxlen];//�������Ľڵ�
    int root;//���ڵ���±�
    int nodenum;//�洢���ÿռ�
    int insert(); //��������
};
template <class T>
int BTtree<T>::Lchild(int t)
{
  return element[t].rchild;
}
template <class T>
int BTtree<T>::Rchild(int t)
{
    return element[t].lchild;
}
template<class T>
T BTtree<T>::elements(int t)
{
    return element[t].data;
}
template <class T>
int  BTtree<T>::return_root()
{
    return root;
}
template <class T>
void BTtree<T>::pre_create()
{
    root=insert();
}
template<class T>
int BTtree<T>::insert()
{
    T ch;
    cin >> ch;
    int t=nodenum;
    //�����һ���ڵ���±긳��t��Ҫ֪��ÿ���ڵ㶼��һ�����������ǽ����������Ļ���
    if(ch=='#') t=-1;
    else
    {
        nodenum++;//�൱�������еĿ����µĽڵ�
        element[t].data=ch;
        element[t].lchild=insert();
        element[t].rchild=insert();
    }
    return t;//���ض��������ڵ���±�
}
template <class T>
void BTtree<T>::pre_order(int t)
{
    if(t!=-1)
    {
        cout << element[t].data;
        pre_order(element[t].lchild);
        pre_order(element[t].rchild);
    }
}

template <class T>
void BTtree<T>::in_order(int t)
{
    if(t!=-1)
    {
        in_order(element[t].lchild);
        cout << element[t].data;
        in_order(element[t].rchild);
    }
}
template <class T>
void BTtree<T>::post_order(int t)
{
    if(t!=-1)
    {
        post_order(element[t].lchild);
        post_order(element[t].rchild);
        cout << element[t].data;
    }
}
template <class T>
void BTtree<T>::nrec_pre_order(int t)
{
    stack<int> s;
    while(t!=-1||!s.empty())//ѭ����ջ�ն�����Ϊ��
    {
        while(t!=-1)//�������Ϊ��һֱ���·��ʣ�����һ��
        {
            cout << element[t].data;
            s.push(t);
            t=element[t].lchild;
        }
        if(!s.empty())
        {
            t=s.top();
            s.pop();//ȡջ������ջ
            t=element[t].rchild; //����һ��
        }
    }
}
template <class T>
void BTtree<T>::nrec_in_order(int t)
{
    stack<int> s;
    while(t!=-1||!s.empty())//ѭ����ջ�ն�����Ϊ��
    {
        if(t!=-1)//������ѹջ����һ��
        {
            s.push(t);
            t=element[t].lchild;
        }
        else//���գ���ʱ����������ϣ�����ջ���ʸ��ڵ㣬���ߡ�����
        {
            t=s.top();
            s.pop();
            cout << element[t].data;
            t=element[t].rchild;
        }
    }
}
template <class T>
void BTtree<T>::nrec_post_order(int t)
{
    struct STACK
    {
        int  tree,flag;
    } S[maxlen];
    int top=maxlen;//����һ����������˳��ջ��������Ӱ�죬��ϲ�������ã�������ϰ��~~��
    int temp;
    temp=t;
    while(temp!=-1||top!=maxlen)//ѭ����ջ�պ�����
    {
        if(temp!=-1)//�����գ���ջ�����Ϊ��һ�η��ʣ�����
        {
            S[--top].tree=temp;
            S[top].flag=1;
            temp=element[temp].lchild;
        }
        else//����
        {
            if(S[top].flag==2)//���ջ��Ԫ�����Ѿ����η��ʹ��ģ���ô��ջ�������
            {
                t=S[top++].tree;
                cout << element[t].data;
            }
            else//���ջ�����ʹ�һ�Σ���ô���Ϊ�ڶ��η��ʣ�����
            {
                S[top].flag=2;
                temp=element[S[top].tree].rchild;
            }
        }
    }
}
template <class T>
void BTtree<T>::level_order(int  t)
{
    //�������Ƚ��ȳ����ص�
    queue<int> q;
    int p;
    if(t==-1)  return;
    q.push(t);
    while(!q.empty())//���ʵ����п�
    {
        p=q.front();
        cout << element[p].data;//���ӷ���
        if(element[p].lchild!=-1)
            q.push(element[p].lchild);//�������գ����
        if(element[p].rchild!=-1)
            q.push(element[p].rchild);//�������գ����
        q.pop();
    }
}
#endif
