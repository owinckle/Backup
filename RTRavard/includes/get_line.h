/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 19:23:20 by owinckle          #+#    #+#             */
/*   Updated: 2017/04/03 19:23:21 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define GL_BUFF 42

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

int	get_next_line(const int fd, char **line);

#endif
