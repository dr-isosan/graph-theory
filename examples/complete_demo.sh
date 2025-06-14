#!/bin/zsh

# Complete demonstration script for Graph Theory Algorithms
# This script shows all algorithms with beautiful formatted output

echo "🔗 Graph Theory Algorithms Collection - Complete Demo"
echo "====================================================="
echo ""
echo "This demonstration showcases five fundamental graph algorithms:"
echo "1. Dijkstra's Algorithm (Shortest Path)"
echo "2. Bellman-Ford Algorithm (Shortest Path with Negative Weights)"
echo "3. Kruskal's Algorithm (Minimum Spanning Tree)"
echo "4. Prim's Algorithm (Minimum Spanning Tree)"
echo "5. Ford-Fulkerson Algorithm (Maximum Flow)"
echo ""
echo "Press Enter to begin the demonstration..."
read

# Compile if needed
if [ ! -d "../build" ] || [ ! -f "../build/dijkstra" ]; then
    echo "🔧 Compiling algorithms..."
    cd .. && make all && cd examples
    echo ""
fi

# Function to display algorithm header
show_algorithm() {
    local name="$1"
    local description="$2"

    echo ""
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    echo "🔍 Algorithm: $name"
    echo "📝 Description: $description"
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    echo ""
}

# Function to pause between algorithms
pause_demo() {
    echo ""
    echo "⏸️  Press Enter to continue to the next algorithm..."
    read
}

# Algorithm 1: Dijkstra's Algorithm
show_algorithm "Dijkstra's Shortest Path" "Finds shortest paths from source to all vertices (non-negative weights)"
../build/dijkstra
pause_demo

# Algorithm 2: Bellman-Ford Algorithm
show_algorithm "Bellman-Ford Shortest Path" "Handles negative weights and detects negative cycles"
../build/bellman-ford
pause_demo

# Algorithm 3: Kruskal's Algorithm
show_algorithm "Kruskal's Minimum Spanning Tree" "Builds MST using edge-based greedy approach"
echo "📋 Sample input for Kruskal's algorithm:"
echo "Number of vertices: 4"
echo "Adjacency Matrix:"
echo "0 1 4 0"
echo "1 0 2 5"
echo "4 2 0 1"
echo "0 5 1 0"
echo ""
echo "4" | ../build/kruskal << 'EOF'
0 1 4 0
1 0 2 5
4 2 0 1
0 5 1 0
EOF
pause_demo

# Algorithm 4: Prim's Algorithm
show_algorithm "Prim's Minimum Spanning Tree" "Builds MST using vertex-based greedy approach"
../build/prim
pause_demo

# Algorithm 5: Ford-Fulkerson Algorithm
show_algorithm "Ford-Fulkerson Maximum Flow" "Computes maximum flow in a flow network"
../build/ford-fulkerson

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "🎉 Demonstration Complete!"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
echo "📊 Algorithm Summary:"
echo "   • Dijkstra:     O(V²) time, best for non-negative weights"
echo "   • Bellman-Ford: O(VE) time, handles negative weights"
echo "   • Kruskal:      O(E log E) time, edge-based MST"
echo "   • Prim:         O(V²) time, vertex-based MST"
echo "   • Ford-Fulkerson: O(VE²) time, maximum flow"
echo ""
echo "🚀 Ready for GitHub! This project includes:"
echo "   ✅ Clean, documented code"
echo "   ✅ Comprehensive README with examples"
echo "   ✅ Build system with Makefile"
echo "   ✅ Beautiful formatted output"
echo "   ✅ Error handling and input validation"
echo "   ✅ MIT License for open source"
echo "   ✅ Contributing guidelines"
echo ""
echo "📁 To explore the code:"
echo "   • Check individual .c files for implementations"
echo "   • Read README.md for usage instructions"
echo "   • See ALGORITHMS.md for technical details"
echo "   • Review CONTRIBUTING.md for collaboration"
echo ""
echo "🌟 Star this repository if you found it helpful!"
