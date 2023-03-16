/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:22:05 by eyagiz            #+#    #+#             */
/*   Updated: 2023/01/23 17:12:42 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_wall_texture(t_game *game, t_calc *calc)
{
	calc->lineheight = (int)(SCREEN_H / calc->perpwalldist);
	calc->drawstart = -calc->lineheight / 2 + SCREEN_H / 2;
	if (calc->drawstart < 0)
		calc->drawstart = 0;
	calc->drawend = calc->lineheight / 2 + SCREEN_H / 2;
	if (calc->drawend >= SCREEN_H)
		calc->drawend = SCREEN_H - 1;
	if (calc->raydirx > 0 && calc->side == 0)
		calc->texnum = NO;
	else if (calc->raydirx < 0 && calc->side == 0)
		calc->texnum = SO;
	else if (calc->raydiry > 0 && calc->side == 1)
		calc->texnum = WE;
	else
		calc->texnum = EA;
	if (calc->side == 0)
		calc->wallx = game->ray.posy + calc->perpwalldist * calc->raydiry;
	else
		calc->wallx = game->ray.posx + calc->perpwalldist * calc->raydirx;
	calc->wallx -= floor(calc->wallx);
	calc->texx = (int)(calc->wallx * (double)TEX_W);
	if (calc->side == 0 && calc->raydirx > 0)
		calc->texx = TEX_W - calc->texx - 1;
	if (calc->side == 1 && calc->raydiry < 0)
		calc->texx = TEX_W - calc->texx - 1;
}

void	input_wall_texture(int x, t_game *game, t_calc *calc)
{
	int		y;
	int		color;

	calc->step = 1.0 * TEX_H / calc->lineheight;
	calc->texpos = (calc->drawstart - SCREEN_H / 2 \
		+ calc->lineheight / 2) * calc->step;
	y = -1;
	while (++y < SCREEN_H)
	{
		if (y >= calc->drawstart && y <= calc->drawend)
		{
			calc->texy = (int)calc->texpos & (TEX_H - 1);
			calc->texpos += calc->step;
			color = game->texture[calc->texnum] \
				[TEX_H * calc->texy + calc->texx];
			if (calc->side == 1)
				color = (color >> 1) & 8355711;
			game->buf[y][x] = color;
		}
		else if (y < calc->drawstart)
			game->buf[y][x] = game->ceiling;
		else
			game->buf[y][x] = game->floor;
	}
}
