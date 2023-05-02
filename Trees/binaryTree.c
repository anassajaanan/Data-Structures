#include <stdlib.h>
#include <stdio.h>

// ===================S Stack==============
struct SNode
{
	struct BNode	*data;
	struct SNode	*next;
};

void	Push(struct SNode **top, struct BNode *x)
{
	struct SNode *new;

	new = (struct SNode *)malloc(sizeof(struct SNode));
	new->data = x;
	new->next = *top;
	*top = new;
}

struct BNode *Pop(struct SNode **top)
{
	struct SNode *p;
	struct BNode *x;

	if (*top)
	{
		p = *top;
		*top = (*top)->next;
		x = p->data;
		free(p);
	}
	return (x);
}


struct BNode *StackTop(struct SNode *top)
{
	if (top)
		return (top->data);
	else
		return (NULL);
}

int	isEmpty(struct SNode *top)
{
	if (top)
		return (0);
	return (1);
}
// ===================E Stack==============

struct BNode
{
	struct BNode	*lchild;
	int				data;
	struct BNode	*rchild;
};

struct QNode
{
	struct BNode	*data;
	struct QNode	*next;
};


void	enqueue(struct QNode **front, struct QNode **rear, struct BNode *x)
{
	struct QNode	*new;

	new = (struct QNode *)malloc(sizeof(struct QNode));
	if (new == NULL)
		printf("Queue is Full\n");
	else
	{
		new->data = x;
		new->next = NULL;
		if (*front == NULL)
		{
			*front = new;
			*rear = new;
		}
		else
		{
			(*rear)->next = new;
			(*rear) = new;
		}
	}
}

struct BNode *dequeue(struct QNode **front, struct QNode **rear)
{
	struct QNode *p;
	struct BNode *x;

	if (*front == NULL)
		return (NULL);
	else
	{
		p = *front;
		x = p->data;
		*front = (*front)->next;
		free(p);
		return (x);
	}
}

void	CreateBinaryTree(struct BNode **root)
{
	struct QNode	*front;
	struct QNode	*rear;
	struct BNode	*p;
	struct BNode	*new;
	int				x;

	front = NULL;
	rear = NULL;
	(*root) = (struct BNode *)malloc(sizeof(struct BNode));
	printf("Enter data for root: ");
	scanf("%d", &(*root)->data);
	(*root)->lchild = NULL;
	(*root)->rchild = NULL;
	enqueue(&front, &rear, (*root));
	while (front != NULL)
	{
		p = dequeue(&front, &rear);
		printf("Left child data of %d : ", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			new = (struct BNode *)malloc(sizeof(struct BNode));
			new->data = x;
			new->lchild = NULL;
			new->rchild = NULL;
			enqueue(&front, &rear, new);
			p->lchild = new;
		}
		printf("Right child data of %d : ", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			new = (struct BNode *)malloc(sizeof(struct BNode));
			new->data = x;
			new->lchild = NULL;
			new->rchild = NULL;
			enqueue(&front, &rear, new);
			p->rchild = new;
		}
	}
}

void displayTree(struct BNode *root, int level)
{
    if (root == NULL) {
        return;
    }

    displayTree(root->rchild, level + 1);

    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%d\n", root->data);

    displayTree(root->lchild, level + 1);
}

void	Preorder(struct BNode *root) // Recursive function of Preorder
{
	if (root)
	{
		printf("%d  ", root->data);
		Preorder(root->lchild);
		Preorder(root->rchild);
	}
}

void	IPreorder(struct BNode *t) // Iterative function of Preorder
{
	struct SNode *top;

	top = NULL;
	while (t || !isEmpty(top))
	{
		if (t)
		{
			printf("%d  ", t->data);
			Push(&top, t);
			t = t->lchild;
		}
		else
		{
			t = Pop(&top);
			t = t->rchild;
		}
	}
}

void	Inorder(struct BNode *root) // Recursive function of Inorder Traversal
{
	if (root)
	{
		Inorder(root->lchild);
		printf("%d \n", root->data);
		Inorder(root->rchild);
		printf("    ");
	}
}

