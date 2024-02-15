/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:47:51 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/15 15:08:02 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cmp_dollar(char *str, int *i, char flag)
{
	printf("%s			ENTRA EN CMP_DOLLAR%s\n", RED, NORMAL);
	printf("			valor de entrada de i: %d\n", *i);
	*i += 1;
	while (str[*i] && str[*i] != flag)
	{
		printf("			Comprobando caracter: %c\n", str[*i]);
		if (str[*i] == '$')
		{
			while (str[*i + 1] != flag)
			{
				(*i)++;
				printf("			valor c: %c\n", str[*i]);
			}
			if (flag == '\'')
			{
				printf("			$ dentro de comilla simple\n");
				return (-1);
			}
			printf("			$ dentro de comilla doble\n");
			return (1);
		}
		else
			(*i)++;
	}
	return (0);
}

int	quotes_dollar(char *str)
{
	int	i;
	int	double_q;
	int	single_q;

	printf("%s		ENTRA EN QUOTES_DOLLAR%s\n", RED, NORMAL);
	i = 0;
	double_q = 0;
	single_q = 0;
	while (str[i])
	{
		printf("		valor comprobado: %c\n", str[i]);
		if (str[i] == '\"' && single_q == 0 && double_q == 0)
		{
			printf("		Entra if de comilla doble\n");
			double_q = cmp_dollar(str, &i, '\"');
			printf("		Valor de double_q: %d\n", double_q);
		}
		if (str[i] == '\'' && double_q == 0)
		{
			printf("		Entra if de comilla simple\n");
			single_q = cmp_dollar(str, &i, '\'');
			printf("		Valor de single_q: %d\n", single_q);
		}
		if (single_q == -1)
		{
			printf("		eNTrA\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	dollar_sign(char *str)
{
	int	i;

	printf("%s	ENTRA EN DOLLAR_SIGN%s\n", RED, NORMAL);
	i = 0;
	while (str[i])
	{
		printf("	Caracter comprobando: %c\n", str[i]);
		if (str[i] == '$')
		{
			printf("	ENCUENTRA $\n");
			return (i + 1);
		}
		i++;
	}
	return (0);
}

void	expansor(char **str)
{
	int	result;
	int	result_q;
	int	i;
	char	tmp;

	i = 0;
	printf("str: %s\n", str[i]);
	while (str[i])
	{
		if ((result = dollar_sign(str[i])) != 0 && (result_q = quotes_dollar(str[i])))		// hay dollar y esta primero entre comillas dobles o sin comillas
		{
			tmp = NULL; // crear funcion para cambiar el str por el expansor correspondiente;
		}
		printf("\nresultado de comprobacion comillas: %d\n", result_q);
		printf("%sString comprobado: %s%s\n", BLUE, str[i], NORMAL);
		printf("%sPosicion $: %d%s\n", GREEN, result, NORMAL);
		i++;
	}
	return ;
}

int	main(void)
{
	expansor(ft_split(readline(PROMPT_MSG), ' '));
	return (0);
}
