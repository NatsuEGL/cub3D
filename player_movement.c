/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaabi <akaabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:43:33 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/24 17:47:03 by akaabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_reles(mlx_key_data_t keydata, t_mlx *mlx) // release the key
{
 if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
  mlx->play->lr_flag = 0;
 else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
  mlx->play->lr_flag = 0;
 else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
  mlx->play->ud_flag = 0;
 else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
  mlx->play->ud_flag = 0;
 else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
  mlx->play->r_flag = 0;
 else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
  mlx->play->r_flag = 0;
}

void mlx_key(mlx_key_data_t keydata, void *ml) // key press
{
 t_mlx *mlx;
  
 mlx = ml;
 if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) // exit the game
  exit(1);
 else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS)) // move left
  mlx->play->lr_flag = -1;
 else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS)) // move right
  mlx->play->lr_flag = 1;
 else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS)) // move down
	mlx->play->ud_flag = -1;
 else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) // move up
  mlx->play->ud_flag = 1;
 else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) // r_flagate left
  mlx->play->r_flag = -1;
 else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) // r_flagate right
  mlx->play->r_flag = 1;
 ft_reles(keydata, mlx); // release the key
}

void rotate_player(t_mlx *mlx, int i) // rotate the player
{
 if (i == 1)
 {
  mlx->play->angle += ROTATION_SPEED; // rotate right
  if (mlx->play->angle > 2 * M_PI)
   mlx->play->angle -= 2 * M_PI;
 }
 else
 {
  mlx->play->angle -= ROTATION_SPEED; // rotate left
  if (mlx->play->angle < 0)
   mlx->play->angle += 2 * M_PI;
 }
}

void calculate_move(t_mlx *mlx)
{
  
  float x;
  float y;
   if (mlx->play->r_flag == 1) //rotate right
  rotate_player(mlx, 1);
 if (mlx->play->r_flag == -1) //rotate left
  rotate_player(mlx, 0);
  if (mlx->play->ud_flag == 1)
  {
   x = cos(mlx->play->angle) * PS;
   y = sin(mlx->play->angle) * PS; 
  }
  if (mlx->play->ud_flag == -1)
  {
    x = -cos(mlx->play->angle) * PS;
    y = -sin(mlx->play->angle) * PS; 
  }
  if (mlx->play->lr_flag == 1)
  {
    x = -sin(mlx->play->angle) * PS;
    y = cos(mlx->play->angle) * PS;
  }
  if (mlx->play->lr_flag == -1)
  {
    x = sin(mlx->play->angle) * PS;
    y = -cos(mlx->play->angle) * PS;
  }
  move_player(mlx, x, y);
  
}

void move_player(t_mlx *mlx, float x, float y)
{
  int n_x;
  int n_y;
  int x_map;
  int y_map;
  
  n_x = roundf(mlx->play->pos_x + x);
  n_y = roundf(mlx->play->pos_y + y);
  x_map = (n_x / TS);
  y_map = (n_y / TS);
  if (mlx->drct->map[y_map][x_map] != '1' && mlx->drct->map[y_map][mlx->play->pos_x / TS] != '1' && mlx->drct->map[mlx->play->pos_y / TS][x_map] != '1')
  {
    mlx->play->pos_x = n_x;
    mlx->play->pos_y = n_y;
  }
}