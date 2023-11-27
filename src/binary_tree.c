/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:44:24 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/27 17:23:26 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
	int	valor;
	struct s_nodo	*izquierda;
	struct s_nodo	*derecha;
}	t_nodo;

t_nodo	*crear_nodo(int valor)
{
	t_nodo	*nodo;

	nodo = (t_nodo *)malloc(sizeof(t_nodo));
	nodo->valor = valor;
	nodo->izquierda = NULL;
	nodo->derecha = NULL;
	return (nodo);
}

t_nodo	*insertar(t_nodo *raiz, int valor)
{
	if (raiz == NULL)
		return (crear_nodo(valor));

	if (valor < raiz->valor)
		raiz->izquierda = insertar(raiz->izquierda, valor);
	else
		raiz->derecha = insertar(raiz->derecha, valor);
	return (raiz);
}

void	imprimir_arbol(t_nodo *raiz, unsigned long espacio)
{
	unsigned long	i;

	i = 0;
	if (raiz == NULL)
		return ;

	espacio += 5;

	imprimir_arbol(raiz->derecha, espacio);

	printf("\n");
	while (i < espacio)
	{
		if (i == 0)
			printf(" ");
		else if (i % 6 == 0)
			printf("|");
		else
			printf("-");

		i++;
	}
	printf("%d\n", raiz->valor);

	imprimir_arbol(raiz->izquierda, espacio);
}

void	en_orden(t_nodo *raiz)
{
	if (raiz != NULL)
	{
		en_orden(raiz->derecha);
		printf("%d ", raiz->valor);
		en_orden(raiz->izquierda);
	}
}

int	main(void)
{
	t_nodo	*raiz;
	int		tamano_numeros;
	int		i;
	int		numeros[] = {50, 30, 20, 40, 70, 60, 80}; // Puedes ajustar los números aquí

	raiz = NULL;

	tamano_numeros = sizeof(numeros) / sizeof(numeros[0]);

	i = 0;
	while (i < tamano_numeros)
		raiz = insertar(raiz, numeros[i++]);

	printf("Árbol binario:\n");
	imprimir_arbol(raiz, 0);

	printf("\n\nRecorrido en orden (de menor a mayor):\n");
	en_orden(raiz);
	printf("\n");

	return (0);
}
