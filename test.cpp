#include <stdio.h>
#include <stdlib.h>
#include <ctime>
typedef struct NODE
{
	int m_data;
	struct NODE* pNext;
}NODE;
NODE* Creat_Head();//����ͷ�ڵ�
bool creat_list(NODE* p,int len);//��������
bool insert_list(NODE* p, int pos, int num);//����
bool delete_list(NODE* p,int pos,int* num);//ɾ������
bool sort_list(NODE* p);//����
int len_list(NODE* p);//���㳤��
void show_list(NODE* p);//��ʾ����
void test01()
{
	int num;
	NODE* p= Creat_Head();
	creat_list(p, 5);	
	show_list(p);
	printf("------------------\r\n");
	insert_list(p, 3,100);
	show_list(p);
	printf("------------------\r\n");
	delete_list(p,3,&num);
	show_list(p);
	printf("------------------\r\n");
	sort_list(p);
	show_list(p);
	printf("------------------\r\n");
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
		printf("�����ڴ�ʧ��\r\n");
		exit(-1);
	}
	p->pNext = NULL;
	return p;
}
bool creat_list(NODE* p,int len)
{
	for (int i = 0; i < len; i++)
	{
		NODE* temp=(NODE*)malloc(sizeof(NODE));
		if (temp == NULL)
		{
			printf("�����ڴ�ʧ��\r\n");
			exit(-1);
		}
		temp->m_data = rand()%10;
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
bool delete_list(NODE* p,int pos,int* num)//pos��1��ʼ,����洢����
{
	NODE* temp=NULL;
	for (int i = 0; i < pos-1; i++)//���pָ��pos-1
	{
		p = p->pNext;
		if (p->pNext== NULL)
		{
			printf("����û����ô��\r\n");
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
bool insert_list(NODE* p, int pos, int num)
{
	int i = 0;
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	if (temp == NULL)
	{
		printf("�����ڴ�ʧ��\r\n");
		return 0;
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
	return 1;
}
bool sort_list(NODE* p)
{
	int i = 0, j = 0,len=len_list(p),change_num;
	NODE* temp=NULL;	
	for (i = 0; i < len-1; i++)
	{		
		p = p->pNext;
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
	return 1;
}








