/*
 * CSC A48 - Exercise 11 - Sudoku Solver
 * 
 * Your goal in this exercise is to practice recursion and
 * to see how a properly written recursive solution can
 * take care of fairly complicated tasks with a few lines
 * of (well thought out) code.
 * 
 * We will be solving Sudoku puzzles. In case you have never
 * solved or seen a Sudoku, you can learn more about them
 * here:
 * 
 * https://en.wikipedia.org/wiki/Sudoku
 * 
 * Your task if to write a function that takes an input
 * Sudoku in the form of a 9x9 array of integers. the
 * array will have a few entries filled with numbers in
 * [1, 9], and the remaining entries set to zero.
 * 
 * For the example in the wiki, the input array will
 * be
 * 
 * 5 3 0 0 7 0 0 0 0
 * 6 0 0 1 9 5 0 0 0
 * 0 9 8 0 0 0 0 6 0
 * 8 0 0 0 6 0 0 0 3
 * 4 0 0 8 0 3 0 0 1
 * 7 0 0 0 2 0 0 0 6
 * 0 6 0 0 0 0 2 8 0 
 * 0 0 0 4 1 9 0 0 5
 * 0 0 0 0 8 0 0 7 9
 * 
 * Your code should find the values that correctly
 * complete the Sudoku. 
 * 
 * As a brief reminder, a correctly solved Sudoku is
 * one in which there are no repeated digits in any
 * row, any column, or any of the 3x3 sub-arrays that
 * make up the large 9x9 grid. Another way to think
 * about it is, every row, column, and 3x3 subgrid
 * uses all of the different digits.
 * 
 * How to solve this?
 * 
 * * RECURSIVELY!
 * 
 * (hint) - Solving a Sudoku with N unknown values
 * may involve trying something, then solving an
 * easier Sudoku problem.
 * 
 * * How to approach this?
 * 
 * - As noted in class:
 * 	a) Determine the base case(s)
 * 	b) Figure out the recursive case
 * 	c) Determine what needs to happen to
 * 	   the solution for the entire problem
 * 	   is returned once the recursion hits
 * 	   the base case(s)
 * 
 * - Conditions on the input Sudoku
 * 	- It will have AT LEAST ONE DIGIT in each
 * 	  3x3 subgrid. Likely there will be several
 * 	  3x3 subgrids with several digits already
 * 	  set to some value.
 * 
 * - Conditions on your solution
 * 	- It should return a solution if there
 * 	  exists one.
 * 	- If no solution can be found, return the
 * 	  original input array
 * 	- If multiple solutions exist, any one of
 *        them is valid
 * 
 * - Can I use helper functions?
 * 	- Yes, by all means!
 * 
 * - Can I add extra libraries?
 * 	- No, they won't be needed.
 * 
 * - Can I change the 'print_sudoku()' function?
 * 	- Please don't, we may need it for testing!
 * 
 * (c) F. Estrada, March 2019
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j=0; j<9; j++)
  {
    for (int i=0; i<9;i++)
    {
      printf("%d  ",sudoku[j][i]);
    }
    printf("\n");
  }
}

void reset_bucket(int bucket[9])
{
	for(int i = 0; i < 9; i++)
	{
		bucket[i] = 0;
	}
}





int check_rows(int row[9][9])
{
	int bucket[9];
	
	for(int j = 0; j < 9; j++)
	{
		reset_bucket(bucket);
		
		for(int i = 0; i < 9; i++)
		{
			if(row[j][i] > 0 && row[i][j] <= 9)
			{
				//printf("n at %d = %d", row[j][i] - 1, bucket[row[j][i] - 1]);
				bucket[row[j][i] - 1] = bucket[row[j][i] - 1] + 1;
				//printf("n at %d = %d\n", row[j][i] - 1, bucket[row[j][i] - 1]);
				
			}
		}
		for(int i = 0; i < 9; i++)
		{
			//printf("n = %d", bucket[i]);
			if(bucket[i] >= 2)
			{
				return -1;
			}
		}
	}
	return 1;
}

int check_cols(int col[9][9])
{
	int bucket[9];
	
	for(int i = 0; i < 9; i++)
	{
		reset_bucket(bucket);
		
		for(int j = 0; j < 9; j++)
		{
			if(col[j][i] > 0 && col[j][i] <= 9)
			{
				//printf("n at %d = %d ", col[j][i] - 1, bucket[col[j][i] - 1]);
				bucket[col[j][i] - 1] = bucket[col[j][i] - 1] + 1;
				//printf("n at %d = %d\n", col[j][i] - 1, bucket[col[j][i] - 1]);
			}
		}
		for(int j = 0; j < 9; j++)
		{
			if(bucket[j] >= 2)
			{
				return -1;
			}
		}
	}
	return 1;
}

int check_three(int three[9][9], int x, int y)
{
	int bucket[9];
	reset_bucket(bucket);
	//printf("here\n");
	for(int j = -1; j <= 1; j++)
	{
		for(int i = -1; i <= 1; i++)
		{
			if(three[x + j][y + i] > 0 && three[x + j][y + i] <= 9)
			{
				//printf("n at %d = %d ", three[x + j][y + i] - 1, bucket[three[x + j][y + i] - 1]);
				bucket[three[x + j][y + i] - 1] = bucket[three[x + j][y + i] - 1] + 1;
				//printf("n at %d = %d\n", three[x + j][y + i] - 1, bucket[three[x + j][y + i] - 1]);
			}
		}
	}
	for(int j = 0; j < 9; j++)
	{
		if(bucket[j] >= 2)
		{
			return -1;
		}
	}
	return 1;
}


int check_sudoku(int sudoku[9][9])
{
  /*
   *  This function checks whether a Sudoku is properly
   * solved. That means that each row, column, and
   * 3x3 subgrid uses each digit only once.
   * 
   *  If *ignores* zeros, so you can use it to check
   * that a partial solution is valid
   */
  
  /*****
   * TO DO:
   * Complete this function
   *   -- BUT ONLY IF YOU WANT TO!
   * Our testing script only checks your Sudoku
   * solution, if you want to solve it without
   * using this function, or if you want to write
   * your own helper functions, that's ok!
   * *****/
