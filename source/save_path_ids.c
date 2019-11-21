/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path_ids.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:14:43 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/21 16:26:31 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		path_counter(t_link *paths)
{
	int	i;

	i = 1;
	while (paths->next)
	{
		i++;
		paths = paths->next;
	}
	return (i);
}

int		path_length(t_room *room)
{
	int	i;

	i = 1;
	while (room->to)
	{
		i++;
		room = room->to;
	}
	return (i);
}

void	write_path(t_room *room, int *path_ids, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		path_ids[i] = room->id;
		i++;
		if (room->to)
			room = room->to;
	}
}

/*
** @descr: Saves the id values of every path in a 2d int array.
*/

int		**save_path_ids(t_link *paths)
{
	int	i;
	int	path_len;
	int	path_count;
	int	**path_ids;
	// del this
	int j = 0;
	t_room *room;

	i = 0;
	path_count = path_counter(paths);
	path_ids = (int**)ft_memalloc(sizeof(int*) * (path_count + 1));
	while (paths)
	{
		path_len = paths->on;
		path_ids[i] = (int*)ft_memalloc(sizeof(int) * path_len);
		room = paths->ptr;
		// del here
		while (j < path_len)
		{
			path_ids[i][j] = room->id;
		//	ft_printf("%d ", path_ids[i][j]);
			j++;
			if (room->to)
				room = room->to;
		}
		//ft_printf("\n--------------------------------------------------------\n");
		j = 0;
		//write_path(paths->ptr, path_ids[i], path_len);
		i++;
		if (!paths->next)
			break ;
		paths = paths->next;
	}
	path_ids[i] = 0;
	return (path_ids);
}
