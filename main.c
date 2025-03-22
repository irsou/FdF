#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		write(1, "Error: one argument expected.\n",32);
		return (1);
	map = parse_file(argv[1]);
	if (!map)
	{
		perror("File couldn't be read.");
		return(1);
	}
	//render_map(map);
	//free_map(map);
}