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
typedef int ElemType; //数据元素类型定义

//点集定义（图的顶点）
typedef struct Nodes
{
	ElemType data;//结点的data域
	struct Edges *first_adj;//指向第一个邻接点
}Vertice,N[MaxLength];
//边集定义（邻接链）
typedef struct Edges
{
	int ajvex;//该边指向的顶点序号
	struct Edges *next;//指向下一个边结点的指针
	//int weight;//权值
}E;
//图的定义（图的头结点）
typedef struct GNode
{
	N vertices;//图的顶点数组
	int ver_num;//图的顶点数量
	int ed_num;//图的边数量
}Graph;

//队列定义
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
