# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
DEBUG_FLAGS = -g -DDEBUG

# Directories
SRC_DIR = .
BUILD_DIR = build
TEST_DIR = tests

# Source files
SOURCES = dijkstra.c bellman-ford.c kruskal.c prim.c Ford-Fulkerson.c

# Executable names
EXECUTABLES = dijkstra bellman-ford kruskal prim ford-fulkerson

# Default target
all: $(BUILD_DIR) $(EXECUTABLES)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Individual targets
dijkstra: $(SRC_DIR)/dijkstra.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

bellman-ford: $(SRC_DIR)/bellman-ford.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

kruskal: $(SRC_DIR)/kruskal.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

prim: $(SRC_DIR)/prim.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

ford-fulkerson: $(SRC_DIR)/Ford-Fulkerson.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

# Debug builds
debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

# Test target
test: all
	@echo "Running algorithm tests..."
	@echo "Testing Dijkstra's Algorithm:"
	@$(BUILD_DIR)/dijkstra
	@echo "\n" "=" * 50
	@echo "Testing Bellman-Ford Algorithm:"
	@$(BUILD_DIR)/bellman-ford
	@echo "\n" "=" * 50
	@echo "Testing Kruskal's Algorithm:"
	@$(BUILD_DIR)/kruskal
	@echo "\n" "=" * 50
	@echo "Testing Prim's Algorithm:"
	@$(BUILD_DIR)/prim
	@echo "\n" "=" * 50
	@echo "Testing Ford-Fulkerson Algorithm:"
	@$(BUILD_DIR)/ford-fulkerson

# Demo target
demo: all
	@echo "🚀 Graph Theory Algorithms Demo"
	@echo "================================"
	@for exe in $(EXECUTABLES); do \
		echo "\n📊 Running $$exe:"; \
		echo "-------------------"; \
		$(BUILD_DIR)/$$exe; \
		echo; \
	done

# Clean target
clean:
	rm -rf $(BUILD_DIR)

# Install target (copies executables to /usr/local/bin)
install: all
	sudo cp $(BUILD_DIR)/* /usr/local/bin/

# Uninstall target
uninstall:
	sudo rm -f /usr/local/bin/dijkstra
	sudo rm -f /usr/local/bin/bellman-ford
	sudo rm -f /usr/local/bin/kruskal
	sudo rm -f /usr/local/bin/prim
	sudo rm -f /usr/local/bin/ford-fulkerson

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build all algorithms"
	@echo "  dijkstra     - Build Dijkstra's algorithm"
	@echo "  bellman-ford - Build Bellman-Ford algorithm"
	@echo "  kruskal      - Build Kruskal's algorithm"
	@echo "  prim         - Build Prim's algorithm"
	@echo "  ford-fulkerson - Build Ford-Fulkerson algorithm"
	@echo "  debug        - Build with debug flags"
	@echo "  test         - Run all algorithms with test data"
	@echo "  demo         - Run a formatted demo of all algorithms"
	@echo "  clean        - Remove build directory"
	@echo "  install      - Install executables to /usr/local/bin"
	@echo "  uninstall    - Remove installed executables"
	@echo "  help         - Show this help message"

# Phony targets
.PHONY: all debug test demo clean install uninstall help
