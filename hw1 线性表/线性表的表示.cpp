#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
using namespace std;
 
struct student {
    char num[20];
    char name[20];
};  //学生信息 
 
struct sqlist {
    student * StuNode;
    int length;
    int MaxSize;
};  //学生信息表 
 
void insert(sqlist& InforList);
void remove(sqlist& InforList);
void check(sqlist& InforList);
void shuchu(sqlist& InforList);
int main()
{
    sqlist InforList;
	InforList.MaxSize = 20000;
    InforList.StuNode = (student * )malloc(InforList.MaxSize * sizeof(student));
 
	//输入初始学生数量
    int StuNum;
    cin >> StuNum;
    InforList.length = StuNum;
    
	//输入初始学生信息 
    for (int i = 0; i <= InforList.length-1; i++)
        cin >> InforList.StuNode[i].num >> InforList.StuNode[i].name;

    //执行操作 
    while (1)
    {
        string command;
        cin >> command;
        if (command == "end")
        {
            cout << InforList.length;
            break;
        }
        else if (command == "insert") {
            insert(InforList);
        }
        else if (command == "remove") {
            remove(InforList);
        }
        else if (command == "check") {
            check(InforList);
        }
		else if (command == "shuchu") {
            shuchu(InforList);
        }
        else
            ;
    }
    return 0;
}
 

//插入学生信息 
void insert(sqlist& InforList)
{
    int pos;
    cin >> pos;
    char tempnum[8];
    char tempname[20];
    cin >> tempnum >> tempname;
    if (pos<1 || pos > InforList.length + 1)
	{
        cout << -1 << endl;
    }
    else
	{
        for (int i = InforList.length - 1; i >= pos - 1; i--)
            InforList.StuNode[i + 1] = InforList.StuNode[i];
		strcpy(InforList.StuNode[pos - 1].num, tempnum);
        strcpy(InforList.StuNode[pos - 1].name, tempname);
        InforList.length++;
        cout << 0 << endl;
    }
}

//删除学生信息
void remove(sqlist& InforList)
{
	int poss;
	cin >> poss;
	if ((poss <= InforList.length) && (poss >= 1))
	{
		student* p;
		student* q;
		p = & (InforList.StuNode[poss-1]);
		q = InforList.StuNode + InforList.length - 1;
		for (++p; p <= q; ++p) *(p-1) = *p;
		--InforList.length;
		cout << 0 << endl;
	}
	else
		cout << -1 << endl;
}
 
//查找学生信息
void check(sqlist& InforList)
{
	string checktype;
	string nameornum;
	cin >> checktype;cin >> nameornum;
	if (checktype == "name")
	{
		int i = 1;
		while(i <= InforList.length && !(InforList.StuNode[i-1].name == nameornum)) ++i;
		if (i <= InforList.length)
			cout << i << " " << InforList.StuNode[i-1].num << " " << InforList.StuNode[i-1].name << endl;
		else cout << "-1" << endl;
	}
	else
	{
		int i = 1;
		while(i <= InforList.length && !(InforList.StuNode[i-1].num == nameornum)) ++i;
		if (i <= InforList.length)
			cout << i << " " << InforList.StuNode[i-1].num << " " << InforList.StuNode[i-1].name << endl;
		else cout << "-1" << endl;
	}
}

void shuchu(sqlist& InforList)
{
	int i = 1;
	while(i <= InforList.length)
	{
		cout << i << "  " << InforList.StuNode[i-1].num << "  " << InforList.StuNode[i-1].name << endl;
		i++;
	}
}
