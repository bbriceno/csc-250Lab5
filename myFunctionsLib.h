
//3
void sortNumbers(double sortArray[], int n);
void sortVisualize(double list[], int size);

//4
#define MAXROWS 200
#define MAXCOLS 200
void init_board(void);
void draw_board(void);
void printTableOfInts(int table[MAXROWS][MAXCOLS], int nRows, int nCols);
void printGameOfLife(int table[MAXROWS][MAXCOLS], int nRows, int nCols);
void countNeighbors(int sourceGrid[MAXROWS][MAXCOLS], int countGrid[MAXROWS][MAXCOLS], int nRows, int nCols);
void updateGameOfLife(int golGrid[MAXROWS][MAXCOLS], int nRows, int nCols);
