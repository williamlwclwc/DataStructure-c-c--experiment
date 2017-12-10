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
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct LNode
{  
	//顺序表（链式结构）的定义
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

typedef struct Mul_List
{
	//表头链表实现多表
	int num;//多表序号
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
int LocateElem(LinkList L, ElemType e); //简化过
status PriorElem(LinkList L, ElemType cur, ElemType & pre_e);
status NextElem(LinkList L, ElemType cur, ElemType & next_e);
status ListInsert(LinkList & L, int i, ElemType e);
status ListDelete(LinkList & L, int i, ElemType & e);
status ListTrabverse(LinkList L);  //简化过
status LoadFromFile(FILE*fp, LinkList &L);
status ExportToFile(FILE*fp, LinkList L);
int Switch_List();
/*--------------------------------------------*/
