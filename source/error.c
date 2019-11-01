#include "lem-in.h"

/* Checks if there is an error given and exits the program with an error message */

void			error_check(int error)
{
	if (error < 0)
	{
		if (error == FD_ERROR)
			ft_printf("%s\n", strerror(errno));
		else if (error == ROOM_ERROR)
			ft_putendl("ROOM ERROR");
		else if (error == DUP_ERROR)
			ft_putendl("DUPLICATE ERROR");
		else if (error == ANTS_ERROR)
			ft_putendl("ANT ERROR");
		exit(-1);
	}
}
