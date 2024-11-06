/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:53:55 by micha             #+#    #+#             */
/*   Updated: 2024/08/18 17:58:58 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void do_op(char *s1, char s2, char *s3)
{
    int num1 = atoi(s1);
    int num2 = atoi(s3);
    
    if (s2 == '*')
        printf("%d\n", num1 * num2);
    else if (s2 == '/')
	printf("%d\n", num1 / num2);
    else if (s2 == '-')
        printf("%d\n", num1 - num2);
    else if (s2 == '+')
        printf("%d\n", num1 + num2);
    else if (s2 == '%')
	printf("%d\n", num1 % num2);
    else
        printf("\n");
}

int main(int argc, char **argv)
{
    if (argc == 4)
        do_op(argv[1], argv[2][0], argv[3]);
    else
        printf("\n");
    
    return 0;
}

