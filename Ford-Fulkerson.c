/**
 * @file Ford-Fulkerson.c
 * @brief Implementation of Ford-Fulkerson maximum flow algorithm
 * @author İshak Duran (22060664)
 * @date 2025
 *
 * The Ford-Fulkerson algorithm computes the maximum flow in a flow network.
 * This implementation uses BFS (Edmonds-Karp) to find augmenting paths.
 *
 * Time Complexity: O(VE²)
 * Space Complexity: O(V²)
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define V 6 // Number of vertices in the graph
#define INF INT_MAX

/**
 * @brief BFS to find if there is a path from source to sink in residual graph
 * @param rGraph Residual graph represented as adjacency matrix
 * @param s Source vertex
 * @param t Sink vertex
 * @param parent Array to store the path from source to sink
 * @return true if there is a path from source to sink, false otherwise
 */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, false, sizeof(visited));

    // Create a queue for BFS
    int queue[V];
    int front = 0, rear = 0;

    // Mark the source node as visited and enqueue it
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (front < rear)
    {
        // Dequeue a vertex from queue
        int u = queue[front++];

        // Get all adjacent vertices of the dequeued vertex u
        // If an adjacent vertex is not visited, mark it visited and enqueue it
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                // If we find a connection to the sink node, then there is no point
                // in BFS anymore. We just have to set its parent and return true
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // We didn't reach sink in BFS starting from source, so return false
    return false;
}

/**
 * @brief Implementation of Ford-Fulkerson algorithm using Edmonds-Karp (BFS)
 * @param graph Original graph represented as adjacency matrix
 * @param s Source vertex
 * @param t Sink vertex
 * @return Maximum flow value from source to sink
 */
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    // Create a residual graph and fill it with original capacities
    int rGraph[V][V];
    for (u = 0; u < V; u++)
    {
        for (v = 0; v < V; v++)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];    // Array to store path from source to sink
    int max_flow = 0; // Initialize max flow to 0
    int iteration = 0;

    printf("🔄 Finding augmenting paths:\n");

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        iteration++;

        // Find minimum residual capacity of the edges along the path
        // filled by BFS, or find the maximum flow through the path found
        int path_flow = INF;
        printf("\nIteration %d:\n", iteration);
        printf("  Path found: ");

        // Print the path
        for (v = t; v != s; v = parent[v])
        {
            printf("%d <- ", v);
        }
        printf("%d\n", s);

        // Find bottleneck capacity
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            if (rGraph[u][v] < path_flow)
            {
                path_flow = rGraph[u][v];
            }
        }

        printf("  Bottleneck capacity: %d\n", path_flow);

        // Add path flow to overall flow
        max_flow += path_flow;

        // Update residual capacities of the edges and reverse edges
        // along the path
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow; // Decrease forward edge
            rGraph[v][u] += path_flow; // Increase backward edge
        }

        printf("  Current total flow: %d\n", max_flow);
    }

    printf("\n✅ No more augmenting paths found.\n");

    // Return the overall flow
    return max_flow;
}

/**
 * @brief Print the input graph
 * @param graph Adjacency matrix to print
 */
void printGraph(int graph[V][V])
{
    printf("Input Graph (Capacity Matrix):\n");
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
 * @brief Main function demonstrating Ford-Fulkerson algorithm
 * @return 0 on successful execution
 */
int main()
{
    printf("🔗 Graph Theory Algorithms - Ford-Fulkerson Maximum Flow\n");
    printf("========================================================\n\n");

    // Example flow network represented as capacity matrix
    // graph[i][j] = capacity of edge from vertex i to vertex j
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};

    printGraph(graph);

    int source = 0, sink = 5; // Define source and sink vertices

    printf("Source vertex: %d\n", source);
    printf("Sink vertex: %d\n\n", sink);

    // Run Ford-Fulkerson algorithm
    int maxFlow = fordFulkerson(graph, source, sink);

    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║                 FORD-FULKERSON ALGORITHM RESULT               ║\n");
    printf("╠═══════════════════════════════════════════════════════════════╣\n");
    printf("║  Maximum Flow from vertex %d to vertex %d: %-18d ║\n", source, sink, maxFlow);
    printf("╚═══════════════════════════════════════════════════════════════╝\n");

    printf("\n💡 Note: This implementation uses BFS (Edmonds-Karp) to find\n");
    printf("   augmenting paths, which guarantees O(VE²) time complexity.\n");

    return 0;
}
