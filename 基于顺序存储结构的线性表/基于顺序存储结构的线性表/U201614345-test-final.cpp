#include "stdafx.h"
#include "linear_list_unit_test.h"


/*********************************NOTICE****************************************/
/* 1. 所有函数中，在遇到异常情况时，如访问越界，对空表进行删除，未创建表时就对表操作等，
    请不要调用exit等函数退出程序，仅仅return，使本次操作无效化即可，不影响之后正确的操作。
   2. 在未调用InitiaList或者LoadList前，线性表L中数据域指针开始应该指向NULL，避免野指针。
   3. ElemType为int类型。
   4. 多表操作将手动进行测试，不纳入该测试系统中。
   5. 由于错误类型统一返回ERROR，所以需要大家通过printf等方式打印错误信息，方便查看。
*/
/*******************************************************************************/



/**
 * 函数名称：InitiaList
 * 函数参数：线性表L的地址
 * 函数功能：构造一个空的线性表
 * 返回值：成功构造返回OK，否则返回ERROR
 **/

status IntiaList(SqList & L)
{
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) return ERROR;//存储分配失败
	L.length = 0;//空表长度为0
	L.listsize = LIST_INIT_SIZE;//初始存储容量
	return OK;
}
/**
 * 函数名称：DestroyList
 * 函数参数：线性表L的地址
 * 函数功能：删除线性表
 * 返回值：成功销毁返回OK，否则返回ERROR
 **/
status DestroyList(SqList & L)
{
  //判断线性表是否已创建
	if (L->elem!=NULL)
	{
		//释放空间
		free(L->elem);
		L->elem = NULL;
		return OK;
	}
	else
	{
		return ERROR;
	}
}
/**
 * 函数名称：ClearList
 * 函数参数：线性表L的地址
 * 函数功能：重置线性表
 * 返回值：成功置空返回OK，否则返回ERROR
 **/
status ClearList(SqList &L)
{
  if (L.elem!=NULL)
	{
		L.length = 0;//清空：将长度置0
		return OK;
	}
	else
	{
		return ERROR;
	}
}
/**
 * 函数名称：ListEmpty
 * 函数参数：线性表L
 * 函数功能：判断线性表是否为空
 * 返回值：若L为空表则返回TRUE，否则返回FALSE
 **/
status ListEmpty(SqList L)
{
  if (L.elem!=NULL)
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
	else
	{
		return ERROR;
	}
}
/**
 * 函数名称：ListLength
 * 函数参数：线性表L
 * 函数功能：计算线性表L中数据元素个数；
 * 返回值：成功返回L中数据元素个数，失败返回ERROR
 **/
int ListLength(SqList L)
{
  if (L.elem == NULL)
	{
		return ERROR;
	}
	return L.length;
}
/**
 * 函数名称：GetElem
 * 函数参数：线性表L，e为第i个数据的地址；
 * 函数功能：查找并显示L中第i个元素的值；
 * 返回值：成功则返回第i个元素的值，否则返回ERROR
 **/
