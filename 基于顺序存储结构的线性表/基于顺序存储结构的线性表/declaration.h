#pragma once
/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

					  /*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct {  //˳���˳��ṹ���Ķ���
	ElemType * elem;
	int length;
	int listsize;
}SqList;
/*-----page 19 on textbook ---------*/
status IntiaList(SqList & L);
status DestroyList(SqList * L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType & e);
int LocateElem(SqList L,ElemType e); //�򻯹�
status PriorElem(SqList L,ElemType cur,ElemType & pre_e);
status NextElem(SqList L,ElemType cur,ElemType & next_e);
status ListInsert(SqList & L,int i,ElemType e);
status ListDelete(SqList & L, int i, ElemType & e);
status ListTrabverse(SqList L);  //�򻯹�
status LoadFromFile(SqList &L);
status ExportToFile(SqList L);
								 /*--------------------------------------------*/