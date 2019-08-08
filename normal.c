#include "rtv1.h"

t_vec cylinder_normal(t_mlx *mlx, t_obj *cyl,  t_vec pos, double t)
{
	double	m;
	t_vec	p;
	t_vec		norm;
	t_cylinder  *obj;

	(void)pos;
	obj = (t_cylinder * )cyl;
	m = ft_vecdot(mlx->ray_dir, obj->rot) * t + \
	ft_vecdot(ft_vecsub(mlx->cam_pos, obj->pos), obj->rot);
	p = ft_vecadd(mlx->cam_pos, ft_vecmult(mlx->ray_dir, t));
	norm = ft_vecsub(ft_vecsub(p, obj->pos), ft_vecmult(obj->rot, m));
	ft_vecnorm(&norm);

	return (norm);
}

t_vec cone_normal(t_mlx *mlx, t_obj *cone,  t_vec pos, double t)
{
	double	m;
	t_vec	p;
	t_vec		norm;
	t_cone  *obj;

	(void)pos;
	obj = (t_cone * )cone;
	m = ft_vecdot(mlx->ray_dir, obj->rot) * t + \
	ft_vecdot(ft_vecsub(mlx->cam_pos, obj->pos), obj->rot);
	p = ft_vecadd(mlx->cam_pos, ft_vecmult(mlx->ray_dir, t));
	norm = ft_vecsub(ft_vecsub(p, obj->pos), ft_vecmult(obj->rot, m));
	ft_vecnorm(&norm);

	return (norm);
}

t_vec plane_normal(t_mlx *mlx, t_obj *obj,  t_vec pos, double t)
{
	(void)mlx;
	(void)pos;
	(void)t;
	return (((t_plane *)obj)->rot);
}

t_vec sphere_normal(t_mlx *mlx, t_obj *obj,  t_vec pos, double t)
{
	(void)mlx;
	(void)t;
	return (ft_vecsub(pos, ((t_sphere *)obj)->pos));
}