//��Ԫ�����ת��
//�²ۣ�����Ҫ����ҵ������...ѧ������а����ľ�У�����õģ��Ż�ʲô��̸������...����....
#include<iostream>
using namespace std;
#include  "threemat.h"
int main()
{
    TSMatrix<int>  mat;
    cin >> mat.row >> mat.col >> mat.unzero;
    for(int l=0; l<mat.unzero; l++)
        cin >> mat.data[l].i >> mat.data[l].j >> mat.data[l].v;
    cout << "ԭ����Ϊ:" << endl;
    mat.show();
    mat.turn();
    cout << endl << "ת��֮��ľ���Ϊ��" << endl;
    mat.show();
    return 0;
}
//
//3 3 4
//0 0 1
//0 1 2
//0 2 3
//1 2 4
