/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:14:22 by mseinic           #+#    #+#             */
/*   Updated: 2017/11/28 19:24:44 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_alloc		*manage_alloc(size_t size)
{
	t_alloc		*mem;

	mem = new_page(size);
	return (mem);
}
