#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
using namespace std;
 
struct sqlist{
    int * StuNode;
    int length;
    int MaxSize;
};  //˳���
 
void shuchu(sqlist& InforList);
void Delist_El_same(sqlist& InforList);

int main()
{
    sqlist InforList;
	InforList.MaxSize = 50000;
    InforList.StuNode = (int *)malloc(InforList.MaxSize * sizeof(int));
 
	//����˳����ʼԪ�ظ���
    int StuNum;
    cin >> StuNum;
    InforList.length = StuNum;
    
	//�����ʼ��Ϣ 
    for (int i = 0; i <= InforList.length - 1; i++)
        cin >> InforList.StuNode[i];

	Delist_El_same(InforList);
	shuchu(InforList);
}

void Delist_El_same(sqlist& InforList)    //
{
	for(int i=0;i<InforList.length;i++){
		for(int j=i+1; j<InforList.length; j++){
			if(InforList.StuNode[j] == InforList.StuNode[i]){
				for(int k=j; k+1<InforList.length;k++){
					InforList.StuNode[k] = InforList.StuNode[k+1];
					}
				InforList.length--;
				j--;     //ע�⣬Ԫ��j+1�ƶ�����j��������j������һ����Ҫ������
			}
		}
	}
}

void shuchu(sqlist& InforList)
{
	int i = 1;
	while(i < InforList.length)
	{
		cout << InforList.StuNode[i-1] << "  ";
		i++;
	}
	cout << InforList.StuNode[i-1];
}