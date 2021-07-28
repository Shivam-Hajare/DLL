#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
int num;
struct node* p;

void addatbeg();
void addatend();
void addatmid();
void delete();
void display();
int main()
{
	int ch;
	while (1)
	{
		display();

		printf("\n 1.addatbeg\n2.addatend\n3.addatmid\n4.delete\n5.display\n6.exit\n");
		printf("Enter choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			addatbeg();
			break;

		case 2:
			addatend();
			break;

		case 3:
			addatmid();
			break;

		case 4:
			delete();
			break;

		case 5:
			display();
			break;

		case 6:
			exit(0);

		default:
			printf("\n invalid choice:");
			exit(0);
		}

	}
	
}
void addatbeg()
{
	struct node* r;
	r = (struct node*)malloc(sizeof(struct node));

	printf("Enter Data:");
	scanf("%d", &num);

	if (p == NULL)
	{
		r->data = num;
		r->next = NULL;
		r->prev = NULL;
		p = r;

	}
	else
	{
		r->data = num;
		r->prev = NULL;
		r->next = p;
		p->prev = r;
		p = r;
	}
	
}
void addatend()
{
	struct node* r;
	struct node* q;
	q = p;

	r = (struct node*)malloc(sizeof(struct node));

	printf("Enter Data:");
	scanf("%d", &num);

	if (p == NULL)
	{
		r->data = num;
		r->next = NULL;
		r->prev = NULL;
		p = r;

	}
	else
	{
		while (q->next != NULL)
		{
			q = q->next;
		}
		r->data = num;
		q->next = r;
		r->prev = q;
		r->next = NULL;
	}

}
void addatmid()
{
	struct node* r;
	struct node* q;
	q = p;
	int no;

	r = (struct node*)malloc(sizeof(struct node));

	printf("Enter Data:");
	scanf("%d", &num);

	printf("\n After which element do u want to add: ");
	scanf("%d", &no);

	if (p == NULL)
	{
		printf("List is Empty....");
	}
	else
	{
		while (q->data != no)
		{
			q = q->next;

			if (q == NULL)
			{
				printf("Given no not found...");
				return;
			}
		}
			r->data = num;
			r->next = q->next;
			r->prev = q;
			
			if (q->next != NULL)
				q->next->prev = r;
				q->next = r;
	
		
	}

}
void delete()
{
	struct node* q;
	struct node* old=NULL;
	q = p;
	int no;

	printf("Enter which data do u want to delete: ");
	scanf("%d", &no);

	if (p == NULL)
	{
		printf("\n List is empty.....");
		return;
	}
	else
	{
		while (q->data != no)
		{
			if (q->next == NULL) {
				printf("\n Given no not found.....");
				return;
			}
			old = q;
			q = q->next;
		}
		if (p == q) {
			p = p->next;
			p->prev = NULL;
			free(q);
			return;
		}
		old->next = q->next;
		if (q->next != NULL)q->next->prev = old;
		free(q);
	}
}

void display()
{
	struct node* q;
	q = p;

	printf("[");
	if (p == NULL)
	{
		printf("List is Empty.......");
	}
	else
	{
		while (q != NULL)
		{
			printf("%d", q->data);
			if (q->next != NULL)printf(", ");
			q = q->next;
		}

	}
	printf("]");


}