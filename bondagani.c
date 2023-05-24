#include "main.h"

/**
 * print_list - _print linked list
 * @h: linked list
 * Return: size of linked list
 */

size_t write_list(link_t *h)
{
	link_t *c_list = h;
	int cnt = 0, x = 0;

	if (h == NULL)
		return (0);
	while (c_list != NULL)
	{
		if (c_list->value == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			x = 0;
			while ((c_list->value)[x] != '\0')
				x++;
			write(STDOUT_FILENO, c_list->value, x);
			write(STDOUT_FILENO, "\n", 1);
		}
		c_list = c_list->next;
		cnt++;
	}
	return (cnt);
}

/**
 * add_end_node - add node to end of linked list
 * @head: pointer to head of linked list
 * @str: data to new node
 * Return: pointer to new linked list
 */
link_t *add_node_end(link_t **head, char *str)
{
	link_t *new;
	link_t *holder;

	if (head == NULL || str == NULL)
		return (NULL);
	new = malloc(sizeof(link_t));
	if (new == NULL)
		return (NULL);

	new->value = _strdup(str);
	new->next = NULL;

	holder = *head;
	if (holder != NULL)
	{
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}

/**
 * delete_nodeint_at_index - removing node at index
 * @head: input head address
 * @index: input index
 * Return: 1 if success, else -1
 */
int rm_node_int_at_index(link_t **head, int index)
{
	link_t *n_head;
	link_t *holder;
	int cnt = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		holder = (*head)->next;
		free((*head)->value);
		free(*head);
		*head = holder;
		return (1);
	}
	cnt = 1;
	n_head = *head;
	while (cnt < index)
	{
		if (n_head == NULL)
			return (-1);
		n_head = n_head->next;
		cnt++;
	}
	holder = n_head->next;
	n_head->next = holder->next;
	free(holder->value);
	free(holder);
	return (1);
}

/**
 * free_linked_list - frees linked list
 * @list: linked list
 */
void free_list(link_t *list)
{
	link_t *holder;

	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->value);
		free(holder);
	}

}