/*    printf("col = %d\n", check_cols(sudoku));
   printf("row = %d\n", check_rows(sudoku));
   printf("q1 = %d\n", check_three(sudoku, 1, 1));
   printf("q2 = %d\n", check_three(sudoku, 4, 1));
   printf("q3 = %d\n", check_three(sudoku, 7, 1));
   printf("q4 = %d\n", check_three(sudoku, 1, 4));
   printf("q5 = %d\n", check_three(sudoku, 4, 4));
   printf("q6 = %d\n", check_three(sudoku, 7, 4));
   printf("q7 = %d\n", check_three(sudoku, 1, 7));
   printf("q8 = %d\n", check_three(sudoku, 4, 7));
   printf("q9 = %d\n", check_three(sudoku, 7, 7)); */
   
   
   if(check_cols(sudoku) != 1 || check_rows(sudoku) != 1 || check_three(sudoku, 1, 1) != 1 || check_three(sudoku, 4, 1) != 1 || check_three(sudoku, 7, 1) != 1 || check_three(sudoku, 1, 4) != 1 || check_three(sudoku, 4, 4) != 1 || check_three(sudoku, 7, 4) != 1 || check_three(sudoku, 1, 7) != 1 || check_three(sudoku, 4, 7) != 1 || check_three(sudoku, 7, 7) != 1)
   {
	   return 0;
   }
   
   return 1;  
}

