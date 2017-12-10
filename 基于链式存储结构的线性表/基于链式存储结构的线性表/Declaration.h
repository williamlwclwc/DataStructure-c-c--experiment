#pragma once
#pragma once
/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -2
//#define INFEASTABLE -1
//#define OVERFLOW -2
#define MaxLength 100

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct LNode
{  
	//˳�����ʽ�ṹ���Ķ���
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

typedef struct Mul_List
{
	//��ͷ����ʵ�ֶ��
	int num;//������
	LinkList L;
	struct Mul_List *next;
}Mul_List,*Mul;

/*-----on textbook ---------*/
status IntiaList(LinkList & L);
status DestroyList(LinkList &L);
status ClearList(LinkList &L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType & e);
int LocateElem(LinkList L, ElemType e); //�򻯹�
status PriorElem(LinkList L, ElemType cur, ElemType & pre_e);
status NextElem(LinkList L, ElemType cur, ElemType & next_e);
status ListInsert(LinkList & L, int i, ElemType e);
status ListDelete(LinkList & L, int i, ElemType & e);
status ListTrabverse(LinkList L);  //�򻯹�
status LoadFromFile(FILE*fp, LinkList &L);
status ExportToFile(FILE*fp, LinkList L);
int Switch_List();
/*--------------------------------------------*/
