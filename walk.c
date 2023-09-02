/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:17:44 by zalkan            #+#    #+#             */
/*   Updated: 2022/12/28 17:22:45 by zalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	putchr(t_win *pnc, int keycode)
{
	if (keycode == 2)
		pnc->chr->chr_cur = pnc->chr->chr_right;
	else if (keycode == 0)
		pnc->chr->chr_cur = pnc->chr->chr_left;
	else if (keycode == 13)
		pnc->chr->chr_cur = pnc->chr->chr_back;
	else if (keycode == 1)
		pnc->chr->chr_cur = pnc->chr->chr_front;
}

void	print_score(t_win *pnc)
{
	ft_printf("%d\n", pnc->chr->point);
}

void	move_p(t_win *pnc, int side, int x, int y)
{
	int	current_x;
	int	current_y;

	current_x = pnc->chr->l_x;
	current_y = pnc->chr->l_y;
	if (pnc->map->cb == 0 && pnc->map->mappin[y / 64][x / 64] == 'E')
	{
		pnc->chr->point += 1;
		print_score(pnc);
		ft_printf("Totoro Şemsiyesine Kavuştu!", 30);
		close_frame(pnc);
	}
	else if (pnc->map->mappin[y / 64][x / 64] != '1'
			&& pnc->map->mappin[y / 64][x / 64] != 'E')
	{
		putchr(pnc, side);
		pnc->chr->point += 1;
		if (pnc->map->mappin[y / 64][x / 64] == 'C')
			pnc->map->cb -= 1;
		pnc->map->mappin[current_y / 64][current_x / 64] = '0';
		pnc->map->mappin[y / 64][x / 64] = 'P';
		pnc->chr->l_x = x;
		pnc->chr->l_y = y;
		print_score(pnc);
	}
}

int	walk(int keycode, void *param)
{
	int		new_y;
	int		new_x;
	t_win	*pnc;

	pnc = param;
	mlx_clear_window(pnc->mlx, pnc->win);
	new_x = pnc->chr->l_x;
	new_y = pnc->chr->l_y;
	if (keycode == 2)
		new_x += 64;
	else if (keycode == 0)
		new_x -= 64;
	else if (keycode == 13)
		new_y -= 64;
	else if (keycode == 1)
		new_y += 64;
	else if (keycode == 53)
		close_frame(pnc);
	if (keycode == 1 || keycode == 13 || keycode == 0 || keycode == 2)
		move_p(pnc, keycode, new_x, new_y);
	render_map(pnc);
	return (keycode);
}

void	readmapp(t_win *pnc, char *path)
{
	pnc->map = read_map(path);
}

int free_map(void *param)
{
	t_win	*pnc;
	int		i;

	pnc = param;
	i = 0;
	while (pnc->map->mappin[i])
		free(pnc->map->mappin[i++]);
	free(pnc->map->mappin);
	free(pnc->map);
	return(1);
}