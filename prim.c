/**
 * @file prim.c
 * @brief Implementation of Prim's Minimum Spanning Tree algorithm
 * @author İshak Duran (22060664)
 * @date 2025
 *
 * Prim's algorithm finds the minimum spanning tree of a graph by
 * growing the tree one vertex at a time. It starts with an arbitrary
 * vertex and repeatedly adds the minimum weight edge that connects
 * a vertex in the tree to a vertex outside the tree.
 *
 * Time Complexity: O(V²)
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph
#define INF INT_MAX

/**
 * @brief Find the vertex with minimum key value from the set of vertices
 *        not yet included in MST
 * @param key Array of key values
 * @param mstSet Boolean array to track vertices included in MST
 * @return Index of the vertex with minimum key value
 */
int minKey(int key[], bool mstSet[])
{
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++)
    {
        // If vertex is not yet in MST and has smaller key value
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

/**
 * @brief Print the Minimum Spanning Tree with edges and weights
 * @param parent Array containing parent vertices in MST
 * @param graph Adjacency matrix of the graph
 */
void printMST(int parent[], int graph[V][V])
{
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║                     PRIM'S ALGORITHM RESULT                   ║\n");
    printf("╠═══════════════════════════════════════════════════════════════╣\n");
    printf("║                   Minimum Spanning Tree Edges                 ║\n");
    printf("╠════════════════════╤════════════════════╤══════════════════════╣\n");
    printf("║       Edge         │       Vertices     │       Weight         ║\n");
    printf("╠════════════════════╪════════════════════╪══════════════════════╣\n");

    int totalWeight = 0;
    int edgeCount = 0;

    for (int i = 1; i < V; i++)
    {
        edgeCount++;
        int weight = graph[i][parent[i]];
        totalWeight += weight;

        printf("║       %2d           │        %d - %d       │         %2d           ║\n",
               edgeCount, parent[i], i, weight);
    }

    printf("╠════════════════════╧════════════════════╧══════════════════════╣\n");
    printf("║  Total MST Weight: %-43d ║\n", totalWeight);
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
}

/**
 * @brief Implementation of Prim's algorithm for finding MST
 * @param graph Adjacency matrix representation of the graph
 */
void primAlgorithm(int graph[V][V])
{
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }

    // Always include first vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked first
    parent[0] = -1; // First node is always root of MST

    printf("🔄 Building MST step by step:\n");
    printf("Starting with vertex 0\n\n");

    // The MST will have V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, mstSet);

        if (u == -1)
        {
            printf("❌ Graph is not connected!\n");
            return;
        }

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        printf("Step %d: Added vertex %d to MST", count + 1, u);
        if (parent[u] != -1)
        {
            printf(" (connected to vertex %d with weight %d)", parent[u], key[u]);
        }
        printf("\n");

        // Update key value and parent index of the adjacent vertices
        // of the picked vertex. Consider only those vertices which are
        // not yet included in MST
        for (int v = 0; v < V; v++)
        {
            // Update the key only if:
            // 1. graph[u][v] is non-zero (there's an edge)
            // 2. v is not in mstSet (not yet included in MST)
            // 3. weight of edge u-v is less than current key of v
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("\n");
    printMST(parent, graph);
}

/**
 * @brief Print the input graph
 * @param graph Adjacency matrix to print
 */
void printGraph(int graph[V][V])
{
    printf("Input Graph (Adjacency Matrix):\n");
    printf("     ");
    for (int i = 0; i < V; i++)
    {
        printf("%4d", i);
    }
    printf("\n");

    for (int i = 0; i < V; i++)
    {
        printf("%3d: ", i);
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == 0)
            {
                printf("   -");
            }
            else
            {
                printf("%4d", graph[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Main function demonstrating Prim's algorithm
 * @return 0 on successful execution
 */
int main()
{
    printf("🔗 Graph Theory Algorithms - Prim's Minimum Spanning Tree\n");
    printf("=========================================================\n\n");

    // Example graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 1, 4, 0},
        {1, 0, 2, 5},
        {4, 2, 0, 1},
        {0, 5, 1, 0}};

    printGraph(graph);

    // Run Prim's algorithm
    primAlgorithm(graph);

    printf("\n💡 Note: Prim's algorithm grows the MST one vertex at a time.\n");
    printf("   It always chooses the minimum weight edge connecting a vertex\n");
    printf("   in the MST to a vertex outside the MST.\n");

    return 0;
}
