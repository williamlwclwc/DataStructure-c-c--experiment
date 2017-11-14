#include "declaration.h"//声明&定义头文件

void main(void) {
	SqList L;  
	int op = 1;
	ElemType elem,cur;
	int pos=0,result;
	//Main Menu Entrance
	while (op) {
		system("cls");	printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. IntiaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty     10. ListInsert\n");
		printf("    	  5. ListLength     11. ListDelete\n");
		printf("    	  6. GetElem       12. ListTrabverse\n");
		printf("          13. LoadFromFile  14. ExportToFile\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~12]:");
		scanf_s("%d", &op);
		//根据用户输入调用相应函数，执行相应功能
		switch (op) {
		case 1:
			if (IntiaList(L) == OK) printf("线性表创建成功！\n");
			else printf("线性表创建失败！\n");
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyList(&L) == OK)
			{
				printf("线性表销毁成功\n");
			}
			/*
			else
			{
				printf("线性表销毁失败\n");
			}
			*/
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 3:
			if (ClearList(L) == OK)
			{
				printf("线性表清空成功\n");
			}
			else
			{
				printf("线性表清空失败\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 4:
			if (ListEmpty(L) == TRUE)
			{
				printf("线性表已经清空\n");
			}
			else
			{
				printf("线性表未清空\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 5:
			result = ListLength(L);
			if (result!=0)
			{
				printf("该线性表的长度为：%d\n", result);
			}
			else if(result==-1)
			{
				printf("测量长度失败\n");
			}
			else if (result == 0)
			{
				printf("线性表为空表\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 6:
			printf("请输入要查询的元素的序号：");
			scanf_s("%d", &pos);
			if (GetElem(L, pos, elem) == OK)
			{
				printf("您所查询的元素（第%d个）是：%d\n", pos,elem);
			}
			else
			{
				printf("查找失败\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 7:
			printf("请输入你想要查找的元素：");
			scanf_s("%d", &elem);
			result = LocateElem(L, elem);
			if (result != 0)
			{
				printf("该元素的位置是：%d\n",result);
			}
			else
			{
				printf("查找失败\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 8:
			printf("请输入要查询的元素：");
			scanf_s("%d", &cur);
			if (PriorElem(L, cur, elem) == OK)
			{
				printf("该元素的前驱为：%d\n", elem);
			}
			else
			{
				printf("前驱查找失败\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 9:
			printf("请输入要查询的元素：");
			scanf_s("%d", &cur);
			if (NextElem(L, cur, elem) == OK)
			{
				printf("该元素的后继为：%d\n", elem);
			}
			else
			{
				printf("后继查找失败\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 10:
			printf("请输入要插入的位置i：");
			scanf_s("%d", &pos);
			printf("请输入要插入的元素e：");
			scanf_s("%d", &elem);
			if(ListInsert(L, pos, elem)==OK) printf("线性表插入成功\n");
			else
			{
				printf("线性表插入失败\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 11:
			printf("请输入要删除元素的位置i：");
			scanf_s("%d", &pos);
			if (ListDelete(L, pos, elem) == OK) 
			{
				printf("线性表删除成功\n");
				printf("所删除的元素为： %d\n",elem);
			}
			else
			{
				printf("线性表删除失败\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 12:
			if (!ListTrabverse(L)) {
				//printf("线性表是空表！\n");
			}
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 13:
			LoadFromFile();
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 14:
			ExportToFile();
			printf("按任意键继续\n");
			getchar(); getchar();
			break;
		case 0:
			printf("欢迎下次再使用本系统！\n");
			getchar(); getchar();
			break;
		}//end of switch
	}//end of while
}//end of main()
 /*--------page 23 on textbook --------------------*/

//创建线性表
status IntiaList(SqList & L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);//存储分配失败
	L.length = 0;//空表长度为0
	L.listsize = LIST_INIT_SIZE;//初始存储容量
	return OK;
}

//销毁线性表（free空间）
status DestroyList(SqList * L)
{
		free(L->elem);
		L->elem= NULL;
		return OK;
}

//清空线性表（长度为0）
status ClearList(SqList &L)
{
	L.length = 0;
	return OK;
}

//判断线性表是否为空（判断长度是否为0）
status ListEmpty(SqList L)
{
	if (L.length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//返回线性表的长度信息
int ListLength(SqList L)
{
	return L.length;
}

//获得第i个位置上的元素值
status GetElem(SqList L, int i, ElemType & e)
{
	if (i <= L.length)//判断第i个元素是否存在
	{
		e = *(L.elem + i - 1);//第1个位置对应elem，第i个即从elem向后移动i-1个位置
		return OK;
	}
	else
	{
		return ERROR;
	}
}

//查找值为e的元素的位置
int LocateElem(SqList L, ElemType e)//简化过
{
	for (int j = 1; j <= L.length; j++)//循环遍历线性表
	{
		if (*L.elem != e)//查找值为e的元素
		{
			L.elem++;//当前不等，则比较下一个
		}
		else
		{
			return j;//找到了，返回其下标
		}
	}
	return 0;
}

//找到某元素的前驱元素
status PriorElem(SqList L, ElemType cur, ElemType & pre_e)
{
	for (int j = 1; j <= L.length; j++)//遍历线性表
	{
		if (L.elem[j] == cur)//找到目标元素
		{
			pre_e = L.elem[j - 1];//获取目标元素下标-1的元素
			return OK;
		}
	}
	return ERROR;
}

//找到某元素的后继元素 原理同PriorElem
status NextElem(SqList L, ElemType cur, ElemType & next_e)
{
	for (int j = 1; j <= L.length; j++)
	{
		if (L.elem[j] == cur)
		{
			next_e = L.elem[j + 1];
			return OK;
		}
	}
	return ERROR;
}

//插入元素
status ListInsert(SqList & L, int i, ElemType e)
{
	//在顺序线性表L中第i个位置之前插入新的元素e，i的合法值为1~ListLength+1
	if (i<1 || i>L.length + 1) return ERROR; //i值不合法
	if (L.length >= L.listsize)
	{
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);//存储分配失败
		L.elem = newbase;//新基址
		L.listsize += LISTINCREMENT;//增加存储容量
	}
	int *q = &(L.elem[i - 1]);//q为插入位置
	for (int *p = &(L.elem[L.length - 1]); p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	return OK;
}

//删除元素
status ListDelete(SqList & L, int i, ElemType & e)
{
	//在顺序线性表L中删除第i个元素，并用e返回其值
	//i的合法值为1~ListLength
	if ((i < 1 || (i > L.length))) return ERROR;//i值不合法
	int *p = &(L.elem[i - 1]);//p为被删除元素的值赋给e
	e = *p;//被删除的元素赋给e
	int *q = L.elem + L.length - 1;//表尾元素的位置
	for (++p; p <= q; ++p)
	{
		*(p - 1) = *p;//被删除元素后元素左移
	}
	--L.length;//表长减1
	return OK;
}

//遍历输出线性表
status ListTrabverse(SqList L) {
		int i;
		printf("\n-----------all elements -----------------------\n");
		for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
		printf("\n------------------ end ------------------------\n");
		return OK;
}

//从文件中读入线性表的元素
void LoadFromFile()
{

}

//将线性表的内容写入文件中保存
void ExportToFile()
{

}
