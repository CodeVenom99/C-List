#include <stdio.h>
#include <stdlib.h>
#include <ctime>
typedef struct NODE
{
	int m_data;
	struct NODE* pNext;
}NODE;
NODE* Creat_Head();
bool creat_list(NODE* p,int len);
int len_list(NODE* p);
void show_list(NODE* p);
bool delete_list(NODE* p,int pos,int* num);
void sort_list(NODE* p);
void insert_list(NODE* p, int pos, int num);
void test01()
{
	int num;
	NODE* p= Creat_Head();
	creat_list(p, 5);	
	show_list(p);
	printf("------------------\r\n");
	//insert_list(p, 3,100);
	//show_list(p);
	//printf("------------------\r\n");
	//delete_list(p,3,&num);
	//show_list(p);
	//printf("------------------\r\n");
	sort_list(p);
	show_list(p);
	printf("------------------\r\n");
}
void test02()
{
	int num[5] = { 1,7,3,8,5 };
	int i = 0, j = 0,change_num;
	for (i = 0; i < 5; i++)
	{
		for (j = i+1; j < 5; j++)
		{
			if (num[i] < num[j])
			{
				change_num = num[j];
				num[j] = num[i];
				num[i] = change_num;
			}

		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d\r\n",num[i]);
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	test01();
	return 0;
}
NODE* Creat_Head()
{
	NODE* p = (NODE*)malloc(sizeof(NODE));
	if (p == NULL)
	{
		printf("创建内存失败\r\n");
		exit(-1);
	}
	p->pNext = NULL;
	return p;
}
bool creat_list(NODE* p,int len)
{
	int num[5] = { 5,2,6,6,7 };
	for (int i = 0; i < len; i++)
	{
		NODE* temp=(NODE*)malloc(sizeof(NODE));
		if (temp == NULL)
		{
			printf("创建内存失败\r\n");
			exit(-1);
		}
		temp->m_data = num[i];
		temp->pNext = NULL;
		p->pNext = temp;
		p = p->pNext;
	}
	return 1;

}
void show_list(NODE* p)
{
	while (p->pNext != NULL)
	{
		printf("%d\r\n", p->pNext->m_data);
		p = p->pNext;
	}
}
int len_list(NODE* p)
{
	int cout = 0;
	while (p->pNext != NULL)
	{
		p = p->pNext;
		cout++;
	}
	return cout;
}
bool delete_list(NODE* p,int pos,int* num)//pos从1开始,差个存储数据
{
	NODE* temp=NULL;
	for (int i = 0; i < pos-1; i++)//最后p指向pos-1
	{
		p = p->pNext;
		if (p->pNext== NULL)
		{
			printf("链表没有这么长\r\n");
			exit(-1);
		}

	}
	temp = p->pNext;
	p->pNext = p->pNext->pNext;
	*num = temp->m_data;
	free(temp);
	temp = NULL;
	return 1;
}
void insert_list(NODE* p, int pos, int num)
{
	int i = 0;
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	if (temp == NULL)
	{
		printf("创建内存失败\r\n");
		exit(-1);
	}
	temp->m_data = num;
	while (p->pNext != NULL && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	temp->pNext = p->pNext;
	p->pNext = temp;
}
void sort_list(NODE* p)
{
	int i = 0, j = 0,len=len_list(p),change_num;
	NODE* temp=NULL;
	p = p->pNext;
	for (i = 0; i < len; i++,p = p->pNext)
	{		
		for (j = i + 1 ,temp = p->pNext; j < len; j++,temp = temp->pNext)
		{
			if (p->m_data < temp->m_data)
			{
				change_num = temp->m_data;
				temp->m_data = p->m_data;
				p->m_data = change_num;
			}
		}
	}
}








