# include "rt.h"

int	main(int ac, char **av)
{
	t_env	*e;
	float	tmp[45];

if (ac != 2)
		ft_error(ARG);

/******************** DEBUG START ********************/
	vect_set(tmp, -500, -500, 2000); // cam pos
	vect_set(tmp + 3, 1, 1, 0); // cam dir
	vect_set(tmp + 6, 0, 0, 0); // plan pos
	vect_set(tmp + 9, 0, 0, 1); // plan nor
	vect_set(tmp + 12, 0, 0, 4000); // plan pos
	vect_set(tmp + 15, 0, 0, 1); // plan nor
	vect_set(tmp + 18, 2000, 0, 0); // plan pos
	vect_set(tmp + 21, -1, 0, 0); // plan nor
	vect_set(tmp + 24, -2000, 0, 0); // plan pos
	vect_set(tmp + 27, 1, 0, 0); // plan nor
	vect_set(tmp + 30, 0, 2000, 0); // plan pos
	vect_set(tmp + 33, 0, -1, 0); // plan nor
	vect_set(tmp + 36, 0, -2000, 0); // plan pos
	vect_set(tmp + 39, 0, 1, 0); // plan nor
	vect_set(tmp + 42, 0, 0, 2000); // sphere pos
/******************** DEBUG STOP ********************/

	e = env_init(av[1]);
	cam_init(e, tmp, tmp + 3);
/******************** DEBUG START ********************/
	plan_set(e, tmp + 6, tmp + 9, 0x00CC99);
	plan_set(e, tmp + 12, tmp + 15, 0xFF00CC);
	plan_set(e, tmp + 18, tmp + 21, 0xFF3300);
	plan_set(e, tmp + 24, tmp + 27, 0xFF3300);
	plan_set(e, tmp + 30, tmp + 33, 0);
	plan_set(e, tmp + 36, tmp + 39, 0);
	sphere_set(e, tmp + 42, 50, 0xFFFFFF);
/******************** DEBUG STOP ********************/
/******************** DEBUG START ********************/
	printf("CAMX = %f\n", CAMX);
	printf("CAMY = %f\n", CAMY);
	printf("CAMZ = %f\n", CAMZ);
	printf("CAMDX = %f\n", CAMDX);
	printf("CAMDY = %f\n", CAMDY);
	printf("CAMDZ = %f\n", CAMDZ);
	printf("LIGHT = %f\n", LIGHT);
	printf("ANTIALISING = %f\n", e->antialiasing);
/******************** DEBUG STOP ********************/
	loop(e);
	return (0);
}
