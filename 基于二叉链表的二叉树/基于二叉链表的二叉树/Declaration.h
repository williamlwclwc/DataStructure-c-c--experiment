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
typedef char ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct Bi_Node
{
	//������������������㶨��
	ElemType data;//������
	int key;//�ؼ���
	struct Bi_Node *lchild,*rchild;//���Һ���ָ��
}Tree,*T_Node;

typedef struct Tree_head
{
	//����ͷ��㶨��
	char name[20];//��������
	int num = 0;//�����ܽ����Ŀ
	Tree *root = NULL;//ָ������
}Head;

typedef struct Mul_Tree
{
	//ɭ�ֹ���ṹ�嶨��
	Head *elem;//����ͷ�������
	int length;//��������
	int listsize ;//�����������
}SqList;

typedef struct queue
{
	Tree* data[100];
	int front;
	int rear;
}seq;

/*-----�������� ---------*/
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

