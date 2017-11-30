/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:51:17 by mseinic           #+#    #+#             */
/*   Updated: 2017/11/28 19:27:23 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <sys/mman.h>
#define PAGE_SIZE getpagesize() 
#define	TINY_ZONE (128)
#define	SMALL_ZONE (512)
#define TINY (TINY_ZONE * 100)
#define SMALL (SMALL_ZONE * 100)
#define TINY_PAGE (TINY * PAGE_SIZE)
#define SMALL_PAGE (SMALL * PAGE_SIZE)

typedef struct		s_data
{
	size_t			size;
	size_t			status;
	struct s_data	*block;
}					t_data;

typedef struct		s_list
{
	size_t			size;
	t_data			*page;
}					t_list;

typedef struct		s_alloc
{
	t_list			tiny;
	t_list			small;
	t_list			large;
}					t_alloc;


t_alloc				g_ptr;

void				*malloc(size_t size);
t_alloc				*manage_alloc(size_t size);
void				*new_page(size_t size);

