//ver 1.0
//Author: BYOA

/* What to be done with program 

1. Change fixed array to dynamic array allocation. Large neightbour counts will result in errors so this must be fixed ASAP.


*/ 
#include<iostream> //accounts for character output and character input.


using namespace std;

const int LARGENUM =10000; //BAD DESIGN. Will be changed later for dynamic array or vectors.
void DisplayGrid (bool grid[][LARGENUM], int gridmin);
int Calculation (bool grid[][LARGENUM], int gridmin, int CenterValue);

int main ()
{
    int RowInput, answer; //user will check for the number of rows of the surround neighbour.

    cout << "                     NEIGHBOUR CHECK -- Program by BYOA\n";
    cout << "\n\n" << "This program will allow a user to check the number of neighbour elements surrounding a centre element in a grid.\n";
    cout << "Users can input the amount of surrounding rows.\n\n";

    cout << "FOR EXAMPLE:\n1 surrounding row should be 8 neighbours, (+ 8) on a 3 x 3 grid.";
    cout << "\n2 surrounding rows should be 24 neighbours, (+ 16) on a 5 x 5 grid.";
    cout << "\n3 surrounding rows should be 48 neighbours, (+ 24)on a 7 x 7 grid.\n\n";
    cout << "...\n\n";
    cout << "n rows should be x neighbours, (OR x from previous row + 8n) on a 2n + 1 x 2n + 1 grid.\n\n";
    cout << "And so on.\n\n";


    cout << "Please enter the number of rows that you wish to count as neighbours.\n";
    cin >> RowInput;

    int gridmin = (RowInput*2) + 1; // + 1 is needed to account for the centre element. rowinput * 2 accounts for up and down sides of center element.

    bool grid [gridmin][LARGENUM] = {}; //initalizes to 0 which is false in boolean terminology.

    answer = Calculation (grid, gridmin, RowInput);
    //displaying grid
    system("CLS");
    DisplayGrid(grid, gridmin);

    cout << "\nThere are " << answer << " neighbours with a " << gridmin << " X " << gridmin <<" grid.\n";
}

int Calculation (bool grid[][LARGENUM], int gridmin, int CenterValue)
{
    int NeighbourCount = 0;

    grid [CenterValue][CenterValue] = true; //Interestingly, rowinput coordinates will result in always being in the centre, no matter the size of the grid.

    for (int x = 0; x < gridmin ; x++)
    {
        for (int y = 0; y < gridmin ; y++)
        {
            if (grid[x][y] == false)
                ++NeighbourCount;
        }
    }
    return NeighbourCount;
}


void DisplayGrid (bool grid[][LARGENUM], int gridmin)
{
    for (int x = 0; x < gridmin ; x++)
    {
        for (int y = 0; y < gridmin ; y++)
        {
            if (grid[x][y]== true)
                cout << " O ";
            else
                cout <<" . ";
        }
        cout << '\n';
    }

}
