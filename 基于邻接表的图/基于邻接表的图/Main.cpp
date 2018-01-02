#include "Declaration.h"//声明&定义头文件

FILE *fp1,*fp2;
char filename1[30],filename2[30];
Graph G[MaxLength];
int Graph_index = 1;//多图的下标
int nv;//未遍历的顶点序号，-1表示全部遍历过

void main(void) {
	int op = 1;
	ElemType u,value;
	int result;
	Vertice *re;
	//Main Menu Entrance
	while (op) {
		system("cls");	printf("\n\n");
		printf("                      Menu for Graph On Adjacency List Structure \n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("    	  1. CreateGraph（创建图）           7. NextAdjVex（获取下一个邻接点）\n");
		printf("    	  2. DestroyGraph（销毁图）          8. InsertVex（插入顶点）\n");
		printf("    	  3. LocateVex（查找顶点）           9. DeleteVex（删除顶点） \n");
		printf("    	  4. GetVex（获取顶点）              10.InsertArc（插入弧）\n");
		printf("    	  5. PutVex（顶点赋值）              11.DeleteArc（删除弧）\n");
		printf("    	  6. FirstAdjVex（获取第一邻接点）   12.DFSTraverse（深度优先搜索遍历）\n");
		printf("          13.BFSTraverse（广度优先搜索遍历） 14.LoadFromFile（读取文件）\n");
		printf("          15.ExportToFile（输出到文件）      16.Multi-Graph（多图操作）\n");
		printf("    	  0. Exit\n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("您当前所操作的是第%d号图\n", Graph_index);
		printf("请选择你的操作[0~16]:");
		scanf_s("%d", &op);
		//根据用户输入调用相应函数，执行相应功能
		switch (op) {
		case 1:
			if (CreateGraph(G[Graph_index]) == OK)
			{
				printf("创建图成功\n");
			}
			else
			{
				printf("创建图失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyGraph(G[Graph_index]) == OK)
			{
				printf("销毁图成功\n");
			}
			else
			{
				printf("销毁图失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 3:
			printf("请输入要查找的结点信息：");
			scanf_s("%d", &u);
			result = LocateVex(G[Graph_index], u);
			if (result != ERROR)
			{
				printf("您要查找的结点序号为:%d\n",result);
			}
			else
			{
				printf("查找失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 4:
			printf("请输入要查找的结点信息：");
			scanf_s("%d", &u);
			re = GetVex(G[Graph_index], u);
			if (re != NULL)
			{
				printf("您找的结点是：%d\n", re->data);
			}
			else
			{
				printf("获取失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 5:
			printf("请输入要查找的结点信息：");
			scanf_s("%d", &u);
			printf("请输入要替换的值：");
			scanf_s("%d", &value);
			if (PutVex(G[Graph_index], u, value) == OK)
			{
				printf("赋值成功\n");
			}
			else
			{
				printf("赋值失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 6:
			printf("请输入要查找的结点信息：");
			scanf_s("%d", &u);
			re = FirstAdjVex(G[Graph_index], u);
			if (re != NULL)
			{
				printf("第一个邻接点是：%d\n", re->data);
			}
			else
			{
				printf("查找失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 7:
			printf("请输入要查找的结点信息：");
			scanf_s("%d", &u);
			printf("请输入要查找的邻接点信息：");
			scanf_s("%d", &value);
			re = NextAdjVex(G[Graph_index], u, value);
			if (re != NULL)
			{
				printf("输入的结点的输入的邻接点的下一个邻接点是：%d\n", re->data);
			}
			else
			{
				printf("查找失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 8:
			printf("请输入要插入的结点信息：");
			scanf_s("%d", &u);
			if (InsertVex(G[Graph_index], u) == OK)
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
		case 9:
			printf("请输入要删除的结点信息：");
			scanf_s("%d", &u);
			if (DeleteVex(G[Graph_index], u) == OK)
			{
				printf("删除成功\n");
			}
			else
			{
				printf("删除失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 10:
			printf("请输入要插入的弧尾信息：");
			scanf_s("%d", &u);
			printf("请输入要插入的弧头信息：");
			scanf_s("%d", &value);
			if (InsertArc(G[Graph_index], u, value) == OK)
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
			printf("请输入要删除的弧尾信息：");
			scanf_s("%d", &u);
			printf("请输入要删除的弧头信息：");
			scanf_s("%d", &value);
			if (DeleteArc(G[Graph_index], u, value) == OK)
			{
				printf("删除成功\n");
			}
			else
			{
				printf("删除失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 12:
			if (DFSTraverse(G[Graph_index]) == OK)
			{
				printf("深度优先遍历成功\n");
			}
			else
			{
				printf("深度优先遍历失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 13:
			if (BFSTraverse(G[Graph_index]) == OK)
			{
				printf("广度优先遍历成功\n");
			}
			else
			{
				printf("广度优先遍历失败\n");
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 14:
			printf("请输入结点文件的文件名：");
			scanf_s("%s", filename1, 30);
			printf("请输入弧文件的文件名：");
			scanf_s("%s", filename2, 30);
			if (fopen_s(&fp1, filename1, "r+") != 0||fopen_s(&fp2, filename2, "r+") != 0)
			{
				printf("文件打开失败\n ");
			}
			else
			{
				if (LoadFromFile(G[Graph_index]) == OK)
				{
					printf("读取文件创建图成功\n");
				}
				else
				{
					printf("读取文件创建图失败\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 15:
			printf("请输入结点文件的文件名：");
			scanf_s("%s", filename1, 30);
			printf("请输入弧文件的文件名：");
			scanf_s("%s", filename2, 30);
			if (G[Graph_index].ver_num == 0)
			{
				printf("图不存在\n");
				printf("输出图信息到文件失败\n");
			}
			else if (fopen_s(&fp1, filename1, "w+") != 0 || fopen_s(&fp2, filename2, "w+") != 0)
			{
				printf("文件打开失败\n ");
			}
			else
			{
				if (ExportToFile(G[Graph_index]) == OK)
				{
					printf("输出图信息到文件成功\n");
				}
				else
				{
					printf("输出图信息到文件失败\n");
				}
			}
			printf("按回车键继续\n");
			getchar(); getchar();
			break;
		case 16:
			if (Switch_Graph() == OK)
			{
				printf("切换成功\n");
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
 * 函数名称：CreateGraph
 * 函数参数：图G头结点的引用
 * 函数功能：按照给定点和边构造一个图
 * 返回值：成功构造返回OK，否则返回ERROR
 **/
status CreateGraph(Graph &G)
{
	int i, j, k;
	ElemType va, vb;
	Edges *p;
	printf("请输入顶点的数量：");
	scanf_s("%d", &G.ver_num);
	printf("请输入边的数量：");
	scanf_s("%d", &G.ed_num);
	for (k = 0; k < G.ver_num; k++)
	{
		printf("请输入结点的data值：");
		scanf_s("%d", &G.vertices[k].data);
		G.vertices[k].first_adj = NULL;
	}
	for (k = 0; k < G.ed_num; k++)
	{
		p = (Edges*)malloc(sizeof(Edges));
		printf("请输入第%d条边的弧尾结点：", k + 1);
		scanf_s("%d", &va);
		printf("请输入第%d条边的弧头结点：", k + 1);
		scanf_s("%d", &vb);
		i = LocateVex(G, va);//弧尾序号
		j = LocateVex(G, vb);//弧头序号
		p->ajvex = j;//边的指针指向弧头结点
		p->next = G.vertices[i].first_adj;//插入在上一个结点的前面（表头结点后）
		G.vertices[i].first_adj = p;//表头结点指向新插入的结点
	}
	return OK;
}

/**
* 函数名称：DestroyGraph
* 函数参数：图G的引用
* 函数功能：销毁一个图
* 返回值：成功销毁返回OK，否则返回ERROR
**/
status DestroyGraph(Graph &G)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return ERROR;
	}
	Edges *p, *q;
	for (int i = 0; i < G.ver_num; i++)
	{
		p = G.vertices[i].first_adj;//初始p为第一邻接点
		while (p != NULL)
		{
			q = p->next;//令q为p的下一个邻接点（或空）
			free(p);
			p = q;//循环下一个邻接点
		}
	}
	G.ed_num = 0;
	G.ver_num = 0;
	return OK;
}

/**
* 函数名称：LocateVex
* 函数参数：图G，特征u
* 函数功能：查找一个顶点
* 返回值：成功返回u的位置，否则失败提示
**/
int LocateVex(Graph G, ElemType u)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return ERROR;
	}
	for (int i = 0; i < G.ver_num; i++)
	{
		if (G.vertices[i].data == u)
		{
			return i;
		}
	}
	return ERROR;
}

/**
* 函数名称：GetVex
* 函数参数：图G，顶点v
* 函数功能：返回顶点的信息
* 返回值：成功返回顶点信息，否则NULL
**/
Vertice* GetVex(Graph G, ElemType v)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return NULL;
	}
	for (int i = 0; i < G.ver_num; i++)
	{
		if (G.vertices[i].data == v)
		{
			return G.vertices+i;
		}
	}
	return NULL;
}

/**
* 函数名称：PutVex
* 函数参数：图G的引用，顶点v，要赋的值value
* 函数功能：改变顶点v的值
* 返回值：成功返回OK，失败返回ERROR
**/
status PutVex(Graph &G,ElemType v,ElemType value)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return ERROR;
	}
	for (int i = 0; i < G.ver_num; i++)
	{
		if (G.vertices[i].data == v)
		{
			G.vertices[i].data = value;
			return OK;
		}
	}
	return ERROR;
}

/**
* 函数名称：FirstAdjVex
* 函数参数：图G，顶点v
* 函数功能：查找第一个邻接点
* 返回值：返回v的第一个邻接点，否则返回空
**/
Vertice* FirstAdjVex(Graph G, ElemType v)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return NULL;
	}
	int index, flag = 0;//第一个邻接点的序号
	for (int i = 0; i < G.ver_num; i++)
	{
		if (G.vertices[i].data == v)
		{
			index = G.vertices[i].first_adj->ajvex;
			flag = 1;
		}
	}
	if (flag == 1)
	{
		return G.vertices + index;
	}
	else
	{
		return NULL;
	}
}

/**
* 函数名称：NextAdjVex
* 函数参数：图G，顶点v，邻接点w
* 函数功能：查找w的下一个邻接点
* 返回值：返回w的下一个邻接点，否则返回空
**/
Vertice* NextAdjVex(Graph G, ElemType v,ElemType w)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return NULL;
	}
	int v_index, w_index, index, flag = 0;
	//找到顶点v和w的序号
	v_index = LocateVex(G, v);
	w_index = LocateVex(G, w);
	if (v_index == ERROR || w_index == ERROR)
	{
		return NULL;
	}
	Edges *p = G.vertices[v_index].first_adj;//初始p为第一个邻接点
	while (p != NULL)
	{
		if (p->ajvex == w_index)
		{
			if (p->next != NULL)//如果w不是最后一个邻接点
			{
				index = p->next->ajvex;//目标顶点的序号
				flag = 1;
				break;
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			p = p->next;
		}
	}
	if (flag == 1)
	{
		return G.vertices + index;
	}
	else
	{
		//遍历v的所有邻接点依然没有找到w
		return NULL;
	}
}

/**
* 函数名称：InsertVex
* 函数参数：图G，要添加的顶点v
* 函数功能：在G中添加一个顶点v
* 返回值：成功返回OK，失败返回ERROR
**/
status InsertVex(Graph &G, ElemType v)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return NULL;
	}
	//初始化新的顶点信息
	G.vertices[G.ver_num].data = v;
	G.vertices[G.ver_num].first_adj = NULL;
	G.ver_num++;//顶点总数+1
	return OK;
}

/**
* 函数名称：DeleteVex
* 函数参数：图G，要删除的顶点v
* 函数功能：删除顶点v及其相关的弧
* 返回值：成功OK，失败返回ERROR
**/
status DeleteVex(Graph &G, ElemType v)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return ERROR;
	}
	Edges *cur, *next, *temp, *pre;
	int flag = 0;
	for (int i = 0; i < G.ver_num; i++)
	{
		if (G.vertices[i].data == v)
		{
			flag = 1;
			cur = G.vertices[i].first_adj;//cur初始为第一个邻接点
			while (cur != NULL)
			{
				//从第一个邻接点开始逐一删除邻接边
				next = cur->next;//指针域跳过第一个邻接点，即从表头开始删除
				free(cur);
				G.ed_num--;
				cur = next;//原来的第二个邻接点变为第一个邻接点，继续循环
			}
			//删除结点，后面的向前移动
			for (int j = i; j < G.ver_num-1; j++)
			{
				G.vertices[j] = G.vertices[j + 1];
			}
			G.ver_num--;//结点总数-1
			break;
		}
	}
	if (flag == 0)
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}

/**
* 函数名称：InsertArc
* 函数参数：图G，顶点v，w
* 函数功能：添加弧vw
* 返回值：成功OK，失败ERROR
**/
status InsertArc(Graph &G, ElemType v, ElemType w)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return ERROR;
	}
	Edges *p;
	p = (Edges*)malloc(sizeof(Edges));
	int i = LocateVex(G, v);//弧尾序号
	int j = LocateVex(G, w);//弧头序号
	p->ajvex = j;//边的指针指向弧头结点
	p->next = G.vertices[i].first_adj;//插入在上一个结点的前面（表头结点后）
	G.vertices[i].first_adj = p;//表头结点指向新插入的结点
	G.ed_num++;//图的边数+1
	return OK;
}

/**
* 函数名称：DeleteArc
* 函数参数：图G，顶点v，w
* 函数功能：删除弧vw
* 返回值：成功返回OK，否则返回ERROR
**/
status DeleteArc(Graph &G, ElemType v, ElemType w)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return ERROR;
	}
	Edges *cur, *pre;
	int start = LocateVex(G, v);//弧尾
	int end = LocateVex(G, w);//弧头
	if (start != ERROR&&end != ERROR)
	{
		cur = G.vertices[start].first_adj;//弧尾结点的第一个邻接点
		pre = NULL;
		while (cur != NULL)
		{
			if (cur->ajvex == end)//找到一个弧vw
			{
				break;//退出while循环
			}
			//本邻接点未找到弧vw
			pre = cur;
			cur = cur->next;//判断v结点的下一个邻接点
		}
		if (cur == NULL)//遍历所有邻接点均没有弧vw
		{
			//vw之间没有弧
			printf("两个结点之间没有弧\n");
			return ERROR;
		}
		else
		{
			if (pre == NULL)//首结点
			{
				G.vertices[start].first_adj = cur->next;//结点的邻接指针跳过第一个邻接点指向下一个
			}
			else//非首结点
			{
				pre->next = cur->next;//调整指针域跳过cur结点
			}
			free(cur);//释放cur结点
			G.ed_num--;//边的数量-1
			return OK;
		}
	}
	else
	{
		printf("起点或终点错误\n");
		return ERROR;
	}
}

//访问打印结点信息的函数Visit
void Visit(Vertice v)
{
	printf("结点的值为：%d\n", v.data);
}

//判断非连通图还有哪个顶点没有遍历
int not_visited(bool *visited)
{
	for (int i = 0; i < G[Graph_index].ver_num; i++)
	{
		if (visited[i] != true)
		{
			return i;//返回没有遍历的顶点序号
		}
	}
	return -1;//全部遍历过了返回-1
}

/**
* 函数名称：DFSTraverse
* 函数参数：图G
* 函数功能：按照深度优先依次遍历访问顶点
* 返回值：成功OK，失败ERROR
**/
status DFSTraverse(Graph G)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return ERROR;
	}
	bool visited[MaxLength] = { false };
	int count = 1;
	nv = not_visited(visited);
	while (nv != -1)
	{
		printf("第%d个连通分量的遍历为：\n",count);
		count++;
		DFS_re(G, G.vertices+nv, visited);
		nv = not_visited(visited);//更新nv的值
	}
	return OK;
}
//DFS递归算法
void DFS_re(Graph G,Vertice *v,bool *visited)
{
	Visit(*v);
	visited[LocateVex(G,v->data)] = true;//标记v结点已访问
	if (v->first_adj != NULL)
	{
		Vertice *w = G.vertices + v->first_adj->ajvex;//w为第一个邻接点
		while (w != NULL)
		{
			if (visited[LocateVex(G,w->data)] == false)//邻接点没有访问，则递归访问
			{
				DFS_re(G, w, visited);
			}
			if (w->data==G.vertices[0].data)//退回第一个点，即递归退出条件
			{
				return;
			}
			w = NextAdjVex(G, v->data, w->data);//否则寻找下一个邻接点访问
		}
	}
}

/**
* 函数名称：BFSTraverse
* 函数参数：图G
* 函数功能：按照广度优先依次遍历访问顶点
* 返回值：成功OK，失败ERROR
**/
status BFSTraverse(Graph G)
{
	if (G.ver_num == 0)
	{
		printf("图不存在\n");
		return ERROR;
	}
	Vertice *v,*w;
	//初始化队列q
	seq q;
	q.front = q.rear = 0;
	int pos;
	bool visited[MaxLength] = { false };//判断结点是否已经遍历过
	int count = 1;
	nv = not_visited(visited);
	while (nv != -1)
	{
		printf("第%d个连通分量遍历为：\n",count);
		count++;
		Visit(G.vertices[nv]);
		visited[nv] = true;
		enter(&q, G.vertices+nv);//第一个顶点入队
		while (qEmpty(q) != TRUE)//若队列q非空
		{
			v = del(&q);
			w = FirstAdjVex(G, v->data);
			while (w != NULL)
			{
				pos = LocateVex(G, w->data);
				if (visited[pos] == false)
				{
					Visit(G.vertices[pos]);//访问结点w
					visited[pos] = true;
					enter(&q, G.vertices + pos);
				}
				w = NextAdjVex(G, v->data, w->data);//w后移一个邻接点
			}
		}
		nv = not_visited(visited);
	}
	return OK;
}

//队列操作
//进队
void enter(seq *q, Nodes* t)
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
Nodes* del(seq*q)
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
* 函数参数：图G引用
* 函数功能：读取文件信息创建图G。
* 返回值：加载成功返回OK，加载失败返回ERROR
**/
status LoadFromFile(Graph &G)
{
	int i, j, k;
	ElemType va, vb;
	Edges *p;
	if (fscanf_s(fp1, "%d", &G.ver_num) == EOF)
	{
		fclose(fp1);
		fclose(fp2);
		return ERROR;
	}
	if (fscanf_s(fp2, "%d", &G.ed_num) == EOF)
	{
		fclose(fp1);
		fclose(fp2);
		return ERROR;
	}
	for (k = 0; k < G.ver_num; k++)
	{
		if (fscanf_s(fp1, "%d", &G.vertices[k].data) == EOF)
		{
			fclose(fp1);
			fclose(fp2);
			return ERROR;
		}
		G.vertices[k].first_adj = NULL;
	}
	for (k = 0; k < G.ed_num; k++)
	{
		p = (Edges*)malloc(sizeof(Edges));
		if (fscanf_s(fp2, "%d", &va) == EOF)
		{
			fclose(fp1);
			fclose(fp2);
			return ERROR;
		}
		if (fscanf_s(fp2, "%d", &vb) == EOF)
		{
			fclose(fp1);
			fclose(fp2);
			return ERROR;
		}
		i = LocateVex(G, va);//弧尾序号
		j = LocateVex(G, vb);//弧头序号
		p->ajvex = j;//边的指针指向弧头结点
		p->next = G.vertices[i].first_adj;//插入在上一个结点的前面（表头结点后）
		G.vertices[i].first_adj = p;//表头结点指向新插入的结点
	}
	fclose(fp1);
	fclose(fp2);
	return OK;
}

/**
* 函数名称：ExportToFile
* 函数参数：图G
* 函数功能：将G中的数据保存到fp指针指向的文件中
* 返回值：成功OK，失败ERROR
**/
status ExportToFile(Graph G)
{
	Edges *temp;
	fprintf(fp1, "%d ", G.ver_num);
	fprintf(fp2, "%d ", G.ed_num);
	for (int i = 0; i < G.ver_num; i++)
	{
		fprintf(fp1, "%d ", G.vertices[i].data);
		temp = G.vertices[i].first_adj;
		while (temp != NULL)
		{
			fprintf(fp2, "%d %d\n", G.vertices[i].data, G.vertices[temp->ajvex].data);
			temp = temp->next;
		}
	}
	fclose(fp1);
	fclose(fp2);
	return OK;
}
//多图操作
status Switch_Graph()
{
	int temp;
	printf("请输入要切换到第几号图：");
	scanf_s("%d", &temp);
	if (temp >= 1 && temp <= MaxLength - 1)
	{
		Graph_index = temp;
		return OK;
	}
	else
	{
		printf("只支持1-%d号多图\n",MaxLength-1);
		return ERROR;
	}
}