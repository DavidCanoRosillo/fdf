/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro < dcano-ro@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:47:59 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/09/27 13:05:39 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		pbits;	//bits per pixel
	int		llength; //line length	
	int		e; // endian
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->llength + x * (data->pbits / 8));
	*(unsigned int *)dst = color;
}

void	rectangle(t_data img, int x, int y, int side1, int side2)
{
	int i;
	int	j;

	i = 0;
	while (i < side1)
	{
		my_mlx_pixel_put(&img, x + i, y, 0x00FFFFFF);
		my_mlx_pixel_put(&img, x + i, y + side2, 0x00FFFFFF);
		i++;
	}
	j = 0;
	while (j < side2)
	{
		my_mlx_pixel_put(&img, x, y + j, 0x00FFFFFF);
		my_mlx_pixel_put(&img, x + side1, y + j, 0x00FFFFFF);
		j++;
	}	
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;
	
	// init mlx
	mlx = mlx_init();
	// create new image
	img.img = mlx_new_image(mlx, 500, 500);
	// get address of image, bits per pixel, line length 
	img.addr = mlx_get_data_addr(img.img, &img.pbits, &img.llength, &img.e);

	// call drawing
	rectangle(img, 250, 100, 60, 300);

	// create window
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	// push image to window and loop
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
