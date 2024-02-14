/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:47:51 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/14 13:50:50 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cmp_dollar(char *str, int *i, char flag)
{
	while (str[*i] || str[*i] != flag)
	{
		if (str[*i] == '$')
		{
			if (flag == '\'')
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	quotes_dollar(char *str)
{
	int	i;
	int	double_q;
	int	single_q;

	i = 0;
	double_q = 0;
	single_q = 0;
	while (str[i])
	{
		if (str[i] == '\"' && single_q == 0 && double_q == 0)
		{
			double_q = cmp_dollar(str, (&i + 1), '\"');
		}
		if (str[i] == '\'' && double_q == 0)
			single_q = cmp_dollar(str, (&i + 1), '\'');
		if (single_q == -1)
			return (-1);
	}
	return (0);
}

int	dollar_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

void	expansor(char **str)
{
	int	result;
	int	i;

	i = 1;
	while (str[i])
	{
		if (dollar_sign(str[i]) != 0)
		{
			printf("\nresultado de comprobacion comillas%d\n", quotes_dollar(str[i]));
		}
		printf("\n\n%sString: %s%s\n", BLUE, str[i], NORMAL);
		result = dollar_sign(str[i]);
		printf("\n\n%sResult: %d%s\n", GREEN, result, NORMAL);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Error: No arguments\n");
		return (1);
	}
	expansor(argv);
	return (0);
}
