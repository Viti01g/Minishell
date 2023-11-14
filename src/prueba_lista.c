#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/minishell.h"

t_token	*ft_lstnew_addback(t_token **token, char *str)
{
	t_token	*new;

	if (!token)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	if (*token == NULL)
	{
		*token = new;
	}
	else
	{
		t_token	*end = *token;
		while (end->next != NULL)
			end = end->next;
		end->next = new;
	}
	return (new);
}

/* int main(void)
{
	t_list	*my_list = NULL;  // Inicializa una lista vacía

	// Crea nodos y agrégalos al final de la lista
	ft_lstnew_addback(&my_list, "Nodo 1");
	ft_lstnew_addback(&my_list, "Nodo 2");
	ft_lstnew_addback(&my_list, "Nodo 3");

	// Itera a través de la lista e imprime su contenido
	t_list *current = my_list;
	while (current != NULL)
	{
		printf("Contenido: %s\n", (char *)current->str);
		current = current->next;
	}
	return (0);
} */