status GetElem(SqList L,int i,ElemType & e)
{
  if (L.elem!=NULL)
	{
		if (i <= L.length && i > 0)//判断第i个元素是否存在
		{
			e = *(L.elem + i - 1);//第1个位置对应elem，第i个即从elem向后移动i-1个位置
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
 * 函数名称：LocateElem
 * 函数参数：线性表L，相对比的元素值；
 * 函数功能：查找L中与e相同数据所在的位序；位序从1开始
 * 返回值：成功则返回第一个与e相同的数据的位序，不存在则返回0，其余情况返回ERROR
 **/
status LocateElem(SqList L,ElemType e)
{
  if (L.elem!=NULL)
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
	else
	{
		return ERROR;
	}
}
/**
 * 函数名称：PriorElem
 * 函数参数：线性表L，查找的数据cur_e,前驱pre_e；
 * 函数功能：查找L中与cur_e相同的第一个数据，并返回其前驱
 * 返回值：成功则返回与cur_e相同的第一个数据，并返回其第一个前驱；若无前驱以及其他情况则返回ERROR
 **/
status PriorElem(SqList L,ElemType cur_e,ElemType & pre_e)
{
  if (L.elem!=NULL)
	{
		for (int j = 1; j <= L.length - 1; j++)//遍历线性表
		{
			if (L.elem[j] == cur_e)//找到目标元素
			{
				pre_e = L.elem[j - 1];//获取目标元素下标-1的元素
				return OK;
			}
		}
	}
	return ERROR;
}
/**
 * 函数名称：NextElem
 * 函数参数：线性表L，查找的数据cur_e,后驱next_e；
 * 函数功能：查找L中与cur_e相同的第一个数据，并返回其后驱
 * 返回值：成功则返回与cur_e相同的第一个数据，并返回其后驱；若无后驱以及其他情况则返回ERROR
 **/
status NextElem(SqList L,ElemType cur_e,ElemType & next_e)
{
  if (L.elem!=NULL)
	{
		for (int j = 0; j < L.length - 1; j++)
		{
			if (L.elem[j] == cur_e)
			{
				next_e = L.elem[j + 1];//获取后继
				return OK;
			}
		}
	}
	return ERROR;
}
/**
 * 函数名称：ListInsert
 * 函数参数：线性表L的地址，插入的位置i，插入的数据元素e。
 * 函数功能：在L的第i个位置之前插入新的数据元素e；若已插满，则按照分配增量，分配更大的空间。
 * 返回值：成功插入返回OK，否则返回ERROR
 **/
status ListInsert(SqList & L,int i,ElemType e)
{
  if (L.elem!=NULL)
	{
		//在顺序线性表L中第i个位置之前插入新的元素e，i的合法值为1~ListLength+1
		if (i<1 || i>L.length + 1) return ERROR; //i值不合法
		if (L.length >= L.listsize)
		{
			ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
			if (!newbase) return ERROR;//存储分配失败
			L.elem = newbase;//新基址
			L.listsize += LISTINCREMENT;//增加存储容量
		}
		int *q = &(L.elem[i - 1]);//q为插入位置
		//遍历，将插入位置后面的元素后移一位
		for (int *p = &(L.elem[L.length - 1]); p >= q; --p)
		{
			*(p + 1) = *p;
		}
		*q = e;
		++L.length;//线性表长度+1
		return OK;
	}
	else
	{
		return ERROR;
	}
}
/**
 * 函数名称：ListDelete
 * 函数参数：线性表L的地址，删除的位序i，指针e的地址。
 * 函数功能：删除L的第i个数据元素，用e返回其值。
 * 返回值：成功删除返回OK，否则返回ERROR
 **/
status ListDelete(SqList & L, int i, ElemType & e)
{
  if (L.elem!=NULL)
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
	else
	{
		return ERROR;
	}
}
/**
 * 函数名称：ListTrabverse
 * 函数参数：线性表L
 * 函数功能：依次显示线性表中的每个元素。
 * 返回值：成功遍历返回线性表的长度，否则返回ERROR
 **/
status ListTrabverse(SqList L)
{
  if (L.elem!=NULL) {
		int i;
		printf("\n-----------all elements -----------------------\n");
		//循环遍历输出
		for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
		printf("\n------------------ end ------------------------\n");
		return OK;
	}
	else
	{
		return ERROR;
	}
}
/**
 * 函数名称：LoadList
 * 函数参数：文件指针，线性表L
 * 函数功能：数据加载，为线性表输入元素。
 * 返回值：加载成功返回OK，加载失败返回E
 **/
 status LoadList(FILE *fp,SqList &L)
 {
   if (L.elem!=NULL && fp!=NULL)
	{
		L.length = 0;
		char vacant;//用于读取空格
		while (fscanf_s(fp, "%d", &L.elem[L.length])!=EOF)
		{
			fscanf_s(fp, "%c", &vacant);//读取数字后的空格
			L.length++;
		}
		fclose(fp);
		return OK;
	}
	else
	{
		return ERROR;
	}
 }
 /**
 * 函数名称：SaveList
 * 函数参数：文件指针，线性表L
 * 函数功能：将L中的数据保存到fp指针指向的文件中
 * 返回值：OK
 **/
 status SaveList(FILE *fp,SqList L)
 {
   if (L.elem!=NULL && fp!=NULL)
	{
		//循环遍历线性表，并将线性表内容放入文件中
		for (int j = 0; j < L.length; j++)
		{
			fprintf(fp, "%d ", L.elem[j]);
		}
		fclose(fp);
		return OK;
	}
	else
	{
		return ERROR;
	}
 }
