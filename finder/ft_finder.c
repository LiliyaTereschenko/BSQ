#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	int	j;
	int	i;
	int	min;
	int I;
	int J;

	i = 0;
	j = 0;
	min = 0;
	I = 0;
	J = 0;
	int arr[5][6] = {	{0,1,1,0,1,0},
						{0,1,1,1,0,0},
						{0,1,1,1,0,0},
						{0,1,1,1,0,0},
						{0,0,0,0,0,0}
					};
//---------------------------------------------------------------------------
	while (i < 5)
	{                                               //printing
		j = 0;
		while (j < 6)
		{
			printf("%d", arr[i][j]);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
//---------------------------------------------------------------------------
	i = 4;
	while (i >= 0)
	{                                               //main block
		j = 5;
		while (j >= 0)
		{
			min = arr[i][j + 1];
			if (arr[i + 1][j] < min)
				min = arr[i + 1][j];
			if (arr[i + 1][j + 1] < min)
				min = arr[i + 1][j + 1];
			arr[i][j] = min + arr[i][j];
            if (arr[i][j] >= arr[I][J])
            {
                I = i;
                J = j;
            }
			j--;
		}
		i--;
	}
//---------------------------------------------------------------------------
	i = 0;                                          //printing
	while (i < 5)
	{
		j = 0;
		while (j < 6)
		{
			printf("%d", arr[i][j]);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	printf("\nMAX VALUE: %d, arr[%d][%d].\n\n", arr[I][J], I, J);
	printf("(then we send MAX and it's coordinates to the main function");
	printf("\nand replace corresponding elements with xxxx)\n");
//---------------------------------------------------------------------------
	return (0);
}
