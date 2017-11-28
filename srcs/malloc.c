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

void	work_with_tiny(size_t size)
{
	t_data		*cursor;

	cursor = g_ptr.tiny.node;
	while (cursor != NULL)
		cursor = cursor->next;

}

void	*malloc(size_t size)
{
	void	*ptr;
	if (size < TINY_ZONE)
		ptr = NULL;
	else if (size >= TINY_ZONE && size < SMALL_ZONE)
		ptr = NULL;
	else
		ptr = NULL;

	return (ptr);
}
