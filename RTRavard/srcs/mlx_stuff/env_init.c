# include "rt.h"

static char		*get_buf(int *lc, int fd)
{
	char		*line;
	char		*buf;

	buf = ft_strnew(1);
	while (get_next_line(fd, &line) > 0 && (*lc)++ > -1)
		buf = ft_strjoint(buf, ft_strjoint(line, "\n", 'L'), 'B');
	if (close(fd) == -1)
		ft_error(FILE);
	free(line);
	return (buf);
}

static char		**get_scene(char *buf, int lc, int j)
{
	int			i;
	int			k;
	char		**scene;

	k = 0;
	if (!buf)
		ft_error(FILE);
	if (!(scene = (char**)malloc(sizeof(char*) * (lc + 1))))
		ft_error(MALLOC);
	while (buf[k] != '\0' && j < lc)
	{
		i = 0;
		if (!(scene[j] = (char*)malloc(sizeof(char) * linelen(buf, k))))
			ft_error(MALLOC);
		while (buf[k] != '\0' && buf[k] != '\n')
			scene[j][i++] = buf[k++];
		scene[j][i] = '\0';
		j++;
		k++;
	}
	free(buf);
	return (scene);
}

t_env		*env_init(char *file)
{
	t_env		*e;
	int			info[3];
	int			i;
	char		*buf;

	e = (t_env *)malloc(sizeof(t_env));
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, MAX_X, MAX_Y, "RT");
	e->img = mlx_new_image(e->ptr, MAX_X, MAX_Y);
	e->data_img = mlx_get_data_addr(e->img, info, info + 1, info + 2);
	e->c = NULL;
	i = -1;
	while (++i < 12)
		e->move[i] = 0;
	e->move[12] = 1;
	e->antialiasing = 0;
	buf = get_buf(&(e->lc), open_file(file));
	e->scene = get_scene(buf, e->lc, 0);
	e->l = NULL;
	e->o = NULL;
	e = parse(e);
	return (e);
}
