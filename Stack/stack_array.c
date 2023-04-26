#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Stack
{
	int size;
	int top;
	int	*s;
};

void	Push(struct Stack *st, int x)
{
	if (st->top == st->size - 1)
		printf("Stack Overflow\n");
	else
	{
		st->top++;
		st->s[st->top] = x;
	}
}

int	Pop(struct Stack *st)
{
	int	n;

	if (st->top == -1)
	{
		printf("Stack Underflow\n");
		return (-1);
	}
	else
	{
		n = st->s[st->top];
		st->top--;
		return (n);
	}
}

int	Peek(struct Stack st, int pos)
{
	if (st.top - pos + 1 < 0)
	{
		printf("Invalid Position\n");
		return (-1);
	}
	else
		return (st.s[st.top - pos + 1]);
}

int	StackTop(struct Stack st)
{
	if (st.top == -1)
	{
		printf("Stack is Empty\n");
		return (-1);
	}
	else
		return (st.s[st.top]);
}

int isEmpty(struct Stack st)
{
	if (st.top == -1)
		return (1);
	else
		return (0);
}

int isFull(struct Stack st)
{
	if (st.top == st.size - 1)
		return (1);
	else
		return (0);
}

void Display(struct Stack st)
{
    if (st.top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack with top pointer:\n");

    for (int i = st.size - 1; i >= 0; i--)
    {
		printf("-----\n");
        if (i <= st.top)
		{
			if (i == st.top)
			{
				printf("  %d", st.s[i]);
				printf("     <-- top: %d\n", st.top);
			}
			else
				printf("  %d\n", st.s[i]);
		}
		else
			printf("\n");
		printf("-----\n");
    }
}

int	isBalance(char *exp) // Parenthesis Matching
{
	struct Stack	st;

	st.size = strlen(exp);
	st.top = -1;
	st.s = (int *)malloc(sizeof(int) * st.size);
	for (int i = 0; exp[i]; i++)
	{
		if (exp[i] == '(')
			Push(&st, (int)exp[i]);
		if (exp[i] == ')')
		{
			if (isEmpty(st))
				return (0);
			Pop(&st);
		}
	}
	if (isEmpty(st))
		return (1);
	else
		return (0);
}

// infix To Postfix conversion
int	precedence(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else if (c == '*' || c == '/')
		return (2);
	else
		return (3);
}

char	*infixToPostfix(char *infix)
{
	char			*postfix;
	struct Stack	st;
	int				j;

	j = 0;
	st.size = strlen(infix);
	st.top = -1;
	st.s = (int *)malloc(sizeof(int) * st.size);
	postfix = (char *)malloc(sizeof(char) * st.size + 1);
	for (int i = 0; infix[i]; i++)
	{
		if (isEmpty(st))
			Push(&st, (int)infix[i]);
		else
		{
			if (precedence(infix[i]) > precedence((char)st.s[st.top]))
				Push(&st, (int)infix[i]);
			else
			{
				while (!isEmpty(st) && precedence(infix[i]) <= precedence((char)st.s[st.top]))
					postfix[j++] = (char)Pop(&st);
				Push(&st, (int)infix[i]);
			}
		}
	}
	while (!isEmpty(st))
		postfix[j++] = (char)Pop(&st);
	postfix[j] = '\0';
	return (postfix);
}


int main(void)
{
	char 	infix[] = "a+b*c-d/e+h/j*g";
	char	*postfix = infixToPostfix(infix);

	printf("The Posfix of [%s] is : [%s]\n",infix , postfix);
}
