#include "rtv1.h"

double						obj_intersect(t_vec origin, t_vec dir, t_obj *s)
{
	return (s->vtable->intersect(origin, dir, s));
}

t_vec							obj_normal(t_mlx *mlx, t_obj *s, t_vec pos, double t)
{
	return (s->vtable->normal(mlx, s, pos, t));
}

/*
**------------------------------Sphere_start---------------------------------
*/
#define SPHERE_VTABLE {sphere_intersect, sphere_normal}

t_obj										*create_sphere(void)
{
	t_sphere								*sa;
	static const t_obj_interface			vtable = SPHERE_VTABLE;
	static t_obj							base = { &vtable };

	sa = (t_sphere *)malloc(sizeof(*sa));
	ft_memcpy(&sa->base, &base, sizeof(t_obj));
	return (&sa->base);
}

/*
**------------------------------Plane_start---------------------------------
*/
#define PLANE_VTABLE {plane_intersect, plane_normal}

t_obj										*create_plane(void)
{
	t_plane									*sa;
	static const t_obj_interface			vtable = PLANE_VTABLE;
	static t_obj							base = { &vtable };

	sa = (t_plane *)malloc(sizeof(*sa));
	ft_memcpy(&sa->base, &base, sizeof(t_obj));
	return (&sa->base);
}

/*
**------------------------------Cylinder_start---------------------------------
*/
#define CYLINDER_VTABLE {cylinder_intersect, cylinder_normal}

t_obj										*create_cylinder(void)
{
	t_plane									*sa;
	static const t_obj_interface			vtable = CYLINDER_VTABLE;
	static t_obj							base = { &vtable };

	sa = (t_plane *)malloc(sizeof(*sa));
	ft_memcpy(&sa->base, &base, sizeof(t_obj));
	return (&sa->base);
}

/*
**------------------------------Cone_start---------------------------------
*/
#define CONE_VTABLE {cone_intersect, cone_normal}

t_obj										*create_cone(void)
{
	t_plane									*sa;
	static const t_obj_interface			vtable = CONE_VTABLE;
	static t_obj							base = { &vtable };

	sa = (t_plane *)malloc(sizeof(*sa));
	ft_memcpy(&sa->base, &base, sizeof(t_obj));
	return (&sa->base);
}