void	IInorder(struct BNode *t) // Iterative function of Inorder Traversal
{
	struct SNode *top;

	top = NULL;
	while (t || !isEmpty(top))
	{
		if (t)
		{
			Push(&top, t);
			t = t->lchild;
		}
		else
		{
			t = Pop(&top);
			printf("%d  ", t->data);
			t = t->rchild;
		}
	}
}

void	Postorder(struct BNode *root) // Recursive function of postorder Traversal
{
	if (root)
	{
		Postorder(root->lchild);
		Postorder(root->rchild);
		printf("%d  ", root->data);
	}
}

void	IPostorder(struct BNode *t) // Iterative function of postorder Traversal
{
	struct SNode	*top;
	long int		temp;

	top = NULL;
	while (t || !isEmpty(top))
	{
		if (t)
		{
			Push(&top, t);
			t = t->lchild;
		}
		else
		{
			temp = (long int)Pop(&top);
			if (temp > 0)
			{
				Push(&top, (struct BNode *)(-temp));
				t = ((struct BNode *)temp)->rchild;
			}
			else
			{

				printf("%d  ", ((struct BNode *)(-temp))->data);
				t = NULL;
			}
		}
	}
}


void	LevelOrder(struct BNode *root)
{
	struct QNode	*front;
	struct QNode	*rear;
	struct BNode	*t;

	front = NULL;
	rear = NULL;
	enqueue(&front, &rear, root);
	while (front != NULL)
	{
		t = dequeue(&front, &rear);
		printf("%d  ", t->data);
		if (t->lchild)
			enqueue(&front, &rear, t->lchild);
		if (t->rchild)
			enqueue(&front, &rear, t->rchild);
	}
	printf("\n");
}

int Count(struct BNode *p)
{
	int	x;
	int	y;

	if (p)
	{
		x = Count(p->lchild);
		y = Count(p->rchild);
		return (x + y + 1);
	}
	return (0);
}

int	Height(struct BNode *p)
{
	int	x = 0;
	int	y = 0;

	if (p == NULL)
		return (0);
	x = Count(p->lchild);
	y = Count(p->rchild);
	if (x > y)
		return (x + 1);
	else
		return (y + 1);
}

int CountLeafNodes(struct BNode *p) // count number of nodes of degree 0
{
	int x;
	int y;

	if (p)
	{
		x = CountLeafNodes(p->lchild);
		y = CountLeafNodes(p->rchild);
		if (x == y && x == 0)
			return (1);
		else
			return (x + y);
	}
	else
		return (0);
}

int countNodeDeg2(struct BNode *p)
{
	int x;
	int y;

	if (p)
	{
		x = countNodeDeg2(p->lchild);
		y = countNodeDeg2(p->rchild);
		if (p->lchild && p->rchild)
			return (x + y + 1);
		else
			return (x + y);
	}
	return (0);
}

int countNodeDeg12(struct BNode *p) // Count number of nodes with degree 1 or 2
{
	int x;
	int y;

	if (p)
	{
		x = countNodeDeg2(p->lchild);
		y = countNodeDeg2(p->rchild);
		if (p->lchild || p->rchild)
			return (x + y + 1);
		else
			(x + y);
	}
	return (0);
}

int countNodeDeg1(struct BNode *p)  // Count number of nodes with degree 1
{

	if (p == NULL)
		return (0);
	if (p->lchild && p->rchild == NULL)
		return (countNodeDeg2(p->lchild) + countNodeDeg2(p->rchild) + 1);
	else if (p->rchild && p->lchild == NULL)
		return (countNodeDeg2(p->lchild) + countNodeDeg2(p->rchild) + 1);
	else
		return (countNodeDeg2(p->lchild) + countNodeDeg2(p->rchild));
}

int main(void)
{
	struct BNode *root;

	CreateBinaryTree(&root);

	displayTree(root, 0);
}