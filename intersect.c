/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:00:34 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 22:00:46 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	solve_quadratic(double a, double b, double c)
{
	double		t1;
	double		t2;
	double		discriminant;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0001)
		return (-1);
	discriminant = sqrt(discriminant);
	t1 = (-b + discriminant) / (2 * a);
	t2 = (-b - discriminant) / (2 * a);
	if (t1 > t2)
		t1 = t2;
	return (t1);
}

double			sphere_intersect(t_vec origin, t_vec direction, t_obj *obj)
{
	t_vec		oc;
	double		a;
	double		b;
	double		c;
	t_sphere	*sphere;

	sphere = (t_sphere *)obj;
	oc = ft_vecsub(origin, sphere->pos);
	a = ft_vecdot(direction, direction);
	b = 2 * ft_vecdot(oc, direction);
	c = ft_vecdot(oc, oc) - sphere->size * sphere->size;
	return (solve_quadratic(a, b, c));
}

double			cylinder_intersect(t_vec origin, t_vec dir, t_obj *obj)
{
	t_vec		oc;
	double		a;
	double		b;
	double		c;
	t_cylinder	*cyl;

	cyl = (t_cylinder *)obj;
	oc = ft_vecsub(origin, cyl->pos);
	ft_vecnorm(&cyl->rot);
	a = ft_vecdot(dir, dir) - pow(ft_vecdot(dir, cyl->rot), 2);
	b = 2 * (ft_vecdot(dir, oc) - (ft_vecdot(dir, cyl->rot) \
		* ft_vecdot(oc, cyl->rot)));
	c = ft_vecdot(oc, oc) - pow(ft_vecdot(oc, cyl->rot), 2) - pow(cyl->size, 2);
	return (solve_quadratic(a, b, c));
}

double			cone_intersect(t_vec origin, t_vec dir, t_obj *obj)
{
	t_vec		oc;
	double		a;
	double		b;
	double		c;
	t_cone	*cone;

	cone = (t_cone *)obj;
	oc = ft_vecsub(origin, cone->pos);
	ft_vecnorm(&cone->rot);
	a = ft_vecdot(dir, dir) - (1 + pow(tan(cone->size), 2)) *
							  pow(ft_vecdot(dir, cone->rot), 2);
	b = 2 * (ft_vecdot(dir, oc) - (1 + pow(tan(cone->size), 2)) *
								  ft_vecdot(dir, cone->rot) * ft_vecdot(oc, cone->rot));
	c = ft_vecdot(oc, oc) - (1 + pow(tan(cone->size), 2)) *
							pow(ft_vecdot(oc, cone->rot), 2);
	return (solve_quadratic(a, b, c));
}

double			plane_intersect(t_vec origin, t_vec dir, t_obj *obj)
{
	double		t;
	t_vec		oc;
	t_plane		*plane;

	plane = (t_plane *)obj;
	oc = ft_vecsub(origin, plane->pos);
	t = ft_vecdot(ft_vectransfor(oc), plane->rot) / ft_vecdot(dir, plane->rot);
	if (t < 0.0001)
		return (-1);
	return (t);
}
