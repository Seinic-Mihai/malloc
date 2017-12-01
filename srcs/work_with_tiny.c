/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_tiny.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:48:44 by mseinic           #+#    #+#             */
/*   Updated: 2017/12/01 18:28:40 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_data    *new_tiny(size_t size)
{
	t_data  *ptr;

	ptr = new_page(TINY);
	place_block(ptr, size);
	return (ptr);
}

void    *work_with_tiny(size_t size)
{
	t_data      *cursor;
	size_t      buss;

	buss = 0;
	cursor = g_ptr.tiny.page;
	while (cursor != NULL)
	{

		if (!cursor->status && size <= cursor->size)
			buss++;
		buss += cursor->size;
		cursor = cursor->block;
	}
	cursor = new_tiny(size);
	return ((void *)(cursor + sizeof(t_data)));
}
