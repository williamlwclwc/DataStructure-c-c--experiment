#include "Declaration.h"//����&����ͷ�ļ�

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
		printf("    	  1. IntiaList���������Ա�          7. LocateElem����λԪ�أ�\n");
		printf("    	  2. DestroyList���������Ա�        8. PriorElem����ǰ����\n");
		printf("    	  3. ClearList��������Ա�          9. NextElem�����̣� \n");
		printf("    	  4. ListEmpty���ж��Ƿ�Ϊ�ձ�     10. ListInsert������Ԫ�أ�\n");
		printf("    	  5. ListLength�������            11. ListDelete��ɾ��Ԫ�أ�\n");
		printf("    	  6. GetElem����ȡԪ�أ�             12. ListTrabverse������������Ա�\n");
		printf("          13. LoadFromFile����ȡ�ļ���       14. ExportToFile��������ļ���\n");
		printf("          15. Multi-Operation����������\n");
		printf("    	  0. Exit\n");
		printf("--------------------------------------------------------------------------------------\n");
		printf("����ǰ���������ǵ�%d�����Ա�\n", List_index);
	
		printf("��ѡ����Ĳ���[0~15]:");
		scanf_s("%d", &op);
		//�����û����������Ӧ������ִ����Ӧ����
		switch (op) {
		case 1:
			if (IntiaList(L) == OK)
			{
				printf("���Ա����ɹ���\n");
			}
			else printf("���Ա���ʧ�ܣ�\n");
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyList(L) == OK)
			{
				printf("���Ա����ٳɹ�\n");
			}
			else
			{
				printf("���Ա�����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 3:
			if (ClearList(L) == OK)
			{
				printf("���Ա���ճɹ�\n");
			}
			else
			{
				printf("���Ա����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 4:
			if (ListEmpty(L) == TRUE)
			{
				printf("���Ա��Ѿ����\n");
			}
			else if (ListEmpty(L) == FALSE)
			{
				printf("���Ա�δ���\n");
			}
			else if (ListEmpty(L) == ERROR)
			{
				printf("���Ա�δ����\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 5:
			result = ListLength(L);
			if (result == -2)
			{
				printf("��������ʧ��\n");
			}
			else if (result == 0)
			{
				printf("���Ա�Ϊ�ձ�\n");
			}
			else if (result != 0)
			{
				printf("�����Ա�ĳ���Ϊ��%d\n", result);
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 6:
			printf("������Ҫ��ѯ��Ԫ�ص���ţ�");
			scanf_s("%d", &pos);
			if (GetElem(L, pos, elem) == OK)
			{
				printf("������ѯ��Ԫ�أ���%d�����ǣ�%d\n", pos, elem);
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 7:
			printf("����������Ҫ���ҵ�Ԫ�أ�");
			scanf_s("%d", &elem);
			result = LocateElem(L, elem);
			if (result != 0 && result != ERROR)
			{
				printf("��Ԫ�ص�λ���ǣ�%d\n", result);
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 8:
			printf("������Ҫ��ѯ��Ԫ�أ�");
			scanf_s("%d", &cur_e);
			if (PriorElem(L, cur_e, elem) == OK)
			{
				printf("��Ԫ�ص�ǰ��Ϊ��%d\n", elem);
			}
			else
			{
				printf("ǰ������ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 9:
			printf("������Ҫ��ѯ��Ԫ�أ�");
			scanf_s("%d", &cur_e);
			if (NextElem(L, cur_e, elem) == OK)
			{
				printf("��Ԫ�صĺ��Ϊ��%d\n", elem);
			}
			else
			{
				printf("��̲���ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 10:
			printf("������Ҫ�����λ��i��");
			scanf_s("%d", &pos);
			printf("������Ҫ�����Ԫ��e��");
			scanf_s("%d", &elem);
			if (ListInsert(L, pos, elem) == OK)
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
			printf("������Ҫɾ��Ԫ�ص�λ��i��");
			scanf_s("%d", &pos);
			if (ListDelete(L, pos, elem) == OK)
			{
				printf("ɾ���ɹ�\n");
				printf("��ɾ����Ԫ��Ϊ�� %d\n", elem);
			}
			else
			{
				printf("ɾ��ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 12:
			if (ListTrabverse(L) != OK) {
				printf("���Ա�δ������\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 13:
			printf("�������ļ���: ");
			scanf_s("%s", filename, 30);
			if (fopen_s(&fp, filename, "r+") != 0)
			{
				printf("�ļ���ʧ��\n ");
			}
			else if (LoadFromFile(fp, L) == OK)
			{
				printf("��ȡ���Ա�ɹ�\n");
			}
			else
			{
				printf("��ȡ���Ա�ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 14:
			printf("�������ļ���: ");
			scanf_s("%s", filename, 30);
			if (fopen_s(&fp, filename, "w+") != 0)
			{
				printf("���ļ�ʧ��\n");
			}
			else if (ExportToFile(fp, L) == OK)
			{
				printf("������Ա�ɹ�\n");
			}
			else
			{
				printf("������Ա�ʧ��\n");
			}
			printf("���س�������\n");
			getchar(); getchar();
			break;
		case 15:
			if (Switch_List() == OK)
			{
				printf("�л��ɹ�����ǰ�ǵ�%d�����Ա�\n", List_index);
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
 * �������ƣ�InitiaList
 * �������������Ա�L�ĵ�ַ
 * �������ܣ�����һ���յ����Ա�
 * ����ֵ���ɹ����췵��OK�����򷵻�ERROR
 **/
status IntiaList(LinkList &L) 
{
	L = (LinkList)malloc(sizeof(LNode));//��������ͷ�ĵ������Ա�
	//�����ʼ��
	L->data = 0;//��ͷ�����������д������ĳ���
	L->next = NULL;
	return OK;
}

/**
* �������ƣ�DestroyList
* �������������Ա�L�ĵ�ַ
* �������ܣ�ɾ�����Ա�
* ����ֵ���ɹ����ٷ���OK�����򷵻�ERROR
**/
status DestroyList(LinkList &L)
{
	//�ж������Ƿ��Ѿ���������ͬ
	if (!L) return ERROR;
	//��ǰ�Ǳ�β
	if (L->next == NULL)
	{
		free(L->next);
		free(L);
		L = NULL;
	}
	else//�ݹ飬ֱ���ҵ���β�����ν�������
	{
		DestroyList(L->next);
		L->next = NULL;
		free(L);
	}
	return OK;
}

/**
* �������ƣ�ClearList
* �������������Ա�L�ĵ�ַ
* �������ܣ��������Ա�
* ����ֵ���ɹ��ÿշ���OK�����򷵻�ERROR
**/
status ClearList(LinkList &L)
{
	if (!L) return ERROR;
	DestroyList(L->next);//free����ͷ�������Ľ��
	L->next = NULL;
	L->data = 0;//������
	return OK;
}

/**
* �������ƣ�ListEmpty
* �������������Ա�L
* �������ܣ��ж����Ա��Ƿ�Ϊ��
* ����ֵ����LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
**/
status ListEmpty(LinkList L)
{
	if (!L) return ERROR;
	//ͷ������һ������Ƿ�Ϊ��
	if (L->next == NULL) return TRUE;
	else return FALSE;
}

/**
* �������ƣ�ListLength
* �������������Ա�L
* �������ܣ��������Ա�L������Ԫ�ظ�����
* ����ֵ���ɹ�����L������Ԫ�ظ�����ʧ�ܷ���ERROR
**/
int ListLength(LinkList L)
{
	if (!L) return ERROR;
	int len = 0;//��������ֵ�����������
	//��������ÿ�γ���+1
	for (LinkList p = L->next; p != NULL; p = p->next)
	{
		len++;
	}
	return len;
}

/**
* �������ƣ�GetElem
* �������������Ա�L��eΪ��i�����ݵĵ�ַ��
* �������ܣ����Ҳ���ʾL�е�i��Ԫ�ص�ֵ��
* ����ֵ���ɹ��򷵻ص�i��Ԫ�ص�ֵ�����򷵻�ERROR
**/
status GetElem(LinkList L, int i, ElemType & e)
{
	if (!L) return ERROR;
	if (i>=1 && i <= L->data)//�ж�����λ���Ƿ�Ϸ�
	{
		int index = 1;
		LinkList p = L->next;
		//������ֱ������β���������i��
		while (p != NULL && index != i)
		{
			p = p->next;
			index++;
		}
		e = p->data;//����i��Ԫ�ص�ֵ��e
		return OK;
	}
	else return ERROR;
}

/**
* �������ƣ�LocateElem
* �������������Ա�L����Աȵ�Ԫ��ֵ��
* �������ܣ�����L����e��ͬ�������ڵ�λ��λ���1��ʼ
* ����ֵ���ɹ��򷵻ص�һ����e��ͬ�����ݵ�λ�򣬲������򷵻�0�������������ERROR
**/
int LocateElem(LinkList L, ElemType e)//�򻯹�
{
	if (!L) return ERROR;
	int index = 1;
	LinkList p = L->next;
	//��������
	while (p != NULL)
	{
		if (p->data != e)
		{
			//��ǰԪ�ز�ͬ��ָ����һ��λ�ã��±�ֵ+1
			p = p->next;
			index++;
		}
		else
		{
			//�ҵ���ͬ��Ԫ�أ������±�ֵ
			return index;
		}
	}
	//����������δ�ҵ�������ERROR
	return ERROR;
}

/**
* �������ƣ�PriorElem
* �������������Ա�L�����ҵ�����cur_e,ǰ��pre_e��
* �������ܣ�����L����cur_e��ͬ�ĵ�һ�����ݣ���������ǰ��
* ����ֵ���ɹ��򷵻���cur_e��ͬ�ĵ�һ�����ݣ����������һ��ǰ��������ǰ���Լ���������򷵻�ERROR
**/
status PriorElem(LinkList L, ElemType cur_e, ElemType & pre_e)
{
	if (!L) return ERROR;
	LinkList p = L->next;
	if (p->data == cur_e) return ERROR;//��һ��Ԫ��û��ǰ��
	//��������
	while (p != NULL)
	{
		//��ǰԪ�غ�Ŀ��Ԫ����ͬ����ʱpre_e��ֵΪǰ��ֵ
		if (p->data == cur_e)
		{
			return OK;
		}
		else
		{
			//��ǰԪ�ز���Ŀ��Ԫ�أ����µ�ǰ��data��pָ����һ��
			pre_e = p->data;
			p = p->next;
		}
	}
	//����������δ�ҵ�Ŀ��ֵ������ERROR
	return ERROR;
}

/**
* �������ƣ�NextElem
* �������������Ա�L�����ҵ�����cur_e,����next_e��
* �������ܣ�����L����cur_e��ͬ�ĵ�һ�����ݣ������������
* ����ֵ���ɹ��򷵻���cur_e��ͬ�ĵ�һ�����ݣ�����������������޺����Լ���������򷵻�ERROR
**/
status NextElem(LinkList L, ElemType cur_e, ElemType & next_e)
{
	if (!L) return ERROR;
	LinkList p = L->next;
	//�����������һ��Ԫ��û�к�̣�������һ��ѭ��
	while (p->next != NULL)
	{
		//�ҵ�Ŀ��Ԫ��
		if (p->data == cur_e)
		{
			//��Ŀ��Ԫ�ص���һ������е�ֵ����next_e��
			next_e = p->next->data;
			return OK;
		}
		//δ�ҵ���ָ����һ��λ��
		p = p->next;
	}
	//����������δ�ҵ�����ERROR
	return ERROR;
}

/**
* �������ƣ�ListInsert
* �������������Ա�L�ĵ�ַ�������λ��i�����������Ԫ��e��
* �������ܣ���L�ĵ�i��λ��֮ǰ�����µ�����Ԫ��e�����Ѳ��������շ����������������Ŀռ䡣
* ����ֵ���ɹ����뷵��OK�����򷵻�ERROR
**/
status ListInsert(LinkList & L, int i, ElemType e)
{
	if (!L) return ERROR;
	//�жϲ���λ���Ƿ�Ϸ�
	if (i<1 || i>L->data + 1)
	{
		return ERROR;
	}
	L->data++;//��+1
	//Ѱ�Ҳ����
	LinkList p = L;
	int j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	//�ڲ���λ�������µĽ�㲢�ı�ָ�����
	LinkList f = (LinkList)malloc(sizeof(LNode));//����һ���µĽ��ռ�
	f->data = e;
	//�ı�ָ��ָ��
	f->next = p->next;
	p->next = f;
	return OK;
}

/**
* �������ƣ�ListDelete
* �������������Ա�L�ĵ�ַ��ɾ����λ��i��ָ��e�ĵ�ַ��
* �������ܣ�ɾ��L�ĵ�i������Ԫ�أ���e������ֵ��
* ����ֵ���ɹ�ɾ������OK�����򷵻�ERROR
**/
status ListDelete(LinkList & L, int i, ElemType & e)
{
	if (!L) return ERROR;
	L->data--;//��-1
	//Ѱ��ɾ����
	LinkList p = L;
	int j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	e = p->next->data;//ɾ����Ԫ�ظ�ֵ��e
	LinkList del = p->next;//��¼ɾ�����ָ��
	p->next = p->next->next;//�ı�ָ������ɾ�����
	free(del);//freeɾ�����
	return OK;
}

/**
* �������ƣ�ListTrabverse
* �������������Ա�L
* �������ܣ�������ʾ���Ա��е�ÿ��Ԫ�ء�
* ����ֵ���ɹ������������Ա�ĳ��ȣ����򷵻�ERROR
**/
status ListTrabverse(LinkList L) 
{
	if (!L) return ERROR;
	LinkList p = L->next;
	if (p == NULL)//�ձ������
	{
		printf("��ǰ�����ǿ�����\n");
	}
	else//�ǿձ�ѭ���������
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
* �������ƣ�LoadFromFile
* �����������ļ�ָ�룬���Ա�L
* �������ܣ����ݼ��أ�Ϊ���Ա�����Ԫ�ء�
* ����ֵ�����سɹ�����OK������ʧ�ܷ���E
**/
status LoadFromFile(FILE*fp, LinkList &L)
{
	//δ����������ʧ�ܷ���ERROR������ļ�ͬ
	if (!L || fp == NULL)
	{
		fclose(fp);
		return ERROR;
	}
	L->data = 0;
	LinkList p = L;
	char vacant;//���ڶ�ȡ�ո�
	ElemType elem;//���ڴ�Ŷ����Ԫ��ֵ
	while (fscanf_s(fp, "%d", &elem) != EOF)//�����ļ��е�Ԫ��ֵ
	{
		LinkList f = (LinkList)malloc(sizeof(LNode));//����һ���µĽ��ռ�
		f->data = elem;//������ֵ�������data��
		//�ı�ָ��ָ��
		f->next = NULL;//����βָ��NULL
		p->next = f;//����ԭ���ı�β
		fscanf_s(fp, "%c", &vacant);//��ȡ���ֺ�Ŀո�
		p = p->next;
		L->data++;//��+1
	}
	fclose(fp);
	return OK;
}

/**
* �������ƣ�ExportToFile
* �����������ļ�ָ�룬���Ա�L
* �������ܣ���L�е����ݱ��浽fpָ��ָ����ļ���
* ����ֵ��OK
**/
status ExportToFile(FILE*fp, LinkList L)
{
	if (!L || fp == NULL)
	{
		fclose(fp);
		return ERROR;
	}
	LinkList p = L->next;
	//��������������ļ�
	while (p != NULL)
	{
		fprintf(fp, "%d ", p->data);
		p = p->next;
	}
	fclose(fp);
	return OK;
}

//�������������л����Ա�
status Switch_List()
{

	return OK;
}
