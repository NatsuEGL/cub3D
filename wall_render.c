/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaabi <akaabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:37:25 by akaabi            #+#    #+#             */
/*   Updated: 2024/02/25 11:44:40 by akaabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float norm_angle(float angle) // normalize the angle
{
    if (angle < 0)
        angle += (2 * M_PI);
    if (angle > (2 * M_PI))
        angle -= (2 * M_PI);
    return (angle);
}

void draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
{
    int  i;

    i = b_pix;
    while (i < HEIGHT)
     my_mlx_pixel_put(mlx, ray, i++, 0xB99470FF); // floor
    i = 0;
    while (i < t_pix)
     my_mlx_pixel_put(mlx, ray, i++, 0x89CFF3FF); // ceiling
}

int get_color(t_mlx *mlx, int flag) // get the color of the wall
{
 mlx->ray->ray_angle = norm_angle(mlx->ray->ray_angle); // normalize the angle
 if (flag == 0)
 {
  if (mlx->ray->ray_angle > M_PI / 2 && mlx->ray->ray_angle < 3 * (M_PI / 2))
   return (0xB5B5B5FF); // west wall
  else
   return (0xB5B5B5FF); // east wall
 }
 else
 {
  if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < M_PI)
   return (0xF5F5F5FF); // south wall
  else
   return (0xF5F5F5FF); // north wall
 }
}

void draw_wall(t_mlx *mlx, int ray, int t_pix, int b_pix) // draw the wall
{
 int color;

 color = get_color(mlx, mlx->ray->flag);
 while (t_pix < b_pix)
  my_mlx_pixel_put(mlx, ray, t_pix++, color);
}

void render_wall(t_mlx *mlx, int ray) // render the wall
{
 double wall_h;
 double b_pix;
 double t_pix;

 mlx->ray->wall_distance *= cos(norm_angle(mlx->ray->ray_angle - mlx->play->angle)); // fix the fisheye
 wall_h = (TS / mlx->ray->wall_distance) * ((WIDTH / 2) / tan(mlx->play->radfov / 2)); // get the wall height
 b_pix = (HEIGHT / 2) + (wall_h / 2); // get the bottom pixel
 t_pix = (HEIGHT / 2) - (wall_h / 2); // get the top pixel
 if (b_pix > HEIGHT) // check the bottom pixel
  b_pix = HEIGHT;
 if (t_pix < 0) // check the top pixel
  t_pix = 0;
 draw_wall(mlx, ray, t_pix, b_pix); // draw the wall
 draw_floor_ceiling(mlx, ray, t_pix, b_pix); // draw the floor and the ceiling
}