/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:38:00 by antoinemura       #+#    #+#             */
/*   Updated: 2024/01/21 17:29:37 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

void	hash_table_init(t_hashtable	*hash_table, int size,
							unsigned int (*hash_function)(void *),
							int (*key_compare)(void *, void *))
{
	int	i;

	if (!hash_table)
		return ;
	hash_table->size = size;
	hash_table->array = malloc(sizeof(t_hashnode *) * size);
	if (!hash_table->array)
		return ;
	i = 0;
	while (i < size)
	{
		hash_table->array[i] = NULL;
		i++;
	}
	if (hash_function)
		hash_table->hash_function = hash_function;
	else
		hash_table->hash_function = &default_hash_function;
	if (key_compare)
		hash_table->key_compare = key_compare;
	else
		hash_table->key_compare = &default_key_compare;
}

void	hash_table_insert(t_hashtable *table, void *key, void *value)
{
	unsigned int	hash;
	t_hashnode		*new_node;

	if (!table)
		return ;
	hash = table->hash_function(key) % table->size;
	new_node = malloc(sizeof(t_hashnode));
	if (new_node == NULL)
		return ;
	new_node->key = key;
	new_node->value = value;
	new_node->next = table->array[hash];
	table->array[hash] = new_node;
}

void	*hash_table_get(t_hashtable *table, void *key)
{
	unsigned int	index;
	t_hashnode		*node;

	if (!table)
		return (NULL);
	index = table->hash_function(key) % table->size;
	node = table->array[index];
	while (node != NULL)
	{
		if (table->key_compare(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

void	hash_table_delete(t_hashtable *table, void *key)
{
	unsigned int	index;
	t_hashnode		*current;
	t_hashnode		*prev;

	index = table->hash_function(key) % table->size;
	current = table->array[index];
	prev = NULL;
	if (!table)
		return ;
	while (current != NULL)
	{
		if (table->key_compare(current->key, key) == 0)
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				table->array[index] = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	hash_table_free(t_hashtable *table, void (*free_function)(void *))
{
	t_hashnode	*node;
	t_hashnode	*temp;
	int			i;

	i = 0;
	if (!table)
		return ;
	while (i < table->size)
	{
		node = table->array[i];
		while (node != NULL)
		{
			temp = node;
			node = node->next;
			if (free_function)
				free_function(temp->value);
			free(temp);
		}
		i++;
	}
	free(table->array);
	free(table);
}
