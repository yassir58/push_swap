/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:58:16 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/10 14:36:51 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#define BUFFER_SIZE 1
char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*try_get_line(char *str);
char	*extract_line(char **buffer, char **backup, char **line_return);
char	*get_rest_backup(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(const char *str, int len);
char	*ft_strchr(char *str, char c);
#endif
