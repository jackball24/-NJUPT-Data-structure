#include<stdio.h>
#include<stdlib.h>

typedef struct pNode{
	int coef;
	int exp;
	struct pNode* link;
}PNode;
typedef struct polynominal{
	PNode *head;
}Polynominal; 

void Create(Polynominal* p)
{
	PNode* mx, * pre, * q;	
	p->head = (PNode*)malloc(sizeof(PNode));	
	p->head->exp = -1;
	p->head->link = p->head;
	printf("�Զ�����������ʽ:\n");
	while(1)	// ��������
	{
		mx = (PNode*)malloc(sizeof(PNode));	
		printf("������ϵ��:\n");
		scanf("%d", &mx->coef);				// ����ϵ��
		printf("ָ����С��0ʱֹͣ���룩:\n");
		scanf("%d", &mx->exp);				// ����ָ��
		if (mx->exp < 0)						// ��ָ��Ϊ0ʱֹͣ����
			break;
		pre = p->head;
		q = p->head->link;
		while (q&&q->exp>mx->exp)				// ���ս�������
		{
			pre = q;
			q = q->link;
		}
		mx->link = q;							// ������
		pre->link = mx;
	}
}

void Output(Polynominal* p)							// ���
{
	PNode* temp = p->head->link;
	while (temp->exp>=0)
	{
		printf("%dx^%d", temp->coef, temp->exp);	
		printf("+");
		temp = temp->link;
	}
	// ���Ƹ�ʽ
	printf("\b ");
	printf("\n");
}

void Add(Polynominal* px, Polynominal* qx)			// ����ʽ���
{
	PNode* q, * q1 = qx->head, * p, * p1, * temp;	// q1ָ���ͷ���
	p = px->head->link;								// pָ�����ʽpx�ĵ�һ�����
	q = q1->link;									
	while (p->exp>=0)
	{
		while (p->exp < q->exp)						// ����q->exp�����
		{
			q1 = q;
			q = q->link;
		}
		if (p->exp==q->exp)							// ��ָ�����ʱ��ϵ�����
		{
			q->coef = q->coef + p->coef;
			if (q->coef == 0)						// ����Ӻ�ϵ��Ϊ0
			{
				q1->link = q->link;					// ɾ��q
				free(p);							// �ͷſռ�
				q = q1->link;						// ����ָ��
				p = p->link;
			}
			else									// ����Ӻ�Ϊ0
			{
				q1 = q;								// q1����
				q = q->link;
				p = p->link;
			}
		}
		else // p->epx > q->exp �����
		{
			temp = (PNode*)malloc(sizeof(PNode));	// �����½��
			temp->coef = p->coef;
			temp->exp = p->exp;
			temp->link = q1->link;
			q1->link = temp;
			q1 = q1->link;
			p = p->link;
		}
	}
}

int main()
{
	Polynominal mx0;
	Polynominal mx1;
	Create(&mx0);
	Output(&mx0);
	Create(&mx1);
	Output(&mx1);
	printf("��Ӻ�:");
	Add(&mx0, &mx1);
	Output(&mx1);
}


