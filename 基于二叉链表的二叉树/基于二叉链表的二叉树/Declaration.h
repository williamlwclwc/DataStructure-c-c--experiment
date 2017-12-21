#pragma once
/*Binary Tree On Binary-Tree-List Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -2
#define MaxLength 100

typedef int status;
typedef char ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct Bi_Node
{
	//二叉树（二叉链表）结点定义
	ElemType data;//数据域
	int key;//关键字
	struct Bi_Node *lchild,*rchild;//左右孩子指针
}Tree,*T_Node;

typedef struct Tree_head
{
	//树的头结点定义
	char name[20];//树的名字
	int num = 0;//树的总结点数目
	Tree *root = NULL;//指向根结点
}Head;

typedef struct Mul_Tree
{
	//森林管理结构体定义
	Head *elem;//树的头结点数组
	int length;//树的总数
	int listsize ;//树的最大数量
}SqList;

typedef struct queue
{
	Tree* data[100];
	int front;
	int rear;
}seq;

/*-----函数声明 ---------*/
status InitBiTree(SqList&L);
void FreeNode(Tree *root);
status DestroyBiTree(SqList&L);
status CreateBiTree(Tree**root,char*definition);
status ClearBiTree(SqList&L);
status BiTreeEmpty(Head T);
int BiTreeDepth(Tree* T);
Tree* Root(SqList L);
Tree* search_tree(Tree* T, int e);
char Value(Tree* T, int e);
status Assign(T_Node &T, int e, char value);
Tree *Parent(Tree* T, int e);
Tree* LeftChild(Tree* T, int e);
Tree* RightChild(Tree* T, int e);
Tree* LeftSibling(Tree* T, int e);
Tree* RightSibling(Tree* T, int e);
status InsertChild(Tree* T, int e, int LR, Tree* Add);
status DeleteChild(Tree* T, int e, int LR);
void Visit(Tree*T);
void PreOrderTraverse(Tree *T);
void InOrderTraverse(Tree *T);
void PostOrderTraverse(Tree *T);
void LevelOrderTraverse(Tree *T);
void enter(seq *q, Tree* t);
Tree* del(seq *q);
status qEmpty(seq q);
status LoadFromFile(Tree**T);
status ExportToFile(Tree*T);
void PreOTfile(Tree *T);
/*--------------------------------------------*/

