# Contributing to Graph Theory Algorithms

We welcome contributions to this project! Here's how you can help improve the Graph Theory Algorithms collection.

## 🤝 How to Contribute

### Reporting Issues

- Use the GitHub issue tracker to report bugs
- Include detailed steps to reproduce the issue
- Specify your operating system and compiler version
- Provide sample input/output if applicable

### Suggesting Enhancements

- Open an issue with the "enhancement" label
- Clearly describe the proposed feature
- Explain why it would be useful
- Consider backward compatibility

### Submitting Code Changes

1. **Fork the repository**
2. **Create a feature branch**

   ```bash
   git checkout -b feature/algorithm-name
   ```

3. **Make your changes**
   - Follow the coding standards below
   - Add appropriate comments
   - Update documentation if needed

4. **Test your changes**

   ```bash
   make clean && make all
   make test
   ```

5. **Commit your changes**

   ```bash
   git commit -m "Add: Implementation of [Algorithm Name]"
   ```

6. **Push to your fork**

   ```bash
   git push origin feature/algorithm-name
   ```

7. **Create a Pull Request**

## 📝 Coding Standards

### Code Style

- Use consistent indentation (4 spaces)
- Follow C99 standard
- Use descriptive variable names
- Include function documentation comments

### Function Documentation

```c
/**
 * @brief Brief description of the function
 * @param param1 Description of parameter 1
 * @param param2 Description of parameter 2
 * @return Description of return value
 */
```

### File Header

```c
/**
 * @file filename.c
 * @brief Brief description of the algorithm
 * @author Your Name
 * @date Year
 *
 * Detailed description of the algorithm including:
 * - Time complexity
 * - Space complexity
 * - Use cases
 */
```

### Variable Naming

- Use `camelCase` for function names
- Use `snake_case` for variable names
- Use `UPPER_CASE` for constants
- Use descriptive names (avoid single letters except for loop counters)

### Error Handling

- Check for invalid inputs
- Provide meaningful error messages
- Handle memory allocation failures
- Validate array bounds

## 🧪 Testing Guidelines

### Test Cases

- Include edge cases (empty graphs, single vertex, etc.)
- Test with various graph sizes
- Verify algorithm correctness with known solutions
- Test error handling paths

### Performance Testing

- Measure execution time for different input sizes
- Monitor memory usage
- Compare with theoretical complexity

### Documentation Testing

- Ensure README examples work
- Verify code comments are accurate
- Test compilation instructions

## 📊 Algorithm Implementation Checklist

When implementing a new algorithm:

- [ ] **Algorithm correctness**: Verify against known test cases
- [ ] **Input validation**: Check for invalid inputs
- [ ] **Memory management**: Proper allocation and deallocation
- [ ] **Error handling**: Graceful handling of edge cases
- [ ] **Documentation**: Complete function and file documentation
- [ ] **Formatting**: Consistent code style
- [ ] **Testing**: Comprehensive test cases
- [ ] **Integration**: Update Makefile and README
- [ ] **Examples**: Provide usage examples

## 🏗️ Project Structure

When adding new files:

```
graph-theory-algorithms/
├── src/                    # Source files (.c)
├── include/               # Header files (.h) - if needed
├── tests/                 # Test files
├── examples/              # Example usage
├── docs/                  # Additional documentation
├── Makefile              # Build configuration
└── README.md             # Main documentation
```

## 💡 Algorithm Ideas for Contribution

### High Priority

- [ ] Floyd-Warshall Algorithm (All-pairs shortest path)
- [ ] A* Search Algorithm
- [ ] Johnson's Algorithm
- [ ] Topological Sort

### Medium Priority

- [ ] Kosaraju's Algorithm (Strongly Connected Components)
- [ ] Tarjan's Algorithm (Bridges and Articulation Points)
- [ ] Maximum Bipartite Matching
- [ ] Minimum Cut algorithms

### Low Priority

- [ ] Graph coloring algorithms
- [ ] Hamiltonian path algorithms
- [ ] Network flow variants
- [ ] Approximation algorithms

## 🔍 Code Review Process

All submissions go through code review:

1. **Automated checks**: Compilation, basic tests
2. **Manual review**: Code quality, documentation, design
3. **Testing**: Functionality and performance validation
4. **Documentation**: Accuracy and completeness

## 📞 Getting Help

If you need help with contributions:

- Check existing issues and documentation
- Ask questions in issue comments
- Reach out to maintainers
- Join community discussions

## 🏆 Recognition

Contributors will be:

- Listed in the README
- Credited in relevant source files
- Acknowledged in release notes

Thank you for contributing to the Graph Theory Algorithms project!
