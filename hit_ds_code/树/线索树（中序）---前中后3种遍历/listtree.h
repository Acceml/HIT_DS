#ifndef _LISTTREE_H_HUMING_INCLUDE_
#define _LISTTREE_H_HUMING_INCLUDE_
#include <iostream>
#include<cstring>
using namespace std;
template <class T>
class Listtree;
template<class T>
class node
{
public:
    node():lchild(NULL),rchild(NULL),ltag(0),rtag(0) {};
    ~node()
    {
        delete this;
    };
    T return_data()
    {
        return data;
    };
    node<T>* return_lc()
    {
        return lchild;
    };
    node<T>* return_rc()
    {
        return rchild;
    };
    friend class Listtree<T>;
private:
    T data;
    node<T> *lchild,*rchild;
    int ltag,rtag;
};//�ڵ���
template <class T>
class Listtree
{
public:
    node<T>* return_hd()
    {
        return head;
    };
    node<T>* return_rt()
    {
        return root;
    };
    void Create();//��������ͨ������
    void to_list();//������
    void pre_order();//����
    void In_order();
    void Post_order();
    node<T>* InNext(node<T>* p);
    node<T>* parent(node<T>* t);
private:
    node<T> *root,*pre,*head;
    void To_list_tree(node<T>* p,node<T>* &pre);
    node<T>* Insert();
};
template <class T>
node<T>* Listtree<T>::parent(node<T>* t)
{
    node<T>* p;
    if(t==root) return NULL;//û�и��ڵ�
    else
    {
        for(p=t; p->ltag==1; p=p->lchild);
        if(p->lchild!=head)
            for(p=p->lchild; p!=head&&p->lchild!=t&&p->rchild!=t; p=p->rchild);
        if((p==head||p->lchild==head))
        {
            for(p=t; p->rtag==1; p=p->rchild);
            for(p=p->rchild; p!=head&&p->lchild!=t&&p->rchild!=t; p=p->lchild);
        }
    }
    return p;
}
template <class T>
void Listtree<T>::Post_order()
{
    node<T> *t=root,*p;
    while(t->ltag==1||t->rtag==1)//һֱ�ҵ���������ĵ�һ���ڵ�λ��
    {
        if(t->ltag==1) t=t->lchild;
        else if(t->rtag==1) t=t->rchild;
        else;
    }
    cout << t->data;
    while((p=parent(t))!=NULL)
    {
        if((p->rchild==t||p->rtag==0))
            //�����ǰ�ڵ��Ǹ��ڵ���Ҷ��ӣ�������Ȼ������ӣ�����������ڵ�û���Ҷ���
            t=p;
        else//������ǵĻ������������ظ�����Ĳ���(�ղ����������������)���ҳ�����������ĺ��������һ���ڵ�
        {
            t=p->rchild;
                while(t->ltag==1||t->rtag==1)//һֱ�ҵ���������������ĵ�һ���ڵ�λ��
                {
                    if(t->ltag==1) t=t->lchild;
                    else if(t->rtag==1) t=t->rchild;
                    else;
                }
        }
        cout << t->data;
    }
}
template <class T>
void Listtree<T>::pre_order()
{
    node<T>* t=root;
    while(t!=NULL&&t!=head)
    {
//            �Ͷ�����������������ƣ�
//    ѭ�������պ��ٴη��ʵ�head�ڵ�
        cout << t->data;
        if(t->ltag==1) t=t->lchild;
        else if(t->rtag==1)t=t->rchild;
//        �����Ҷ���
        else
        {
//            û�����Ҷ��ӣ���ô���������������ҵ���һ�����Ҷ��ӵĽڵ㣬���ǵ�ǰ�ڵ����������ĺ�̽ڵ�
            while(t->rtag==0&&t!=head)
            {
                t=t->rchild;
            }
            if(t!=head) t=t->rchild;
            //ע���ж�һ�½����ı�ʶ��t��һ���ߵ�head�ڵ㣨��ͼ�У�
        }
    }
}
template<class T>
node<T>* Listtree<T>::Insert()
{
    T ch;
    node<T> *t;
    cin >> ch;
    if(ch=='#')  t=NULL;
    else
    {
        t=new node<T>;
        t->data=ch;
        t->lchild=Insert();
        t->rchild=Insert();
    }
    return t;
}
template <class T>
void Listtree<T>::Create()
{
    root=Insert();
    head= new node<T>;
    if(root!=NULL)
    {
        head->lchild =root;
        head->ltag =1;
    }
    else
    {
        head->lchild=head;
        head->ltag =0;
    }
    head->rchild =head;
    head->rtag =1;
};
template <class T>
void Listtree<T>::to_list()
{
    pre=head;
    To_list_tree(root,pre);
    pre->rchild=head;
    pre->rtag=0;
}
template <class T>
void Listtree<T>::To_list_tree(node<T>* p,node<T>* &pre)//����ͨ�Ķ�����ת��Ϊ����������
{
    if(p)
    {
        //p �ǿ�ʱ����ǰ���ʵĽ����p
        To_list_tree(p->lchild,pre); //������������
        p->ltag=( p->lchild )? 1:0; //��(��)���ӷǿ�
        p->rtag=( p->rchild )? 1:0; //ʱ,��־1,��: 0
        if (pre)   //��*p ��ǰ��*pre ����
        {
            if ( pre->rtag ==0) // *p��ǰ���ұ�־Ϊ����
                pre->rchild=p; // ��*pre ��������ָ��������
            if ( p->ltag ==0) // *p�����־Ϊ����
                p->lchild=pre; //��*p��������ָ������ǰ��
        }
        pre = p; // ��pre ����һ�����ʵ�����ǰ��
        To_list_tree(p->rchild,pre); //������������
    }
}
template<class T>
node<T>* Listtree<T>::InNext(node<T>* p)
{
    node<T>* Q ;
    Q=p->rchild ;
    if (p->rtag ==1 )
        while( Q->ltag == 1 )
            Q = Q->lchild ;
    return (Q);
}
template <class T>
void Listtree<T>::In_order()
{
    node<T>* tmp;
    tmp=head;
    do
    {
        tmp = InNext ( tmp ) ;
        if (tmp!=head)
            cout << tmp->data;
    }
    while (tmp !=head) ;
}
#endif
