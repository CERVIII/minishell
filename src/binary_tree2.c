/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:37:53 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/28 13:26:41 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_tree
{
	int				value;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*create_nodo(int value)
{
	t_tree	*new;

	new = (t_tree *)malloc(sizeof(new));
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_tree	*create_tree(t_tree *tree, int value)
{
	if (!tree)
		return (create_nodo(value));
	if (value < tree->value)
		tree->left = create_tree(tree->left, value);
	else
		tree->right = create_tree(tree->right, value);
	return (tree);
}

void	print_tree(t_tree *tree, int space)
{
	int	i;

	i = 0;
	if (!tree)
		return ;
	space += 5;
	print_tree(tree->right, space);
	while (i < space)
	{
		printf(" ");
		i++;
	}
	printf("%d\n", tree->value);
	print_tree(tree->left, space);
}

int	main(void)
{
	t_tree	*tree;
	char	*input;
	char	**nums;
	int		i;

	tree = NULL;
	input = NULL;
	printf("Ingrese los numeros a ordenar:\n");
	scanf("%s", input);
	nums = ft_split(input, ' ');
	i = 0;
	while (input[i])
	{
		create_tree(tree, ft_atoi(nums[i++]));
	}
	printf("HOLA\n");
	print_tree(tree, i);
/* 	order_min(tree);
	order_max(tree); */
}
