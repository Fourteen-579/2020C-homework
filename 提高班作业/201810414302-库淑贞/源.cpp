#include<iostream>
using namespace std;
typedef int elemtype;
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
typedef struct List
{
	elemtype* list;
	int maxsize;
	int size;
}List;
bool IniList(List *L)  //初始化
{
	L->list = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L->list)
	{
		return false;
	}
	L->size = 0;
	L->maxsize = LIST_INIT_SIZE;
	cout << "初始化成功" << endl;
	return true;
}
bool ascendList(int num, List *L)  //插入元素并使其升序
{
	if ((L->size + 1) > L->maxsize)
	{
		L->list = (int*)realloc(L->list, sizeof(int)*(L->size + LISTINCREMENT));
		if (!L->list)
		{
			return false;
		}
	}
	if (L->size == 0)
	{
		L->list[0] = num;
		L->size += 1;
		return true;
	}
	int i = L->size - 1;
	int temp = num;
	while (temp < L->list[i] && i >= 0)
	{
		L->list[i + 1] = L->list[i];
		--i;
	}
	L->list[i + 1] = temp;
	L->size += 1;
	return true;
}
List nList()  //建立一个含N个元素的线性表
{
	int n;
	cout << "输入需要线性表的长度：";
	cin >> n;
	List L;
	L.list = (int*)malloc(n * sizeof(int));
	if (!L.list)
	{
		exit(0);
	}
	L.size = 0;
	L.maxsize = LIST_INIT_SIZE;
	int numbers;
	for (int i = 0; i < n; ++i)
	{
		cout << "输入需要插入的数据：";
		cin >> numbers;
		if (!ascendList(numbers, &L))
		{
			cout << "插入数据失败";
			exit(0);
		}
	}
	return L;
}
bool deleteList(int num, List *L)  //删除某一元素
{
	int i, j;
	for (i = 0; i < L->size; ++i)
	{
		if (num == L->list[i])
		{
			j = i;
			while (j <= L->size)
			{
				L->list[j] = L->list[j + 1];
				++j;
			}
			L->size -= 1;
			--i;
		}
	}
	cout << endl << "删除成功" << endl;
	return true;
}
void print(List *L)  //遍历
{
	cout << "该表数据：";
	for (int i = 0; i < L->size; ++i)
	{
		cout << L->list[i] << "   ";
	}
	return;
}
int main()
{
	List L;
	IniList(&L);
	L = nList();
	print(&L);
	int n = 0;
	cout << endl<<"输入你想要删除的数据：";
	cin >> n;
	deleteList(n, &L);
	print(&L);
	cout <<endl<< "输入你想要插入的数据：";
	cin >> n;
	ascendList(n, &L);
	print(&L);
	getchar();
	getchar();
	return 0;
}
