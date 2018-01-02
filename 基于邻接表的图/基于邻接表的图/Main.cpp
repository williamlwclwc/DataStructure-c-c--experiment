#include "Declaration.h"//����&����ͷ�ļ�

FILE *fp1,*fp2;
char filename1[30],filename2[30];
Graph G[MaxLength];
int Graph_index = 1;//��ͼ���±�
int nv;//δ�����Ķ�����ţ�-1��ʾȫ��������

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
		printf("    	  1. CreateGraph������ͼ��           7. NextAdjVex����ȡ��һ���ڽӵ㣩\n");
		printf("    	  2. DestroyGraph������ͼ��          8. InsertVex�����붥�㣩\n");
		printf("    	  3. LocateVex�����Ҷ��㣩           9. DeleteVex��ɾ�����㣩 \n");
		printf("    	  4. GetVex����ȡ���㣩              10.InsertArc�����뻡��\n");
		printf("    	  5. PutVex�����㸳ֵ��              11.DeleteArc��ɾ������\n");
		printf("    	  6. FirstAdjVex����ȡ��һ�ڽӵ㣩   12.DFSTraverse�������������������\n");
		printf("          13.BFSTraverse������������������� 14.LoadFromFile����ȡ�ļ���\n");
		printf("          15.ExportToFile��������ļ���      16.Multi-Graph����ͼ������\n");
		printf("    	  0. Exit\n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("����ǰ���������ǵ�%d��ͼ\n", Graph_index);
		printf("��ѡ����Ĳ���[0~16]:");
		scanf_s("%d", &op);
		//�����û����������Ӧ������ִ����Ӧ����
		switch (op) {
		case 1:
			if (CreateGraph(G[Graph_index]) == OK)
			{
				printf("����ͼ�ɹ�\n");
			}
			else
			{
				printf("����ͼʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyGraph(G[Graph_index]) == OK)
			{
				printf("����ͼ�ɹ�\n");
			}
			else
			{
				printf("����ͼʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 3:
			printf("������Ҫ���ҵĽ����Ϣ��");
			scanf_s("%d", &u);
			result = LocateVex(G[Graph_index], u);
			if (result != ERROR)
			{
				printf("��Ҫ���ҵĽ�����Ϊ:%d\n",result);
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 4:
			printf("������Ҫ���ҵĽ����Ϣ��");
			scanf_s("%d", &u);
			re = GetVex(G[Graph_index], u);
			if (re != NULL)
			{
				printf("���ҵĽ���ǣ�%d\n", re->data);
			}
			else
			{
				printf("��ȡʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 5:
			printf("������Ҫ���ҵĽ����Ϣ��");
			scanf_s("%d", &u);
			printf("������Ҫ�滻��ֵ��");
			scanf_s("%d", &value);
			if (PutVex(G[Graph_index], u, value) == OK)
			{
				printf("��ֵ�ɹ�\n");
			}
			else
			{
				printf("��ֵʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 6:
			printf("������Ҫ���ҵĽ����Ϣ��");
			scanf_s("%d", &u);
			re = FirstAdjVex(G[Graph_index], u);
			if (re != NULL)
			{
				printf("��һ���ڽӵ��ǣ�%d\n", re->data);
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 7:
			printf("������Ҫ���ҵĽ����Ϣ��");
			scanf_s("%d", &u);
			printf("������Ҫ���ҵ��ڽӵ���Ϣ��");
			scanf_s("%d", &value);
			re = NextAdjVex(G[Graph_index], u, value);
			if (re != NULL)
			{
				printf("����Ľ���������ڽӵ����һ���ڽӵ��ǣ�%d\n", re->data);
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 8:
			printf("������Ҫ����Ľ����Ϣ��");
			scanf_s("%d", &u);
			if (InsertVex(G[Graph_index], u) == OK)
			{
				printf("����ɹ�\n");
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 9:
			printf("������Ҫɾ���Ľ����Ϣ��");
			scanf_s("%d", &u);
			if (DeleteVex(G[Graph_index], u) == OK)
			{
				printf("ɾ���ɹ�\n");
			}
			else
			{
				printf("ɾ��ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 10:
			printf("������Ҫ����Ļ�β��Ϣ��");
			scanf_s("%d", &u);
			printf("������Ҫ����Ļ�ͷ��Ϣ��");
			scanf_s("%d", &value);
			if (InsertArc(G[Graph_index], u, value) == OK)
			{
				printf("����ɹ�\n");
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 11:
			printf("������Ҫɾ���Ļ�β��Ϣ��");
			scanf_s("%d", &u);
			printf("������Ҫɾ���Ļ�ͷ��Ϣ��");
			scanf_s("%d", &value);
			if (DeleteArc(G[Graph_index], u, value) == OK)
			{
				printf("ɾ���ɹ�\n");
			}
			else
			{
				printf("ɾ��ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 12:
			if (DFSTraverse(G[Graph_index]) == OK)
			{
				printf("������ȱ����ɹ�\n");
			}
			else
			{
				printf("������ȱ���ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 13:
			if (BFSTraverse(G[Graph_index]) == OK)
			{
				printf("������ȱ����ɹ�\n");
			}
			else
			{
				printf("������ȱ���ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 14:
			printf("���������ļ����ļ�����");
			scanf_s("%s", filename1, 30);
			printf("�����뻡�ļ����ļ�����");
			scanf_s("%s", filename2, 30);
			if (fopen_s(&fp1, filename1, "r+") != 0||fopen_s(&fp2, filename2, "r+") != 0)
			{
				printf("�ļ���ʧ��\n ");
			}
			else
			{
				if (LoadFromFile(G[Graph_index]) == OK)
				{
					printf("��ȡ�ļ�����ͼ�ɹ�\n");
				}
				else
				{
					printf("��ȡ�ļ�����ͼʧ��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 15:
			printf("���������ļ����ļ�����");
			scanf_s("%s", filename1, 30);
			printf("�����뻡�ļ����ļ�����");
			scanf_s("%s", filename2, 30);
			if (G[Graph_index].ver_num == 0)
			{
				printf("ͼ������\n");
				printf("���ͼ��Ϣ���ļ�ʧ��\n");
			}
			else if (fopen_s(&fp1, filename1, "w+") != 0 || fopen_s(&fp2, filename2, "w+") != 0)
			{
				printf("�ļ���ʧ��\n ");
			}
			else
			{
				if (ExportToFile(G[Graph_index]) == OK)
				{
					printf("���ͼ��Ϣ���ļ��ɹ�\n");
				}
				else
				{
					printf("���ͼ��Ϣ���ļ�ʧ��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 16:
			if (Switch_Graph() == OK)
			{
				printf("�л��ɹ�\n");
			}
			else
			{
				printf("�л�ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 0:
			printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
			getchar(); getchar();
			break;
		}//end of switch
	}//end of while
}//end of main()

 /**
 * �������ƣ�CreateGraph
 * ����������ͼGͷ��������
 * �������ܣ����ո�����ͱ߹���һ��ͼ
 * ����ֵ���ɹ����췵��OK�����򷵻�ERROR
 **/
status CreateGraph(Graph &G)
{
	int i, j, k;
	ElemType va, vb;
	Edges *p;
	printf("�����붥���������");
	scanf_s("%d", &G.ver_num);
	printf("������ߵ�������");
	scanf_s("%d", &G.ed_num);
	for (k = 0; k < G.ver_num; k++)
	{
		printf("���������dataֵ��");
		scanf_s("%d", &G.vertices[k].data);
		G.vertices[k].first_adj = NULL;
	}
	for (k = 0; k < G.ed_num; k++)
	{
		p = (Edges*)malloc(sizeof(Edges));
		printf("�������%d���ߵĻ�β��㣺", k + 1);
		scanf_s("%d", &va);
		printf("�������%d���ߵĻ�ͷ��㣺", k + 1);
		scanf_s("%d", &vb);
		i = LocateVex(G, va);//��β���
		j = LocateVex(G, vb);//��ͷ���
		p->ajvex = j;//�ߵ�ָ��ָ��ͷ���
		p->next = G.vertices[i].first_adj;//��������һ������ǰ�棨��ͷ����
		G.vertices[i].first_adj = p;//��ͷ���ָ���²���Ľ��
	}
	return OK;
}

/**
* �������ƣ�DestroyGraph
* ����������ͼG������
* �������ܣ�����һ��ͼ
* ����ֵ���ɹ����ٷ���OK�����򷵻�ERROR
**/
status DestroyGraph(Graph &G)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
		return ERROR;
	}
	Edges *p, *q;
	for (int i = 0; i < G.ver_num; i++)
	{
		p = G.vertices[i].first_adj;//��ʼpΪ��һ�ڽӵ�
		while (p != NULL)
		{
			q = p->next;//��qΪp����һ���ڽӵ㣨��գ�
			free(p);
			p = q;//ѭ����һ���ڽӵ�
		}
	}
	G.ed_num = 0;
	G.ver_num = 0;
	return OK;
}

/**
* �������ƣ�LocateVex
* ����������ͼG������u
* �������ܣ�����һ������
* ����ֵ���ɹ�����u��λ�ã�����ʧ����ʾ
**/
int LocateVex(Graph G, ElemType u)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
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
* �������ƣ�GetVex
* ����������ͼG������v
* �������ܣ����ض������Ϣ
* ����ֵ���ɹ����ض�����Ϣ������NULL
**/
Vertice* GetVex(Graph G, ElemType v)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
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
* �������ƣ�PutVex
* ����������ͼG�����ã�����v��Ҫ����ֵvalue
* �������ܣ��ı䶥��v��ֵ
* ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
**/
status PutVex(Graph &G,ElemType v,ElemType value)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
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
* �������ƣ�FirstAdjVex
* ����������ͼG������v
* �������ܣ����ҵ�һ���ڽӵ�
* ����ֵ������v�ĵ�һ���ڽӵ㣬���򷵻ؿ�
**/
Vertice* FirstAdjVex(Graph G, ElemType v)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
		return NULL;
	}
	int index, flag = 0;//��һ���ڽӵ�����
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
* �������ƣ�NextAdjVex
* ����������ͼG������v���ڽӵ�w
* �������ܣ�����w����һ���ڽӵ�
* ����ֵ������w����һ���ڽӵ㣬���򷵻ؿ�
**/
Vertice* NextAdjVex(Graph G, ElemType v,ElemType w)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
		return NULL;
	}
	int v_index, w_index, index, flag = 0;
	//�ҵ�����v��w�����
	v_index = LocateVex(G, v);
	w_index = LocateVex(G, w);
	if (v_index == ERROR || w_index == ERROR)
	{
		return NULL;
	}
	Edges *p = G.vertices[v_index].first_adj;//��ʼpΪ��һ���ڽӵ�
	while (p != NULL)
	{
		if (p->ajvex == w_index)
		{
			if (p->next != NULL)//���w�������һ���ڽӵ�
			{
				index = p->next->ajvex;//Ŀ�궥������
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
		//����v�������ڽӵ���Ȼû���ҵ�w
		return NULL;
	}
}

/**
* �������ƣ�InsertVex
* ����������ͼG��Ҫ��ӵĶ���v
* �������ܣ���G�����һ������v
* ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
**/
status InsertVex(Graph &G, ElemType v)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
		return NULL;
	}
	//��ʼ���µĶ�����Ϣ
	G.vertices[G.ver_num].data = v;
	G.vertices[G.ver_num].first_adj = NULL;
	G.ver_num++;//��������+1
	return OK;
}

/**
* �������ƣ�DeleteVex
* ����������ͼG��Ҫɾ���Ķ���v
* �������ܣ�ɾ������v������صĻ�
* ����ֵ���ɹ�OK��ʧ�ܷ���ERROR
**/
status DeleteVex(Graph &G, ElemType v)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
		return ERROR;
	}
	Edges *cur, *next, *temp, *pre;
	int flag = 0;
	for (int i = 0; i < G.ver_num; i++)
	{
		if (G.vertices[i].data == v)
		{
			flag = 1;
			cur = G.vertices[i].first_adj;//cur��ʼΪ��һ���ڽӵ�
			while (cur != NULL)
			{
				//�ӵ�һ���ڽӵ㿪ʼ��һɾ���ڽӱ�
				next = cur->next;//ָ����������һ���ڽӵ㣬���ӱ�ͷ��ʼɾ��
				free(cur);
				G.ed_num--;
				cur = next;//ԭ���ĵڶ����ڽӵ��Ϊ��һ���ڽӵ㣬����ѭ��
			}
			//ɾ����㣬�������ǰ�ƶ�
			for (int j = i; j < G.ver_num-1; j++)
			{
				G.vertices[j] = G.vertices[j + 1];
			}
			G.ver_num--;//�������-1
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
* �������ƣ�InsertArc
* ����������ͼG������v��w
* �������ܣ���ӻ�vw
* ����ֵ���ɹ�OK��ʧ��ERROR
**/
status InsertArc(Graph &G, ElemType v, ElemType w)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
		return ERROR;
	}
	Edges *p;
	p = (Edges*)malloc(sizeof(Edges));
	int i = LocateVex(G, v);//��β���
	int j = LocateVex(G, w);//��ͷ���
	p->ajvex = j;//�ߵ�ָ��ָ��ͷ���
	p->next = G.vertices[i].first_adj;//��������һ������ǰ�棨��ͷ����
	G.vertices[i].first_adj = p;//��ͷ���ָ���²���Ľ��
	G.ed_num++;//ͼ�ı���+1
	return OK;
}

/**
* �������ƣ�DeleteArc
* ����������ͼG������v��w
* �������ܣ�ɾ����vw
* ����ֵ���ɹ�����OK�����򷵻�ERROR
**/
status DeleteArc(Graph &G, ElemType v, ElemType w)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
		return ERROR;
	}
	Edges *cur, *pre;
	int start = LocateVex(G, v);//��β
	int end = LocateVex(G, w);//��ͷ
	if (start != ERROR&&end != ERROR)
	{
		cur = G.vertices[start].first_adj;//��β���ĵ�һ���ڽӵ�
		pre = NULL;
		while (cur != NULL)
		{
			if (cur->ajvex == end)//�ҵ�һ����vw
			{
				break;//�˳�whileѭ��
			}
			//���ڽӵ�δ�ҵ���vw
			pre = cur;
			cur = cur->next;//�ж�v������һ���ڽӵ�
		}
		if (cur == NULL)//���������ڽӵ��û�л�vw
		{
			//vw֮��û�л�
			printf("�������֮��û�л�\n");
			return ERROR;
		}
		else
		{
			if (pre == NULL)//�׽��
			{
				G.vertices[start].first_adj = cur->next;//�����ڽ�ָ��������һ���ڽӵ�ָ����һ��
			}
			else//���׽��
			{
				pre->next = cur->next;//����ָ��������cur���
			}
			free(cur);//�ͷ�cur���
			G.ed_num--;//�ߵ�����-1
			return OK;
		}
	}
	else
	{
		printf("�����յ����\n");
		return ERROR;
	}
}

//���ʴ�ӡ�����Ϣ�ĺ���Visit
void Visit(Vertice v)
{
	printf("����ֵΪ��%d\n", v.data);
}

//�жϷ���ͨͼ�����ĸ�����û�б���
int not_visited(bool *visited)
{
	for (int i = 0; i < G[Graph_index].ver_num; i++)
	{
		if (visited[i] != true)
		{
			return i;//����û�б����Ķ������
		}
	}
	return -1;//ȫ���������˷���-1
}

/**
* �������ƣ�DFSTraverse
* ����������ͼG
* �������ܣ���������������α������ʶ���
* ����ֵ���ɹ�OK��ʧ��ERROR
**/
status DFSTraverse(Graph G)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
		return ERROR;
	}
	bool visited[MaxLength] = { false };
	int count = 1;
	nv = not_visited(visited);
	while (nv != -1)
	{
		printf("��%d����ͨ�����ı���Ϊ��\n",count);
		count++;
		DFS_re(G, G.vertices+nv, visited);
		nv = not_visited(visited);//����nv��ֵ
	}
	return OK;
}
//DFS�ݹ��㷨
void DFS_re(Graph G,Vertice *v,bool *visited)
{
	Visit(*v);
	visited[LocateVex(G,v->data)] = true;//���v����ѷ���
	if (v->first_adj != NULL)
	{
		Vertice *w = G.vertices + v->first_adj->ajvex;//wΪ��һ���ڽӵ�
		while (w != NULL)
		{
			if (visited[LocateVex(G,w->data)] == false)//�ڽӵ�û�з��ʣ���ݹ����
			{
				DFS_re(G, w, visited);
			}
			if (w->data==G.vertices[0].data)//�˻ص�һ���㣬���ݹ��˳�����
			{
				return;
			}
			w = NextAdjVex(G, v->data, w->data);//����Ѱ����һ���ڽӵ����
		}
	}
}

/**
* �������ƣ�BFSTraverse
* ����������ͼG
* �������ܣ����չ���������α������ʶ���
* ����ֵ���ɹ�OK��ʧ��ERROR
**/
status BFSTraverse(Graph G)
{
	if (G.ver_num == 0)
	{
		printf("ͼ������\n");
		return ERROR;
	}
	Vertice *v,*w;
	//��ʼ������q
	seq q;
	q.front = q.rear = 0;
	int pos;
	bool visited[MaxLength] = { false };//�жϽ���Ƿ��Ѿ�������
	int count = 1;
	nv = not_visited(visited);
	while (nv != -1)
	{
		printf("��%d����ͨ��������Ϊ��\n",count);
		count++;
		Visit(G.vertices[nv]);
		visited[nv] = true;
		enter(&q, G.vertices+nv);//��һ���������
		while (qEmpty(q) != TRUE)//������q�ǿ�
		{
			v = del(&q);
			w = FirstAdjVex(G, v->data);
			while (w != NULL)
			{
				pos = LocateVex(G, w->data);
				if (visited[pos] == false)
				{
					Visit(G.vertices[pos]);//���ʽ��w
					visited[pos] = true;
					enter(&q, G.vertices + pos);
				}
				w = NextAdjVex(G, v->data, w->data);//w����һ���ڽӵ�
			}
		}
		nv = not_visited(visited);
	}
	return OK;
}

//���в���
//����
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
//����
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
//�ж϶����Ƿ�Ϊ��
status qEmpty(seq q)
{ /* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
	if (q.front == q.rear)
		return TRUE;
	else
		return FALSE;
}

/**
* �������ƣ�LoadFromFile
* ����������ͼG����
* �������ܣ���ȡ�ļ���Ϣ����ͼG��
* ����ֵ�����سɹ�����OK������ʧ�ܷ���ERROR
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
		i = LocateVex(G, va);//��β���
		j = LocateVex(G, vb);//��ͷ���
		p->ajvex = j;//�ߵ�ָ��ָ��ͷ���
		p->next = G.vertices[i].first_adj;//��������һ������ǰ�棨��ͷ����
		G.vertices[i].first_adj = p;//��ͷ���ָ���²���Ľ��
	}
	fclose(fp1);
	fclose(fp2);
	return OK;
}

/**
* �������ƣ�ExportToFile
* ����������ͼG
* �������ܣ���G�е����ݱ��浽fpָ��ָ����ļ���
* ����ֵ���ɹ�OK��ʧ��ERROR
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
//��ͼ����
status Switch_Graph()
{
	int temp;
	printf("������Ҫ�л����ڼ���ͼ��");
	scanf_s("%d", &temp);
	if (temp >= 1 && temp <= MaxLength - 1)
	{
		Graph_index = temp;
		return OK;
	}
	else
	{
		printf("ֻ֧��1-%d�Ŷ�ͼ\n",MaxLength-1);
		return ERROR;
	}
}