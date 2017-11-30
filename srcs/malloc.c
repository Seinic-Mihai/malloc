/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:10:42 by mseinic           #+#    #+#             */
/*   Updated: 2017/11/28 19:26:51 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void    place_block(t_data *ptr, size_t size)
{
    ptr->size = size;
    ptr->status = 1;
    ptr->block = ptr + (size + sizeof(t_data)); 
}

t_data    *new_tiny(size_t size)
{
    t_data  *ptr;

    ptr = new_page(TINY);
    place_block(ptr, size);
    return (ptr);
}

void	*work_with_tiny(size_t size)
{
	t_data		*cursor;
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
    return ((void *)(cursor /*+ sizeof(t_data)*/));
}

void	*malloc(size_t size)
{
	void	*ptr;
	if (size < TINY_ZONE)
        ptr = work_with_tiny(size);
	else if (size >= TINY_ZONE && size < SMALL_ZONE)
		ptr = NULL;
	else
		ptr = NULL;

	return (ptr);
}
