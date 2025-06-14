# Graph Theory Algorithms - Technical Documentation

## Algorithm Complexity Analysis

### Dijkstra's Algorithm

- **Time Complexity**: O(V²) with adjacency matrix, O((V + E) log V) with priority queue
- **Space Complexity**: O(V)
- **Best Use Case**: Single-source shortest path with non-negative weights
- **Limitations**: Cannot handle negative edge weights

### Bellman-Ford Algorithm

- **Time Complexity**: O(VE)
- **Space Complexity**: O(V)
- **Best Use Case**: Single-source shortest path with negative weights, cycle detection
- **Advantages**: Can detect negative cycles, handles negative weights

### Kruskal's Algorithm

- **Time Complexity**: O(E log E) due to sorting edges
- **Space Complexity**: O(V) for Union-Find structure
- **Best Use Case**: Finding MST when edges are given as a list
- **Key Feature**: Uses Union-Find data structure for cycle detection

### Prim's Algorithm

- **Time Complexity**: O(V²) with adjacency matrix, O(E log V) with priority queue
- **Space Complexity**: O(V)
- **Best Use Case**: Finding MST when graph is dense
- **Key Feature**: Grows MST one vertex at a time

### Ford-Fulkerson Algorithm (Edmonds-Karp)

- **Time Complexity**: O(VE²)
- **Space Complexity**: O(V²)
- **Best Use Case**: Maximum flow problems in flow networks
- **Key Feature**: Uses BFS to find augmenting paths

## Implementation Details

### Data Structures Used

1. **Adjacency Matrix**: Used in Dijkstra, Prim, and Ford-Fulkerson
   - Efficient for dense graphs
   - O(1) edge lookup time
   - O(V²) space requirement

2. **Edge List**: Used in Bellman-Ford and Kruskal
   - Efficient for sparse graphs
   - Easy to sort edges by weight
   - O(E) space requirement

3. **Union-Find**: Used in Kruskal's algorithm
   - Efficient cycle detection
   - Nearly O(1) amortized operations with path compression

### Key Optimizations

1. **Early Termination**:
   - Bellman-Ford stops early if no updates occur
   - Kruskal stops when MST is complete (V-1 edges)

2. **Path Reconstruction**: All shortest path algorithms store parent information for path recovery

3. **Input Validation**: Algorithms check for invalid inputs and edge cases

## Testing and Validation

### Test Cases Included

1. **Dijkstra**: 5-vertex graph with various edge weights
2. **Bellman-Ford**: Graph with negative edges to demonstrate capability
3. **Kruskal**: User input for custom graph testing
4. **Prim**: 4-vertex complete graph
5. **Ford-Fulkerson**: 6-vertex flow network

### Expected Outputs

Each algorithm produces formatted output showing:

- Input graph representation
- Step-by-step execution (where applicable)
- Final result with path/tree information
- Algorithm-specific metrics (total cost, flow value, etc.)

## Performance Benchmarks

Performance tests can be conducted using the following approach:

```bash
# Compile with optimization flags
make CFLAGS="-O2 -DNDEBUG"

# Time execution
time ./build/dijkstra
```

## Future Enhancements

1. **Additional Algorithms**:
   - Floyd-Warshall (all-pairs shortest path)
   - Topological sorting
   - Strongly connected components
   - A* search algorithm

2. **Performance Improvements**:
   - Priority queue implementation for Dijkstra and Prim
   - Path compression in Union-Find for Kruskal
   - Parallel processing for independent operations

3. **Input/Output Enhancements**:
   - File input for large graphs
   - Graph visualization output
   - JSON/XML output formats

4. **Advanced Features**:
   - Dynamic graph updates
   - Weighted vertex problems
   - Directed vs undirected graph handling
