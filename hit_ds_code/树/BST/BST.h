//file��BST.h
#ifndef _BST_H_HITHUMING_INCLUDE_
#define _BST_H_HITHUMING_INCLUDE_
#include <iostream>
#include<cstring>
using namespace std;
// ���BSTģ���ǰ������������node���޷�����BST<T>Ϊ��Ԫ��
template <class T>
class BST;
template<class T>
class node
{
public:
    node():lchild(NULL),rchild(NULL) {};
    node(T p)
    {
        this->data=p;
        lchild=NULL;
        rchild=NULL;
    };
    ~node()
    {
        delete this;
    };
    T return_data()
    {
        return data;
    };
    // ���ﲻ��Ҫ�жϣ���Ϊlchild��rchild���к���Ĭ��ֵ��(���캯��)
    node<T>* return_lc()
    {
        return lchild;
    };
    node<T>* return_rc()
    {
        return rchild;
    };
    //  friend class BST;//��������Ԫ�࣬Ϊʲô���滹���ܷ��ʣ�
    // ������Ϊ����дBST������
    friend class BST<T>;
private:
    T data;
    // �����ִ��ˣ�����дrchild����ָ�룬����node<T>����
    // node<T>* lchild,rchild;
    node<T> *lchild, *rchild;
};
template <class T>
class BST
{
public:
    void CreateBST();//���ظ��ڵ��ָ��
    void InsertBST(T key,node<T>* &t);//��������ͣ����в����λ��
    node<T>* SearchBST(T key,node<T>* F);//����
    void Delete(T k,node<T>* &t);
    void in_order(node<T>* t);
    T de_lete(node<T>* &t);
    node<T>* return_rt()
    {
        return root;
    }
private:
    node<T>* root;
};
template <class T>
void BST<T>::CreateBST()
{
    node<T> *F=NULL;
    T m;
    while(cin >> m&&m!=0)
    {
        InsertBST(m,F);
    }//���ò��ϵĲ���������
    root=F;
}
template <class T>
void BST<T>::InsertBST(T key,node<T>* &t)
//ע�⣺�������޸����ݣ�����Ҫ����ַ����������Щֻ�÷��ʾ��У����Բ��ô���ַ
//��������������һ�۾Ͱ��ҿ���������
{
    // ����t��ָ�룬��ô��.�أ�
    if(t==NULL)
    {
        t=new node<T>;
        t->data=key;
        t->lchild=NULL;
        t->rchild=NULL;
    }
    else if (key < t->data)
        InsertBST(key,t->lchild);
    else if (key > t->data)
        InsertBST(key,t->rchild);
    else ;
    //���������ʵ���ڲ��ң������һ���ǲ���ʧ�ܵ����һ���ڵ������ӻ����Ҷ���
}
template <class T>
node<T>* BST<T>::SearchBST(T k,node<T>* F)
{
    node<T>* p =F;
    if (p== NULL || k == p->data)  //�ݹ���ֹ����
        return p;
    if ( k < p->data)
        return (SearchBST (k,p->lchild)); // ����������
    else
        return (SearchBST(k,p->rchild)) ; // ����������
}
template <class T>
void BST<T>::in_order(node<T>* t)
{
    if(t!=NULL)
    {
        in_order(t->lchild);
        cout << t->data << " ";
        in_order(t->rchild);
    }
}
template <class T>
T BST<T>::de_lete(node<T>* &t)
{
    T temp ;
    node<T> *p ;
    if ( t->lchild == NULL )
    {
        p = t ;
        temp = t->data ;
        t = t->rchild ;
        delete p ;
        return temp ;
    }
    else
        return(de_lete(t->lchild));
}
template <class T>
void BST<T>::Delete(T k,node<T>* &t)
{
    if(t!=NULL)
    {
        if(k<t->data)  Delete(k,t->lchild);
        else if(k>t->data) Delete(k,t->rchild);
        else
        {
            if(t->lchild==NULL) t=t->rchild;
            else if(t->rchild==NULL) t=t->lchild;
            else
            {
                t->data=de_lete(t->rchild);
            }
        }
    }
}
//�е㸴�ӹ�����������~
//1. �����p��Ҷ�ӣ���ֱ��ɾ�����p��
//2. �����pֻ������������ֻ���ؽ�p����������
//�����pֻ������������ֻ���ؽ�p����������
//3. �����p���������������գ���
//3.1 ���ҽ��p���������ϵ������½��s����˫�׽��par��
//3.2 �����s�������滻����ɾ���p��������
//3.3 �����p���Һ�������������
//��s���������ӵ�par���������ϣ�
//���򣬽�s���������ӵ����par���������ϣ�
//3.4 ɾ�����s��
#endif




