#include<stdio.h>
#include<stdlib.h>

void fun_1(FILE *, int [][900], int, int);
int fun_2(int [][900], int, int);
int fun_3(int [][900], int, int);
void fun_4(char[], int, int);

int main(void)
{
    FILE *read_ptr = NULL;
    int int_array_1[100][900] = {0};
    int int_array_2[150][900] = {0};
    int int_array_3[200][900] = {0};
    int h_quad = 0;
    int v_quad = 0;
    char data1[] = "data_19_20_1.dat";
    char data2[] = "data_19_20_2.dat";
    char data3[] = "data_19_20_3.dat";

    read_ptr = fopen("data_19_20_1.dat", "r");
    fun_1(read_ptr, int_array_1, 100, 900);
    h_quad = fun_2(int_array_1, 100, 900);
    v_quad = fun_3(int_array_1, 100, 900);
    fun_4(data1, h_quad, v_quad);
    fclose(read_ptr);

    read_ptr = fopen("data_19_20_2.dat", "r");
    fun_1(read_ptr, int_array_2, 150, 900);
    h_quad = fun_2(int_array_2, 150, 900);
    v_quad = fun_3(int_array_2, 150, 900);
    fun_4(data2, h_quad, v_quad);
    fclose(read_ptr);

    read_ptr = fopen("data_19_20_3.dat", "r");
    fun_1(read_ptr, int_array_3, 200, 900);
    h_quad = fun_2(int_array_3, 200, 900);
    v_quad = fun_3(int_array_3, 200, 900);
    fun_4(data3, h_quad, v_quad);
    fclose(read_ptr);

    return 0;
}

void fun_1(FILE *read_ptr, int int_array[][900], int row, int col)
{
    int i = 0, j = 0;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fscanf(read_ptr, "%d", &int_array[i][j]);
        }
    }

    return;
}

int fun_2(int int_array[][900], int row, int col)
{
    int horizontal = 0, i = 0, j = 0;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col - 3; j++)
        {
            if (int_array[i][j] == int_array[i][j + 1] &&
                int_array[i][j] == int_array[i][j + 2] &&
                int_array[i][j] == int_array[i][j + 3])
                horizontal++;
        }
    }

    return (horizontal);
}

int fun_3(int int_array[][900], int row, int col)
{
    int vertical = 0, i = 0, j = 0;

    for (i = 0; i < row - 3; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (int_array[i][j] == int_array[i + 1][j] &&
                int_array[i][j] == int_array[i + 2][j] &&
                int_array[i][j] == int_array[i + 3][j])
                vertical++;
        }
    }

    return (vertical);
}

void fun_4(char file_name[], int horizontal, int vertical)
{
    printf("\nHorizontal quadruples in %s: %d\n", file_name, horizontal);
    printf("\nVertical quadruples in %s: %d\n", file_name, vertical);

    return;
}
