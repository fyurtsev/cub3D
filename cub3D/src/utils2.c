/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:07:00 by eyagiz            #+#    #+#             */
/*   Updated: 2023/01/23 18:12:40 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_leftright(t_game *game)
{
	if (game->key_a)
	{
		if (game->map[(int)(game->ray.posx - 1 * game->ray.diry * game->msad)] \
			[(int)(game->ray.posy)] != '1')
			game->ray.posx = game->ray.posx - 1 * game->ray.diry * game->msad;
		if (game->map[(int)(game->ray.posx)] \
			[(int)(game->ray.posy + 1 * game->ray.dirx * game->msad)] != '1')
			game->ray.posy = game->ray.posy + 1 * game->ray.dirx * game->msad;
	}
	if (game->key_d)
	{
		if (game->map[(int)(game->ray.posx + 1 * game->ray.diry * game->msad)] \
			[(int)(game->ray.posy)] != '1')
			game->ray.posx = game->ray.posx + 1 * game->ray.diry * game->msad;
		if (game->map[(int)(game->ray.posx)] \
			[(int)(game->ray.posy - 1 * game->ray.dirx * game->msad)] != '1')
			game->ray.posy = game->ray.posy - 1 * game->ray.dirx * game->msad;
	}
}
