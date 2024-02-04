/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: switt <switt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:27:19 by switt             #+#    #+#             */
/*   Updated: 2023/08/12 04:06:42 by switt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

char	*get_next_line(int fd);
char	*ft_update_static(char *str);
char	*ft_extract_line(char *str);
char	*ft_read_all(int fd, char *str);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int f);
char	*ft_strjoin(char *readstr, char *buffer);

#endif
