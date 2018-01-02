#pragma once
/* Graph On Adjacency List Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -2
//#define INFEASTABLE -1
//#define OVERFLOW -2
#define MaxLength 100

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

//�㼯���壨ͼ�Ķ��㣩
typedef struct Nodes
{
	ElemType data;//����data��
	struct Edges *first_adj;//ָ���һ���ڽӵ�
}Vertice,N[MaxLength];
//�߼����壨�ڽ�����
typedef struct Edges
{
	int ajvex;//�ñ�ָ��Ķ������
	struct Edges *next;//ָ����һ���߽���ָ��
	//int weight;//Ȩֵ
}E;
//ͼ�Ķ��壨ͼ��ͷ��㣩
typedef struct GNode
{
	N vertices;//ͼ�Ķ�������
	int ver_num;//ͼ�Ķ�������
	int ed_num;//ͼ�ı�����
}Graph;

//���ж���
typedef struct queue
{
	struct Nodes* data[100];
	int front;
	int rear;
}seq;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

/*-----Declarations of Functions ---------*/
status CreateGraph(Graph &G);
status DestroyGraph(Graph &G);
int LocateVex(Graph G, ElemType u);
Vertice* GetVex(Graph G, ElemType v);
status PutVex(Graph &G, ElemType v, ElemType value);
Vertice* FirstAdjVex(Graph G, ElemType v);
Vertice* NextAdjVex(Graph G, ElemType v, ElemType w);
status InsertVex(Graph &G, ElemType v);
status DeleteVex(Graph &G, ElemType v);
status InsertArc(Graph &G, ElemType v, ElemType w);
status DeleteArc(Graph &G, ElemType v, ElemType w);
void Visit(Vertice v);
status DFSTraverse(Graph G);
void DFS_re(Graph G, Vertice *v, bool *visited);
status BFSTraverse(Graph G);
void enter(seq *q, Nodes* t);
Nodes* del(seq*q);
status qEmpty(seq q);
status LoadFromFile(Graph &G);
status ExportToFile(Graph G);
status Switch_Graph();
/*--------------------------------------------*/
