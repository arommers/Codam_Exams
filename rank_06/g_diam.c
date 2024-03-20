#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Include for write function

// Function to find maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// int input_check(char *input)
// {
//     char *ptr = input;
//     while(*ptr)
//     {
//         if(*ptr < '0' || *ptr > '9')
//         {
//             while(*ptr < '0' || *ptr > '9')
//                 ptr++;
//             if(*ptr != '-');
//                 return 0;
//             ptr++;
//             if(*ptr < '0' || *ptr > '9')
//             {
//                 while(*ptr < '0' || *ptr > '9')
//                     ptr++;
//                 if(*ptr != '\0' && *ptr != ' ')
//                     return 0;
//             }
//             else
//                 return 0;
//         }
//         if(*ptr)
//             ptr++;
//     }
// }

// Depth First Search function
void dfs(int node, int *visited, int num_nodes, int adj_matrix[][100], int *max_len)
{
    visited[node] = 1;
    for (int i = 1; i <= num_nodes; i++)
    {
        if (adj_matrix[node][i] && !visited[i])
            dfs(i, visited, num_nodes, adj_matrix, max_len);
    }
    (*max_len)++;
}

// Function to calculate the longest_path of the graph
int g_diam(char *str)
{
    // Check if input string is empty
    if (str == NULL || str[0] == '\0')
        return 0;

    // Initialize an adjacency matrix
    int adj_matrix[100][100] = {0};
    
    // Variables to keep track of nodes and edges
    int num_nodes = 0, num_edges = 0;

    // Parse the input string to populate the adjacency matrix
    char *ptr = str;
    while (*ptr)
    {
        if (*ptr >= '0' && *ptr <= '9')
        {
            // Extracting node numbers
            int node1 = atoi(ptr);
            while (*ptr && *ptr != '-') ptr++;
            if (*ptr == '-') ptr++;
            int node2 = atoi(ptr);
            // Marking the edge in the adjacency matrix
            adj_matrix[node1][node2] = 1;
            adj_matrix[node2][node1] = 1;
            num_edges++;
            // Update the number of nodes
            num_nodes = max(num_nodes, max(node1, node2));
        }
        ptr++;
    }

    // Initialize visited array
    int visited[100] = {0};

    // Find the longest chain using DFS
    int max_chain = 0;
    for (int i = 1; i <= num_nodes; i++)
    {
        if (!visited[i])
        {
            int current_len = 0;
            dfs(i, visited, num_nodes, adj_matrix, &current_len);
            max_chain = max(max_chain, current_len);
        }
    }

    // Return the longest_path (number of nodes in longest chain)
    return max_chain;
}

int main(int argc, char *argv[])
{
    // Check if the number of arguments is correct
    if (argc != 2)
    {
        write(1, "\n", 1);
        return 1;
    }

    // Calculate the longest_path and print it
    int longest_path = g_diam(argv[1]);
    char buffer[20];
    int len = snprintf(buffer, sizeof(buffer), "%d\n", longest_path);
    write(1, buffer, len);

    return 0;
}
