#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "queue.h"

struct BNode
{
	struct BNode	*lchild;
	int				data;
	struct BNode	*rchild;
};

void	createBinaryTree(struct BNode **root)
{
	struct BNode	*t;
	struct BNode	*p;
	queue			q;
	int 			x;

	createQueue(&q);
	*root = (struct BNode *)malloc(sizeof(struct BNode));
	printf("Enter root value: ");
	scanf("%d", &(*root)->data);
	(*root)->lchild = NULL;
	(*root)->rchild = NULL;
	Enqueue(&q, *root);
	while (!queueIsEmpty(q))
	{
		p = (struct BNode *)Dequeue(&q);
		printf("Enter left child of %d: ", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			t = (struct BNode *)malloc(sizeof(struct BNode));
			t->data = x;
			t->lchild = NULL;
			t->rchild = NULL;
			p->lchild = t;
			Enqueue(&q, t);
		}
		printf("Enter right child of %d: ", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			t = (struct BNode *)malloc(sizeof(struct BNode));
			t->data = x;
			t->lchild = NULL;
			t->rchild = NULL;
			p->rchild = t;
			Enqueue(&q, t);
		}
	}
}

void	Preorder(struct BNode *root) // Recursive Preorder traversal
{
	if (root)
	{
		printf("%d  ", root->data);
		Preorder(root->lchild);
		Preorder(root->rchild);
	}
}

void	Inorder(struct BNode *root) // Recursive Inorder traversal
{
	if (root)
	{
		Inorder(root->lchild);
		printf("%d  ", root->data);
		Inorder(root->rchild);
	}
}

void	Postorder(struct BNode *root) // Recursive Postorder traversal
{
	if (root)
	{
		Postorder(root->lchild);
		Postorder(root->rchild);
		printf("%d  ", root->data);
	}
}

void	IPreorder(struct BNode *t) // Iterative Preorder traversal using stack
{
	stack	s;

	createStack(&s);
	while (t || !stackIsEmpty(s))
	{
		if (t)
		{
			printf("%d  ", t->data);
			Push(&s, t);
			t = t->lchild;
		}
		else
		{
			t = (struct BNode *)Pop(&s);
			t = t->rchild;
		}
	}
	printf("\n");
}

void	IInorder(struct BNode *t) // Iterative Inorder traversal using stack
{
	stack s;

	createStack(&s);
	while (t || !stackIsEmpty(s))
	{
		if (t)
		{
			Push(&s, t);
			t = t->lchild;
		}
		else
		{
			t = (struct BNode *)Pop(&s);
			printf("%d  ", t->data);
			t = t->rchild;
		}
	}
}

void	IPostorder(struct BNode *t) // Iterative Postorder traversal using stack
{
	stack			s;
	long int		temp;

	createStack(&s);
	while (t || !stackIsEmpty(s))
	{
		if (t)
		{
			Push(&s, t);
			t = t->lchild;
		}
		else
		{
			temp = (long int)((struct BNode *)Pop(&s));
			if (temp > 0)
			{
				Push(&s, (struct BNode *)(-temp));
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

void	LevelOrder(struct BNode *root) // Level order traversal using queue
{
	queue			q;
	struct BNode	*t;

	createQueue(&q);
	Enqueue(&q, root);
	while (!queueIsEmpty(q))
	{
		t = (struct BNode *)Dequeue(&q);
		printf("%d  ", t->data);
		if (t->lchild)
			Enqueue(&q, t->lchild);
		if (t->rchild)
			Enqueue(&q, t->rchild);
	}
}

void displayTree(struct BNode *root, int level) // Display the tree in hierarchical format 
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

int countTotalNode(struct BNode *p) // Counts the total number of nodes in the tree.
{
    int x;
    int y;

    if (p)
    {
        x = countTotalNode(p->lchild);
        y = countTotalNode(p->rchild);
        return (x + y + 1);
    }
    return (0);
}

int calculateHeight(struct BNode *p) // Calculates the height of the tree.
{
    int x = 0;
    int y = 0;

    if (p == NULL)
        return (0);
    x = calculateHeight(p->lchild);
    y = calculateHeight(p->rchild);
    if (x > y)
        return (x + 1);
    else
        return (y + 1);
}

int countLeafNodes(struct BNode *p) // Counts the number of leaf nodes (degree 0) 
{
    int x;
    int y;

    if (p)
    {
        x = countLeafNodes(p->lchild);
        y = countLeafNodes(p->rchild);
        if (x == y && x == 0)
            return (1);
        else
            return (x + y);
    }
    else
        return (0);
}

int countDegreeTwoNodes(struct BNode *p) // Counts number of nodes with degree 2
{
    int x;
    int y;

    if (p)
    {
        x = countDegreeTwoNodes(p->lchild);
        y = countDegreeTwoNodes(p->rchild);
        if (p->lchild && p->rchild)
            return (x + y + 1);
        else
            return (x + y);
    }
    return (0);
}

int countDegreeOneNodes(struct BNode *p) // Counts number of nodes with degree 1
{
	int x;
	int y;

	if (p)
	{
		x = countDegreeOneNodes(p->lchild);
		y = countDegreeOneNodes(p->rchild);
		if ((p->lchild && !p->rchild) || (!p->lchild && p->rchild))
			return (x + y + 1);
		else
			return (x + y);
	}
	return (0);
}
