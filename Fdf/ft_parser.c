#include "FdF.h"

t_point_lst		*create_node(t_all *all, char *split)
{
	t_point_lst *ret;
	int color;

	ret = malloc(sizeof(t_point_lst));
	ret->point.x = all->step.x;
	ret->point.y = all->step.y;
	if (!ft_isdigit((*split)) && *split != '-')
		return (NULL);
	ret->point.z = ft_atoi(split);
	if (ret->point.z > all->max_depth)
		all->max_depth = ret->point.z;
	if (ret->point.z < all->min_depth)
		all->min_depth = ret->point.z;
	color = ft_strtol(split);
	if (ret->point.z > 1)
		ret->point.z *= 3;//////////////DOOO SOMETHING
	ret->next_x = NULL;
	ret->next_y = NULL;
	ret->point.color = get_rgb(ret, color);
	all->step.x++;
	return (ret);
}

t_point_lst		*create_line(t_all *all, char **split)
{
	t_point_lst *ret;
	t_point_lst *ptr;

	ret = create_node(all, split[all->step.x]);
	ptr = ret;
	while (ptr != NULL && split[all->step.x] != NULL)
	{
		ptr->next_x = create_node(all, split[all->step.x]);
		ptr = ptr->next_x;
	}
	all->width = all->step.x;
	all->step.x = 0;
	return (ret);
}

t_point_lst *link_line(t_point_lst *line1, t_point_lst *line2)
{
	t_point_lst *ret;

	ret = line2;
	line1 = line1->next_x;
	line2 = line2->next_x;
	while (line1 != NULL && line2 != NULL)
	{
		line1->next_y = line2;
		line1 = line1->next_x;
		line2 = line2->next_x;
	}
	return (ret);
}

void		ft_parser(char **av, t_all *all)
{
	int 		fd;
	char 		*str;
	char 		**split;
	t_point_lst *ptr;
	t_point_lst *prev;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error(1);
	get_next_line(fd, &str);
	split = ft_strsplit(str, ' ');
	all->map = create_line(all, split);
	if (all->map == NULL)
		ft_error(2);
	free_split(split);
	ptr = all->map;
	prev = ptr;
	while (get_next_line(fd, &str) > 0 )
	{
		all->step.y++;
		split = ft_strsplit(str, ' ');
		ptr->next_y = create_line(all, split);
		free_split(split);
		ptr = ptr->next_y;
		prev = link_line(prev, ptr);
	}
	all->height = all->step.y;
	if (all->height == 0 && all->width >= 1)
		all->height = 1;
}