int solved(int sudoku[9][9])
{
  /*
   * This function checks whether a given Sudoku is
   * completely solved (it has no zeros, all digits
   * are used once per row, column, and sub-grid.
   * It returns 1 if the Sudoku is solved, zero
   * otherwise
   */
  
  /*****
   * TO DO
   * Complete this function
   * BUT ONLY IF YOU WANT TO!
   *   You can solve the Sudoku without using this function,
   * or you can write a different helper function, whatever
   * makes more sense to yoU! our checker won't look at this
   * function, 
   * ****/
   
   
   
   if(check_sudoku(sudoku) == 1)
   {
	   for(int j = 0; j < 9; j++)
	   {
		   for(int i = 0; i < 9; i++)
		   {
			   if(sudoku[j][i] == 0)
			   {
				   return 0;
			   }
		   }
	   }
	   return 1;
   }
	return 0;  
}

void solve_sudoku(int sudoku[9][9], int depth)
{
  /*
   * This function solves an input Sudoku, the
   * input has a value of 0 for any entries that
   * are not yet decided. If no solution exists
   * the function returns the input array *exactly
   * as it was* when the function was called.
   * 
   * The 'depth' parameter is provided in case you
   * want to use it to help debug and trace your
   * code. You do not need to use it if you don't
   * want to, and the problem can be solved without
   * using the depth value at all. 
   * 
   * The automated checker won't look at the depth
   * either.
   */
  
  /*****
   * TO DO:
   * Complete this function
   *****/ 
   

	
	if(solved(sudoku) != 1)
	{
		int i = 0; 
		int j = 0;
		int found = 0;

		while(i < 9 && found == 0)
		{
		   j = 0;
		   while(j < 9 && found == 0)
		   {
			   //printf("%d\n", sudoku[i][j]);
			   if(sudoku[i][j] == 0)
			   {
				   found = 1;
				   for(int l = 1; l <= 9; l++)
				   {				   
					   if(solved(sudoku) != 1)
					   {
							sudoku[i][j] = l;
							printf("--%d--", depth);
							if(check_sudoku(sudoku) == 1)
							{
								solve_sudoku(sudoku, depth + 1);
								
							}
							if(solved(sudoku) != 1 && sudoku[i][j] == 9)
							{
								sudoku[i][j] = 0;
							}
					   }
				   }
				     
			   }
			   j++;
		   }
		   i++;
		}
	}
	
   
}

#ifndef __testing

int main()
{
   // We'll provide you with the same test case
   // from the Wiki, so you can check your output.
   // But as always, be aware we will test your
   // solution on different Sudoku puzzles.
  
    /* int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
		     {6, 0, 0, 1, 9, 5, 0, 0, 0},
		     {0, 9, 8, 0, 0, 0, 0, 6, 0},
		     {8, 0, 0, 0, 6, 0, 0, 0, 3},
		     {4, 0, 0, 8, 0, 3, 0, 0, 1},
		     {7, 0, 0, 0, 2, 0, 0, 0, 6},
		     {0, 6, 0, 0, 0, 0, 2, 8, 0},
		     {0, 0, 0, 4, 1, 9, 0, 0, 5},
		     {0, 0, 0, 0, 8, 0, 0, 7, 9}}; */
			 
	int Sudoku[9][9]={{2, 0, 0, 9, 0, 0, 0, 0, 0},
				  	  {0, 0, 0, 0, 0, 0, 0, 6, 0},
					  {0, 0, 0, 0, 0, 1, 0, 0, 0},
					  {5, 0, 2, 6, 0, 0, 4, 0, 7},
					  {0, 0, 0, 0, 0, 4, 1, 0, 0},
					  {0, 0, 0, 0, 9, 8, 0, 2, 3},
					  {0, 0, 0, 0, 0, 3, 0, 8, 0},
					  {0, 0, 5, 0, 1, 0, 0, 0, 0},
					  {0, 0, 7, 0, 0, 0, 0, 0, 0}};


  printf("Input puzzle is:\n");
  print_sudoku(Sudoku);
  
  solve_sudoku(Sudoku,0);
  //printf("\n\n\n\n\n");
  //printf("\n\n%d", solved(Sudoku));
  //printf("\n\n%d", check_sudoku(Sudoku));
  
  printf("Solution is:\n");
  print_sudoku(Sudoku);
  
}

#endif