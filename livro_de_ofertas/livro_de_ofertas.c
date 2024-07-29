/*
Livro de ofertas

Parabéns!! você foi contratado por uma corretora para montar  um sistema de livro de ofertas de vendas e compras.
Um livro de ofertas nada mais é que uma lista de um mesmo produto organizadas pelo seu preço.

A cada negocicão de compra ou venda  os livros de ofertas são atualizados, podendo inserir , remover ou modifcar as ofertas presentes no livro.
Cada operação na livro gera uma nova mensagem que é composta por 4 paramêtros, o primeiro valor é a posição da atualização, já segunda é o tipo de ação a ser tomada, em  terceiro temos o valor e por último a quantidade. Cada propriedade é descrita na tabela abaixo:


PROPRIEDADE  |    TIPO     |  VALORES
-------------|-------------|------------
POSIÇÃO      |   INTEIRO   |  valores positivos diferente de 0
ACÃO         |   INTEIRO   |  0 = INSERIR, 1 = MODIFICAR, 2 = DELETAR
VALORES      |   DOUBLE    |  Qualquer valor positivo diferente de 0
QUANTIDADE   |   INTEIRO   |  Qualquer valor positivo diferente de 0


Exemplo:

LIVRO DE OFERTA

POSICAO | VALOR | QUANTIDADE
--------|-------|------------
1       | 15.4  | 50
2       | 15.4  | 10
3       | 15.9  | 20
4       | 16.1  | 100
5       | 16.20 | 20
6       | 16.43 | 30
7       | 17.20 | 70
8       | 17.35 | 80
9       | 17.50 | 200

Seu objetivo é fazer um programa que receba e processe todas as notificações de atualizações de um livro de ofertas e imprima seu resultado.

Input:
A primeira linha é composta por um inteiro informando o número de notificações e as linhas subsequences contem as notificações no seguinte formato: posição,ação,valor,quantidade.

exemplo:
12\
1,0,15.4,50\
2,0,15.5,50\
2,2,0,0\
2,0,15.4,10\
3,0,15.9,30\
3,1,0,20\
4,0,16.50,200\
5,0,17.00,100\
5,0,16.59,20\
6,2,0,0\
1,2,0,0\
2,1,15.6,0

## Output:
O output deve seguir o seguinte formato onde cada linha representa uma posição.

1,15.4,10\
2,15.6,20\
3,16.50,200\
4,16.59,20\


*representação do resultado*

POSICAO | VALOR | QUANTIDADE
--------|-------|------------
1       | 15.4  | 10
2       | 15.6  | 20
3       | 16.50 | 200
4       | 16.59 | 20
*/

#include <stdio.h>
#include <stdlib.h>

enum ACTIONS
{
	INSERT = 0,
	MODIFY,
	DELETE,
};

typedef struct book book;

struct book
{
	int		quantity;
	double	value;
	book	*next;
};

typedef struct action
{
	int		action;
	int		position;
	int		quantity;
	int		notification_count;
	double	value;
}	action;

void	do_action(book **books_list, action action);
void	print_books_list(book *books_list);
void	clear_books_list(book **books_list);

int	main(void)
{
	action	action;
	book	*books_list = NULL;

	scanf("%d", &action.notification_count);

	for (int i = 0; i < action.notification_count; i++)
	{
		scanf("%d,%d,%lf,%d", &action.position, &action.action, &action.value, &action.quantity);
		do_action(&books_list, action);
	}

	print_books_list(books_list);
	clear_books_list(&books_list);

	return (0);
}

void	modify_book(book **books_list, action action)
{
	int		pos = 1;
	book	*books_list_aux = *books_list;

	while (books_list_aux)
	{
		if (pos == action.position)
			break ;
		pos++;
		books_list_aux = books_list_aux->next;
	}

	if (!books_list_aux)
		return ;

	if (action.value != 0)
		books_list_aux->value = action.value;

	if (action.quantity != 0)
		books_list_aux->quantity = action.quantity;
}

void	insert_book(book **books_list, action action)
{
	int		pos = 0;
	book	*new;
	book	*books_list_aux = *books_list;

	while (books_list_aux && books_list_aux->next)
	{
		pos++;
		if (pos == action.position)
			break ;
		books_list_aux = books_list_aux->next;
	}

	if (pos == action.position)		// Se o livro já existir é só modificar ele
	{
		modify_book(books_list, action);
		return ;
	}

	new = malloc(sizeof(book));
	new->value = action.value;
	new->quantity = action.quantity;
	new->next = NULL;

	if (books_list_aux)
		books_list_aux->next = new;
	else
		*books_list = new;
}

void	delete_book(book **books_list, action action)
{
	int		pos = 1;
	book	*prev = NULL;
	book	*books_list_aux = *books_list;

	while (books_list_aux)
	{
		if (pos == action.position)
			break ;
		pos++;
		prev = books_list_aux;
		books_list_aux = books_list_aux->next;
	}

	if (!books_list_aux)
		return ;

	if (prev)
		prev->next = books_list_aux->next;
	else
		*books_list = books_list_aux->next;

	free(books_list_aux);
}

void	do_action(book **books_list, action action)
{
	if (action.position < 0)
		printf("Posicao invalida!\n");
	else if (action.value < 0)
		printf("Valor invalido!\n");
	else if (action.quantity < 0)
		printf("Quantidade invalida\n");

	else if (action.action == INSERT)
		insert_book(books_list, action);
	else if (action.action == MODIFY)
		modify_book(books_list, action);
	else if (action.action == DELETE)
		delete_book(books_list, action);

	else
		printf("Acao invalida!\n");
}

void	print_books_list(book *books_list)
{
	int		pos = 1;
	book	*books_list_aux = books_list;

	while (books_list_aux)
	{
		printf("%d,%.2lf,%d\n", pos, books_list_aux->value, books_list_aux->quantity);
		pos++;
		books_list_aux = books_list_aux->next;
	}
}

void	clear_books_list(book **books_list)
{
	book	*prev = NULL;
	book	*books_list_aux = *books_list;

	while (books_list_aux)
	{
		prev = books_list_aux;
		books_list_aux = books_list_aux->next;
		free(prev);
	}

	*books_list = NULL;
}
