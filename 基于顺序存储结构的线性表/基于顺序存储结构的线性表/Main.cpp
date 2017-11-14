#include "declaration.h"//����&����ͷ�ļ�

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
		printf("    ��ѡ����Ĳ���[0~12]:");
		scanf_s("%d", &op);
		//�����û����������Ӧ������ִ����Ӧ����
		switch (op) {
		case 1:
			if (IntiaList(L) == OK) printf("���Ա����ɹ���\n");
			else printf("���Ա���ʧ�ܣ�\n");
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 2:
			if (DestroyList(&L) == OK)
			{
				printf("���Ա����ٳɹ�\n");
			}
			/*
			else
			{
				printf("���Ա�����ʧ��\n");
			}
			*/
			printf("�����������\n");
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
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 4:
			if (ListEmpty(L) == TRUE)
			{
				printf("���Ա��Ѿ����\n");
			}
			else
			{
				printf("���Ա�δ���\n");
			}
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 5:
			result = ListLength(L);
			if (result!=0)
			{
				printf("�����Ա�ĳ���Ϊ��%d\n", result);
			}
			else if(result==-1)
			{
				printf("��������ʧ��\n");
			}
			else if (result == 0)
			{
				printf("���Ա�Ϊ�ձ�\n");
			}
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 6:
			printf("������Ҫ��ѯ��Ԫ�ص���ţ�");
			scanf_s("%d", &pos);
			if (GetElem(L, pos, elem) == OK)
			{
				printf("������ѯ��Ԫ�أ���%d�����ǣ�%d\n", pos,elem);
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 7:
			printf("����������Ҫ���ҵ�Ԫ�أ�");
			scanf_s("%d", &elem);
			result = LocateElem(L, elem);
			if (result != 0)
			{
				printf("��Ԫ�ص�λ���ǣ�%d\n",result);
			}
			else
			{
				printf("����ʧ��\n");
			}
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 8:
			printf("������Ҫ��ѯ��Ԫ�أ�");
			scanf_s("%d", &cur);
			if (PriorElem(L, cur, elem) == OK)
			{
				printf("��Ԫ�ص�ǰ��Ϊ��%d\n", elem);
			}
			else
			{
				printf("ǰ������ʧ��\n");
			}
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 9:
			printf("������Ҫ��ѯ��Ԫ�أ�");
			scanf_s("%d", &cur);
			if (NextElem(L, cur, elem) == OK)
			{
				printf("��Ԫ�صĺ��Ϊ��%d\n", elem);
			}
			else
			{
				printf("��̲���ʧ��\n");
			}
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 10:
			printf("������Ҫ�����λ��i��");
			scanf_s("%d", &pos);
			printf("������Ҫ�����Ԫ��e��");
			scanf_s("%d", &elem);
			if(ListInsert(L, pos, elem)==OK) printf("���Ա����ɹ�\n");
			else
			{
				printf("���Ա����ʧ��\n");
			}
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 11:
			printf("������Ҫɾ��Ԫ�ص�λ��i��");
			scanf_s("%d", &pos);
			if (ListDelete(L, pos, elem) == OK) 
			{
				printf("���Ա�ɾ���ɹ�\n");
				printf("��ɾ����Ԫ��Ϊ�� %d\n",elem);
			}
			else
			{
				printf("���Ա�ɾ��ʧ��\n");
			}
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 12:
			if (!ListTrabverse(L)) {
				//printf("���Ա��ǿձ�\n");
			}
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 13:
			LoadFromFile();
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 14:
			ExportToFile();
			printf("�����������\n");
			getchar(); getchar();
			break;
		case 0:
			printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
			getchar(); getchar();
			break;
		}//end of switch
	}//end of while
}//end of main()
 /*--------page 23 on textbook --------------------*/

//�������Ա�
status IntiaList(SqList & L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);//�洢����ʧ��
	L.length = 0;//�ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE;//��ʼ�洢����
	return OK;
}

//�������Ա�free�ռ䣩
status DestroyList(SqList * L)
{
		free(L->elem);
		L->elem= NULL;
		return OK;
}

//������Ա�����Ϊ0��
status ClearList(SqList &L)
{
	L.length = 0;
	return OK;
}

//�ж����Ա��Ƿ�Ϊ�գ��жϳ����Ƿ�Ϊ0��
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

//�������Ա�ĳ�����Ϣ
int ListLength(SqList L)
{
	return L.length;
}

//��õ�i��λ���ϵ�Ԫ��ֵ
status GetElem(SqList L, int i, ElemType & e)
{
	if (i <= L.length)//�жϵ�i��Ԫ���Ƿ����
	{
		e = *(L.elem + i - 1);//��1��λ�ö�Ӧelem����i������elem����ƶ�i-1��λ��
		return OK;
	}
	else
	{
		return ERROR;
	}
}

//����ֵΪe��Ԫ�ص�λ��
int LocateElem(SqList L, ElemType e)//�򻯹�
{
	for (int j = 1; j <= L.length; j++)//ѭ���������Ա�
	{
		if (*L.elem != e)//����ֵΪe��Ԫ��
		{
			L.elem++;//��ǰ���ȣ���Ƚ���һ��
		}
		else
		{
			return j;//�ҵ��ˣ��������±�
		}
	}
	return 0;
}

//�ҵ�ĳԪ�ص�ǰ��Ԫ��
status PriorElem(SqList L, ElemType cur, ElemType & pre_e)
{
	for (int j = 1; j <= L.length; j++)//�������Ա�
	{
		if (L.elem[j] == cur)//�ҵ�Ŀ��Ԫ��
		{
			pre_e = L.elem[j - 1];//��ȡĿ��Ԫ���±�-1��Ԫ��
			return OK;
		}
	}
	return ERROR;
}

//�ҵ�ĳԪ�صĺ��Ԫ�� ԭ��ͬPriorElem
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

//����Ԫ��
status ListInsert(SqList & L, int i, ElemType e)
{
	//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e��i�ĺϷ�ֵΪ1~ListLength+1
	if (i<1 || i>L.length + 1) return ERROR; //iֵ���Ϸ�
	if (L.length >= L.listsize)
	{
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);//�洢����ʧ��
		L.elem = newbase;//�»�ַ
		L.listsize += LISTINCREMENT;//���Ӵ洢����
	}
	int *q = &(L.elem[i - 1]);//qΪ����λ��
	for (int *p = &(L.elem[L.length - 1]); p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	return OK;
}

//ɾ��Ԫ��
status ListDelete(SqList & L, int i, ElemType & e)
{
	//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
	//i�ĺϷ�ֵΪ1~ListLength
	if ((i < 1 || (i > L.length))) return ERROR;//iֵ���Ϸ�
	int *p = &(L.elem[i - 1]);//pΪ��ɾ��Ԫ�ص�ֵ����e
	e = *p;//��ɾ����Ԫ�ظ���e
	int *q = L.elem + L.length - 1;//��βԪ�ص�λ��
	for (++p; p <= q; ++p)
	{
		*(p - 1) = *p;//��ɾ��Ԫ�غ�Ԫ������
	}
	--L.length;//����1
	return OK;
}

//����������Ա�
status ListTrabverse(SqList L) {
		int i;
		printf("\n-----------all elements -----------------------\n");
		for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
		printf("\n------------------ end ------------------------\n");
		return OK;
}

//���ļ��ж������Ա��Ԫ��
void LoadFromFile()
{

}

//�����Ա������д���ļ��б���
void ExportToFile()
{

}
