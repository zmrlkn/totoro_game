/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ultils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:02:04 by zalkan            #+#    #+#             */
/*   Updated: 2023/02/18 16:02:06 by zalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_win *pnc, int x, int y)
{
	pnc->height = pnc->map->h * 64;
	pnc->width = pnc->map->w * 64;
	pnc->mlx = mlx_init();
	pnc->win = mlx_new_window(pnc->mlx, pnc->width, pnc->height, "Totoro");
	pnc->chr = ft_calloc(1, sizeof(t_char));
	pnc->chr->l_x = 0;
	pnc->chr->l_y = 0;
	pnc->chr->point = 0;
	pnc->chr->chr_front = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/front_char.xpm", &x, &y);
	pnc->chr->chr_back = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/back_char.xpm", &x, &y);
	pnc->chr->chr_right = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/right_char.xpm", &x, &y);
	pnc->chr->chr_left = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/left_char.xpm", &x, &y);
	pnc->chr->chr_cur = pnc->chr->chr_front;
	pnc->img_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/bg.xpm", &x, &y);
	pnc->block_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/block.xpm", &x, &y);
	pnc->c_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/coin.xpm", &x, &y);
	pnc->end_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/endgate.xpm", &x, &y);
}

void	open_windows(t_win *pnc, char *path)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	pnc->map = read_map(path);
	get_img(pnc, x, y);
	player_control(pnc);
	map_size_control(pnc);
	wall_control(pnc);
	end_control(pnc);
	coin_control(pnc);
	char_control(pnc);
}

int	close_frame(void *param)
{
	t_win	*pnc;
	int		i;

	pnc = param;
	i = 0;
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_front);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_back);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_right);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_left);
	mlx_destroy_image(pnc->mlx, pnc->c_bg);
	mlx_destroy_image(pnc->mlx, pnc->end_bg);
	mlx_destroy_image(pnc->mlx, pnc->block_bg);
	mlx_destroy_image(pnc->mlx, pnc->img_bg);
	free(pnc->chr);
	while (pnc->map->mappin[i])
		free(pnc->map->mappin[i++]);
	free(pnc->map->mappin);
	free(pnc->map);
	mlx_destroy_window(pnc->mlx, pnc->win);
	system("leaks so_long");
	exit(1);
	return (1);
}

int	close_frame_two(void *param)
{
	t_win	*pnc;
	int		i;

	pnc = param;
	i = 0;
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_front);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_back);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_right);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_left);
	mlx_destroy_image(pnc->mlx, pnc->c_bg);
	mlx_destroy_image(pnc->mlx, pnc->end_bg);
	mlx_destroy_image(pnc->mlx, pnc->block_bg);
	mlx_destroy_image(pnc->mlx, pnc->img_bg);
	free(pnc->chr);
	while (pnc->map->mappin[i])
		free(pnc->map->mappin[i++]);
	free(pnc->map->mappin);
	free(pnc->map);
	mlx_destroy_window(pnc->mlx, pnc->win);
	return (1);
}

int	main(int argc, char **argv)
{
	t_win	pnc;

	if (argc == 2)
	{
		xpm_control();
		xpm_control_two();
		path_checker(argv[1]);
		file_control(argv[1]);
		open_windows(&pnc, argv[1]);
		if (valid(&pnc))
			close_frame(&pnc);
		free_map(&pnc);
		readmapp(&pnc, argv[1]);
		render_map(&pnc);
		mlx_hook(pnc.win, 2, (1L << 0), walk, &pnc);
		mlx_hook(pnc.win, 17, 0, close_frame, &pnc);
		mlx_loop(pnc.mlx);
	}
	else
	{
		ft_printf("Eksik arguman girildi");
	}
	return (0);
}
