#!/bin/zsh

# Performance benchmarking script for graph algorithms
# This script measures execution time and provides complexity analysis

echo "📊 Graph Theory Algorithms - Performance Analysis"
echo "================================================"
echo ""

# Check if build exists
if [ ! -d "../build" ]; then
    echo "🔧 Building algorithms first..."
    cd .. && make all && cd examples
    echo ""
fi

echo "🔬 Running performance tests..."
echo ""

# Function to time algorithm execution
benchmark_algorithm() {
    local name="$1"
    local executable="$2"
    local description="$3"

    echo "┌─────────────────────────────────────────────────────────────┐"
    echo "│ Algorithm: $name"
    echo "│ Description: $description"
    echo "├─────────────────────────────────────────────────────────────┤"

    # Run the algorithm and measure time
    local start_time=$(date +%s.%N)
    ../$executable > /dev/null 2>&1
    local end_time=$(date +%s.%N)
    local execution_time=$(echo "$end_time - $start_time" | bc -l)

    printf "│ Execution Time: %.4f seconds\n" $execution_time
    echo "└─────────────────────────────────────────────────────────────┘"
    echo ""
}

# Benchmark all algorithms
benchmark_algorithm "Dijkstra's Algorithm" "build/dijkstra" "Single-source shortest path (non-negative weights)"
benchmark_algorithm "Bellman-Ford Algorithm" "build/bellman-ford" "Single-source shortest path (negative weights ok)"
benchmark_algorithm "Prim's Algorithm" "build/prim" "Minimum spanning tree (vertex-based)"
benchmark_algorithm "Ford-Fulkerson Algorithm" "build/ford-fulkerson" "Maximum flow in flow networks"

echo "📈 Complexity Analysis Summary:"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
printf "%-20s %-15s %-15s %-25s\n" "Algorithm" "Time Complexity" "Space Complexity" "Best Use Case"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
printf "%-20s %-15s %-15s %-25s\n" "Dijkstra" "O(V²)" "O(V)" "Dense graphs, positive weights"
printf "%-20s %-15s %-15s %-25s\n" "Bellman-Ford" "O(VE)" "O(V)" "Negative weights, cycle detection"
printf "%-20s %-15s %-15s %-25s\n" "Kruskal" "O(E log E)" "O(V)" "Sparse graphs, MST"
printf "%-20s %-15s %-15s %-25s\n" "Prim" "O(V²)" "O(V)" "Dense graphs, MST"
printf "%-20s %-15s %-15s %-25s\n" "Ford-Fulkerson" "O(VE²)" "O(V²)" "Network flow problems"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
echo "💡 Note: Times may vary based on system performance and current load."
echo "   For accurate benchmarking, run tests multiple times and average results."
echo ""
echo "🔧 To run individual performance tests:"
echo "   time ../build/dijkstra"
echo "   time ../build/bellman-ford"
echo "   time ../build/kruskal"
echo "   time ../build/prim"
echo "   time ../build/ford-fulkerson"
