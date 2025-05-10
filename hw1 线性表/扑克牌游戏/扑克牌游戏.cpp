#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
using namespace std;
 
struct puke {
    char color[15];
    char num[5];
};  //�˿�����Ϣ 
 
struct sqlist {
    puke * Node;
    int length;
};  //�˿�����Ϣ�� 
 
void Append(sqlist& List);
void Extract(sqlist& List);
void Revert(sqlist& List);
void Pop(sqlist& List);
void shuchu(sqlist& List);

//�Ƚ��������ݵĴ�С
int compare(char *a,char *b)
{
	int a1,b1;
	string a2=a,b2=b;
	a1=atoi(a);
	b1=atoi(b);
	if (a2 == "A") a1=1;
	if (b2 == "A") b1=1;
	if (a2 == "J") a1=11;
	if (b2 == "J") b1=11;
	if (a2 == "Q") a1=12;
	if (b2 == "Q") b1=12;
	if (a2 == "K") a1=13;
	if (b2 == "K") b1=13;
	if (a1 >b1){
		return 1;
	}
	else
		return 0;
}


int main()
{
    sqlist List;
	List.length=0;
    List.Node = (puke * )malloc(10000 * sizeof(puke));
 
	//������������
    int TotalNum;
    cin >> TotalNum;

	//���벢ִ������
	for(int i=1;i<=TotalNum;++i){
		string command;
        cin >> command;
        if (command == "Pop"){
            Pop(List);
        }
        else if (command == "Append") {
            Append(List);
        }
        else if (command == "Extract") {
            Extract(List);
        }
        else if (command == "Revert") {
            Revert(List);
        }
	}
	//��ӡ�ƶ��������ƵĻ�ɫ������
	shuchu(List);
}
 

//���һ���˿��Ƶ��ƶѵĵײ� 
void Append(sqlist& List)
{
    cin >> List.Node[List.length].color >> List.Node[List.length].num;
	++List.length;
}



//ʹ�����ƶ�����
void Revert(sqlist& List)
{
	puke temp;  //��������
    for(int i=0;i<List.length/2;i++){
        temp=List.Node[i];  //���� List.Node[i]�� List.Node[List.length-i-1]
        List.Node[i]=List.Node[List.length-i-1];
        List.Node[List.length-i-1]=temp;
    }
}



//����ƶѷǿգ����ȥ�ƶѶ����ĵ�һ���ƣ�����ӡ���ƵĻ�ɫ�����֣�����ƶ�Ϊ�գ����ӡNULL��
void Pop(sqlist& List)
{
	if (List.length != 0){
		cout << List.Node[0].color << " " << List.Node[0].num << endl;
		for(int i=0;i<=List.length-2;i++)
			List.Node[i]=List.Node[i+1];
		--List.length;
	}
	else
		cout << "NULL" << endl;
}



//���ƶ��г�ȡĳ�ֻ�ɫ�������ƣ����ձ�Ŵ�С����������򣬲��ŵ��ƶѵĶ�����
void Extract(sqlist& List)
{
	string col;
	cin >> col;
	puke temp;
	for(int i=0;i<=List.length-2;++i){
		for(int j=List.length-1;j>=i+1;--j){
			if (List.Node[j].color == col && (List.Node[j-1].color != col || (compare(List.Node[j-1].num, List.Node[j].num) && List.Node[j-1].color ==col)))
			{
				temp=List.Node[j];
				List.Node[j]=List.Node[j-1];
				List.Node[j-1]=temp;
			}
		}
	}
}
 
//��ӡ�ƶ��������ƻ�ɫ�����֣����ƶѶ����ƶѵף�������ƶ�Ϊ�գ����ӡNULL��
void shuchu(sqlist& List)
{
	if (List.length != 0){
		for(int i=0;i<=List.length-1;++i)
			cout << List.Node[i].color << " " << List.Node[i].num << endl;
	}
	else
		cout << "NULL" << endl;
}