#include <stdio.h>
// // this function is used to print the error message and exit the program
// while(get_next_line(fd, &matrix))
// 	{
// 		if (matrix[0][0] == 'R')
// 			read_resolution(matrix);
// 		else if (matrix[0][0] == 'N')
// 			read_north(matrix);
// 		else if (matrix[0][0] == 'S')
// 			read_south(matrix);
// 		else if (matrix[0][0] == 'W')
// 			read_west(matrix);
// 		else if (matrix[0][0] == 'E')
// 			read_east(matrix);
// 		else if (matrix[0][0] == 'F')
// 			read_floor(matrix);
// 		else if (matrix[0][0] == 'C')
// 			read_ceiling(matrix);
// 		else if (matrix[0][0] == ' ')
// 			read_map(matrix);
// 		else
// 			error_msg("Error\n");
// 	}
//     close(fd);
//     return (0);
// }
// /*
//     this function is used to read the resolution of the map
//     the resolution is the size of the map file in pixels (width and height) and is specified by the R command in the map filename. 
//     the resolution is specified by two integers separated by a space.
//     the first integer is the width and the second integer is the height.
//     the resolution must be at least 200x200 pixels.
// */
// int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
// {
// 	double deltaX = endX - beginX; // 10
// 	double deltaY = endY - beginY; // 0

// 	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY)); // we will divide by this number to get the number of pixels to draw on the screen notice that sqrt is not a function but a macro that calculates the square root of a number for example: sqrt(4) = 2
// 	//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10

// 	deltaX /= pixels; // 1
// 	deltaY /= pixels; // 0	

// 	double pixelX = beginX;
// 	double pixelY = beginY;
// 	while (pixels)
// 	{
// 		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// 		pixelX += deltaX;
// 		pixelY += deltaY;
// 		--pixels;
// 	}
// 	return (0); 
// }

void    adder(char *p)
{
    *p =  *p + 1;
}
int main()
{
    char c  = 'a';
    printf("%c", c);
    adder(&c);
    printf("%c", c);

    char *p = &c;
    adder(p);
    printf("%c", *p);
    return 0;0
}

