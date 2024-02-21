/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaabi <akaabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:30:29 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/21 13:38:29 by akaabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void creat_window(t_direct *direct)
{
	t_mlx	mlx;
	
	mlx.drct = direct;
	mlx.play = ft_calloc(1, sizeof(t_player));
	mlx.ray = ft_calloc(1, sizeof(t_ray));
	mlx.mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", 0);
	creat_player(mlx);
	mlx_loop_hook(mlx.mlx, &map_loop, &mlx);
	mlx_key_hook(mlx.mlx, &mlx_key , &mlx);
	mlx_loop(mlx.mlx);
	
}

void creat_player(t_mlx mlx)
{
	mlx.play->pos_x = mlx.drct->p_x * TS - TS / 2;
	mlx.play->pos_y = mlx.drct->p_y * TS - TS / 2;
	mlx.play->radfov = (FOV * M_PI) / 180;
	mlx.play->angle = M_PI / 2;
}


void map_loop(void * m)
{
	t_mlx *mlx;

	mlx = m;
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	draw_2d_map(mlx);
	calculate_move(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	cast_rays(mlx);
}

void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
 if (x < 0) 
  return ;
 else if (x >= WIDTH)
  return ;
 if (y < 0)
  return ;
 else if (y >= HEIGHT)
  return ;
 mlx_put_pixel(mlx->img, x, y, color);
}

void	draw_2d_map(t_mlx *mlx)
{
	int x,i,j,y = 0;

	y = 0;
	while(mlx->drct->map[y])
	{
		x = 0;
		while(mlx->drct->map[y][x])
		{
			if(mlx->drct->map[y][x] == '1')
			{
				i = 0;
				while(i < TS - 1)
				{
					j = 0;
					while(j < TS - 1)
					{
						my_mlx_pixel_put(mlx, x * TS + j,  y * TS + i, 0xB99470FF);
						j++;
					}
						my_mlx_pixel_put(mlx, x * TS + j,  y * TS + i, 0xB1111);
					i++;
				}
					my_mlx_pixel_put(mlx, x * TS + j,  y * TS + i, 0xB1111);
			}
			else
			{
				i = 0;
				while(i < TS -1 )
				{
					j = 0;
					while(j < TS - 1)
					{
						my_mlx_pixel_put(mlx, x * TS + j,  y * TS + i, 0xff);
						j++;
					}
						my_mlx_pixel_put(mlx, x * TS + j,  y * TS + i, 0xB1111);
					i++;
				}
					my_mlx_pixel_put(mlx, x * TS + j,  y * TS + i, 0xB1111);
			}
			x++;
		}
		y++;
	}
	draw_player(mlx, mlx->play->pos_x, mlx->play->pos_y, 0xF5F5F5FF);
}

void	draw_player(t_mlx *mlx, int x_p, int y_p, int color)
{
	int		x;
	int		y;
	int		r;

	r = TS / 5;
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (pow(x, 2) + pow(y, 2) <= pow(r, 2))
				my_mlx_pixel_put(mlx, x_p + x, y_p + y, color);
			x++;
		}
		y++;
	}
}