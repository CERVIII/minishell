/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:11:09 by drubio-m          #+#    #+#             */
/*   Updated: 2024/02/07 14:02:12 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../include/minishell.h"
#include "../../include/lexer.h"

/* static void	ft_free_split(char **str, size_t words)
{
	while (words > 0)
	{
		free(str[words]);
		words--;	
	}
	free(str);
} */

char	*get_next_word(char *s, size_t *start, char c)
{
	size_t	i;
	int		in_quotes;
	char	current_quote;
	char	*word;

	i = *start;
	in_quotes = 0;
	current_quote = '\0';
	while (s[i] && (s[i] != c || in_quotes))
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			p_quotes_cmd(s, &i, &in_quotes, &current_quote);
			continue ;
		}
		else
			i++;
	}
	word = ft_substr(s, *start, (i - *start));
	*start = i;
	skip_delimiters(s, start, c, in_quotes);
	return (word);
}

char	**ft_split_cmd(char *s, char c)
{
	char	**words;
	size_t	i;
	size_t	start;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_words_cmd(s, c);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	i = 0;
	start = 0;
	while (s[start] == c && s[start] != '\0')
		start++;
	while (i < word_count)
	{
		words[i] = get_next_word(s, &start, c);
		if (words[i] == NULL)
			break ;
		i++;
	}
	words[i] = NULL;
	return (words);
}

//*****************************************************************************
// INPUT
// #1. La string a separar.
// #2. El caracter delimitador.
//*****************************************************************************
// OUTPUT
// El array de strings resultante. NULL si la reserva falla.
//*****************************************************************************
// DESCRIPTION
// Reserva con malloc(3) y devuelve un array de strings obtenido al separar 
// ’s’ con el caracter ’c’ como delimitador. El array debe terminar en NULL.
//*****************************************************************************

/* int main(void)
{
char s[] = " pedro' h o\"la'ap\"ito\"     c' pedro' n ";
//char s[] = "'hola' 'mundo'";
//char s[] = "\"hola\" \"mundo\"";
char c = ' ';
char **res;
int i = 0;
res = ft_split_cmd(s, ' ');
while (res[i])
{
	printf("%s\n", res[i]);
	i++;
}
printf("%s\n", res[i]);
//system("leaks a.out");
return (0);
} */
