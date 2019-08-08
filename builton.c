#include "rtv1.h"


void temporary_builton(t_mlx *mlx)
{
	t_old *tmp  = mlx->old;
	t_obj **obj = &mlx->obj;

//	t_sphere *s;
//	t_sphere *p;

	while (tmp)
	{
		if (tmp->type == PLANE)
		{
			*obj = create_plane();
			((t_plane *)*obj)->type = tmp->type;
			((t_plane *)*obj)->color = tmp->color;
			((t_plane *)*obj)->intensity = tmp->intensity;
			((t_plane *)*obj)->pos = tmp->pos;
			((t_plane *)*obj)->refl = tmp->refl;
			((t_plane *)*obj)->rot = tmp->rot;
			((t_plane *)*obj)->size = tmp->size;
			((t_plane *)*obj)->spec = tmp->spec;
		}
		else if (tmp->type == SPHERE)
		{
			*obj = create_sphere();
			((t_sphere *)*obj)->type = 2;
			((t_sphere *)*obj)->color = tmp->color;
			((t_sphere *)*obj)->intensity = tmp->intensity;
			((t_sphere *)*obj)->pos = tmp->pos;
			((t_sphere *)*obj)->refl = tmp->refl;
			((t_sphere *)*obj)->rot = tmp->rot;
			((t_sphere *)*obj)->size = tmp->size;
			((t_sphere *)*obj)->spec = tmp->spec;
		}
		else if (tmp->type == CONE)
		{
			*obj = create_cone();
			((t_plane *)*obj)->type = tmp->type;
			((t_plane *)*obj)->color = tmp->color;
			((t_plane *)*obj)->intensity = tmp->intensity;
			((t_plane *)*obj)->pos = tmp->pos;
			((t_plane *)*obj)->refl = tmp->refl;
			((t_plane *)*obj)->rot = tmp->rot;
			((t_plane *)*obj)->size = tmp->size;
			((t_plane *)*obj)->spec = tmp->spec;
		}
		else if (tmp->type == CYLINDER)
		{
			*obj = create_cylinder();
			((t_plane *)*obj)->type = tmp->type;
			((t_plane *)*obj)->color = tmp->color;
			((t_plane *)*obj)->intensity = tmp->intensity;
			((t_plane *)*obj)->pos = tmp->pos;
			((t_plane *)*obj)->refl = tmp->refl;
			((t_plane *)*obj)->rot = tmp->rot;
			((t_plane *)*obj)->size = tmp->size;
			((t_plane *)*obj)->spec = tmp->spec;
		}
		(*obj)->next = NULL;
		obj = &(*obj)->next;
		tmp = tmp->next;
	}
}