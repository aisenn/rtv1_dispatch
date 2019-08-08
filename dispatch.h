#ifndef DISPATCH_H
# define DISPATCH_H

# include "libft/includes/libft.h"
# include "libavec/libavec.h"
# include "libvec/libvec.h"
//#include "rtv1.h"

# include <stdio.h>//

typedef enum		e_type
{
	POINT,
	AMBIENT,
	DIRECT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}					t_type;

typedef struct								s_old
{
	const struct s_obj_interface *const		vtable;
	struct s_old							*next;
}											t_old;

typedef struct								s_obj_interface
{
	int										(*intersect)(t_old *);
	int										(*normal)(t_old *);
}											t_obj_interface;

static inline int							obj_intersect(t_old *s)
{
	return (s->vtable->intersect(s));
}

static inline int							obj_normal(t_old *s)
{
	return (s->vtable->normal(s));
}

/*
**------------------------------Sphere_start---------------------------------
*/

typedef struct								s_sphere
{
	t_old									base;

	int										type;
	t_vector								pos;
	t_vector								rot;
	t_vector								color;
	double									size;
	double									intensity;
	int										spec;
	double									refl;
//	struct s_old							*next;
}											t_sphere;

static int									sphere_intersect(t_old *s)
{
	return (SPHERE);
}

static int									sphere_normal(t_old *s)
{
	return (SPHERE);
}

#define SPHERE_VTABLE {sphere_intersect, sphere_normal}

t_old										*create_sphere(void)
{
	t_sphere								*sa;
	static const t_obj_interface			vtable = SPHERE_VTABLE;
	static t_old							base = { &vtable };

	sa = (t_sphere *)malloc(sizeof(*sa));
	ft_memcpy(&sa->base, &base, sizeof(t_old));
	return (&sa->base);
}

/*
**------------------------------Plane_start---------------------------------
*/

typedef struct								s_plane
{
	t_old									base;

	int										type;
	t_vector								pos;
	t_vector								rot;
	t_vector								color;
	double									size;
	double									intensity;
	int										spec;
	double									refl;

//	struct s_old							*next;
}											t_plane;

static int									plane_intersect(t_old *s)
{
	return (PLANE);
}

t_vec									plane_normal(t_old *s);

#define PLANE_VTABLE {plane_intersect, plane_normal}

t_old										*create_plane(void)
{
	t_plane									*sa;
	static const t_obj_interface			vtable = PLANE_VTABLE;
	static t_old							base = { &vtable };

	sa = (t_plane *)malloc(sizeof(*sa));
	ft_memcpy(&sa->base, &base, sizeof(t_old)); // sizeof(t_old) ???
//	sa->idx = 0;
	return (&sa->base);
}

/*
**------------------------------Cylinder_start---------------------------------
*/

typedef struct								s_cylinder
{
	t_old									base;

	int										type;
	t_vector								pos;
	t_vector								rot;
	t_vector								color;
	double									size;
	double									intensity;
	int										spec;
	double									refl;

//	struct s_old							*next;
}											t_cylinder;

/*static int									cylinder_intersect(t_old *s)
{
	return (PLANE);
}*/

static int									cylinder_normal(t_old *s)
{
	return (PLANE);
}

#define CYLINDER_VTABLE {cylinder_intersect, cylinder_normal}

t_old										*create_cylinder(void)
{
	t_plane									*sa;
	static const t_obj_interface			vtable = CYLINDER_VTABLE;
	static t_old							base = { &vtable };

	sa = (t_plane *)malloc(sizeof(*sa));
	ft_memcpy(&sa->base, &base, sizeof(t_old)); // sizeof(t_old) ???
	return (&sa->base);
}

/*
**------------------------------Cone_start---------------------------------
*/

typedef struct								s_cone
{
	t_old									base;

	int										type;
	t_vector								pos;
	t_vector								rot;
	t_vector								color;
	double									size;
	double									intensity;
	int										spec;
	double									refl;

//	struct s_old							*next;
}											t_cone;

/*static int									cone_intersect(t_old *s)
{
	return (PLANE);
}*/

static int									cone_normal(t_old *s)
{
	return (PLANE);
}

#define CONE_VTABLE {cone_intersect, cone_normal}

t_old										*create_cone(void)
{
	t_plane									*sa;
	static const t_obj_interface			vtable = CONE_VTABLE;
	static t_old							base = { &vtable };

	sa = (t_plane *)malloc(sizeof(*sa));
	ft_memcpy(&sa->base, &base, sizeof(t_old)); // sizeof(t_old) ???
	return (&sa->base);
}

#endif
