/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_default.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:28:50 by antoinemura       #+#    #+#             */
/*   Updated: 2024/01/20 18:41:27 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

unsigned int	default_hash_function(void *key)
{
	return (*(int *)key) % INT_MAX;
}

int	default_key_compare(void *key1, void *key2)
{
	int k1; 
	int k2; 
	
	k1 = *(int *)key1;
	k2 = *(int *)key2;
	if (k1 == k2)
		return (0);
	else if (k1 > k2)
		return (1);
	else
		return (-1);
}

