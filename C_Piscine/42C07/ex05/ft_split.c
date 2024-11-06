/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:47:45 by micha             #+#    #+#             */
/*   Updated: 2024/08/27 15:47:47 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	while (*sep != '\0')
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

char	*str_dup(char *str, char *charset)
{
	int		len;
	char	*dest;
	int		i;

	len = 0;
	while (str[len] != '\0' && !is_sep(str[len], charset))
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	element_count(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		if (!is_sep(*str, charset))
		{
			cnt++;
			while (!is_sep(*str, charset) && *str != '\0')
				str++;
		}
		else
			str++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		num;
	int		i;
	char	**result;

	num = element_count(str, charset);
	result = (char **)malloc(sizeof(char *) * (num + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		if (!is_sep(*str, charset))
		{
			result[i++] = str_dup(str, charset);
			while (!is_sep(*str, charset) && *str != '\0')
				str++;
		}
		else
			str++;
	}
	result[i] = 0;
	return (result);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(char *str, char *charset);

void do_test(char* str, char* charset)
{
	char	**array;
	int		i;

	array = ft_split(str, charset);
	i = 0;
	while (array[i])
	{
		printf("'%s' (len=%d)\n", array[i], (int)strlen(array[i]));
		i++;
	}
}

int main(void)
{
	do_test(",1,2,3", ",");
	do_test("Hello.,World,.!!KOKO!ZZZ.Hello.Good.World!KK!ZORO,Good", ",.!");
	do_test("abcakaabcaakaabce", "bck");
	do_test("|---AA-|GoogooGooGoo|aaaa-| Hello World Good| ^^|Nice Boat!", " |-");
	do_test("               ", "     ");
	do_test("  \t ", " \t");
	do_test("123,456,789 ,", ",l1");
	do_test("0tNue8", "0tNue8");
	do_test("80hzNIGZYoIa3ATwY8dRCFmBBYx0RA", "AKfwjE5l");
	return 0;
}
