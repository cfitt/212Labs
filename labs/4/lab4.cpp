#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

void RandoCalrissian(int **color, int **gridm, int GRID_SIZE);

//the output statement is: ./a.out >NAME_OF_PPM.ppm

int main( )
{
	const int MAXVAL = 255;
	const int PRINT_SIZE = 1000;
/*
to produce a ppm image of your choosing, one must
change the hardcode of the two varibles below:
	GRID_SIZE
	numRando
if you wish you may also change PRINT_SIZE, to change
the overall size of the image
*/

//Set grid size
        int GRID_SIZE = 40;

//Set number of random values
        int numRando = 9001;
//in this case it's over 9000


//creat the temp color setter grid, and the final grid for the rand() inputs
        int **color = new int *[GRID_SIZE];//store colors
        for (int i = 0; i < GRID_SIZE; i++ )
                color[i] = new int [GRID_SIZE];

        int **grid = new int *[GRID_SIZE];//final grid
        for (int i = 0; i < GRID_SIZE; i++ )
                grid[i] = new int [GRID_SIZE];


//set colors on color[][]
//colors vary from:
        //red if colm# + row # = odd
        //blue if colm# + row # = even
        //white if color already exists and tried to be filled in later
        int r,c;
        for(r=0; r<GRID_SIZE; r++) {
                for(c=0; c<GRID_SIZE; c++)
                {
                        if((r+c)%2==0) //red
                                color[r][c] = 1;
                        else if((r+c)%2==1) //blue
                                color[r][c] = 2;
                }
        }

//check all random spaces, and fill in color from int **color
        for(int i=0; i<numRando ; i++)
		RandoCalrissian(color, grid, GRID_SIZE);

//Essent header for PPM imgs
        printf("P6\n");
        printf("%d %d %d\n", PRINT_SIZE, PRINT_SIZE, MAXVAL);
//now print this bad boy
	for(int row=0; row<GRID_SIZE; row++)
     	{ 	
		for(int j=0; j<(PRINT_SIZE/GRID_SIZE); j++)
		{       
			for(int x=0; x<GRID_SIZE; x++)
	        	{
				if(grid[x][row] == 0)
				{
	        			for(int i=0; i<(PRINT_SIZE/GRID_SIZE); i++)
						printf("%c%c%c", 255, 255, 255);//prints white for one stripe of block
				}
				if(grid[x][row] == 1)
				{
	        			for(int i=0; i<(PRINT_SIZE/GRID_SIZE); i++)
						printf("%c%c%c", 255, 0, 0);//prints red for one stripe of block
				}
				if(grid[x][row] == 2)
				{
	        			for(int i=0; i<(PRINT_SIZE/GRID_SIZE); i++)
						printf("%c%c%c", 0, 0, 255);//prints blue for one stripe of block
				}			
			}
		}
	}
}

void RandoCalrissian(int **color, int **grid, int GRID_SIZE)
{
        int Rando_X = rand() % GRID_SIZE;
        int Rando_Y = rand() % GRID_SIZE;
	
	GRID_SIZE-=1;
//-------------------------------------Top or Bottom--------------------------------------
		if (Rando_X!=0 && Rando_Y==0 && Rando_X!=GRID_SIZE)//If rando wants top row, not corners
                {
                        if(grid[Rando_X-1][Rando_Y] == 0 && grid[Rando_X][Rando_Y+1] == 0 && grid[Rando_X+1][Rando_Y] == 0)
                                grid[Rando_X][Rando_Y] = color[Rando_X][Rando_Y];
                        else
                                grid[Rando_X][Rando_Y] = 0;
                }

                if (Rando_X!=0 && Rando_Y==GRID_SIZE && Rando_X!=GRID_SIZE)//If rando wants BOTTOM row, not corners
                {
                        if(grid[Rando_X-1][Rando_Y] == 0 && grid[Rando_X][Rando_Y-1] == 0 && grid[Rando_X+1][Rando_Y] == 0)
                                grid[Rando_X][Rando_Y] = color[Rando_X][Rando_Y];
                        else
                                grid[Rando_X][Rando_Y] = 0;
                }
//-------------------------------------Left side------------------------------------------
                if (Rando_X==0 && Rando_Y!=0 && Rando_Y!=GRID_SIZE)//if rando wants left, not top or bottom
                {
                        if(grid[Rando_X+1][Rando_Y] == 0 && grid[Rando_X][Rando_Y+1] == 0 && grid[Rando_X][Rando_Y-1] == 0)
                                grid[Rando_X][Rando_Y] = color[Rando_X][Rando_Y];
                        else
                                grid[Rando_X][Rando_Y] = 0;
                }

                if (Rando_X==0 && Rando_Y==0) //if rando wants top left
                {
                        if(grid[Rando_X+1][Rando_Y] == 0 && grid[Rando_X][Rando_Y+1] == 0)
                                grid[Rando_X][Rando_Y] = color[Rando_X][Rando_Y];
                        else
                                grid[Rando_X][Rando_Y] = 0;
                }

                if (Rando_X==0 && Rando_Y==GRID_SIZE) //if rando wants bottom left
                {
                        if(grid[Rando_X+1][Rando_Y] == 0 && grid[Rando_X][Rando_Y-1] == 0)
                                grid[Rando_X][Rando_Y] = color[Rando_X][Rando_Y];
			else
                                grid[Rando_X][Rando_Y] = 0;
                }
//-------------------------------------Right side------------------------------------------
                if (Rando_X==GRID_SIZE && Rando_Y!=0 && Rando_Y!=GRID_SIZE)//if rando wants right, not top or bottom
                {
                        if(grid[Rando_X-1][Rando_Y] == 0 && grid[Rando_X][Rando_Y+1] == 0 && grid[Rando_X][Rando_Y-1] == 0)
                                grid[Rando_X][Rando_Y] = color[Rando_X][Rando_Y];
                        else
                                grid[Rando_X][Rando_Y] = 0;
                }

                if (Rando_X==GRID_SIZE && Rando_Y==0)//if rando wants top right
                {
                        if(grid[Rando_X-1][Rando_Y] == 0 && grid[Rando_X][Rando_Y+1] == 0)
                                grid[Rando_X][Rando_Y] = color[Rando_X][Rando_Y];
                        else
                                grid[Rando_X][Rando_Y] = 0;
                }
                if (Rando_X==GRID_SIZE && Rando_Y==GRID_SIZE)//if rando wants bottom right
                {
                        if(grid[Rando_X-1][Rando_Y] == 0 && grid[Rando_X][Rando_Y-1] == 0)
                                grid[Rando_X][Rando_Y] = color[Rando_X][Rando_Y];
                        else
                                grid[Rando_X][Rando_Y] = 0;
                }
//-------------------------------------Within boarders of grid----------------------------
                if (Rando_X!=0 && Rando_X!=GRID_SIZE && Rando_Y!=0 && Rando_Y!=GRID_SIZE)
                {
                        if(grid[Rando_X+1][Rando_Y] == 0 && grid[Rando_X-1][Rando_Y] == 0
                        && grid[Rando_X][Rando_Y+1] == 0 && grid[Rando_X][Rando_Y-1] == 0)
                        {
                                if(grid[Rando_X][Rando_Y] == 0)
                                        grid[Rando_X][Rando_Y] = color[Rando_X][Rando_Y];
                                else
                                        grid[Rando_X][Rando_Y] == 0;
                        }
                        else
                                grid[Rando_X][Rando_Y] = 0;
                }
}
                                                                                                                                                                  

