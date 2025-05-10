#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
using namespace std;
 
struct puke {
    char color[15];
    char num[5];
};  //扑克牌信息 
 
struct sqlist {
    puke * Node;
    int length;
};  //扑克牌信息表 
 
void Append(sqlist& List);
void Extract(sqlist& List);
void Revert(sqlist& List);
void Pop(sqlist& List);
void shuchu(sqlist& List);

//比较两个数据的大小
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
 
	//输入命令数量
    int TotalNum;
    cin >> TotalNum;

	//输入并执行命令
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
	//打印牌堆中所有牌的花色和数字
	shuchu(List);
}
 

//添加一张扑克牌到牌堆的底部 
void Append(sqlist& List)
{
    cin >> List.Node[List.length].color >> List.Node[List.length].num;
	++List.length;
}



//使整个牌堆逆序
void Revert(sqlist& List)
{
	puke temp;  //辅助变量
    for(int i=0;i<List.length/2;i++){
        temp=List.Node[i];  //交换 List.Node[i]与 List.Node[List.length-i-1]
        List.Node[i]=List.Node[List.length-i-1];
        List.Node[List.length-i-1]=temp;
    }
}



//如果牌堆非空，则除去牌堆顶部的第一张牌，并打印该牌的花色和数字；如果牌堆为空，则打印NULL。
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



//从牌堆中抽取某种花色的所有牌，按照编号从小到大进行排序，并放到牌堆的顶部。
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
 
//打印牌堆中所有牌花色和数字（从牌堆顶到牌堆底），如果牌堆为空，则打印NULL。
void shuchu(sqlist& List)
{
	if (List.length != 0){
		for(int i=0;i<=List.length-1;++i)
			cout << List.Node[i].color << " " << List.Node[i].num << endl;
	}
	else
		cout << "NULL" << endl;
}