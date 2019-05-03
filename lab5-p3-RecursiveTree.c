#include <stdio.h>
#include <stdlib.h>
#include "myGfxShapesLib.h"
#include "gfx2.h"


int main(int argc, char *argv[])
{
	char c; 
	int xMax = 800, yMax = 800;
    double baseX, baseY, branchLength, branchAngle, lengthRatioA, lenghtRatioB, branchAngleA, branchAngleB, minBranchLength, Pi = 3.142;
    int count=0, R, G, B;
	 
	// open a drawing window
	gfx_open(xMax, yMax, "Recursive Tree");

    while(count!=1)
    {
    
    //get initial details from user 
    printf("Please enter the base x y coordinate in that order: ");
	scanf("%lf %lf", &baseX, &baseY);

    printf("Please enter the branch length and angle in that order: ");
	scanf("%lf %lf", &branchLength, &branchAngle);
	
	printf("Please enter the branch ratio A B in that order (fraction between 0.0 - 1.0): ");
	scanf("%lf %lf", &lengthRatioA, &lenghtRatioB);

    printf("Please enter the branch angle of A B in that order: ");
	scanf("%lf %lf", &branchAngleA, &branchAngleB);

	printf("Please enter the minimum branch length ");
	scanf("%lf", &minBranchLength);

    printf("Please enter R G B color values in that order (0-255): ");
	scanf("%d %d %d", &R, &G, &B);
    
    //set color
 	gfx_color(R, G, B);			
	
    //draw tree
	recursiveTree(baseX, baseY,  branchLength, branchAngle*Pi/180, lengthRatioA, lenghtRatioB, branchAngleA*Pi/180, branchAngleB*Pi/180, minBranchLength);
    gfx_flush();

    c = gfx_wait();
 	if(c == 'q') count = 1;
   
	printf("\n===================================================\n"); 
	
    }
}
