/**
 * @file bellman-ford.c
 * @brief Implementation of Bellman-Ford shortest path algorithm
 * @author İshak Duran (22060664)
 * @date 2025
 *
 * The Bellman-Ford algorithm finds shortest paths from a source vertex
 * to all other vertices in a weighted graph. Unlike Dijkstra's algorithm,
 * it can handle negative edge weights and detect negative cycles.
 *
 * Time Complexity: O(VE)
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

/**
 * @brief Structure to represent an edge in the graph
 */
struct Edge
{
    int src;    // Source vertex
    int dest;   // Destination vertex
    int weight; // Weight of the edge
};

/**
 * @brief Structure to represent a graph
 */
struct Graph
{
    int V;             // Number of vertices
    int E;             // Number of edges
    struct Edge *edge; // Array of edges
};
/**
 * @brief Create a graph with V vertices and E edges
 * @param V Number of vertices
 * @param E Number of edges
 * @return Pointer to the created graph
 */
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    if (!graph)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));

    if (!graph->edge)
    {
        printf("Memory allocation failed!\n");
        free(graph);
        exit(1);
    }

    return graph;
}

/**
 * @brief Print the shortest distances and paths from source
 * @param dist Array containing shortest distances
 * @param n Number of vertices
 * @param parent Array containing parent vertices for path reconstruction
 */
void printSolution(int dist[], int n, int parent[])
{
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║                   BELLMAN-FORD ALGORITHM RESULT               ║\n");
    printf("╠═══════════════════════════════════════════════════════════════╣\n");
    printf("║ Vertex │ Distance │ Path                                      ║\n");
    printf("╠════════╪══════════╪═══════════════════════════════════════════╣\n");

    for (int i = 0; i < n; i++)
    {
        printf("║   %d    │", i);

        if (dist[i] == INF)
        {
            printf("    ∞    │ No path available");
        }
        else
        {
            printf("   %3d   │ ", dist[i]);

            // Print path by backtracking through parent array
            int path[n], pathLength = 0;
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
        }

        // Add padding for alignment
        printf("%*s║\n", (int)(37 - (dist[i] == INF ? 18 : 0)), "");
    }
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
}

/**
 * @brief Implementation of Bellman-Ford shortest path algorithm
 * @param graph Pointer to the graph structure
 * @param src Source vertex
 * @return true if no negative cycle exists, false otherwise
 */
bool BellmanFord(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int parent[V]; // Array to store parent vertices for path reconstruction

    // Step 1: Initialize distances and parents
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Step 2: Relax all edges V-1 times
    printf("🔄 Relaxing edges (V-1 = %d iterations)...\n", V - 1);
    for (int i = 1; i <= V - 1; i++)
    {
        bool updated = false;

        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u; // Update parent for path reconstruction
                updated = true;
            }
        }

        // Early termination if no updates in this iteration
        if (!updated)
        {
            printf("✅ Converged early at iteration %d\n", i);
            break;
        }
    }

    // Step 3: Check for negative cycles
    printf("🔍 Checking for negative cycles...\n");
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;

        if (dist[u] != INF && dist[u] + weight < dist[v])
        {
            printf("❌ Negative cycle detected!\n");
            printf("   The graph contains a negative-weight cycle reachable from source.\n");
            printf("   Shortest distances are not well-defined.\n");
            return false;
        }
    }

    printf("✅ No negative cycles found.\n\n");

    // Print the computed distances and paths
    printSolution(dist, V, parent);
    return true;
}

/**
 * @brief Main function demonstrating Bellman-Ford algorithm
 * @return 0 on successful execution
 */
int main()
{
    printf("🔗 Graph Theory Algorithms - Bellman-Ford Shortest Path\n");
    printf("=======================================================\n\n");

    // Create a graph with 5 vertices and 8 edges
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    struct Graph *graph = createGraph(V, E);

    // Add edges to the graph
    // Edge 0: 0 → 1 with weight -1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // Edge 1: 0 → 2 with weight 4
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // Edge 2: 1 → 2 with weight 3
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // Edge 3: 1 → 3 with weight 2
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // Edge 4: 1 → 4 with weight 2
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // Edge 5: 3 → 2 with weight 5
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // Edge 6: 3 → 1 with weight 1
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // Edge 7: 4 → 3 with weight -3
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    // Display graph information
    printf("Input Graph (Edge List):\n");
    printf("Vertices: %d, Edges: %d\n", V, E);
    printf("Edge List:\n");
    for (int i = 0; i < E; i++)
    {
        printf("  %d → %d (weight: %d)\n",
               graph->edge[i].src,
               graph->edge[i].dest,
               graph->edge[i].weight);
    }
    printf("\nSource vertex: 0\n\n");

    // Run Bellman-Ford algorithm starting from vertex 0
    bool result = BellmanFord(graph, 0);

    if (result)
    {
        printf("\n💡 Note: Bellman-Ford can handle negative edge weights.\n");
        printf("   It can also detect negative cycles in the graph.\n");
    }

    // Clean up memory
    free(graph->edge);
    free(graph);

    return 0;
}
