#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	isPalindrome(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
		i++;
	j = i - 1;
	i = 0;
	while (i < j)
	{
		if (str[i] != str[j])
		{
			printf("It is not a Palindrome\n");
			return ;
		}
		i++;
		j--;
	}
	printf("It is a Palindrome\n");
}

int	FindDuplicate1(char *str) // Using Hash Table
{
	int	i;
	int	len;
	int Hash[128];

	len = 0;
	while (str[len])
		len++;
	for (int i = 0; i < 128; i++)
		Hash[i] = 0;
	i = 0;
	while (i < len)
		Hash[(int)str[i++]]++;
	for (int i = 0; i < 128; i++)
	{
		if (Hash[i] > 1)
			return (0);
			// printf("'%c' is duplicates %d times\n", i, Hash[i]);
	}
	return (1);
}

void	FindDuplicate2(char *str) // Using Bitwise Operations;
{
	int	H;
	int	i;
	int	x;

	H = 0;
	i = 0;
	while (str[i])
	{
		x = 1;
		x = x << (str[i] - 'a');
		if ((H & x) > 0)
			printf("%c is duplicated\n", str[i]);
		else
			H = (H | x);
		i++;
	}
}

int	isAnagram(char *str1, char *str2) // 2 strings are Anagram if they have same letters/length;
{
	int	i;
	int Hash[26] = {0};

	if (ft_strlen(str1) != ft_strlen(str2))
		return 0;
	if (FindDuplicate1(str1) == 0 || FindDuplicate1(str2) == 0)
		return 0;
	for (i = 0; str1[i]; i++)
	{
		Hash[str1[i] - 'a']++;
		Hash[str2[i] - 'a']++;
	}
	for (i = 0; str1[i]; i++)
	{
		if (Hash[str1[i] - 'a'] != 2)
			return 0;
	}
	return (1);
}

char	*ft_strrev(char	*str)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	for (i = 0; i < ft_strlen(str); i++)
	{
		new_str[i] = str[ft_strlen(str) - 1 - i];
	}
	new_str[i] = '\0';
	return (new_str);
}

void	Permutations(char *str, int k) // find all possible permutations for a string
{
	static char	res[10];
	static int	A[10] = {0};
	int	i;

	i = 0;
	if (str[k] == '\0')
	{
		res[k] = '\0';
		printf("%s\n", res);
	}
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (A[i] == 0)
			{
				A[i] = 1;
				res[k] = str[i];
				Permutations(str, k+1);
				A[i] = 0;
			}
		}
	}
}

int main(void)
{
	char *str = "ABCD";
	Permutations(str, 0);
}