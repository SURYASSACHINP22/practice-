#include <iostream>
 
using namespace std;
 
// N is the size of the 2D matrix   N*N
#define N 9
 
/* A utility function to print grid */
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < 9; j++)
        {
            cout << arr[i][j] <<" ";
            if(j%3==2)
            {
                cout<<"\t\t";
            }
        }
        cout<<"\n";
        if(i%3==2)
        {
            cout<<"\n\n";
        }
    }
}
 
// Checks whether it will be 
// legal to assign num to the
// given row, col
bool isSafe(int grid[N][N], int row, 
                       int col, int num)
{
     
    // Check if we find the same num 
    // in the similar row , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
 
    // Check if we find the same num in 
    // the similar column , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
 
    // Check if we find the same num in 
    // the particular 3*3 matrix,
    // we return false
    int startRow = row - row % 3, 
            startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + 
                            startCol] == num)
                return false;
 
    return true;
}
 
/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool solveSuduko(int grid[N][N], int row, int col)
{
    // Check if we have reached the 8th 
    // row and 9th column (0
    // indexed matrix) , we are 
    // returning true to avoid
    // further backtracking
    if (row == N - 1 && col == N)
        return true;
 
    // Check if column value  becomes 9 , 
    // we move to next row and
    //  column start from 0
    if (col == N) {
        row++;
        col = 0;
    }
   
    // Check if the current position of 
    // the grid already contains
    // value >0, we iterate for next column
    if (grid[row][col] > 0)
        return solveSuduko(grid, row, col + 1);
 
    for (int num = 1; num <= N; num++) 
    {
         
        // Check if it is safe to place 
        // the num (1-9)  in the
        // given row ,col  ->we 
        // move to next column
        if (isSafe(grid, row, col, num)) 
        {
             
           /* Assigning the num in 
              the current (row,col)
              position of the grid
              and assuming our assined 
              num in the position
              is correct     */
            grid[row][col] = num;
           
            //  Checking for next possibility with next
            //  column
            if (solveSuduko(grid, row, col + 1))
                return true;
        }
       
        // Removing the assigned num , 
        // since our assumption
        // was wrong , and we go for 
        // next assumption with
        // diff num value
        grid[row][col] = 0;
    }
    return false;
}
 
// Driver Code
int main()
{   
    long int ele;
    // 0 means unassigned cells
     int grid[N][N];
     cout<<"\n\n\nEnter the Sukodo Elements row wise from 1-9 and Enter 0 for empty blocks of sudoko \n";
    for(int i =0;i<N;i++)
    {
        cout<<"\nLine = "<<i+1<<"\n";
        cin>>ele;
        for(int j=8;j>=0;j--)
        {
          grid[i][j]=(ele%10);
          ele=ele/10;
        // cin>>grid[i][j];
            
        }
    }
    print(grid); 
    cout<<endl<<endl<<endl;
    cout<<"The solved code is \n";   
    if (solveSuduko(grid, 0, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;
 
    return 0;
    // This is code is contributed by Pradeep Mondal P
}