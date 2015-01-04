//#ifndef _LIST_LINK_H_HUMING_INCLUDE_
//#define _LIST_LINK_H_HUMING_INCLUDE_
//#define maxlen 100
//template <class T>
//class node
//{
//public:
//    T data;
//    int next;
//};
//template <class T>
//class link
//{
//public :
//    void link();
//    int GetNode();
//    void FreeNode(int q);
//    void Insert(T x, int p);
//    void Delete(int  p);
//private :
//    node<T> space[maxlen];
//    int avail;
//};
//template <class T>
//void link<T>::link()
//{
//    for(int j=0; j<maxlen-1; j++)
//        space[j].next=j+1;
//    space[j]=-1;//���һ��Ϊ��
//    avail=0;//��ʾ���Ա�
//}
//template <class T>
//int link<T>::GetNode() //q=new spacestr;
//{
//    int p;
//    if (space[avail].next ==-1)
//        p=-1;
//    else
//    {
//        p= space[avail].next ;
//        space[avail].next =space[p].next ;
//    }
//    return p;
//}
//template <class T>
//void link<T>::FreeNode(int  q) //delete q;
//{
//    space[q].next =space[avail].next ;
//    space[avail].next=q ;
//} /* �Żس���*/
//template <class T>
//void link<T>::Insert(T x, int p)
//{
//    int q ;
//    q=GetNode( ) ;
//    space[q].data = x ;
//    space[q].next=space[p].next ;
//    space[p].next = q ;
//}
//template <class T>
//void link<T>::Delete(int  p)
//{
//    int  q ;
//    if (space[p].next != -1 )
//    {
//        q=space[p].next ;
//        space[p].next = space[q].next ;
//        FreeNode(q) ;
//    }
//}
//#endif
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define maxlength 10000
template<typename T>
class list
{
public:
    list();
    ~list(){};//???
    void Insert(int position,T value);
    void Delete(int position);
    void Swap(int x,int y);
    int Size();
    int Locate(T value);
    int Previous(int position);
    int Next(int position);
    int First();
    int End();
    T Retrieve(int position);
    bool Empty();
    bool Judge(int position,bool sign);
private:
    int GetNode();
    void FreeNode(int position);
    bool Full();
    int Unused();
    struct spacestr
    {
        T data;
        int next;
    };
    spacestr *SPACE;
    int avail;
    int head;//��ͷ���ı��
};
//���ÿռ��ʼ��
template<typename T>
list<T>::list()
{
    SPACE=new spacestr[maxlength];
    int i;
    for(i=0; i<maxlength-1; i++)
        SPACE[i].next=i+1;
    SPACE[i].next=-1;
    avail=0;
    head=GetNode();
    SPACE[head].next=-1;
}
////��������
//template<typename T>
//list<T>::~list()
//{
//    delete []SPACE;
//}
//���ÿռ�ķ������
//���ؿ��ýڵ�ı��
//û�п��õĽ�㷵��-1
//���Ϊavail(0)�Ľ��ʼ�ղ��洢Ԫ��
template<typename T>
int list<T>::GetNode()
{
    if(SPACE[avail].next==-1)
        return -1;
    else
    {
        int p=SPACE[avail].next;
        SPACE[avail].next=SPACE[p].next;
        return p;
    }
}
//���ÿռ�Ļ��ղ���
template<typename T>
void list<T>::FreeNode(int position)
{
    SPACE[position].next=SPACE[avail].next;
    SPACE[avail].next=position;
}
//��Ԫ�ز��뵽pλ����
template<typename T>
void list<T>::Insert(int position,T value)
{
    if(Judge(position,true))
    {
        int p=head,temp;
        position--;
        while(position--)
          p=SPACE[p].next;
        temp=GetNode();
        SPACE[temp].data=value;
        SPACE[temp].next=SPACE[p].next;
        SPACE[p].next=temp;
    }
    else return;
}
//ɾ��pλ���ϵ�Ԫ��
template<typename T>
void list<T>::Delete(int position)
{
    if(Judge(position,false))
    {
        int p=head,temp;
        position--;
        while(position--)
          p=SPACE[p].next;
        temp=SPACE[p].next;
        SPACE[p].next=SPACE[temp].next;
        FreeNode(temp);
    }
    else return;
}
template<typename T>
bool list<T>::Empty()
{
    if(SPACE[head].next==-1)
        return true;
    else return false;
}
template<typename T>
bool list<T>::Full()
{
    if(SPACE[avail].next==-1)
        return true;
    else return false;
}
//���ص�һ��Ԫ�ص�λ�ñ��
//��ִ�в������ʱ��ʹ��First()��Ϊλ�ò�������ʾ��Ԫ�ز��뵽��һ��λ��
template<typename T>
int list<T>::First()
{
    return 1;
}
//�������һ��Ԫ�غ���һ��λ�õ�λ�ñ��
//��ִ�в������ʱ��ʹ��End()��Ϊλ�ò�������ʾ��Ԫ�ز��뵽��β
template<typename T>
int list<T>::End()
{
    if(Size()<maxlength-2)
      return Size()+1;
    else return -1;
}
//�������Ա���Ԫ�صĸ���
template<typename T>
int list<T>::Size()
{
    if(!Empty())
    {
        int count=0;
        int p=SPACE[head].next;
        while(p!=-1)
        {
            p=SPACE[p].next;
            count++;
        }
        return count;
    }
    else return 0;

}
//�������Ա��п����õ�ʣ��ռ�ĸ���
template<typename T>
int list<T>::Unused()
{
    return maxlength-2-Size();
}
template<typename T>
T list<T>::Retrieve(int position)
{
    if(Judge(position,false))
    {
        int p=head;
        while(position--)
        {
            p=SPACE[p].next;
        }
        return SPACE[p].data;
    }
}
//��λ
template<typename T>
int list<T>::Locate(T value)
{
    if(!Empty())
    {
        int p=SPACE[head].next;
        int count=1;
        while(p!=-1&&SPACE[p].data!=value)
        {
            p=SPACE[p].next;
            count++;
        }
        if(p==-1) return -1;
        return count;
    }
    else return -1;
}
template<typename T>
int list<T>::Previous(int position)
{
    if(Judge(position,false))
        return position-1;
    else return -1;
}
template<typename T>
int list<T>::Next(int position)
{
    if(Judge(position,false))
        return position+1;
    else return -1;
}
//�ж�λ��position�ĺ�����
//���ڿձ�ɾ��û�к����λ��
//���ڿձ����positionֻ����1
template<typename T>
bool list<T>::Judge(int position,bool sign)
{
    if(sign)
    {
        if(position>=1&&position<=Size()+1)
            return true;
        else return false;
    }
    else
    {
        if(position>=1&&position<=Size())
            return true;
        else return false;
    }
}
//������������Ԫ�أ�����һ�����ı��Ϊx��һ�����Ϊy  AC
template<typename T>
void list<T>::Swap(int x,int y)
{
    int p=head;
    int q=head;
    while(x--)
     p=SPACE[p].next;
    while(y--)
     q=SPACE[q].next;
    T temp;
    temp=SPACE[p].data;
    SPACE[p].data=SPACE[q].data;
    SPACE[q].data=temp;
}
#endif // LIST_H_INCLUDED

