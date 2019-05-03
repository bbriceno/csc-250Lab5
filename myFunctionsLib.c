
#include <stdio.h>
#include "myGfxShapesLib.h"
#include "gfx2.h"
#include <unistd.h>
#include "myFunctionsLib.h"
#include <math.h>

#define MAXROWS 200
#define MAXCOLS 200
	

//function to sort an array of double using bubble sort
void sortNumbers(double sortArray[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (sortArray[j] > sortArray[j + 1])
			{
				double temp = sortArray[j];
				sortArray[j] = sortArray[j + 1];
				sortArray[j + 1] = temp;
			}

		}
	}
}

//function to visually sort an array of double using bubble sort 
void sortVisualize(double sortArray[], int n)
{
	int xsize = 400;
	int ysize = 400;
	int i, j;

	//graphic window
	while (1) {

		gfx_open(xsize, ysize, "Sorting");
		gfx_color(100, 100, 100);

		//Initialis draw bars
		drawBars(sortArray, n, 50, 300, .75*(300 / n), .25*(300 / n));
		gfx_flush();

		//stop for user
		usleep(300000);

		//bubble sort implementation with visualization
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				gfx_clear();
				drawBars(sortArray, n, 50, 300, .75*(300 / n), .25*(300 / n));
				gfx_flush();
				usleep(500000);

				if (sortArray[j] > sortArray[j + 1])
				{	
					double temp = sortArray[j];
					sortArray[j] = sortArray[j + 1];
					sortArray[j + 1] = temp;
				}

			}
		}

		i = gfx_wait();

		// Stop if it is the letter q.
		if (i == 'q') break;

	}
}


	

	

typedef struct
{
    char tile;      // current tile at board position
    int letter;     // letter multiplier (2 or 3), 0 if none
    int word;       // word multiplier (2 or 3), 0 if none
} board_t;
	

	// board geometry 21x21
	

board_t Board[21][22]; // add one extra column for print border
	

void init_board(void) // function to initialize a blank scrabble board
{
    int i, j;
	

	    for (i=0; i<21; i++)
	        for (j=0; j<22; j++)
	        {
	            Board[i][j].letter = 0;
	            Board[i][j].word = 0;
	            Board[i][j].tile = ' ';
	            if ((i==0 || i==7 || i==14) && (j==0 || j==7 || j==14))
	                Board[i][j].word = (i==7 && j==7) ? 2 : 3;
	            else if ((i==5 || i==9) && ((j-1)%4==0))
	                Board[i][j].letter = 3;
	            else if ((j==5 || j==9) && ((i-1)%4==0))
	                Board[i][j].letter = 3;
	            else if ((i==6 || i==8) && (j==2 || j==6 || j==8 || j==12))
	                Board[i][j].letter = 2;
	            else if ((j==6 || j==8) && (i==2 || i==6 || i==8 || i==12))
	                Board[i][j].letter = 2;
	            else if ((i==3 || i==11) && (j==0 || j==7 || j==14))
	                Board[i][j].letter = 2;
	            else if ((j==3 || j==11) && (i==0 || i==7 || i==14))
	                Board[i][j].letter = 2;
	            else if (i==j || i==(14-j))
	                Board[i][j].word = 2;
	        }
	}
	

void draw_board(void) // function to draw scrabble board
{
	    int i, j, letter, word;
	    printf("    1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21\n  "); // creates  top column
	                                                                                                          // border numbers
	    for (i=0; i<21; i++)
	    {
	        for (j=0; j<21; j++)
	        {
	            letter = (Board[i][j].letter | ((i)?Board[i-1][j].letter:0));
	            word = (Board[i][j].word | ((i)?Board[i-1][j].word:0));
	        }
	

	        printf("\n%c ",i+0x61); // creates row border letters
	        for (j=0; j<22; j++) // creates row border letters
	        {
	            letter = (Board[i][j].letter | ((j)?Board[i][j-1].letter:0));
	            word = (Board[i][j].word | ((j)?Board[i][j-1].word:0));
	            if (letter == 3)
	                printf("  %c ",(j<21)?Board[i][j].tile:i+0x61);
	            else if (word == 3)
	                printf("  %c ",(j<21)?Board[i][j].tile:i+0x61);
	            else
	                printf("  %c ",(j<21)?Board[i][j].tile:i+0x61);
	        }
	        printf("\n  "); // creates new lines for neatly spacing the board
	

	    }
	    printf("  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21\n"); // creates bottom column
	                                                                                                      // border numbers
}
	 
void printTableOfInts(int table[MAXROWS][MAXCOLS], int nRows, int nCols)
{
    int i,j;
    for (i=0; i<nRows; i++) 
    {
        for (j=0; j<nCols; j++)
        {
            printf("%3d", table[i][j]); 
        }
	        printf("\n"); 
	    }
	}
	

//Prints the game of life board
void printGameOfLife(int table[MAXROWS][MAXCOLS], int nRow, int nCols)
{
	int i,j;
	
	for (i=0; i < nRow; i++)
	{
		for (j=0; j < nCols; j++)
		{
			if (table[i][j] == 1) {
			printf(" * ");
			} else {
			printf("   ");
			}
		}
		printf("\n");	
	}

}	

void countNeighbors(int sourceGrid[MAXROWS][MAXCOLS], int countGrid[MAXROWS][MAXCOLS], int nRows, int nCols) 
{
	int i,j,deltaRow,deltaCol;	

	for(i = 0;i < nRows;i++) { //loop for each row
		for(j = 0;j < nCols;j++) { // loop for each col
			//Initialize current 
			countGrid[i][j] = 0;
			for(deltaRow = -1;deltaRow <= 1;deltaRow++) { //loop for each neighbor row
				for(deltaCol = -1;deltaCol <= 1;deltaCol++) { //loop for each neighbor col
					//if sourceGrid[i+deltaRow][j+deltaCol] is 1 then add 1 to the count 
				  	if( i+deltaRow >= 0 && j+deltaCol >= 0 && 	 //if neighbor not out of bounds
				  		i+deltaRow < nRows && j+deltaCol < nCols)
				  	{	
						if(deltaRow != 0 || deltaCol != 0){	
							countGrid[i][j] = countGrid[i][j] + sourceGrid[i+deltaRow][j+deltaCol];
					
						}
					}
				}
			}		
		}
	}		
}		

	

// given a game of life grid, update values according to rules
void updateGameOfLife(int golGrid[MAXROWS][MAXCOLS], int nRows, int nCols )
{
	int countGrid[MAXROWS][MAXCOLS];
	countNeighbors(golGrid,countGrid,nRows,nCols); 
	//look at each cell of golGrid and corresponding count and
	//decide whether it should be updated to 1 or 0 according to rules
	for(int i=0;i<nRows;i++){
		for(int j=0;j<nCols;j++){
			if(golGrid[i][j] == 1){ //if cell is currently alive	
				if(countGrid[i][j] < 2 || countGrid[i][j] > 3){
					golGrid[i][j] = 0;
				}	
			
			} else {		//if cell is currently empty	 
				if(countGrid[i][j] == 3){ //if cell has exactly 3 neighbors
					golGrid[i][j] = 1;	//a cell is born
				}	
			}
		}
	}
}
