#include "Declaration.h"//声明&定义头文件

int T_index = 1;//当前树的编号
SqList L;//声明森林管理结构体
Tree* re;
int count = 0;
FILE*fp;

void main(void) {
	int op = 1;
	int pos = 0, result,e,value,LR,temp=0;
	char definition[100];//创建树时输入的串
	char filename[30];
	Tree* Add;

	//Main Menu Entrance
	while (op) {
		system("cls");	printf("\n\n");
		printf("                      Menu for Binary-Tree On Binary-Tree-List Structure \n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("    	  1. InitBiTree（初始化二叉树）         2.DestroyBiTree（销毁二叉树） \n");
		printf("    	  3. CreateBiTree（创建二叉树）         4.ClearBiTree（清空二叉树） \n");
		printf("    	  5. BiTreeEmpty（判断空二叉树）        6.BiTreeDepth（求深度）  \n");
		printf("    	  7. Root（获得根结点）                 8.Value（获得结点） \n");
		printf("    	  9. Assign（结点赋值）                 10.Parent（获得双亲结点） \n");
		printf("    	  11.LeftChild（获得左孩子结点）        12.RightChild（获得右孩子结点）\n");
		printf("    	  13.LeftSibling（获得左兄弟结点）      14.RightSibling（获得右兄弟结点） \n");
		printf("    	  15.InsertChild（插入子树）            16.DeleteChild（删除子树） \n ");
		printf("    	  17.PreOrderTraverse（前序遍历）       18.InOrderTraverse（中序遍历） \n");
		printf("          19.PostOrderTraverse（后序遍历）      20.LevelOrderTraverse（按层遍历）\n");
		printf("    	  21.LoadFromFile（读取文件）           22.ExportToFile（输出到文件）\n");
		printf("          23 Multi-Operation（多树操作）\n");
		printf("    	  0. Exit\n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("当前操作的树为树%d:\n", T_index);
		printf("请选择你的操作[0~23]:");
		scanf_s("%d", &op);
		//根据用户输入调用相应函数，执行相应功能
		switch (op) {
		case 1:
			if (InitBiTree(L) == OK)
			{
				L.elem[T_index].num = 0;
				printf("初始化二叉树成功\n");
			}
			else
			{
				printf("初始化二叉树失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyBiTree(L) == OK)
			{
				printf("销毁二叉树成功\n");
			}
			else
			{
				printf("销毁失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 3:
			printf("请按照前序输入相应的key和data(key为0，data为#代表空):\n");
			printf("注意：如果key读入的不为数字，则视此结点为空\n请勿输入重复的key值，否则无法准确查找\n");
			getchar();
			scanf_s("%s", definition, 100);
			if (CreateBiTree(&L.elem[T_index].root, definition) == OK)
			{
				printf("二叉树创建成功\n");
				if (BiTreeEmpty(L.elem[T_index]) == TRUE)
				{
					printf("创建了空的二叉树\n");
				}
			}
			else
			{
				printf("二叉树创建失败\n");
			}
			count = 0;
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 4:
			if (ClearBiTree(L) == OK)
			{
				printf("清空成功\n");
			}
			else
			{
				printf("清空失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 5:
			if(L.length<T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				result = BiTreeEmpty(L.elem[T_index]);
				if (result == TRUE)
				{
					printf("二叉树为空\n");
				}
				else if (result == FALSE)
				{
					printf("二叉树非空\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 6:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				result = BiTreeDepth(L.elem[T_index].root);
				printf("二叉树的深度为%d\n", result);
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 7:
			re = Root(L);
			if (re != NULL)
			{
				printf("key:%d data:%c\n", re->key, re->data);
			}
			else
			{
				printf("不存在根结点\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 8:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("请输入关键字e:");
				scanf_s("%d", &e);
				result = Value(L.elem[T_index].root, e);
				if (result != ERROR)
				{
					printf("该结点的data值是%c\n", result);
				}
				else
				{
					printf("未能找到该结点\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 9:
			printf("请输入要替换的结点的关键字:");
			scanf_s("%d", &e);
			printf("请输入要替换的data值:");
			getchar();
			scanf_s("%c", &value);
			if (Assign(L.elem[T_index].root, e, value) == OK)
			{
				printf("替换值成功\n");
			}
			else
			{
				printf("替换值失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 10:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("请输入结点的关键字:\n");
				scanf_s("%d", &e);
				re = Parent(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("双亲的key：%d data:%c\n", re->key, re->data);
				}
				else
				{
					printf("未找到双亲结点\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 11:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("请输入结点的关键字:");
				scanf_s("%d", &e);
				re = LeftChild(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("左孩子的key：%d data：%c\n", re->key, re->data);
				}
				else
				{
					printf("未找到左孩子\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 12:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("请输入结点的关键字:");
				scanf_s("%d", &e);
				re = RightChild(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("右孩子的key：%d data：%c\n", re->key, re->data);
				}
				else
				{
					printf("未找到右孩子\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 13:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("请输入结点的关键字:");
				scanf_s("%d", &e);
				re = LeftSibling(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("左兄弟的key：%d data：%c\n", re->key, re->data);
				}
				else
				{
					printf("未找到左兄弟\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 14:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("请输入结点的关键字:");
				scanf_s("%d", &e);
				re = RightSibling(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("右兄弟的key：%d data：%c\n", re->key, re->data);
				}
				else
				{
					printf("未找到右兄弟\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 15:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("请按照前序输入插入子树的相应的key和data(key为0，data为#代表空):\n");
				getchar();
				scanf_s("%s", definition, 100);
				if (CreateBiTree(&Add, definition) == OK)
				{
					printf("请输入要插入的结点的父亲结点的关键字：");
					scanf_s("%d", &e);
					printf("请输入要插入其左子树还是右子树（左输入0，右输入1）：");
					scanf_s("%d", &LR);
					if (InsertChild(L.elem[T_index].root, e, LR, Add) == OK)
					{
						printf("插入子树成功\n");
					}
					else
					{
						printf("插入子树失败\n");
					}
				}
				else
				{
					printf("未能创建子树\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 16:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("请输入要删除的结点的父亲结点的关键字：");
				scanf_s("%d", &e);
				printf("请输入要删除其左子树还是右子树（左输入0，右输入1）：");
				scanf_s("%d", &LR);
				if (DeleteChild(L.elem[T_index].root, e, LR) == OK)
				{
					printf("删除子树成功\n");
				}
				else
				{
					printf("删除失败\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 17:
			if (L.length < T_index||strcmp(L.elem[T_index].name, "already_destroyed") == 0)
			{
				printf("二叉树未创建\n");
			}
			else
			{
				if (L.elem[T_index].root != NULL)
				{
					PreOrderTraverse(L.elem[T_index].root);
				}
				else
				{
					printf("前序遍历失败\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 18:
			if (L.length < T_index||strcmp(L.elem[T_index].name, "already_destroyed") == 0)
			{
				printf("二叉树未创建\n");
			}
			else
			{
				if (L.elem[T_index].root != NULL)
				{
					InOrderTraverse(L.elem[T_index].root);
				}
				else
				{
					printf("中序遍历失败\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 19:
			if (L.length < T_index||strcmp(L.elem[T_index].name, "already_destroyed") == 0)
			{
				printf("二叉树未创建\n");
			}
			else
			{
				if (L.elem[T_index].root != NULL)
				{
					PostOrderTraverse(L.elem[T_index].root);
				}
				else
				{
					printf("中序遍历失败\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 20:
			if (L.length < T_index||strcmp(L.elem[T_index].name, "already_destroyed") == 0)
			{
				printf("二叉树未创建\n");
			}
			else
			{
				if (L.elem[T_index].root != NULL)
				{
					LevelOrderTraverse(L.elem[T_index].root);
				}
				else
				{
					printf("层序遍历失败\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 21:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("注意：请检查文件内容，如果key读入的不为数字，则视此结点为空\n请勿输入重复的key值，否则无法准确查找\n");
				printf("请输入文件名: ");
				scanf_s("%s", filename, 30);
				if (fopen_s(&fp, filename, "r+") != 0)
				{
					printf("文件打开失败\n ");
				}
				else if (LoadFromFile(&L.elem[T_index].root) == OK)
				{
					printf("读取前序序列成功\n");
					if (BiTreeEmpty(L.elem[T_index]) == TRUE)
					{
						printf("创建了空的二叉树\n");
					}
				}
				else
				{
					printf("读取前序序列失败\n");
				}
				count = 0;
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 22:
			if (L.length < T_index)
			{
				printf("二叉树不存在\n");
			}
			else
			{
				printf("请输入文件名: ");
				scanf_s("%s", filename, 30);
				if (fopen_s(&fp, filename, "w+") != 0)
				{
					printf("打开文件失败\n");
				}
				else if (ExportToFile(L.elem[T_index].root) == OK)
				{
					printf("输出树前序成功\n");
				}
				else
				{
					printf("输出树前序失败\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 23:
			printf("请输入要切换到第几棵树：\n");
			temp = L.length;
			scanf_s("%d", &T_index);
			if (T_index < temp + 1)
			{
				printf("已经切换到第%d棵树\n", T_index);
			}
			else
			{
				printf("请先使用多树%d\n", temp );
				T_index = temp - 1;
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 0:
			printf("欢迎下次再使用本系统！\n");
			getchar(); getchar();
			break;
		}//end of switch
	}//end of while
}//end of main()

 /**
 * 函数名称：InitBiTree
 * 函数参数：SqList的引用变量&L
 * 函数功能：构造一个空的树
 * 返回值：成功构造返回OK，否则返回ERROR
 **/
status InitBiTree(SqList &L)
{
	Head *newbase;//申请新的空间
	//当前森林空间是否足够
	if (L.length >= L.listsize)
	{
		newbase = (Head*)realloc(L.elem,(L.listsize + LISTINCREMENT) * sizeof(Head));
		if (!newbase) return ERROR;
		for (int i = 0; i < LISTINCREMENT; i++)
		{
			strcpy_s(newbase[i].name, "already_destroyed");
		}
		L.listsize += LISTINCREMENT;   
		L.elem = newbase;
		(L.length)++;
	}
	if (strcmp(L.elem[T_index].name, "already_destroyed") == 0)
	{
		(L.length)++;//树的数量+1
	}
	//输入新添加的树的信息
	printf("请输入树的名称：\n");
	scanf_s("%s", L.elem[T_index].name,20);
	L.elem[T_index].root = NULL;
	return OK;
}

//递归释放结点空间
void FreeNode(Tree *root)
{
	if (root != NULL)
	{
		if (root->lchild)
		{
			FreeNode(root->lchild);
			root->lchild = NULL;
		}
		if (root->rchild)
		{
			FreeNode(root->rchild);
			root->rchild = NULL;
		}
		if (root != NULL)
		{
			free(root);
			root = NULL;
		}
	}
}

/**
* 函数名称：DestroyBiTree
* 函数参数：L的引用
* 函数功能：销毁一个树
* 返回值：成功摧毁返回OK，否则返回ERROR
**/
status DestroyBiTree(SqList&L)
{
	if (L.length < T_index)
	{
		return ERROR;
	}
	if (strcmp(L.elem[T_index].name,"already_destroyed")!=0)
	{
		//根结点已经存在，则递归释放结点空间
		if (L.elem[T_index].num!=0)
		{
			FreeNode(L.elem[T_index].root);//从根结点开始递归释放所有结点空间
			L.elem[T_index].num = 0;
			L.elem[T_index].root = NULL;
			strcpy_s(L.elem[T_index].name , "already_destroyed");
			(L.length)--;//删除当前头结点的记录
			return OK;
		}
		else
		{
			strcpy_s(L.elem[T_index].name, "already_destroyed");
			(L.length)--;
			return OK;
		}
	}
	else
	{
		return ERROR;
	}
}

/**
* 函数名称：CreateBiTree
* 函数参数：树的结点的二级指针
* 函数功能：创建一个二叉树
* 返回值：成功摧毁返回OK，否则返回ERROR
**/
status CreateBiTree(Tree**root,char* definition)
{
	if (L.length < T_index)
	{
		return ERROR;
	}
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0 && count<=strlen(definition))
	{
		char data;
		int key,i,c=0;
		char a[20];//用于存放key多于一位数时所读取的字符串
		for (i = count;; i++)
		{
			if (*(definition + i) < '0' || *(definition + i) > '9')
			{
				//读到字符的时候就退出
				break;
			}
			else
			{
				//否则将数字存入a串中
				a[c] = *(definition + i);
				c++;
			}
		}
		a[c] = '\0';//将a变成字符串
		//单个字符的处理
		if (i == count+1) 
		{
			key = *(definition + count) - '0'; // 读入一个key，假定为int型
			count++;
		}
		//字符串的处理
		else
		{
			key = atoi(a);
			count = count + c;
		}
		c = 0;
		data = *(definition + count); // 读入一个data，假定为字符型
		count++;
		if (data == '#'|| key == 0) //data输入#，key输入0代表空
			(*root) = NULL;
		else
		{
			(*root) = (Tree *)malloc(sizeof(Tree));
			L.elem[T_index].num++;//结点数+1
			(*root)->data = data;  //给data和key赋值
			(*root)->key = key;
			if (CreateBiTree(&(*root)->lchild, definition) == ERROR)//递归构造左子树
			{
				return ERROR;
			}
			if (CreateBiTree(&(*root)->rchild, definition) == ERROR)//递归构造右子树
			{
				return ERROR;
			}
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}

/**
* 函数名称：ClearBiTree
* 函数参数：L的引用
* 函数功能：清空一个二叉树
* 返回值：成功清空返回OK，否则返回ERROR
**/
status ClearBiTree(SqList&L)
{
	if (L.length < T_index)
	{
		return ERROR;
	}
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		//根结点已经存在，则递归释放结点空间
		if (L.elem[T_index].num != 0)
		{
			FreeNode(L.elem[T_index].root);//从根结点开始递归释放所有结点空间
			L.elem[T_index].root = NULL;
			L.elem[T_index].num = 0;
			return OK;
		}
		else
		{
			printf("无需清空\n");
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

/**
* 函数名称：BiTreeEmpty
* 函数参数：树的头结点
* 函数功能：清空一个二叉树
* 返回值：成功摧毁返回OK，否则返回ERROR
**/
status BiTreeEmpty(Head T)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		if (T.num == 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return ERROR;
	}
}

/**
* 函数名称：BiTreeDepth
* 函数参数：树的根结点
* 函数功能：计算树的深度
* 返回值：成功摧毁返回OK，否则返回ERROR
**/
int BiTreeDepth(Tree* T)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		int i, j;
		if (T == NULL)
			return 0;
		i = BiTreeDepth(T->lchild);
		j = BiTreeDepth(T->rchild);
		if (i > j)
			return i + 1;
		else
			return j + 1;
	}
	else
	{
		return ERROR;
	}
}

/**
* 函数名称：ROOT
* 函数参数：L
* 函数功能：返回树的根结点指针
* 返回值：成功返回根结点指针，否则返回NULL
**/
Tree* Root(SqList L)
{
	if (L.length < T_index)
	{
		return NULL;
	}
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		return L.elem[T_index].root;
	}
	else
	{
		return NULL;
	}
}

//查找key为e的结点
Tree* search_tree(Tree* T, int e)
{
	if (!T)
	{
		return NULL;
	}
	if (T->key == e)
	{
		return T;
	}
	else
	{
		if (!search_tree(T->lchild, e))
		{
			return search_tree(T->rchild, e);
		}
	}
}

/**
* 函数名称：Value
* 函数参数：树T，关键字e
* 函数功能：返回关键字结点的data值
* 返回值：char类型的data
**/
char Value(Tree *T, int e)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		if (!T)
		{
			return ERROR;
		}
		Tree* result = search_tree(T, e);
		if (result != NULL)
		{
			return result->data;
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

/**
* 函数名称：Assign
* 函数参数：树T，关键字e
* 函数功能：将结点e的data赋值为value
* 返回值：成功OK，失败ERROR
**/
status Assign(T_Node &T, int e, char value)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		if (!T)
		{
			return NULL;
		}
		Tree* result = search_tree(T, e);
		if (result != NULL)
		{
			result->data = value;
			return OK;
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

/**
* 函数名称：Parent
* 函数参数：树T，关键字e
* 函数功能：获取双亲结点
* 返回值：成功返回双亲结点，失败返回NULL
**/
Tree *Parent(Tree *T, int e)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		/* 初始条件: 二叉树T存在,e是T中某个结点 */
		/* 操作结果: 若e是T的非根结点,则返回它的双亲,否则返回＂空＂ */
		seq q;
		q.front = q.rear = 0;
		Tree* a;
		if (T) /* 非空树 */
		{
			enter(&q, T); /* 树根入队 */
			while (qEmpty(q) != TRUE) /* 队不空 */
			{
				a = del(&q); /* 出队,队列元素赋给a */
				if (a->lchild&&a->lchild->key == e || a->rchild&&a->rchild->key == e)
					/* 找到e(是其左或右孩子) */
					return a; /* 返回e的双亲的值 */
				else /* 没找到e,则入队其左右孩子指针(如果非空) */
				{
					if (a->lchild)
						enter(&q, a->lchild);
					if (a->rchild)
						enter(&q, a->rchild);
				}
			}
		}
		return NULL; /* 树空或没找到e */
	}
	else
	{
		return NULL;
	}
}

/**
* 函数名称：LeftChild
* 函数参数：树T，关键字e
* 函数功能：获取左孩子结点
* 返回值：成功返回左孩子结点，失败返回NULL
**/
Tree* LeftChild(Tree *T, int e)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		if (!T)
		{
			return NULL;
		}
		Tree* result = search_tree(T, e);
		if (result != NULL)
		{
			return result->lchild;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

/**
* 函数名称：RightChild
* 函数参数：树T，关键字e
* 函数功能：获取右孩子结点
* 返回值：成功返回右孩子结点，失败返回NULL
**/
Tree* RightChild(Tree *T, int e)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		if (!T)
		{
			return NULL;
		}
		Tree* result = search_tree(T, e);
		if (result != NULL)
		{
			return result->rchild;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

/**
* 函数名称：LeftSibling
* 函数参数：树T，关键字e
* 函数功能：获取左兄弟结点
* 返回值：成功返回左兄弟结点，失败返回NULL
**/
Tree* LeftSibling(Tree *T, int e)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") == 0)
	{
		return NULL;
	}
	/* 初始条件: 二叉树T存在,e是T中某个结点 */
	/* 操作结果: 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂ */
	Tree* p;
	if (T) /* 非空树 */
	{
		p = Parent(T, e);  /* p为指向结点e的双亲的指针 */
		if (p->lchild&&p->rchild&&p->rchild->key == e) /* p存在左右孩子且右孩子是e */
			return p->lchild; /* 返回p的左孩子(e的左兄弟) */
	}
	return NULL; /* 树空或没找到e的左兄弟 */
}

/**
* 函数名称：RightSibling
* 函数参数：树T，关键字e
* 函数功能：获取右兄弟结点
* 返回值：成功返回右兄弟结点，失败返回NULL
**/
Tree* RightSibling(Tree *T, int e)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") == 0)
	{
		return NULL;
	}
	/* 初始条件: 二叉树T存在,e是T中某个结点 */
	/* 操作结果: 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂ */
	//Tree* a;
	Tree* p;
	if (T) /* 非空树 */
	{
		p = Parent(T, e);  /* p为指向结点e的双亲的指针 */
		if (p->lchild&&p->rchild&&p->lchild->key == e) /* p存在左右孩子且左孩子是e */
			return p->rchild; /* 返回p的右孩子(e的右兄弟) */
	}
	return NULL; /* 树空或没找到e的左兄弟 */
}

/**
* 函数名称：InsertChild
* 函数参数：原树的根结点指针，关键字e，左右子树标志，添加的子树的根结点指针
* 函数功能：插入子树
* 返回值：成功返回OK，失败返回ERROR
**/

status InsertChild(Tree* T,int e,int LR,Tree* Add)
{
	if (T && strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		Tree *p = search_tree(T, e);
		if (p == NULL)
		{
			return ERROR;
		}
		if (LR == 0)
		{
			if (p->lchild == NULL)
			{
				p->lchild = Add;
				return OK;
			}
			else
			{
				return ERROR;
			}
		}
		if (LR == 1)
		{
			if (p->lchild == NULL)
			{
				p->rchild = Add;
				return OK;
			}
			else
			{
				return ERROR;
			}
		}
		if (LR != 0 && LR != 1)
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

/**
* 函数名称：DeleteChild
* 函数参数：树的指针，关键字e，左右子树标志
* 函数功能：删除子树
* 返回值：成功返回OK，失败返回ERROR
**/

status DeleteChild(Tree*T, int e, int LR)
{
	if (T && strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		Tree* p;
		p = search_tree(T, e);
		if (p == NULL)
		{
			return ERROR;
		}
		if (LR == 0)
		{
			if (p->lchild != NULL)
			{
				FreeNode(p->lchild);
				p->lchild = NULL;
			}
			else
			{
				return ERROR;
			}
		}
		else if (LR == 1)
		{
			if (p->rchild != NULL)
			{
				FreeNode(p->rchild);
				p->rchild = NULL;
			}
			else
			{
				return ERROR;
			}
		}
		if (LR != 0 && LR != 1)
		{
			return ERROR;
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}

//对结点操作的应用函数
void Visit(Tree *T)
{
	printf("key:%d ", T->key);
	printf("data:%c\n", T->data);
}

/**
* 函数名称：PreOrderTraverse
* 函数参数：T,visit函数
* 函数功能：前序遍历
* 返回值：无，判断在主函数中进行，减少递归工作量
**/
void PreOrderTraverse(Tree *T)
{
	if (T)
	{
		Visit(T);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

/**
* 函数名称：InOrderTraverse
* 函数参数：T,visit函数
* 函数功能：中序遍历
* 返回值：无，判断在主函数中进行，减少递归工作量
**/
void InOrderTraverse(Tree *T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		Visit(T);
		InOrderTraverse(T->rchild);
	}
}

/**
* 函数名称：PostOrderTraverse
* 函数参数：T,visit函数
* 函数功能：后序遍历
* 返回值：无，判断在主函数中进行，减少递归工作量
**/
void PostOrderTraverse(Tree *T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		Visit(T);
	}
}

/**
* 函数名称：LevelOrderTraverse
* 函数参数：T,visit函数
* 函数功能：按层遍历
* 返回值：无，判断在主函数中进行，减少递归工作量
**/
void LevelOrderTraverse(Tree *T)
{
	seq q;
	Tree* temp;
	q.front = q.rear = 0;
	if (!T)
	{
		printf("树不存在\n");
		return;
	}
	enter(&q, T);//根结点入队
	while (q.front != q.rear)
	{
		T = del(&q);
		Visit(T);
		if (T->lchild)
		{
			enter(&q, T->lchild);
		}
		if (T->rchild)
		{
			enter(&q, T->rchild);
		}
	}
}

//进队
void enter(seq *q, Tree* t)
{
	if (q->rear == 100)
	{
		printf("the queue is full\n");
	}
	else
	{
		q->data[q->rear] = t;
		q->rear++;
	}
}
//出队
Tree* del(seq*q)
{
	if (q->front == q->rear)
	{
		return NULL;
	}
	else
	{
		q->front++;
		return q->data[q->front - 1];
	}
}
//判断队列是否为空
status qEmpty(seq q)
{ /* 若Q为空队列,则返回TRUE,否则返回FALSE */
	if (q.front == q.rear)
		return TRUE;
	else
		return FALSE;
}

/**
* 函数名称：LoadFromFile
* 函数参数：文件指针fp，树的根结点指针的指针
* 函数功能：读取文件中的字符串并创建二叉树
* 返回值：成功返回OK，失败返回ERROR
**/
status LoadFromFile(Tree**T)
{
	if (L.length < T_index)
	{
		return ERROR;
	}
	if (strcmp(L.elem[T_index].name, "already_destroyed") == 0||!T)
	{
		fclose(fp);
		return ERROR;
	}
	if ( fp == NULL)
	{
		return ERROR;
	}
	char definition[100];
	fscanf_s(fp, "%s", definition, 100);
	fclose(fp);
	if (CreateBiTree(T, definition) == OK)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

/**
* 函数名称：ExportToFile
* 函数参数：文件指针fp，树的根结点的指针
* 函数功能：将树按前序和格式输出到文件中
* 返回值：成功返回OK，失败返回ERROR
**/
status ExportToFile(Tree*T)
{
	if (L.length < T_index)
	{
		return ERROR;
	}
	if (strcmp(L.elem[T_index].name, "already_destroyed") == 0)
	{
		return ERROR;
	}
	if (!T || fp == NULL)
	{
		fclose(fp);
		return ERROR;
	}
	PreOTfile(T);
	fclose(fp);
	return OK;
}
//前序遍历并输出到文件中
void PreOTfile(Tree *T)
{
	if (T)
	{
		fprintf(fp, "%d%c", T->key, T->data);
		PreOTfile(T->lchild);
		PreOTfile(T->rchild);
	}
	else
	{
		fprintf(fp, "%d%c", 0, '#');
	}
}
