#!/bin/bash

# Graph Theory Algorithms Demo Script
# This script demonstrates all implemented algorithms

echo "🔗 Graph Theory Algorithms Collection Demo"
echo "=========================================="
echo ""
echo "This demo will run all implemented algorithms with sample data."
echo "Press Enter to continue or Ctrl+C to exit..."
read

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Compiling algorithms..."
    make all
    echo ""
fi

# Function to run algorithm with header
run_algorithm() {
    local name="$1"
    local executable="$2"

    echo "┌─────────────────────────────────────────────────────────────┐"
    echo "│ Running: $name"
    echo "├─────────────────────────────────────────────────────────────┤"
    echo ""

    if [ -f "build/$executable" ]; then
        ./build/$executable
    else
        echo "❌ Error: $executable not found in build directory"
    fi

    echo ""
    echo "└─────────────────────────────────────────────────────────────┘"
    echo ""
    echo "Press Enter to continue to next algorithm..."
    read
}

# Run all algorithms
run_algorithm "Dijkstra's Shortest Path Algorithm" "dijkstra"
run_algorithm "Bellman-Ford Shortest Path Algorithm" "bellman-ford"
run_algorithm "Kruskal's Minimum Spanning Tree Algorithm" "kruskal"
run_algorithm "Prim's Minimum Spanning Tree Algorithm" "prim"
run_algorithm "Ford-Fulkerson Maximum Flow Algorithm" "ford-fulkerson"

echo "🎉 Demo completed! All algorithms have been demonstrated."
echo ""
echo "To run individual algorithms:"
echo "  ./build/dijkstra"
echo "  ./build/bellman-ford"
echo "  ./build/kruskal"
echo "  ./build/prim"
echo "  ./build/ford-fulkerson"
echo ""
echo "To recompile: make clean && make all"
