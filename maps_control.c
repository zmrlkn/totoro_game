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

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	player_control(t_win *pnc)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (pnc->map->mappin[i])
	{
		j = 0;
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'P')
			{
				pnc->chr->l_x = j;
				pnc->chr->l_y = i;
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		ft_printf("haritada player yok yada 1 den fazla var\n");
		close_frame(pnc);
	}
}

void	wall_control(t_win *pnc)
{
	int	i;
	int	last;

	i = -1;
	while (pnc->map->mappin[0][++i])
	{
		if (pnc->map->mappin[0][i] != '1' ||
			pnc->map->mappin[pnc->map->h - 1][i] != '1')
		{
			ft_printf("Duvar Hatası\n");
			close_frame(pnc);
		}
	}
	i = -1;
	last = pnc->map->w - 1;
	while (pnc->map->mappin[++i])
	{
		if (pnc->map->mappin[i][0] != '1' || pnc->map->mappin[i][last] != '1')
		{
			ft_printf("Duvar Hatası\n");
			close_frame(pnc);
		}
	}
}

void	map_size_control(t_win *pnc)
{
	int	i;
	int	len;
	int	error_found;

	i = 0;
	len = pnc->map->w;
	error_found = 0;
	while (pnc->map->mappin[i])
	{
		if (str_len(pnc->map->mappin[i]) != len)
		{
			error_found = 1;
			break ;
		}
		i++;
	}
	if (error_found)
	{
		ft_printf("Harita satırında eksik yer bulunyor\n");
		close_frame(pnc);
	}
}

void	end_control(t_win *pnc)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (pnc->map->mappin[++i])
	{
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'E')
			{
				pnc->map->end_cnt = pnc->map->end_cnt + 1;
			}
		}
		j = 0;
	}
	if (pnc->map->end_cnt != 1)
	{
		ft_printf("Haritada cikis yok veya 1 den fazla var\n");
		close_frame(pnc);
	}
}
