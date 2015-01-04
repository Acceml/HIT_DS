//��������ʵ�ֺ�ָ��ʵ�ֿ���ͨ��
//����ʽ����
#include <iostream>
#include <stdio.h>
#include "static_state_link.h"
struct polynode
{
    int coef;
    int exp;
};
void PolyAdd(list<polynode> L1,list<polynode> L2,list<polynode> L3);
void PolySub(list<polynode> L1,list<polynode> L2,list<polynode> L3);
void PolyMultiply(list<polynode> L1,list<polynode> L2);
void Sort(list<polynode> L);
void Print(list<polynode> L);

using namespace std;

int main()
{
    int n;
    polynode p;
    list <polynode> l1,l2,l3;
    printf("���ȷֱ�������������ʽ����������ÿ������ʽ���������ٷֱ�����ÿһ���ϵ���ʹ���\n");
    printf("�������һ������ʽ\n");
    scanf(" %d",&n);
    while(n--)
    {
        scanf(" %d %d",&p.coef,&p.exp);
        l1.Insert(l1.First(),p);
    }
    printf("������ڶ�������ʽ\n");
    scanf(" %d",&n);
    while(n--)
    {
        scanf(" %d %d",&p.coef,&p.exp);
        l2.Insert(l2.First(),p);
    }
    printf("1---����ʽ�ӷ�\n2---����ʽ�˷�\n3---����ʽ����\n");
    scanf(" %d",&n);
    switch(n)
    {
    case 1:
        Print(l1);
        Print(l2);
        PolyAdd(l1,l2,l3);
        Print(l3);
        break;
    case 2:
        Print(l1);
        Print(l2);
        PolyMultiply(l1,l2);
        break;
    case 3:
        Print(l1);
        Print(l2);
        PolySub(l1,l2,l3);
        Print(l3);
        break;
    default:
        printf("End\n");
        break;
    }
    return 0;
}
//�����������ʱ���ظ����������ͬ����
void PolyAdd(list<polynode> L1,list<polynode> L2,list<polynode> L3)
{
    polynode temp;
    int p1=1;
    int p2=1;
    Sort(L1);
    Sort(L2);
    while(p1<=L1.Size()&&p2<=L2.Size())
    {
        if(L1.Retrieve(p1).exp>L2.Retrieve(p2).exp)
        {
            L3.Insert(L3.End(),L1.Retrieve(p1));
            p1++;
        }
        else if(L1.Retrieve(p1).exp<L2.Retrieve(p2).exp)
        {
            L3.Insert(L3.End(),L2.Retrieve(p2));
            p2++;
        }
        else
        {
            temp.coef=L1.Retrieve(p1).coef+L2.Retrieve(p2).coef;
            temp.exp=L1.Retrieve(p1).exp;
            L3.Insert(L3.End(),temp);
            p1++;
            p2++;
        }
    }
    if(p1<=L1.Size())
    {
        for(int i=p1; i<=L1.Size(); i++)
            L3.Insert(L3.End(),L1.Retrieve(i));
    }
    if(p2<=L2.Size())
    {
        for(int i=p2; i<=L2.Size(); i++)
            L3.Insert(L3.End(),L2.Retrieve(i));
    }
}
void PolyMultiply(list<polynode> L1,list<polynode> L2)
{
    polynode temp;
    list<polynode> pre;
    for(int i=1; i<=L1.Size(); i++)
    {
        list<polynode> now,ans;
        for(int j=1; j<=L2.Size(); j++)
        {
            temp.coef=L1.Retrieve(i).coef*L2.Retrieve(j).coef;
            temp.exp=L1.Retrieve(i).exp+L2.Retrieve(j).exp;
            now.Insert(now.End(),temp);
        }
        PolyAdd(pre,now,ans);
        if(i==L1.Size()) Print(ans);
        for(int k=pre.Size(); k>=1; k--)
            pre.Delete(k);
        for(int k=1; k<=ans.Size(); k++)
            pre.Insert(1,ans.Retrieve(k));
    }
}
void PolySub(list<polynode> L1,list<polynode> L2,list<polynode> L3)
{
    polynode temp;
    for(int i=1; i<=L2.Size(); i++)
    {
        temp.exp=L2.Retrieve(i).exp;
        temp.coef=L2.Retrieve(i).coef*(-1);
        L2.Delete(i);
        L2.Insert(i,temp);
    }
    PolyAdd(L1,L2,L3);
}
void Sort(list<polynode> L)
{
    for(int i=1; i<L.Size(); i++)
    {
        for(int j=i+1; j<=L.Size(); j++)
        {
            if(L.Retrieve(j).exp>L.Retrieve(i).exp)
                L.Swap(i,j);
        }
    }
}
void Print(list<polynode> L)
{
    if(!L.Empty())
    {
        Sort(L);
        printf("%dx^%d",L.Retrieve(1).coef,L.Retrieve(1).exp);
        for(int i=2; i<=L.Size(); i++)
        {
            if(L.Retrieve(i).coef>0)
                printf("+%dx^%d",L.Retrieve(i).coef,L.Retrieve(i).exp);
            else if(L.Retrieve(i).coef<0)
                printf("%dx^%d",L.Retrieve(i).coef,L.Retrieve(i).exp);
        }
        printf("\n");
    }
}
/*
2
4 1
2 2

3
6 5
4 3
1 0
*/

