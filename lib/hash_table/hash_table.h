/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:37:55 by antoinemura       #+#    #+#             */
/*   Updated: 2024/01/21 17:23:01 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H
# define INT_MAX 2147483647

# include <stdlib.h>

typedef struct s_hashnode
{
	void				*key;
	void				*value;
	struct s_hashnode	*next;
}	t_hashnode;

typedef struct s_hashtable
{
	int				size;
	t_hashnode		**array;
	unsigned int	(*hash_function)(void *key);
	int				(*key_compare)(void *key1, void *key2);
}	t_hashtable;

unsigned int	default_hash_function(void *key);
int				default_key_compare(void *key1, void *key2);
void			hash_table_init(t_hashtable	*hash_table,
					int size,
					unsigned int (*hash_function)(void *),
					int (*key_compare)(void *, void *));
void			hash_table_insert(t_hashtable *table, void *key, void *value);
void			*hash_table_get(t_hashtable *table, void *key);
void			hash_table_delete(t_hashtable *table, void *key);
void			hash_table_free(t_hashtable *table,
					void (*free_function)(void *));

#endif