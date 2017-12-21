#include "Declaration.h"//����&����ͷ�ļ�

int T_index = 1;//��ǰ���ı��
SqList L;//����ɭ�ֹ���ṹ��
Tree* re;
int count = 0;
FILE*fp;

void main(void) {
	int op = 1;
	int pos = 0, result,e,value,LR,temp=0;
	char definition[100];//������ʱ����Ĵ�
	char filename[30];
	Tree* Add;

	//Main Menu Entrance
	while (op) {
		system("cls");	printf("\n\n");
		printf("                      Menu for Binary-Tree On Binary-Tree-List Structure \n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("    	  1. InitBiTree����ʼ����������         2.DestroyBiTree�����ٶ������� \n");
		printf("    	  3. CreateBiTree��������������         4.ClearBiTree����ն������� \n");
		printf("    	  5. BiTreeEmpty���жϿն�������        6.BiTreeDepth������ȣ�  \n");
		printf("    	  7. Root����ø���㣩                 8.Value����ý�㣩 \n");
		printf("    	  9. Assign����㸳ֵ��                 10.Parent�����˫�׽�㣩 \n");
		printf("    	  11.LeftChild��������ӽ�㣩        12.RightChild������Һ��ӽ�㣩\n");
		printf("    	  13.LeftSibling��������ֵܽ�㣩      14.RightSibling��������ֵܽ�㣩 \n");
		printf("    	  15.InsertChild������������            16.DeleteChild��ɾ�������� \n ");
		printf("    	  17.PreOrderTraverse��ǰ�������       18.InOrderTraverse����������� \n");
		printf("          19.PostOrderTraverse�����������      20.LevelOrderTraverse�����������\n");
		printf("    	  21.LoadFromFile����ȡ�ļ���           22.ExportToFile��������ļ���\n");
		printf("          23 Multi-Operation������������\n");
		printf("    	  0. Exit\n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("��ǰ��������Ϊ��%d:\n", T_index);
		printf("��ѡ����Ĳ���[0~23]:");
		scanf_s("%d", &op);
		//�����û����������Ӧ������ִ����Ӧ����
		switch (op) {
		case 1:
			if (InitBiTree(L) == OK)
			{
				L.elem[T_index].num = 0;
				printf("��ʼ���������ɹ�\n");
			}
			else
			{
				printf("��ʼ��������ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyBiTree(L) == OK)
			{
				printf("���ٶ������ɹ�\n");
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 3:
			printf("�밴��ǰ��������Ӧ��key��data(keyΪ0��dataΪ#�����):\n");
			printf("ע�⣺���key����Ĳ�Ϊ���֣����Ӵ˽��Ϊ��\n���������ظ���keyֵ�������޷�׼ȷ����\n");
			getchar();
			scanf_s("%s", definition, 100);
			if (CreateBiTree(&L.elem[T_index].root, definition) == OK)
			{
				printf("�����������ɹ�\n");
				if (BiTreeEmpty(L.elem[T_index]) == TRUE)
				{
					printf("�����˿յĶ�����\n");
				}
			}
			else
			{
				printf("����������ʧ��\n");
			}
			count = 0;
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 4:
			if (ClearBiTree(L) == OK)
			{
				printf("��ճɹ�\n");
			}
			else
			{
				printf("���ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 5:
			if(L.length<T_index)
			{
				printf("������������\n");
			}
			else
			{
				result = BiTreeEmpty(L.elem[T_index]);
				if (result == TRUE)
				{
					printf("������Ϊ��\n");
				}
				else if (result == FALSE)
				{
					printf("�������ǿ�\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 6:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				result = BiTreeDepth(L.elem[T_index].root);
				printf("�����������Ϊ%d\n", result);
			}
			printf("���س�������\n");
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
				printf("�����ڸ����\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 8:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("������ؼ���e:");
				scanf_s("%d", &e);
				result = Value(L.elem[T_index].root, e);
				if (result != ERROR)
				{
					printf("�ý���dataֵ��%c\n", result);
				}
				else
				{
					printf("δ���ҵ��ý��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 9:
			printf("������Ҫ�滻�Ľ��Ĺؼ���:");
			scanf_s("%d", &e);
			printf("������Ҫ�滻��dataֵ:");
			getchar();
			scanf_s("%c", &value);
			if (Assign(L.elem[T_index].root, e, value) == OK)
			{
				printf("�滻ֵ�ɹ�\n");
			}
			else
			{
				printf("�滻ֵʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 10:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("��������Ĺؼ���:\n");
				scanf_s("%d", &e);
				re = Parent(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("˫�׵�key��%d data:%c\n", re->key, re->data);
				}
				else
				{
					printf("δ�ҵ�˫�׽��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 11:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("��������Ĺؼ���:");
				scanf_s("%d", &e);
				re = LeftChild(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("���ӵ�key��%d data��%c\n", re->key, re->data);
				}
				else
				{
					printf("δ�ҵ�����\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 12:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("��������Ĺؼ���:");
				scanf_s("%d", &e);
				re = RightChild(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("�Һ��ӵ�key��%d data��%c\n", re->key, re->data);
				}
				else
				{
					printf("δ�ҵ��Һ���\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 13:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("��������Ĺؼ���:");
				scanf_s("%d", &e);
				re = LeftSibling(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("���ֵܵ�key��%d data��%c\n", re->key, re->data);
				}
				else
				{
					printf("δ�ҵ����ֵ�\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 14:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("��������Ĺؼ���:");
				scanf_s("%d", &e);
				re = RightSibling(L.elem[T_index].root, e);
				if (re != NULL)
				{
					printf("���ֵܵ�key��%d data��%c\n", re->key, re->data);
				}
				else
				{
					printf("δ�ҵ����ֵ�\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 15:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("�밴��ǰ�����������������Ӧ��key��data(keyΪ0��dataΪ#�����):\n");
				getchar();
				scanf_s("%s", definition, 100);
				if (CreateBiTree(&Add, definition) == OK)
				{
					printf("������Ҫ����Ľ��ĸ��׽��Ĺؼ��֣�");
					scanf_s("%d", &e);
					printf("������Ҫ������������������������������0��������1����");
					scanf_s("%d", &LR);
					if (InsertChild(L.elem[T_index].root, e, LR, Add) == OK)
					{
						printf("���������ɹ�\n");
					}
					else
					{
						printf("��������ʧ��\n");
					}
				}
				else
				{
					printf("δ�ܴ�������\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 16:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("������Ҫɾ���Ľ��ĸ��׽��Ĺؼ��֣�");
				scanf_s("%d", &e);
				printf("������Ҫɾ����������������������������0��������1����");
				scanf_s("%d", &LR);
				if (DeleteChild(L.elem[T_index].root, e, LR) == OK)
				{
					printf("ɾ�������ɹ�\n");
				}
				else
				{
					printf("ɾ��ʧ��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 17:
			if (L.length < T_index||strcmp(L.elem[T_index].name, "already_destroyed") == 0)
			{
				printf("������δ����\n");
			}
			else
			{
				if (L.elem[T_index].root != NULL)
				{
					PreOrderTraverse(L.elem[T_index].root);
				}
				else
				{
					printf("ǰ�����ʧ��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 18:
			if (L.length < T_index||strcmp(L.elem[T_index].name, "already_destroyed") == 0)
			{
				printf("������δ����\n");
			}
			else
			{
				if (L.elem[T_index].root != NULL)
				{
					InOrderTraverse(L.elem[T_index].root);
				}
				else
				{
					printf("�������ʧ��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 19:
			if (L.length < T_index||strcmp(L.elem[T_index].name, "already_destroyed") == 0)
			{
				printf("������δ����\n");
			}
			else
			{
				if (L.elem[T_index].root != NULL)
				{
					PostOrderTraverse(L.elem[T_index].root);
				}
				else
				{
					printf("�������ʧ��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 20:
			if (L.length < T_index||strcmp(L.elem[T_index].name, "already_destroyed") == 0)
			{
				printf("������δ����\n");
			}
			else
			{
				if (L.elem[T_index].root != NULL)
				{
					LevelOrderTraverse(L.elem[T_index].root);
				}
				else
				{
					printf("�������ʧ��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 21:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("ע�⣺�����ļ����ݣ����key����Ĳ�Ϊ���֣����Ӵ˽��Ϊ��\n���������ظ���keyֵ�������޷�׼ȷ����\n");
				printf("�������ļ���: ");
				scanf_s("%s", filename, 30);
				if (fopen_s(&fp, filename, "r+") != 0)
				{
					printf("�ļ���ʧ��\n ");
				}
				else if (LoadFromFile(&L.elem[T_index].root) == OK)
				{
					printf("��ȡǰ�����гɹ�\n");
					if (BiTreeEmpty(L.elem[T_index]) == TRUE)
					{
						printf("�����˿յĶ�����\n");
					}
				}
				else
				{
					printf("��ȡǰ������ʧ��\n");
				}
				count = 0;
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 22:
			if (L.length < T_index)
			{
				printf("������������\n");
			}
			else
			{
				printf("�������ļ���: ");
				scanf_s("%s", filename, 30);
				if (fopen_s(&fp, filename, "w+") != 0)
				{
					printf("���ļ�ʧ��\n");
				}
				else if (ExportToFile(L.elem[T_index].root) == OK)
				{
					printf("�����ǰ��ɹ�\n");
				}
				else
				{
					printf("�����ǰ��ʧ��\n");
				}
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 23:
			printf("������Ҫ�л����ڼ�������\n");
			temp = L.length;
			scanf_s("%d", &T_index);
			if (T_index < temp + 1)
			{
				printf("�Ѿ��л�����%d����\n", T_index);
			}
			else
			{
				printf("����ʹ�ö���%d\n", temp );
				T_index = temp - 1;
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
 * �������ƣ�InitBiTree
 * ����������SqList�����ñ���&L
 * �������ܣ�����һ���յ���
 * ����ֵ���ɹ����췵��OK�����򷵻�ERROR
 **/
status InitBiTree(SqList &L)
{
	Head *newbase;//�����µĿռ�
	//��ǰɭ�ֿռ��Ƿ��㹻
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
		(L.length)++;//��������+1
	}
	//��������ӵ�������Ϣ
	printf("�������������ƣ�\n");
	scanf_s("%s", L.elem[T_index].name,20);
	L.elem[T_index].root = NULL;
	return OK;
}

//�ݹ��ͷŽ��ռ�
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
* �������ƣ�DestroyBiTree
* ����������L������
* �������ܣ�����һ����
* ����ֵ���ɹ��ݻٷ���OK�����򷵻�ERROR
**/
status DestroyBiTree(SqList&L)
{
	if (L.length < T_index)
	{
		return ERROR;
	}
	if (strcmp(L.elem[T_index].name,"already_destroyed")!=0)
	{
		//������Ѿ����ڣ���ݹ��ͷŽ��ռ�
		if (L.elem[T_index].num!=0)
		{
			FreeNode(L.elem[T_index].root);//�Ӹ���㿪ʼ�ݹ��ͷ����н��ռ�
			L.elem[T_index].num = 0;
			L.elem[T_index].root = NULL;
			strcpy_s(L.elem[T_index].name , "already_destroyed");
			(L.length)--;//ɾ����ǰͷ���ļ�¼
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
* �������ƣ�CreateBiTree
* �������������Ľ��Ķ���ָ��
* �������ܣ�����һ��������
* ����ֵ���ɹ��ݻٷ���OK�����򷵻�ERROR
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
		char a[20];//���ڴ��key����һλ��ʱ����ȡ���ַ���
		for (i = count;; i++)
		{
			if (*(definition + i) < '0' || *(definition + i) > '9')
			{
				//�����ַ���ʱ����˳�
				break;
			}
			else
			{
				//�������ִ���a����
				a[c] = *(definition + i);
				c++;
			}
		}
		a[c] = '\0';//��a����ַ���
		//�����ַ��Ĵ���
		if (i == count+1) 
		{
			key = *(definition + count) - '0'; // ����һ��key���ٶ�Ϊint��
			count++;
		}
		//�ַ����Ĵ���
		else
		{
			key = atoi(a);
			count = count + c;
		}
		c = 0;
		data = *(definition + count); // ����һ��data���ٶ�Ϊ�ַ���
		count++;
		if (data == '#'|| key == 0) //data����#��key����0�����
			(*root) = NULL;
		else
		{
			(*root) = (Tree *)malloc(sizeof(Tree));
			L.elem[T_index].num++;//�����+1
			(*root)->data = data;  //��data��key��ֵ
			(*root)->key = key;
			if (CreateBiTree(&(*root)->lchild, definition) == ERROR)//�ݹ鹹��������
			{
				return ERROR;
			}
			if (CreateBiTree(&(*root)->rchild, definition) == ERROR)//�ݹ鹹��������
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
* �������ƣ�ClearBiTree
* ����������L������
* �������ܣ����һ��������
* ����ֵ���ɹ���շ���OK�����򷵻�ERROR
**/
status ClearBiTree(SqList&L)
{
	if (L.length < T_index)
	{
		return ERROR;
	}
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		//������Ѿ����ڣ���ݹ��ͷŽ��ռ�
		if (L.elem[T_index].num != 0)
		{
			FreeNode(L.elem[T_index].root);//�Ӹ���㿪ʼ�ݹ��ͷ����н��ռ�
			L.elem[T_index].root = NULL;
			L.elem[T_index].num = 0;
			return OK;
		}
		else
		{
			printf("�������\n");
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

/**
* �������ƣ�BiTreeEmpty
* ��������������ͷ���
* �������ܣ����һ��������
* ����ֵ���ɹ��ݻٷ���OK�����򷵻�ERROR
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
* �������ƣ�BiTreeDepth
* �������������ĸ����
* �������ܣ������������
* ����ֵ���ɹ��ݻٷ���OK�����򷵻�ERROR
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
* �������ƣ�ROOT
* ����������L
* �������ܣ��������ĸ����ָ��
* ����ֵ���ɹ����ظ����ָ�룬���򷵻�NULL
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

//����keyΪe�Ľ��
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
* �������ƣ�Value
* ������������T���ؼ���e
* �������ܣ����عؼ��ֽ���dataֵ
* ����ֵ��char���͵�data
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
* �������ƣ�Assign
* ������������T���ؼ���e
* �������ܣ������e��data��ֵΪvalue
* ����ֵ���ɹ�OK��ʧ��ERROR
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
* �������ƣ�Parent
* ������������T���ؼ���e
* �������ܣ���ȡ˫�׽��
* ����ֵ���ɹ�����˫�׽�㣬ʧ�ܷ���NULL
**/
Tree *Parent(Tree *T, int e)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") != 0)
	{
		/* ��ʼ����: ������T����,e��T��ĳ����� */
		/* �������: ��e��T�ķǸ����,�򷵻�����˫��,���򷵻أ��գ� */
		seq q;
		q.front = q.rear = 0;
		Tree* a;
		if (T) /* �ǿ��� */
		{
			enter(&q, T); /* ������� */
			while (qEmpty(q) != TRUE) /* �Ӳ��� */
			{
				a = del(&q); /* ����,����Ԫ�ظ���a */
				if (a->lchild&&a->lchild->key == e || a->rchild&&a->rchild->key == e)
					/* �ҵ�e(��������Һ���) */
					return a; /* ����e��˫�׵�ֵ */
				else /* û�ҵ�e,����������Һ���ָ��(����ǿ�) */
				{
					if (a->lchild)
						enter(&q, a->lchild);
					if (a->rchild)
						enter(&q, a->rchild);
				}
			}
		}
		return NULL; /* ���ջ�û�ҵ�e */
	}
	else
	{
		return NULL;
	}
}

/**
* �������ƣ�LeftChild
* ������������T���ؼ���e
* �������ܣ���ȡ���ӽ��
* ����ֵ���ɹ��������ӽ�㣬ʧ�ܷ���NULL
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
* �������ƣ�RightChild
* ������������T���ؼ���e
* �������ܣ���ȡ�Һ��ӽ��
* ����ֵ���ɹ������Һ��ӽ�㣬ʧ�ܷ���NULL
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
* �������ƣ�LeftSibling
* ������������T���ؼ���e
* �������ܣ���ȡ���ֵܽ��
* ����ֵ���ɹ��������ֵܽ�㣬ʧ�ܷ���NULL
**/
Tree* LeftSibling(Tree *T, int e)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") == 0)
	{
		return NULL;
	}
	/* ��ʼ����: ������T����,e��T��ĳ����� */
	/* �������: ����e�����ֵܡ���e��T�����ӻ������ֵ�,�򷵻أ��գ� */
	Tree* p;
	if (T) /* �ǿ��� */
	{
		p = Parent(T, e);  /* pΪָ����e��˫�׵�ָ�� */
		if (p->lchild&&p->rchild&&p->rchild->key == e) /* p�������Һ������Һ�����e */
			return p->lchild; /* ����p������(e�����ֵ�) */
	}
	return NULL; /* ���ջ�û�ҵ�e�����ֵ� */
}

/**
* �������ƣ�RightSibling
* ������������T���ؼ���e
* �������ܣ���ȡ���ֵܽ��
* ����ֵ���ɹ��������ֵܽ�㣬ʧ�ܷ���NULL
**/
Tree* RightSibling(Tree *T, int e)
{
	if (strcmp(L.elem[T_index].name, "already_destroyed") == 0)
	{
		return NULL;
	}
	/* ��ʼ����: ������T����,e��T��ĳ����� */
	/* �������: ����e�����ֵܡ���e��T�����ӻ������ֵ�,�򷵻أ��գ� */
	//Tree* a;
	Tree* p;
	if (T) /* �ǿ��� */
	{
		p = Parent(T, e);  /* pΪָ����e��˫�׵�ָ�� */
		if (p->lchild&&p->rchild&&p->lchild->key == e) /* p�������Һ�����������e */
			return p->rchild; /* ����p���Һ���(e�����ֵ�) */
	}
	return NULL; /* ���ջ�û�ҵ�e�����ֵ� */
}

/**
* �������ƣ�InsertChild
* ����������ԭ���ĸ����ָ�룬�ؼ���e������������־����ӵ������ĸ����ָ��
* �������ܣ���������
* ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
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
* �������ƣ�DeleteChild
* ��������������ָ�룬�ؼ���e������������־
* �������ܣ�ɾ������
* ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
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

//�Խ�������Ӧ�ú���
void Visit(Tree *T)
{
	printf("key:%d ", T->key);
	printf("data:%c\n", T->data);
}

/**
* �������ƣ�PreOrderTraverse
* ����������T,visit����
* �������ܣ�ǰ�����
* ����ֵ���ޣ��ж����������н��У����ٵݹ鹤����
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
* �������ƣ�InOrderTraverse
* ����������T,visit����
* �������ܣ��������
* ����ֵ���ޣ��ж����������н��У����ٵݹ鹤����
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
* �������ƣ�PostOrderTraverse
* ����������T,visit����
* �������ܣ��������
* ����ֵ���ޣ��ж����������н��У����ٵݹ鹤����
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
* �������ƣ�LevelOrderTraverse
* ����������T,visit����
* �������ܣ��������
* ����ֵ���ޣ��ж����������н��У����ٵݹ鹤����
**/
void LevelOrderTraverse(Tree *T)
{
	seq q;
	Tree* temp;
	q.front = q.rear = 0;
	if (!T)
	{
		printf("��������\n");
		return;
	}
	enter(&q, T);//��������
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

//����
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
//����
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
* �����������ļ�ָ��fp�����ĸ����ָ���ָ��
* �������ܣ���ȡ�ļ��е��ַ���������������
* ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
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
* �������ƣ�ExportToFile
* �����������ļ�ָ��fp�����ĸ�����ָ��
* �������ܣ�������ǰ��͸�ʽ������ļ���
* ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
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
//ǰ�������������ļ���
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
