#include "rt.h"

float	*mat_prod(float *mp, float **mat, float *src)
{
	int		i;
	int		j;
	float		tmp[3];

	ft_memset(tmp, 0, sizeof(float) * 3);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			tmp[i] += mat[j][i] * src[j];
	}
	i = -1;
	while (++i < 3)
		mp[i] = tmp[i];
	return (mp);
}

/*
** on effectue la rotation de ez  de value radian par rapport a n
** et on stock le resultat dans ez
*/

int	rot(float *ez, float value, float *n)
{
	int		i;
	float		**rot;

	ft_norme(n);
	rot = (float **)malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
		rot[i] = (float *)malloc(sizeof(float) * 3);
	rot[0][0] = cos(value) + (1 - cos(value)) * (pow(n[0], 2));
	rot[0][1] = (1 - cos(value)) * (n[0] * n[1]) - sin(value) * (-n[2]);
	rot[0][2] = (1 - cos(value)) * (n[0] * n[2]) - sin(value) * (n[1]);
	rot[1][0] = (1 - cos(value)) * (n[0] * n[1]) - sin(value) * (n[2]);
	rot[1][1] = cos(value) + (1 - cos(value)) * (pow(n[1], 2));
	rot[1][2] = (1 - cos(value)) * (n[1] * n[2]) - sin(value) * (-n[0]);
	rot[2][0] = (1 - cos(value)) * (n[0] * n[2]) - sin(value) * (-n[1]);
	rot[2][1] = (1 - cos(value)) * (n[1] * n[2]) - sin(value) * (n[0]);
	rot[2][2] = cos(value) + (1 - cos(value)) * (pow(n[2], 2));
	mat_prod(ez, rot, ez);
	i = -1;
	while (++i < 3)
		free(rot[i]);
	free(rot);
	return(1);
}
