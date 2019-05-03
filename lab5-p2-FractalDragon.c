#include <stdio.h>
#include <stdlib.h>
#include "myGfxShapesLib.h"
#include "gfx2.h"


int main(int argc, char *argv[])
{
	char userDecision; 
	int xMax = 800, yMax = 800;
    double initX, initY, endX, endY, lineLength;
    int count=0, R, G, B;
	 
	// open a drawing window
	gfx_open(xMax, yMax, "Fractal Dragon");

    while(count!=1)
    {
    
    //get initial details from user 
    printf("Please enter the initial x y coordinate in that order: ");
	scanf("%lf %lf", &initX, &initY);
	
	 printf("Please enter the ending x y coordinate in that order: ");
	scanf("%lf %lf", &endX, &endY);

	printf("Please enter the minimum line length ");
	scanf("%lf", &lineLength);

    printf("Please enter R G B color values in that order (0-255): ");
	scanf("%d %d %d", &R, &G, &B);
    
    //set color
 	gfx_color(R, G, B);			
	gfx_clear();

    GfxPoint start = {.x = initX, .y = initY}, end = {.x = endX, .y=endY};	
	
    //draw dragon
	drawDragon(start, end, lineLength);
            
    gfx_flush();

	printf("\n===================================================\n"); 
	
    }
}
