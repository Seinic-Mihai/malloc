/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:10:42 by mseinic           #+#    #+#             */
/*   Updated: 2017/12/01 18:28:45 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void    place_block(t_data *ptr, size_t size)
{
    ptr->size = size;
    ptr->status = 1;
    ptr->block = ptr + (size + sizeof(t_data)); 
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
