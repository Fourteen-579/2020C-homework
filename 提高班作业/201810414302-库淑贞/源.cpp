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
bool IniList(List *L)  //��ʼ��
{
	L->list = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L->list)
	{
		return false;
	}
	L->size = 0;
	L->maxsize = LIST_INIT_SIZE;
	cout << "��ʼ���ɹ�" << endl;
	return true;
}
bool ascendList(int num, List *L)  //����Ԫ�ز�ʹ������
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
List nList()  //����һ����N��Ԫ�ص����Ա�
{
	int n;
	cout << "������Ҫ���Ա�ĳ��ȣ�";
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
		cout << "������Ҫ��������ݣ�";
		cin >> numbers;
		if (!ascendList(numbers, &L))
		{
			cout << "��������ʧ��";
			exit(0);
		}
	}
	return L;
}
bool deleteList(int num, List *L)  //ɾ��ĳһԪ��
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
	cout << endl << "ɾ���ɹ�" << endl;
	return true;
}
void print(List *L)  //����
{
	cout << "�ñ����ݣ�";
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
	cout << endl<<"��������Ҫɾ�������ݣ�";
	cin >> n;
	deleteList(n, &L);
	print(&L);
	cout <<endl<< "��������Ҫ��������ݣ�";
	cin >> n;
	ascendList(n, &L);
	print(&L);
	getchar();
	getchar();
	return 0;
}
