#include <stdio.h>
#include <stdlib.h>


struct Node
{
	struct Node	*lchild;
	int			data;
	int			height;
	struct Node	*rchild;
};

void displayTree(struct Node *root, int level) // Display the tree in hierarchical format 
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

struct Node	*newNode(int key)
{
	struct Node	*newNode;

	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->height = 1;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	return (newNode);
}

int	height(struct Node *p)
{
	int	hl;
	int	hr;

	hl = (p && p->lchild) ? p->lchild->height : 0;
	hr = (p && p->rchild) ? p->rchild->height : 0;
	return ((hl > hr) ? hl + 1 : hr + 1);
}

int	getBalanceFactor(struct Node *p)
{
	int	hl;
	int	hr;

	hl = (p && p->lchild) ? p->lchild->height : 0;
	hr = (p && p->rchild) ? p->rchild->height : 0;
	return (hl - hr);
}

struct Node	*LLRotation(struct Node **root, struct Node *p)
{
	struct Node	*pl;
	struct Node	*plr;

	pl = p->lchild;
	plr = pl->rchild;
	p->lchild = plr;
	pl->rchild = p;
	p->height = height(p);
	pl->height = height(pl);
	if (p == *root)
		*root = pl;
	return (pl);
}

struct Node	*LRRotation(struct Node **root, struct Node *p)
{
	struct Node *pl;
	struct Node *plr;

	pl = p->lchild;
	plr = pl->rchild;
	p->lchild = plr->rchild;
	pl->rchild = plr->lchild;
	plr->lchild = pl;
	plr->rchild = p;
	p->height = height(p);
	pl->height = height(pl);
	plr->height = height(plr);
	if (p == *root)
		*root = plr;
	return (plr);
}

struct Node	*RRRotation(struct Node **root, struct Node *p)
{
	struct Node	*pr;
	struct Node	*prl;

	pr = p->rchild;
	prl = pr->lchild;
	p->rchild = prl;
	pr->lchild = p;
	p->height = height(p);
	pr->height = height(pr);
	if (p == *root)
		*root = pr;
	return (pr);
}

struct Node	*RLRotation(struct Node **root, struct Node *p)
{
	struct Node	*pr;
	struct Node	*prl;

	pr = p->rchild;
	prl = pr->lchild;
	p->rchild = prl->lchild;
	pr->lchild = prl->rchild;
	prl->lchild = p;
	prl->rchild = pr;
	p->height = height(p);
	pr->height = height(pr);
	prl->height = height(prl);
	if (p == *root)
		*root = prl;
	return (prl);
}

struct Node	*Insert(struct Node **root, struct Node *p, int key)
{
	struct Node	*new;

	if (p == NULL)
	{
		new = newNode(key);
		if (*root == NULL)
			*root = new;
		return (new);
	}
	if (key < p->data)
		p->lchild = Insert(root, p->lchild, key);
	else if (key > p->data)
		p->rchild = Insert(root, p->rchild, key);

	p->height = height(p);

	if (getBalanceFactor(p) == 2 && getBalanceFactor(p->lchild) == 1)
		return (LLRotation(root, p));
	else if (getBalanceFactor(p) == 2 && getBalanceFactor(p->lchild) == -1)
		return (LRRotation(root, p));
	else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->rchild) == -1)
		return (RRRotation(root, p));
	else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->rchild) == 1)
		return (RLRotation(root, p));
	return (p);
}

int calculateHeight(struct Node *p) // Calculates the height of the tree.
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

struct Node	*InPre(struct Node *p)
{
	while (p && p->rchild != NULL)
		p = p->rchild;
	return (p);
}

struct Node	*InSucc(struct Node *p)
{
	while (p && p->lchild != NULL)
		p = p->lchild;
	return (p);
}

struct Node	*Delete(struct Node **root, struct Node *p, int key)
{
	if (*root == NULL)
		return (NULL);
	if (key == p->data && p->lchild == NULL && p->rchild == NULL)
	{
		if (p == *root)
			*root = NULL;
		free(p);
		return (NULL);
	}
	if (key < p->data)
		p->lchild = Delete(root, p->lchild, key);
	else if (key > p->data)
		p->rchild = Delete(root, p->rchild, key);
	else
	{
		if (calculateHeight(p->lchild) > calculateHeight(p->rchild))
		{
			struct Node *q = InPre(p->lchild);
			p->data = q->data;
			p->lchild = Delete(root, p->lchild, q->data);
		}
		else
		{
			struct Node *q = InSucc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(root, p->rchild, q->data);
		}
	}
	p->height = height(p);
	if (getBalanceFactor(p) == 2 && getBalanceFactor(p->lchild) == 1)
		return (LLRotation(root, p));
	else if (getBalanceFactor(p) == 2 && getBalanceFactor(p->lchild) == -1)
		return (LRRotation(root, p));
	else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->rchild) == -1)
		return (RRRotation(root, p));
	else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->rchild) == 1)
		return (RLRotation(root, p));
	return (p);
}



// int main(void)
// {
// 	struct Node *root;

// 	root = NULL;
// 	Insert(&root, root, 10);
// 	Insert(&root, root, 20);
// 	Insert(&root, root, 30);
// 	Insert(&root, root, 5);

// 	printf("\n\n");
// 	Delete(&root, root, 25);
// 	Delete(&root, root, 4);

// 	displayTree(root, 0);
// }