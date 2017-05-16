#include "FdF.h"

void	ft_error(int error)
{
	if(error == 1)
		write(1,"Invalid map name! Use: \"filename.fdf\".\n", 39);
	if(error == 2)
		write(1, "Invalid map!\n", 12);
	exit(error);

}

