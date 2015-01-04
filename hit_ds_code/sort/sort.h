//file:sort.h
#ifndef _SORT_HIT_HUMING_INCLUDE_
#define _SORT_HIT_HUMING_INCLUDE_
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef int T;
void print(T a[],int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void Swap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}
//hint:�������еĶ��ǰ���������
//-------------����BubbleSort-----------
//o(n^2) �ȶ�
void Basic_BubbleSort(T a[],int n)
{
    for(int i=1; i<n; i++) //��1->n-1����С���������
        for(int j=n-1; j>=i; j--) //�����⣬�����򽻻�
            if(a[j]<a[j-1])
                Swap(a[j],a[j-1]);
}
//-------------�Ľ���BubbleSort-----------
//���۵㣺ĳЩϵ�в���n-1�ξ��Ѿ��ź����������Ļ�����ļ��Ͳ���Ҫ
//������һ������ģ���"��"�ı������������棩;
//��������һ����־λ����Ƿ����������������������˵����û����ȫ�źã�
//û����ô�Ѿ��ź����Ͳ��ü����;
//o(n^2) �ȶ�
void BubbleSort(T a[],int n)
{
    for(int i=1; i<n; i++)
    {
        bool exchange=false; //ÿһ�˼��֮ǰ����־Ϊû�з�������
        for(int j=n-1; j>=i; j--)
        {
            if(a[j]<a[j-1])
            {
                Swap(a[j],a[j-1]);
                exchange=true;
            }
        }
        if(!exchange) return;//û�з�����������ô�Ѿ��ź���
    }
}
//-----------------------------
//---------QuickSort-----------
//-----------------------------
//�Ľ������������۵㣺
//�����ܵıȽϴ������ƶ���
//->�����¼�ıȽϺ��ƶ���
//->�ϴ��¼��ǰ��ֱ���ƶ������棬��С��¼�Ӻ���ֱ���ƶ���ǰ��
//���ţ�ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�
//����һ���ֵ��������ݶ�������һ�����ֵ��������ݶ�ҪС��
//Ȼ���ٰ��˷����������������ݷֱ𣨷��ε�˼�룩���п�������
//���� ������̿��Եݹ���У��Դ˴ﵽ�������ݱ���������С�
int FindPivot(T a[],int low,int high)
{
//ѡ���һ��Ԫ����Ϊ��׼Ԫ��
//    int pivotpos=low;
//    for(int i=low+1; i<=high; i++)
//    {
//        if(a[i]<a[low])
//        {
//            pivotpos++;
//            if(pivotpos!=i)Swap(a[i],a[pivotpos]);
//        }
//    }
//    Swap(a[low],a[pivotpos]);//��׼Ԫ�ؾ�λ
//    return pivotpos;
    //���źö�ѡȡ�ķ�ʽ�������������Ҿ���д�ģ��պ���ʱ�����о��ɣ�
    //����һ����
    while(low<high)
    {
        while(low<high&&a[high]>=a[low])
            high--;
        Swap(a[low],a[high]);
        while(low<high&&a[low]<=a[high])
            low++;
        Swap(a[low],a[high]);
    }
    return low;
}
void Nec_QuickSort(T a[],int left,int right)
{
    if(left<right)
    {
        int pivotpos=FindPivot(a,left,right);
        Nec_QuickSort(a,left,pivotpos-1);
        Nec_QuickSort(a,pivotpos+1,right);
    }
}
void qsort(T a[],int n)
{
    Nec_QuickSort(a,0,n-1);
}
//-----------SelectSort----------
//0(n^2)  ���ȶ�
void SelectSort(T a[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int k=i;
        for(int j=i+1; j<n; j++)
            if(a[k]>a[j])   k=j;
        Swap(a[i],a[k]);
    }
}
void pushdown(T a[],int first,int last)
{
    int i=first,j=2*i+1;//jΪi�������
    T temp=a[i];//����ӽڵ�ĸ�
    while(j<=last)//����Ƿ�����λ��
    {
        if(j<last&&a[j]<a[j+1]) j++;//jָ������еĽϴ��һ��
        if(temp>=a[j]) break;//���Ƚϴ󣬲�����
        else
        {
            a[i]=a[j];
            i=j;
            j=2*j+1;//ָ������
        }
    }
    a[i]=temp;
}
void heapsort(T a[],int n)
{
    int i;
    for(i=(n-2)/2; i>=0; i--)
        pushdown(a,i,n-1);
    //���ѽ���
    for(i=n-1; i>=0; i--)
    {
        Swap(a[0],a[i]);
        pushdown(a,0,i-1);
    }//�����������棬Ȼ������һ�������Ϳ��Եõ�һ�������������
}
//--------Insertsort---------
void Insertsort(T a[],int n)
{
    //����һ�����˿˵�ʱ������Ĺ���
    for(int i=1; i<n; i++)
    {
        int key=a[i],j=i-1;
        while(a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
//���۵㣺����ʱ���ö���
void BinaryInsertsort(T a[],int n)
{
    int i,key,low,high,mid,k;
    for(i=1; i<n; i++)
    {
        key=a[i],low=0,high=i-1;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(key<a[mid])high=mid-1;
            else low=mid+1;
        }//������
        for(k=i-1; k>=low; k--)a[k+1]=a[k];
        a[low]=key;
    }
}
//--------------ShellSort-------------
//�Բ���ĸĽ����۵㣺�ֿ�����
void ShellSort(T a[],int n)
{
    //Knuth���������ȡ��� shell��ʱ���������n/2�����ֲ�̫��
    //��Ϊ����ѡȡ�ߵ����һ����ʱ��������λ�õĲŻ�����ż��λ�õıȽϣ�Ч�ʵͣ�
    //(�廪��������ôд�ģ�������������ѡȡ��ʾ��̫��⣬�������գ�)
    for(int gap=n/3+1; gap>1; gap=gap/3+1)
        for(int i=gap; i<n; i++)
            for(int j=i-gap; j>=0&&a[j]>a[j+gap]; j-=gap)
                Swap(a[j],a[j+gap]);
}
void Merge (T a[] ,T b[],int s,int m , int t )
{
    //����������A[s],��,A[m]��A[m+1],��,A[t]�ϲ�Ϊһ����������B[s]
    int i = s,j = m+1 ,k=s ;
    while (i<= m&&j <= t)
        b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++] ;
    while ( i <= m ) b[k++] = a[i++] ;
    while ( j <= t ) b[k++] = a[j++] ;
}
void MergePass(int a[], int b[], int seg, int n)
{
    //�����������ǰ�a�г���Ϊseg���������й鲢�ɳ���Ϊ2seg�����з���b��
    int seg_start_ind = 0;
    while(seg_start_ind<=n-2*seg)
        //�鲢����С��n-2*seg�ſ��Թ鲢
    {
        Merge(a,b,seg_start_ind,seg_start_ind + seg - 1, seg_start_ind + 2*seg - 1);
        seg_start_ind+=2*seg;
    }
    //��������Σ�һ�ο��Թ鲢��������һ�αȽ϶̣���ô�ϲ�����
    if(seg_start_ind + seg < n)
        Merge(a,b,seg_start_ind,seg_start_ind+seg-1,n-1);
    else
        for(int j = seg_start_ind; j < n; j++) //���ֻʣ��һ��,ֱ�Ӹ��Ƶ�b[]��
            b[j] = a[j];
}
void  MergeSort(T a[],int n)
{
    T* temp = new int[n];
    int seg=1;
    while(seg < n)
    {
        MergePass(a,temp,seg,n);
        //��a�г���Ϊseg�������������кϲ���temp�У�
        seg*=2;
        MergePass(temp,a,seg,n);
        //��temp�г���Ϊseg�������������кϲ���a������
        seg*=2;
        //�鲢�ĳ���ûһ�ζ�Ҫ�������
    }
    delete [] temp;//���ٸ����ռ�temp
}

#endif
