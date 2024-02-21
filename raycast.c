/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaabi <akaabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:27:41 by akaabi            #+#    #+#             */
/*   Updated: 2024/02/21 12:39:42 by akaabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    draw_ray_2d(t_mlx *mlx, double angle, double distance, int color)
{
    double    x;
    double    y;
    int        t;

    t = 0;
    y = mlx->play->pos_y;
    x = mlx->play->pos_x;
    while (t < distance)
    {
        my_mlx_pixel_put(mlx, (int)x, (int)y, color);
        x += 1 * cos(angle);
        y += 1 * sin(angle);
        t++;
    }
}

float nor_angle(float angle)
{
 if (angle < 0)
  angle += (2 * M_PI);
 if (angle > (2 * M_PI))
  angle -= (2 * M_PI);
 return (angle);
}

int unit_circle(float angle, char c)
{
 if (c == 'x')
 {
  if (angle > 0 && angle < M_PI)
   return (1);
 }
 else if (c == 'y')
 {
  if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
   return (1);
 }
 return (0);
}

int wall_hit(float x, float y, t_mlx *mlx)
{
 int  x_m;
 int  y_m;

 if (x < 0 || y < 0)
  return (0);
    x_m = floor (x / TS);
    y_m = floor (y / TS);
    if ((y_m >= mlx->drct->height || x_m >= mlx->drct->Width))
        return (0);
    if (mlx->drct->map[y_m] && x_m <= (int)strlen(mlx->drct->map[y_m]))
    if (mlx->drct->map[y_m][x_m] == '1')
        return (0);
 return (1);
}

int inter_check(float angle, float *inter, float *step, int is_horizon)
{
 if (is_horizon)
 {
  if (angle > 0 && angle < M_PI)
  {
   *inter += TS;
   return (-1);
  }
  *step *= -1;
 }
 else
 {
  if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
  {
   *inter += TS;
   return (-1);
  }
  *step *= -1;
 }
 return (1);
}

float get_h_inter(t_mlx *mlx, float angl)
{
 float h_x;
 float h_y;
 float x_step;
 float y_step;
 int  pixel;

 y_step = TS;
 x_step = TS / tan(angl);
 h_y = floor(mlx->play->pos_y / TS) * TS;
 pixel = inter_check(angl, &h_y, &y_step, 1);
 h_x = mlx->play->pos_x + (h_y - mlx->play->pos_y) / tan(angl);
 if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0)) // check x_step value
  x_step *= -1;
 while (wall_hit(h_x, h_y - pixel, mlx)) // check the wall hit whit the pixel value
 {
  h_x += x_step;
  h_y += y_step;
 }
 return (sqrt(pow(h_x - mlx->play->pos_x, 2) + pow(h_y - mlx->play->pos_y, 2)));
}

float get_v_inter(t_mlx *mlx, float angl)
{
 float v_x;
 float v_y;
 float x_step;
 float y_step;
 int  pixel;

 x_step = TS; 
 y_step = TS * tan(angl);
 v_x = floor(mlx->play->pos_x / TS) * TS;
 pixel = inter_check(angl, &v_x, &x_step, 0); // check the intersection and get the pixel value
 v_y = mlx->play->pos_y + (v_x - mlx->play->pos_x) * tan(angl);
 if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0)) // check y_step value
  y_step *= -1;
 while (wall_hit(v_x - pixel, v_y, mlx)) // check the wall hit whit the pixel value
 {
  v_x += x_step;
  v_y += y_step;
 }
 return (sqrt(pow(v_x - mlx->play->pos_x, 2) + pow(v_y - mlx->play->pos_y, 2))); // get the distance
}


void cast_rays(t_mlx *mlx)
{
 double h_inter;
 double v_inter;
 int  ray;

 ray = 0;
 mlx->ray->ray_angle = mlx->play->angle - (mlx->play->radfov / 2); // the start angle
 while (ray < WIDTH)
 {
  h_inter = get_h_inter(mlx, nor_angle(mlx->ray->ray_angle));
  v_inter = get_v_inter(mlx, nor_angle(mlx->ray->ray_angle));
  if (v_inter <= h_inter)
   mlx->ray->wall_distance = v_inter;
  else
   mlx->ray->wall_distance = h_inter;
//   render_wall(mlx, ray); // render the wall
  draw_ray_2d(mlx ,mlx->play->angle, mlx->ray->wall_distance, 0xB99370FF);
    ray++; // next ray
    mlx->ray->ray_angle += (mlx->play->radfov / WIDTH);
 }
}
