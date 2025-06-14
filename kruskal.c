/**
 * @file kruskal.c
 * @brief Implementation of Kruskal's Minimum Spanning Tree algorithm
 * @author İshak Duran (22060664)
 * @date 2025
 *
 * Kruskal's algorithm finds the minimum spanning tree of a graph using
 * a greedy approach. It sorts edges by weight and uses Union-Find to
 * detect cycles.
 *
 * Time Complexity: O(E log E)
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 30 // Maximum number of vertices

/**
 * @brief Structure to represent an edge
 */
typedef struct edge
{
    int u, v; // Vertices connected by the edge
    int w;    // Weight of the edge
} edge;

/**
 * @brief Structure to represent a list of edges
 */
typedef struct edgelist
{
    edge data[MAX]; // Array of edges
    int n;          // Number of edges
} edgelist;

// Global variables
edgelist elist;    // List of all edges in the graph
int G[MAX][MAX];   // Adjacency matrix representation
int n;             // Number of vertices
edgelist spanlist; // List of edges in the minimum spanning tree

// Function declarations
void kruskal();                             // Main Kruskal's algorithm
int find(int belongs[], int vertexno);      // Find operation for Union-Find
void union1(int belongs[], int c1, int c2); // Union operation for Union-Find
void sort();                                // Sort edges by weight
void print();                               // Print the MST result
void printGraph();                          // Print the input graph

/**
 * @brief Main function demonstrating Kruskal's algorithm
 */
int main()
{
    printf("🔗 Graph Theory Algorithms - Kruskal's Minimum Spanning Tree\n");
    printf("============================================================\n\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices. Must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nEnter the adjacency matrix:\n");
    printf("(Enter 0 for no edge between vertices)\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("G[%d][%d]: ", i, j);
            scanf("%d", &G[i][j]);
        }
    }

    printf("\n");
    printGraph();

    // Run Kruskal's algorithm
    kruskal();

    // Print the result
    print();

    return 0;
}

/**
 * @brief Implementation of Kruskal's algorithm for finding MST
 */
void kruskal()
{
    int belongs[MAX];
    elist.n = 0;

    printf("🔄 Building edge list from adjacency matrix...\n");

    // Build edge list from adjacency matrix (only upper triangle to avoid duplicates)
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (G[i][j] != 0)
            { // If edge exists
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = G[i][j];
                elist.n++;
            }
        }
    }

    printf("Found %d edges.\n", elist.n);

    // Sort edges by weight
    printf("🔄 Sorting edges by weight...\n");
    sort();

    printf("Sorted edges:\n");
    for (int i = 0; i < elist.n; i++)
    {
        printf("  %d-%d (weight: %d)\n",
               elist.data[i].u, elist.data[i].v, elist.data[i].w);
    }
    printf("\n");

    // Initialize Union-Find: each vertex is its own set
    for (int i = 0; i < n; i++)
    {
        belongs[i] = i;
    }

    spanlist.n = 0;

    printf("🔄 Processing edges for MST...\n");

    // Process edges in order of increasing weight
    for (int i = 0; i < elist.n; i++)
    {
        int cno1 = find(belongs, elist.data[i].u); // Find set of first vertex
        int cno2 = find(belongs, elist.data[i].v); // Find set of second vertex

        if (cno1 != cno2)
        { // If vertices are in different sets (no cycle)
            printf("  ✅ Adding edge %d-%d (weight: %d)\n",
                   elist.data[i].u, elist.data[i].v, elist.data[i].w);

            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n++;
            union1(belongs, cno1, cno2); // Union the two sets

            // If we have n-1 edges, we're done
            if (spanlist.n == n - 1)
            {
                break;
            }
        }
        else
        {
            printf("  ❌ Skipping edge %d-%d (would create cycle)\n",
                   elist.data[i].u, elist.data[i].v);
        }
    }
    printf("\n");
}

/**
 * @brief Find operation for Union-Find data structure
 * @param belongs Array representing the set membership
 * @param vertexno Vertex to find the set for
 * @return Set identifier for the vertex
 */
int find(int belongs[], int vertexno)
{
    return belongs[vertexno];
}

/**
 * @brief Union operation for Union-Find data structure
 * @param belongs Array representing the set membership
 * @param c1 First set identifier
 * @param c2 Second set identifier
 */
void union1(int belongs[], int c1, int c2)
{
    for (int i = 0; i < n; i++)
    {
        if (belongs[i] == c2)
        {
            belongs[i] = c1; // Merge second set into first set
        }
    }
}

/**
 * @brief Sort edges by weight using bubble sort
 */
void sort()
{
    edge temp;
    for (int i = 1; i < elist.n; i++)
    {
        for (int j = 0; j < elist.n - 1; j++)
        {
            if (elist.data[j].w > elist.data[j + 1].w)
            { // Sort by weight
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Print the input graph
 */
void printGraph()
{
    printf("Input Graph (Adjacency Matrix):\n");
    printf("     ");
    for (int i = 0; i < n; i++)
    {
        printf("%4d", i);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%3d: ", i);
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                printf("   -");
            }
            else
            {
                printf("%4d", G[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Print the minimum spanning tree result
 */
void print()
{
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║                   KRUSKAL'S ALGORITHM RESULT                  ║\n");
    printf("╠═══════════════════════════════════════════════════════════════╣\n");
    printf("║                   Minimum Spanning Tree Edges                 ║\n");
    printf("╠════════════════════╤════════════════════╤══════════════════════╣\n");
    printf("║       Edge         │       Vertices     │       Weight         ║\n");
    printf("╠════════════════════╪════════════════════╪══════════════════════╣\n");

    int totalCost = 0;
    for (int i = 0; i < spanlist.n; i++)
    {
        printf("║       %2d           │        %d - %d       │         %2d           ║\n",
               i + 1, spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        totalCost += spanlist.data[i].w;
    }

    printf("╠════════════════════╧════════════════════╧══════════════════════╣\n");
    printf("║  Total MST Cost: %-44d ║\n", totalCost);
    printf("╚═══════════════════════════════════════════════════════════════╝\n");

    printf("\n💡 Note: Kruskal's algorithm uses Union-Find to efficiently detect cycles.\n");
    printf("   It processes edges in ascending order of weight.\n");
}
