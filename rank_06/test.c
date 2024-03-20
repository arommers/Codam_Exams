#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int input_check(char *input)
{
    if (!input || *input == '\0')
        return 0;
    
    while(*input)
    {
        if (*input >= '0' && *input <= '9')
        {
            while (*input >= '0' && *input <= '9')
                input++;
            if (*input != '-')
                return 0;
            input++;
            if (*input >= '0' && *input <= '9')
            {
                while (*input >= '0' && *input <= '9')
                    input++;
                if (*input != '\0' && *input != ' ')
                    return 0;
            }
            else
                return 0;
        }
        if (*input)
            input++;
    }
    return 1;
}

void    dfs(int matrix[][100], int i, int num_nodes, int visited[], int *current_len)
{
    visited[i] = 1;
    for (int j = 1; j <= num_nodes; j++)
    {
        if (matrix[i][j] && !visited[j])
            dfs(matrix, j, num_nodes, visited, current_len);
    }
    (*current_len)++;
}

void    g_diam(char *input)
{
   int  matrix[100][100] = {0};
   int  visited[100] = {0};
   int  node1, node2, num_nodes = 0, result = 0;

   while(*input)
   {
    if (*input >= '0' && *input <= '9')
    {
        node1 = atoi(input);
        while(*input && *input != '-')
            input++;
        if (*input == '-')
            input++;
        node2 = atoi(input);
        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;
        num_nodes = max(num_nodes, max(node1, node2));
    }
    input++;
   }

   for (int i = 1; i <= num_nodes; i++)
   {
    if (!visited[i])
    {
        int current_len = 0;
        dfs(matrix, i, num_nodes, visited, &current_len);
        result = max(result, current_len);
    }
   }
   printf("result: %i\n", result);
}

int main(int argc, char *argv[])
{
    if(argc != 2 || !input_check(argv[1]))
    {
        write(1, "\n", 1);
        return 1;
    }
    g_diam(argv[1]);
    return 0;
}