#include <iostream>
#include <stdio.h>
#include "forest.h"
forest<char> v;
using namespace std;
int main()
{
    cout<<"��ɭ��"<<endl;
    v.CreateForest();
    v.Print();
    cout<<"ת��Ϊ������:"<<endl;
    v.TransformForesttoBT();
    cout<<"��������"<<endl;
    v.CreateBT();
    cout<<"������תɭ��:"<<endl;
    v.TransformBTtoForest();
    v.Print();
    return 0;
}

