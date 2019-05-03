#include <stdio.h>
#include <stdlib.h>
#include "myGfxShapesLib.h"
#include "gfx2.h"


int main(int argc, char *argv[])
{
	char userDecision; 
	int xMax = 800, yMax = 800;
    double x, y, initRadius;
    int count=0, n;
	 
	// open a drawing window
	gfx_open(xMax, yMax, "Circle Thing");

    while(count!=1)
    {
    
    //ge initial details from user 
	printf("Please enter the initial radius ");
	scanf("%lf", &initRadius);
	
	printf("Please enter the x coordinate ");
	scanf("%lf", &x);
	
	printf("Please enter the y coordinate ");
	scanf("%lf", &y);
    
    //generate random number betwen 1 to 3
    n = rand() % 3 + 1;

    //set circle color based on random number
    switch(n)
	    {
		case 1: 
			gfx_color(255,0,0);			
			break;
		case 2: 
			gfx_color(0, 255, 0);
			break;			
		case 3: 
			gfx_color(0,0,255);
			break;
		default: 
			gfx_color(255,25,255);
			break;
        }
	
    //draw circle
	circleThing(x,y,initRadius,5); 
	
    //get user decision on what to do next
	printf("\nPlease enter one of the following characters \nc: will clear the old circle thing \nq: will quit the program \nYou can enter any other character to continue:\n "); 
	scanf(" %c", &userDecision);
	
        switch(userDecision)
        {
        case 'c':
            gfx_clear();
            gfx_flush();
            break;
        case 'q':
            count=1;
            break;
        default:
            break;
            
        }

	printf("\n===================================================\n"); 
	
    }
}
