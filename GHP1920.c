/*
ALGORITHM
1. Populate a 200-row and 900-column 2D array of integers from
   a file named data15.d (sent via email... you should store
   data15.d into the same folder/directory that holds your .c
   files)... the 2D array is composed of the following integers:
   0   1  2  3  4  5  6  7  8  9

2. Find the number of horizontal quadruples (four of the same integer
   in a row... example: 7  5  5  5  5  9
   Note - the following should be interpreted a 2 horizontal quadruples:
   3  5  5  5  5  5  2
   ADD YOUR ALGORITHM STEPS HERE... ADD YOUR STEPS AS
   SUB-STEPS OF ALGORITHM STEP 2

2a. Test if the number of rows is less than 200.
    2a1. If true
         2a2. Test if the number of columns is less than 900 minus quads.
              2a2-1. If true
                     2a2-2. Test if the current row and column is equal to
                            the following 3 columns.
                            2a2-2a. If true
                                    2a2-2b. Increment h_quad counter.
                            2a2-2c. If false
                                    2a2-2d. Go to step 2a2-3.
                     2a2-3. Increment column counter.
                     2a2-4. Go to step 2a2.
             2a2-1a. If false
                     2a2-1b. Go to step 2a.
         2a3. Increment row counter.
     2b. If false
         2b1. Go to step 3.

3. Find the number of vertical quadruples (four of the same integer
   in a column... example:
   5
   4
   4
   4
   4
   7
   Note - the following should be interpreted a 2 vertical quadruples:
   5
   4
   4
   4
   4
   4
   1
ADD YOUR ALGORITHM STEPS HERE... ADD YOUR STEPS AS
SUB-STEPS OF ALGORITHM STEP 3

3a. Test if the number of columns is less than 900.
    3a1. If true
         3a2. Test if the number of rows is less than 200 minus quads.
              3a2-1. If true
                     3a2-2. Test if the current row and column is equal to
                            the following 3 rows.
                            3a2-2a. If true
                                    3a2-2b. Increment v_quad counter.
                            3a2-2c. If false
                                    3a2-2d. Go to step 3a2-3.
                     3a2-3. Increment row counter.
                     3a2-4. Go to step 3a2.
             3a2-1a. If false
                     3a2-1b. Go to step 3a.
         3a3. Increment column counter.
     3b. If false
         3b1. Go to step 4.

4. Display the number of horizontal quadruples.

5. Display the number of vertical quadruples.

6. Terminate

YOU WILL KNOW THAT YOUR PROGRAM WORKS CORRECTLY WHEN YOUR PROGRAM
PRODUCES 153 FOR HORIZONTAL QUADRUPLES AND 172 FOR VERTICAL QUADRUPLES.

*/

#include<stdio.h>
#include<stdlib.h>

void fun_1(FILE *, int [][900], int, int);
int fun_2(int [][900], int, int);
int fun_3(int [][900], int, int);
void fun_4(char[], int, int);

int main ( void )
{
     //Local variables declared below
    FILE  *  read_ptr = NULL ;
    int int_array_1[100][900] = { 0 } ;
    int int_array_2[150][900] = { 0 } ;
    int int_array_3[200][900] = { 0 } ;
    int h_quad = 0;
    int v_quad = 0;
    char data1[] = "data_19_20_1.dat";
    char data2[] = "data_19_20_2.dat";
    char data3[] = "data_19_20_3.dat";

     //1. Open data_19_20_1.dat using read_ptr  (defimed above)
    read_ptr = fopen("data_19_20_1.dat", "r");

     //2. Call fun_1( ) 
    fun_1(read_ptr, int_array_1, 100, 900);

     //3. Call fun_2( ) 
    h_quad = fun_2(int_array_1, 100, 900);

     //4. Call fun_3( ) 
    v_quad = fun_3(int_array_1, 100, 900);

     //5. Call fun_4( )
    fun_4(data1, h_quad, v_quad);
    printf("\n");
    
     //6. Close read_ptr
    fclose(read_ptr);

     //7. Open data_19_20_2.dat using read_ptr  (defimed above)
    read_ptr = fopen("data_19_20_2.dat", "r");

     //8. Call fun_1( ) 
    fun_1(read_ptr, int_array_2, 150, 900);

     //9. Call fun_2( ) 
    h_quad = fun_2(int_array_2, 150, 900);

     //10. Call fun_3( ) 
    v_quad = fun_3(int_array_2, 150, 900);

     //11. Call fun_4( )
    fun_4(data2, h_quad, v_quad);
    printf("\n");
    
     //12. Close read_ptr
    fclose(read_ptr);

     //13. Open data_19_20_3.dat using read_ptr  (defimed above)
    read_ptr = fopen("data_19_20_3.dat", "r");

     //14. Call fun_1( ) 
    fun_1(read_ptr, int_array_3, 200, 900);

     //15. Call fun_2( ) 
    h_quad = fun_2(int_array_3, 200, 900);

     //16. Call fun_3( ) 
    v_quad = fun_3(int_array_3, 200, 900);

     //17. Call fun_4( ) 
    fun_4(data3, h_quad, v_quad);
    printf("\n");
    
     //18. Close read_ptr
    fclose(read_ptr);

     //19. Terminate
     return 0 ;
}

void fun_1(FILE * read_ptr, int int_array[][900], int row, int col) {

    int i = 0, j = 0;

    for (i = 0; i < row; i++) {

           for (j = 0; j < col; j++) {

               fscanf(read_ptr, "%d", &int_array[i][j]);
           }
     }


    return;

}

int fun_2(int int_array[][900], int row, int col) {

    int horizontal = 0, i = 0, j = 0;

    for (i = 0; i < row; i++) {

        for (j = 0; j < col - 3; j++) {

            if (int_array[i][j] == int_array[i][j + 1] &&
                   int_array[i][j] == int_array[i][j + 2] &&
                   int_array[i][j] == int_array[i][j + 3])
                
                horizontal++;

        }
    }

    return (horizontal);
}

int fun_3(int int_array[][900], int row, int col) {

    int vertical = 0, i = 0, j = 0;

    for (i = 0; i < row - 3; i++) {

        for (j = 0; j < col; j++) {

            if (int_array[i][j] == int_array[i + 1][j] &&
                   int_array[i][j] == int_array[i + 2][j] &&
                   int_array[i][j] == int_array[i + 3][j])
                
                vertical++;

        }
    }

    return (vertical);

}

void fun_4(char file_name[], int horizontal, int vertical) {

    printf("\nHorizontal quadruples in %s: %d\n", file_name, horizontal);
    printf("\nVertical quadruples in %s: %d\n", file_name, vertical);

    return;

}
