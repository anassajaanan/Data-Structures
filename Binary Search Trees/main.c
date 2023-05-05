#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct BNode
{
	struct BNode	*lchild;
	int				data;
	struct BNode	*rchild;
};

void	Inorder(struct BNode *root) // Recursive Inorder traversal
{
	if (root)
	{
		Inorder(root->lchild);
		printf("%d  ", root->data);
		Inorder(root->rchild);
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

struct BNode	*Search(struct BNode *t, int key)
{
	while (t)
	{
		if (t->data == key)
			return (t);
		else if (key < t->data)
			t = t->lchild;
		else
			t = t->rchild;
	}
	return (NULL);
}

struct BNode	*RSearch(struct BNode *t, int key)
{
	if (t == NULL)
		return (NULL);
	if (t->data == key)
		return (t);
	else if (key < t->data)
		Search(t->lchild, key);
	else
		Search(t->rchild, key);
}

void	Insert(struct BNode **root, int key)
{
	struct BNode *newNode;
	struct BNode *p;
	struct BNode *t;

	newNode = (struct BNode *)malloc(sizeof(struct BNode));
	newNode->data = key;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	if (*root == NULL)
	{
		(*root) = newNode;
		return;
	}
	t = *root;
	p = NULL;
	while (t)
	{
		p = t;
		if (key == t->data)
		{
			free(newNode);
			return;
		}
		if (key < t->data)
			t = t->lchild;
		else
			t = t->rchild;
	}
	if (key < p->data)
		p->lchild = newNode;
	else
		p->rchild = newNode;
}

void	RInsert(struct BNode **root, int key)
{
	if (*root == NULL)
	{
		*root = (struct BNode *)malloc(sizeof(struct BNode));
		(*root)->data = key;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
		return;
	}
	if (key < (*root)->data)
		RInsert(&(*root)->lchild, key);
	else if (key > (*root)->data)
		RInsert(&(*root)->rchild, key);
}

struct BNode	*InPredecessor(struct BNode *p)
{
	while (p && p->rchild)
		p = p->rchild;
	return (p);
}

struct BNode	*InSuccessor(struct BNode *p)
{
	while (p && p->lchild)
		p = p->lchild;
	return (p);
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

struct BNode	*Delete(struct BNode **root, int key)
{
	struct BNode	*q;

	if (*root == NULL)
		return (NULL);
	if ((*root)->data == key && (*root)->lchild == NULL && (*root)->rchild == NULL)
	{
		free((*root));
		*root = NULL;
		return (NULL);
	}
	if (key < (*root)->data)
		Delete(&(*root)->lchild, key);
	else if (key > (*root)->data)
		Delete(&(*root)->rchild, key);
	else
	{
		if (calculateHeight((*root)->lchild) > calculateHeight((*root)->rchild))
		{
			q = InPredecessor((*root)->lchild);
			(*root)->data = q->data;
			Delete(&(*root)->lchild, q->data);
		}
		else
		{
			q = InSuccessor((*root)->rchild);
			(*root)->data = q->data;
			Delete(&(*root)->rchild, q->data);
		}
	}
	return (*root);
}

struct BNode	*createBNode(int data)
{
	struct BNode	*newNode;

	newNode = (struct BNode *)malloc(sizeof(struct BNode));
	newNode->data = data;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	return (newNode);
}

struct BNode *buildBSTFromPreorder(int *Pre, int n)
{
	struct BNode	*p;
	struct BNode	*root;
	struct BNode	*newNode;
	stack			s;
	int 			i;

	Push(&s, createBNode(2147483647));
	root = createBNode(Pre[0]);
	p = root;
	i = 1;
	while (i < n)
	{
		if (Pre[i] < p->data)
		{
			newNode = createBNode(Pre[i++]);
			p->lchild = newNode;
			Push(&s, p);
			p = newNode;
		}
		else
		{
			if (Pre[i] < ((struct BNode *)StackTop(s))->data)
			{
				newNode = createBNode(Pre[i++]);
				p->rchild = newNode;
				p = newNode;
			}
			else
				p = (struct BNode *)Pop(&s);
		}
	}
	destroyStack(&s);
	return (root);
}

struct BNode	*buildBSTFromPostorder(int *Post, int n)
{
	struct BNode	*p;
	struct BNode	*root;
	struct BNode	*newNode;
	stack			s;
	int 			i;

	Push(&s, createBNode(-2147483647));
	root = createBNode(Post[n - 1]);
	p = root;
	i = n - 2;
	while (i >= 0)
	{
		if (Post[i] > p->data)
		{
			newNode = createBNode(Post[i--]);
			p->rchild = newNode;
			Push(&s, p);
			p = newNode;
		}
		else
		{
			if (Post[i] > ((struct BNode *)StackTop(s))->data)
			{
				newNode = createBNode(Post[i--]);
				p->lchild = newNode;
				p = newNode;
			}
			else
				p = (struct BNode *)Pop(&s);
		}
	}
	destroyStack(&s);
	return (root);
}





// int main(void)
// {
// 	struct BNode *root;

// 	int A[] = {70, 50, 40, 80, 30};

// 	root = buildBSTFromPostorder(A, 5);

// 	displayTree(root, 0);	

// }