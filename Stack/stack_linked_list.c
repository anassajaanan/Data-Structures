#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
	int			data;
	struct Node	*next;
};

void	Push(struct Node **top, int x)
{
	struct Node *new;

	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = x;
	new->next = *top;
	*top = new;
}

int	Pop(struct Node **top)
{
	struct Node *p;
	int			x;

	if (*top)
	{
		p = *top;
		*top = (*top)->next;
		x = p->data;
		free(p);
	}
	else
	{
		printf("Stack is Empty\n");
		x = -1;
	}
	return (x);
}

int	Peek(struct Node *top, int pos)
{
	struct Node *p;

	p = top;
	for (int i = 1; p && i < pos; i++)
		p = p->next;
	if (p)
		return (p->data);
	else
		return (-1);
}

int	StackTop(struct Node *top)
{
	if (top)
		return (top->data);
	else
		return (-1);
}

int	isEmpty(struct Node *top)
{
	if (top)
		return (0);
	return (1);
}

int	isFull()
{
	struct Node *t;

	t = (struct Node *)malloc(sizeof(struct Node));
	if (t)
	{
		free(t);
		return (0);
	}
	return (1);
}

void	Display(struct Node *top)
{
	struct Node *p;

	p = top;
	while (p)
	{
		if (p == top)
			printf("-----\n  %d     <-- top\n-----\n", p->data);
		else
			printf("-----\n  %d\n-----\n", p->data);
		p = p->next;
	}
}

// // infix To Postfix conversion
int	isOperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
		return (0);
	return (1);
}

int outStackPrecedence(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else if (c == '*' || c == '/')
		return (3);
	else if (c == '^')
		return (6);
	else if (c == '(')
		return (7);
	else if (c == ')')
		return (0);
	else
		return (0);
}

int	inStackPrecedence(char c)
{
	if (c == '+' || c == '-')
		return (2);
	else if (c == '*' || c == '/')
		return (4);
	else if (c == '^')
		return (5);
	else if (c == '(')
		return (0);
	else
		return (0);
}

char	*ToPostfix(char *infix)
{
	struct Node		*top;
	char			*postfix;
	int				i;
	int				j;

	top = NULL;
	postfix = (char *)malloc(sizeof(char) * strlen(infix) + 1);
	i = 0;
	j = 0;
	while (infix[i])
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (isEmpty(top))
				Push(&top, (int)infix[i++]);
			else
			{
				if (outStackPrecedence(infix[i]) > inStackPrecedence((char)top->data))
					Push(&top, (int)infix[i++]);
				else if (outStackPrecedence(infix[i]) < inStackPrecedence((char)top->data))
					postfix[j++] = (char)Pop(&top);
				else
				{
					Pop(&top);
					i++;
				}

			}
		}
	}
	while (!isEmpty(top))
		postfix[j++] = (char)Pop(&top);
	postfix[j] = '\0';
	return (postfix);
}

int calculate(int n1, int n2, char op)
{
	if (op == '+')
		return (n1 + n2);
	else if (op == '-')
		return (n1 - n2);
	else if (op == '*')
		return (n1 * n2);
	else if (op == '/')
		return (n1 / n2);
}

int	Eval(char	*postfix)
{
	struct Node	*top;
	int			n1;
	int			n2;

	top = NULL;
	for (int i = 0; postfix[i]; i++)
	{
		if (isOperand(postfix[i]))
			Push(&top, postfix[i] - '0');
		else
		{
			n2 = Pop(&top);
			n1 = Pop(&top);
			Push(&top, calculate(n1, n2, postfix[i]));
		}
	}
	return (Pop(&top));
}

int main(void)
{
	struct Node	*top;

	top = NULL;
	
	char infix1[] = "((a+b)*c)-d^e^f";
	char infix2[] = "a+(b*c)-(c/d)";
	char infix3[] = "a+b*c-d/e";
	char *postfix = ToPostfix(infix3);

	printf("%d\n", Eval("234*+82/-"));
}


