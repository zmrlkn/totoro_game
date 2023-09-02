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

int	valid(t_win *map)
{
	recursive_c(map, map->chr->l_y, map->chr->l_x);
	if (coin_c(map) || exit_c(map))
	{
		ft_printf("Ulasilabilirlik hatası");
		return (1);
	}
	return (0);
}

void	recursive_c(t_win *ret, int y, int x)
{
	if (ret->map->mappin[y][x + 1] == '0' || ret->map->mappin[y][x + 1] == 'C')
	{
		ret->map->mappin[y][x + 1] = 'P';
		recursive_c(ret, y, x + 1);
	}
	if (ret->map->mappin[y][x - 1] == '0' || ret->map->mappin[y][x - 1] == 'C')
	{
		ret->map->mappin[y][x - 1] = 'P';
		recursive_c(ret, y, x - 1);
	}
	if (ret->map->mappin[y + 1][x] == '0' || ret->map->mappin[y + 1][x] == 'C')
	{
		ret->map->mappin[y + 1][x] = 'P';
		recursive_c(ret, y + 1, x);
	}
	if (ret->map->mappin[y - 1][x] == '0' || ret->map->mappin[y - 1][x] == 'C')
	{
		ret->map->mappin[y - 1][x] = 'P';
		recursive_c(ret, y - 1, x);
	}
}

int	coin_c(t_win *ret)
{
	int	y;
	int	x;

	y = 0;
	while (ret->map->mappin[y])
	{
		x = 0;
		while (ret->map->mappin[y][x] != 0 && ret->map->mappin[y][x] != '\n')
		{
			if (ret->map->mappin[y][x] == 'C')
			{
				ft_printf("HATA : Oyuncu toplanabilir eşyaya ulaşamıyor!");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	exit_c(t_win *ret)
{
	int	y;
	int	x;

	y = 0;
	while (ret->map->mappin[y] != 0)
	{
		x = 0;
		while (ret->map->mappin[y][x] != '\n')
		{
			if (ret->map->mappin[y][x] == 'E')
				break ;
			x++;
		}
		if (ret->map->mappin[y][x] == 'E')
			break ;
		y++;
	}
	if (ret->map->mappin[y][x + 1] == 'P' ||
		ret->map->mappin[y][x - 1] == 'P' ||
		ret->map->mappin[y + 1][x] == 'P' ||
		ret->map->mappin[y - 1][x] == 'P')
		return (0);
	ft_printf("HATA : Oyuncu çıkışa ulaşamıyor!");
	return (1);
}
