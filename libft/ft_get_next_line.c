/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:25:28 by pcervill          #+#    #+#             */
/*   Updated: 2022/08/06 23:57:20 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_write(int fd, char *save)
{
	char	*stread;
	int		sizebuff;

	sizebuff = 1;
	stread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stread)
		return (NULL);
	while (!ft_strchr2(save, '\n') && sizebuff != 0)
	{
		sizebuff = read(fd, stread, BUFFER_SIZE);
		if (sizebuff == -1)
		{
			free(stread);
			return (NULL);
		}
		stread[sizebuff] = '\0';
		save = ft_strjoin2(save, stread);
	}
	free (stread);
	return (save);
}

char	*ft_print(char *save)
{
	int		cont;
	char	*result;

	cont = 0;
	if (!save[cont])
		return (NULL);
	while (save[cont] && save[cont] != '\n')
		cont++;
	result = malloc(sizeof(char) * (cont + 2));
	if (!result)
		return (NULL);
	cont = 0;
	while (save[cont] && save[cont] != '\n' )
	{
		result[cont] = save[cont];
		cont++;
	}
	if (save[cont] == '\n')
	{
		result[cont] = '\n';
		cont++;
	}
	result[cont] = '\0';
	return (result);
}

char	*ft_cleansave(char *save)
{
	char	*newsave;
	int		cont;
	int		cont1;

	cont = 0;
	while (save[cont] && save[cont] != '\n')
		cont++;
	if (!save[cont])
	{
		free(save);
		return (NULL);
	}
	newsave = malloc(sizeof(char) * (ft_strlen2(save) - cont + 1));
	if (!newsave)
		return (NULL);
	cont++;
	cont1 = 0;
	while (save[cont])
		newsave[cont1++] = save[cont++];
	newsave[cont1] = '\0';
	free(save);
	return (newsave);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_write(fd, save);
	if (!save)
		return (NULL);
	result = ft_print(save);
	save = ft_cleansave(save);
	return (result);
}