/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:11:27 by zalkan            #+#    #+#             */
/*   Updated: 2023/02/26 16:11:30 by zalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

int		ft_n(char *s1);
char	*ft_strjooin(char *s1, char *s2);
int		ft_strllen(char *str);
char	*ft_new_line(char *str);
char	*ft_new_str(char *str);
char	*get_next_line(int fd);
char	*strappend(char **str, char *str2);

#endif