////�������ʱ����ʵ�������������Ա�
//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include "list.h"
//
//using namespace std;
//
//int main()
//{
//    list<double> L1,L2;
//    int n,temp;
//    double year,rate,money,time;
//    bool flag;
//    printf("�������ʱ����\n1---����\n2---ɾ��\n3---�޸�\n4---��ӡ\n5---��ѯ\n6---����\n7---����\n����----����\n");
//    while(scanf(" %d",&n)!=EOF)
//    {
//        flag=true;
//        switch(n)
//        {
//        case 1://����
//           printf("�������޺�����\n");
//           scanf(" %lf %lf",&year,&rate);
//           L1.Insert(L1.First(),year);//���뵽���Ա��еĵ�һ��λ��
//           L2.Insert(L2.First(),rate);//���뵽���Ա��еĵ�һ��λ��
//           break;
//        case 2://ɾ��
//           printf("����Ҫɾ��������\n");
//           scanf(" %lf",&year);
//           if(L1.Locate(year)==-1)
//             printf("Ҫɾ�������޲�����\n");
//           else
//           {
//            L1.Delete(L1.Locate(year));
//            L2.Delete(L1.Locate(year));
//           }
//           break;
//        case 3://�޸�
//            printf("����Ҫ�޸ĵ�����\n");
//            scanf(" %lf",&year);
//            temp=L1.Locate(year);
//            if(temp==-1)
//             printf("Ҫ�޸ĵ����޲�����\n");
//            else
//            {
//                L1.Delete(temp);
//                L2.Delete(temp);
//                printf("�����µ����޺�����\n");
//                scanf(" %lf %lf",&year,&rate);
//                L1.Insert(temp,year);
//                L2.Insert(temp,rate);
//            }
//            break;
//        case 4://��ӡ
//           if(!L1.Empty())
//           {
//               for(temp=L1.First();temp<=L1.Size();temp=L1.Next(temp))
//                 printf("%.2lf----%.3lf\n",L1.Retrieve(temp),L2.Retrieve(temp));
//           }
//           else printf("���Ա�Ϊ��\n");
//           break;
//        case 5://��ѯ
//            if(!L1.Empty())
//            {
//                printf("����Ҫ���ҵ�����\n");
//                scanf(" %lf",&year);
//                for(temp=L1.First();temp<=L1.Size();temp=L1.Next(temp))
//                {
//                    if (L1.Retrieve(temp)==year)
//                    {
//                        printf("����Ϊ:%.3lf\n",L2.Retrieve(temp));
//                        break;
//                    }
//                }
//                if(temp==L1.End())
//                  printf("û���ҵ���Ӧ������\n");
//            }
//            else
//              printf("���Ա�Ϊ��\n");
//            break;
//        case 6://����
//            for(int i=L1.First();i<=L1.Size()-1;i++)
//            {
//                for(int j=i+1;j<=L1.Size();j++)
//                {
//                    if(L2.Retrieve(j)<L2.Retrieve(i))
//                    {
//                        L1.Swap(i,j);
//                        L2.Swap(i,j);
//                    }
//                }
//            }
//            break;
//         case 7://����
//            printf("�������޺�����\n");
//            scanf(" %lf %lf",&year,&rate);
//            temp=L1.Locate(year);
//            if(temp==-1||L2.Retrieve(temp)!=rate)
//              printf("���ʲ�����\n");
//            else
//            {
//               printf("�����û�������޺ͱ���\n");
//               scanf(" %lf %lf",&time,&money);
//               for(int i=1;i<=time;i++)
//               {
//                   money=money*pow((1.0+rate),1/year);
//               }
//               printf("�����û����õ�%.3lf$\n",money);
//            }
//            break;
//        default:
//            flag=false;
//            break;
//        }
//        if(!flag) break;
//        printf("�������ʱ����\n1---����\n2---ɾ��\n3---�޸�\n4---��ӡ\n5---��ѯ\n6---����\n7---����\n����----����\n");
//    }
//    return 0;
//}
