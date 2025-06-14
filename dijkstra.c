/**
 * @file dijkstra.c
 * @brief Implementation of Dijkstra's shortest path algorithm
 * @author İshak Duran (22060664)
 * @date 2025
 *
 * Dijkstra's algorithm finds the shortest paths from a source vertex
 * to all other vertices in a weighted graph with non-negative edge weights.
 *
 * Time Complexity: O(V²)
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph
#define INF INT_MAX

/**
 * @brief Find the vertex with minimum distance value from the set of vertices
 *        not yet included in shortest path tree
 * @param dist Array of distance values
 * @param sptSet Array to track vertices included in shortest path tree
 * @return Index of the vertex with minimum distance
 */
int minDistance(int dist[], bool sptSet[])
{
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

/**
 * @brief Print the shortest distances and paths from source to all vertices
 * @param dist Array containing shortest distances
 * @param parent Array containing parent vertices for path reconstruction
 */
void printSolution(int dist[], int parent[])
{
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║                    DIJKSTRA'S ALGORITHM RESULT                ║\n");
    printf("╠═══════════════════════════════════════════════════════════════╣\n");
    printf("║ Vertex │ Distance │ Path                                      ║\n");
    printf("╠════════╪══════════╪═══════════════════════════════════════════╣\n");

    for (int i = 0; i < V; i++)
    {
        printf("║   %d    │    %2d    │ ", i, dist[i]);

        // Print path by backtracking through parent array
        int path[V], pathLength = 0;
        int current = i;

        // Build path in reverse order
        while (current != -1)
        {
            path[pathLength++] = current;
            current = parent[current];
        }

        // Print path in correct order
        for (int j = pathLength - 1; j >= 0; j--)
        {
            printf("%d", path[j]);
            if (j > 0)
                printf(" → ");
        }

        // Add padding for alignment
        int pathChars = pathLength * 2 - 1 + (pathLength - 1) * 2; // digits + arrows
        for (int k = pathChars; k < 35; k++)
        {
            printf(" ");
        }
        printf("║\n");
    }
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
}

/**
 * @brief Implementation of Dijkstra's shortest path algorithm
 * @param graph Adjacency matrix representation of the graph
 * @param src Source vertex
 */
void dijkstra(int graph[V][V], int src)
{
    int dist[V];    // Array to hold shortest distance from src to each vertex
    int parent[V];  // Array to store parent vertices for path reconstruction
    bool sptSet[V]; // Boolean array to track vertices in shortest path tree

    // Initialize all distances as infinite and sptSet as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        sptSet[i] = false;
        parent[i] = -1;
    }

    // Distance from source to itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex not yet processed
        int u = minDistance(dist, sptSet);

        if (u == -1)
            break; // All remaining vertices are unreachable

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update distance values of the adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // Update dist[v] if:
            // 1. v is not in sptSet
            // 2. there is an edge from u to v
            // 3. total weight of path from src to v through u is smaller than current value
            if (!sptSet[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Set parent for path reconstruction
            }
        }
    }

    // Print the computed distances and paths
    printSolution(dist, parent);
}

/**
 * @brief Main function demonstrating Dijkstra's algorithm
 * @return 0 on successful execution
 */
int main()
{
    printf("🔗 Graph Theory Algorithms - Dijkstra's Shortest Path\n");
    printf("=====================================================\n\n");

    // Example graph represented as adjacency matrix
    // graph[i][j] = weight of edge from vertex i to vertex j
    // 0 means no direct edge between vertices
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}};

    printf("Input Graph (Adjacency Matrix):\n");
    printf("     ");
    for (int i = 0; i < V; i++)
    {
        printf("%3d", i);
    }
    printf("\n");

    for (int i = 0; i < V; i++)
    {
        printf("%3d: ", i);
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == 0)
            {
                printf("  ∞");
            }
            else
            {
                printf("%3d", graph[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nSource vertex: 0\n\n");

    // Run Dijkstra's algorithm starting from vertex 0
    dijkstra(graph, 0);

    printf("\n💡 Note: This algorithm works only with non-negative edge weights.\n");
    printf("   For graphs with negative weights, use Bellman-Ford algorithm.\n");

    return 0;
}
