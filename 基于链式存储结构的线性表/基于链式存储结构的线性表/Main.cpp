#include "Declaration.h"//声明&定义头文件

FILE *fp;
char filename[30];
int List_index = 1;
LinkList L = NULL;

void main(void) {
	int op = 1;
	ElemType elem, cur_e;
	int pos = 0, result;
	//Main Menu Entrance
	while (op) {
		system("cls");	printf("\n\n");
		printf("                      Menu for Linear Table On Linked List Structure \n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("    	  1. IntiaList（生成线性表）          7. LocateElem（定位元素）\n");
		printf("    	  2. DestroyList（销毁线性表）        8. PriorElem（求前驱）\n");
		printf("    	  3. ClearList（清空线性表）          9. NextElem（求后继） \n");
		printf("    	  4. ListEmpty（判断是否为空表）     10. ListInsert（插入元素）\n");
		printf("    	  5. ListLength（求表长）            11. ListDelete（删除元素）\n");
		printf("    	  6. GetElem（获取元素）             12. ListTrabverse（遍历输出线性表）\n");
		printf("          13. LoadFromFile（读取文件）       14. ExportToFile（输出到文件）\n");
		printf("          15. Multi-Operation（多表操作）\n");
		printf("    	  0. Exit\n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("您当前所操作的是第%d号线性表\n", List_index);
	
		printf("请选择你的操作[0~15]:");
		scanf_s("%d", &op);
		//根据用户输入调用相应函数，执行相应功能
		switch (op) {
		case 1:
			if (IntiaList(L) == OK)
			{
				printf("线性表创建成功！\n");
			}
			else printf("线性表创建失败！\n");
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyList(L) == OK)
			{
				printf("线性表销毁成功\n");
			}
			else
			{
				printf("线性表销毁失败\n");
			}
			printf("按回车键继续\n");
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
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 4:
			if (ListEmpty(L) == TRUE)
			{
				printf("线性表已经清空\n");
			}
			else if (ListEmpty(L) == FALSE)
			{
				printf("线性表未清空\n");
			}
			else if (ListEmpty(L) == ERROR)
			{
				printf("线性表未创建\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 5:
			result = ListLength(L);
			if (result == -2)
			{
				printf("测量长度失败\n");
			}
			else if (result == 0)
			{
				printf("线性表为空表\n");
			}
			else if (result != 0)
			{
				printf("该线性表的长度为：%d\n", result);
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 6:
			printf("请输入要查询的元素的序号：");
			scanf_s("%d", &pos);
			if (GetElem(L, pos, elem) == OK)
			{
				printf("您所查询的元素（第%d个）是：%d\n", pos, elem);
			}
			else
			{
				printf("查找失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 7:
			printf("请输入你想要查找的元素：");
			scanf_s("%d", &elem);
			result = LocateElem(L, elem);
			if (result != 0 && result != ERROR)
			{
				printf("该元素的位置是：%d\n", result);
			}
			else
			{
				printf("查找失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 8:
			printf("请输入要查询的元素：");
			scanf_s("%d", &cur_e);
			if (PriorElem(L, cur_e, elem) == OK)
			{
				printf("该元素的前驱为：%d\n", elem);
			}
			else
			{
				printf("前驱查找失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 9:
			printf("请输入要查询的元素：");
			scanf_s("%d", &cur_e);
			if (NextElem(L, cur_e, elem) == OK)
			{
				printf("该元素的后继为：%d\n", elem);
			}
			else
			{
				printf("后继查找失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 10:
			printf("请输入要插入的位置i：");
			scanf_s("%d", &pos);
			printf("请输入要插入的元素e：");
			scanf_s("%d", &elem);
			if (ListInsert(L, pos, elem) == OK)
			{
				printf("插入成功\n");
			}
			else
			{
				printf("插入失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 11:
			printf("请输入要删除元素的位置i：");
			scanf_s("%d", &pos);
			if (ListDelete(L, pos, elem) == OK)
			{
				printf("删除成功\n");
				printf("所删除的元素为： %d\n", elem);
			}
			else
			{
				printf("删除失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 12:
			if (ListTrabverse(L) != OK) {
				printf("线性表未创建！\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 13:
			printf("请输入文件名: ");
			scanf_s("%s", filename, 30);
			if (fopen_s(&fp, filename, "r+") != 0)
			{
				printf("文件打开失败\n ");
			}
			else if (LoadFromFile(fp, L) == OK)
			{
				printf("读取线性表成功\n");
			}
			else
			{
				printf("读取线性表失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 14:
			printf("请输入文件名: ");
			scanf_s("%s", filename, 30);
			if (fopen_s(&fp, filename, "w+") != 0)
			{
				printf("打开文件失败\n");
			}
			else if (ExportToFile(fp, L) == OK)
			{
				printf("输出线性表成功\n");
			}
			else
			{
				printf("输出线性表失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 15:
			if (Switch_List() == OK)
			{
				printf("切换成功，当前是第%d号线性表\n", List_index);
			}
			else
			{
				printf("切换失败\n");
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
 * 函数名称：InitiaList
 * 函数参数：线性表L的地址
 * 函数功能：构造一个空的线性表
 * 返回值：成功构造返回OK，否则返回ERROR
 **/
status IntiaList(LinkList &L) 
{
	L = (LinkList)malloc(sizeof(LNode));//建立带链头的单链线性表
	//链表初始化
	L->data = 0;//在头结点的数据域中存放链表的长度
	L->next = NULL;
	return OK;
}

/**
* 函数名称：DestroyList
* 函数参数：线性表L的地址
* 函数功能：删除线性表
* 返回值：成功销毁返回OK，否则返回ERROR
**/
status DestroyList(LinkList &L)
{
	//判断链表是否已经创建，下同
	if (!L) return ERROR;
	//当前是表尾
	if (L->next == NULL)
	{
		free(L->next);
		free(L);
		L = NULL;
	}
	else//递归，直到找到表尾并依次进行销毁
	{
		DestroyList(L->next);
		L->next = NULL;
		free(L);
	}
	return OK;
}

/**
* 函数名称：ClearList
* 函数参数：线性表L的地址
* 函数功能：重置线性表
* 返回值：成功置空返回OK，否则返回ERROR
**/
status ClearList(LinkList &L)
{
	if (!L) return ERROR;
	DestroyList(L->next);//free掉除头结点以外的结点
	L->next = NULL;
	L->data = 0;//表长清零
	return OK;
}

/**
* 函数名称：ListEmpty
* 函数参数：线性表L
* 函数功能：判断线性表是否为空
* 返回值：若L为空表则返回TRUE，否则返回FALSE
**/
status ListEmpty(LinkList L)
{
	if (!L) return ERROR;
	//头结点的下一个结点是否为空
	if (L->next == NULL) return TRUE;
	else return FALSE;
}

/**
* 函数名称：ListLength
* 函数参数：线性表L
* 函数功能：计算线性表L中数据元素个数；
* 返回值：成功返回L中数据元素个数，失败返回ERROR
**/
int ListLength(LinkList L)
{
	if (!L) return ERROR;
	int len = 0;//函数返回值，存放链表长度
	//遍历链表，每次长度+1
	for (LinkList p = L->next; p != NULL; p = p->next)
	{
		len++;
	}
	return len;
}

/**
* 函数名称：GetElem
* 函数参数：线性表L，e为第i个数据的地址；
* 函数功能：查找并显示L中第i个元素的值；
* 返回值：成功则返回第i个元素的值，否则返回ERROR
**/
status GetElem(LinkList L, int i, ElemType & e)
{
	if (!L) return ERROR;
	if (i>=1 && i <= L->data)//判断输入位置是否合法
	{
		int index = 1;
		LinkList p = L->next;
		//遍历，直到链表尾或遍历到第i个
		while (p != NULL && index != i)
		{
			p = p->next;
			index++;
		}
		e = p->data;//将第i个元素的值给e
		return OK;
	}
	else return ERROR;
}

/**
* 函数名称：LocateElem
* 函数参数：线性表L，相对比的元素值；
* 函数功能：查找L中与e相同数据所在的位序；位序从1开始
* 返回值：成功则返回第一个与e相同的数据的位序，不存在则返回0，其余情况返回ERROR
**/
int LocateElem(LinkList L, ElemType e)//简化过
{
	if (!L) return ERROR;
	int index = 1;
	LinkList p = L->next;
	//遍历链表
	while (p != NULL)
	{
		if (p->data != e)
		{
			//当前元素不同，指向下一个位置，下标值+1
			p = p->next;
			index++;
		}
		else
		{
			//找到相同的元素，返回下标值
			return index;
		}
	}
	//遍历结束仍未找到，返回ERROR
	return ERROR;
}

/**
* 函数名称：PriorElem
* 函数参数：线性表L，查找的数据cur_e,前驱pre_e；
* 函数功能：查找L中与cur_e相同的第一个数据，并返回其前驱
* 返回值：成功则返回与cur_e相同的第一个数据，并返回其第一个前驱；若无前驱以及其他情况则返回ERROR
**/
status PriorElem(LinkList L, ElemType cur_e, ElemType & pre_e)
{
	if (!L) return ERROR;
	LinkList p = L->next;
	if (p->data == cur_e) return ERROR;//第一个元素没有前驱
	//遍历链表
	while (p != NULL)
	{
		//当前元素和目标元素相同，此时pre_e的值为前驱值
		if (p->data == cur_e)
		{
			return OK;
		}
		else
		{
			//当前元素不是目标元素，存下当前的data，p指向下一个
			pre_e = p->data;
			p = p->next;
		}
	}
	//遍历结束仍未找到目标值，返回ERROR
	return ERROR;
}

/**
* 函数名称：NextElem
* 函数参数：线性表L，查找的数据cur_e,后驱next_e；
* 函数功能：查找L中与cur_e相同的第一个数据，并返回其后驱
* 返回值：成功则返回与cur_e相同的第一个数据，并返回其后驱；若无后驱以及其他情况则返回ERROR
**/
status NextElem(LinkList L, ElemType cur_e, ElemType & next_e)
{
	if (!L) return ERROR;
	LinkList p = L->next;
	//遍历链表，最后一个元素没有后继，所以少一次循环
	while (p->next != NULL)
	{
		//找到目标元素
		if (p->data == cur_e)
		{
			//将目标元素的下一个结点中的值放入next_e中
			next_e = p->next->data;
			return OK;
		}
		//未找到则指向下一个位置
		p = p->next;
	}
	//遍历结束仍未找到返回ERROR
	return ERROR;
}

/**
* 函数名称：ListInsert
* 函数参数：线性表L的地址，插入的位置i，插入的数据元素e。
* 函数功能：在L的第i个位置之前插入新的数据元素e；若已插满，则按照分配增量，分配更大的空间。
* 返回值：成功插入返回OK，否则返回ERROR
**/
status ListInsert(LinkList & L, int i, ElemType e)
{
	if (!L) return ERROR;
	//判断插入位置是否合法
	if (i<1 || i>L->data + 1)
	{
		return ERROR;
	}
	L->data++;//表长+1
	//寻找插入点
	LinkList p = L;
	int j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	//在插入位置申请新的结点并改变指针插入
	LinkList f = (LinkList)malloc(sizeof(LNode));//申请一个新的结点空间
	f->data = e;
	//改变指针指向
	f->next = p->next;
	p->next = f;
	return OK;
}

/**
* 函数名称：ListDelete
* 函数参数：线性表L的地址，删除的位序i，指针e的地址。
* 函数功能：删除L的第i个数据元素，用e返回其值。
* 返回值：成功删除返回OK，否则返回ERROR
**/
status ListDelete(LinkList & L, int i, ElemType & e)
{
	if (!L) return ERROR;
	L->data--;//表长-1
	//寻找删除点
	LinkList p = L;
	int j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	e = p->next->data;//删除的元素赋值给e
	LinkList del = p->next;//记录删除结点指针
	p->next = p->next->next;//改变指针跳过删除结点
	free(del);//free删除结点
	return OK;
}

/**
* 函数名称：ListTrabverse
* 函数参数：线性表L
* 函数功能：依次显示线性表中的每个元素。
* 返回值：成功遍历返回线性表的长度，否则返回ERROR
**/
status ListTrabverse(LinkList L) 
{
	if (!L) return ERROR;
	LinkList p = L->next;
	if (p == NULL)//空表单独输出
	{
		printf("当前链表是空链表\n");
	}
	else//非空表循环遍历输出
	{
		printf("-------------------all elements---------------------\n\n");
		while (p != NULL)
		{
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n\n------------------------end-----------------------\n");
	}
	return OK;
}

/**
* 函数名称：LoadFromFile
* 函数参数：文件指针，线性表L
* 函数功能：数据加载，为线性表输入元素。
* 返回值：加载成功返回OK，加载失败返回E
**/
status LoadFromFile(FILE*fp, LinkList &L)
{
	//未创建链表或打开失败返回ERROR，输出文件同
	if (!L || fp == NULL)
	{
		fclose(fp);
		return ERROR;
	}
	L->data = 0;
	LinkList p = L;
	char vacant;//用于读取空格
	ElemType elem;//用于存放读入的元素值
	while (fscanf_s(fp, "%d", &elem) != EOF)//读入文件中的元素值
	{
		LinkList f = (LinkList)malloc(sizeof(LNode));//申请一个新的结点空间
		f->data = elem;//将读入值存入结点的data域
		//改变指针指向
		f->next = NULL;//链表尾指向NULL
		p->next = f;//接在原来的表尾
		fscanf_s(fp, "%c", &vacant);//读取数字后的空格
		p = p->next;
		L->data++;//表长+1
	}
	fclose(fp);
	return OK;
}

/**
* 函数名称：ExportToFile
* 函数参数：文件指针，线性表L
* 函数功能：将L中的数据保存到fp指针指向的文件中
* 返回值：OK
**/
status ExportToFile(FILE*fp, LinkList L)
{
	if (!L || fp == NULL)
	{
		fclose(fp);
		return ERROR;
	}
	LinkList p = L->next;
	//遍历链表输出到文件
	while (p != NULL)
	{
		fprintf(fp, "%d ", p->data);
		p = p->next;
	}
	fclose(fp);
	return OK;
}

//多表操作函数，切换线性表
status Switch_List()
{

	return OK;
}
