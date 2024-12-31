# LSM Tree Implementation

This project implements a Log-Structured Merge Tree (LSM Tree) with a memtable, SSTables, and a Bloom filter for efficient key-value storage and retrieval. It includes a CLI for interactive usage and a benchmarking tool to measure performance.

## Features

- **Memtable**: In-memory storage for fast inserts and lookups.
- **SSTables**: On-disk storage for persistent data.
- **Bloom Filter**: Reduces unnecessary disk reads for non-existent keys.
- **Compaction**: Merges SSTables and memtable to optimize storage.
- **Benchmarking**: Measures negative and random access performance.

## Usage

### Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

### Run the CLI

```bash
./lsm_tree
```

### Commands

- **insert**: Insert a key-value pair.
  ```bash
  insert <key> <value>
  ```
- **get**: Retrieve the value for a key.
  ```bash
  get <key>
  ```
- **delete**: Delete a key.
  ```bash
  delete <key>
  ```
- **compact**: Compact the LSM tree.
  ```bash
  compact
  ```
- **display**: Display the contents of the memtable and SSTables.
  ```bash
  display
  ```
- **benchmark**: Run performance benchmarks.
  ```bash
  benchmark
  ```
- **exit**: Exit the CLI.
  ```bash
  exit
  ```

### Benchmark Results

- **Negative Access Time**: Measures the time taken to check for non-existent keys.
- **Random Access Time**: Measures the time taken to retrieve existing keys.

Example Output:
```bash
Negative access time: 0.061428 seconds
Random access time: 0.062047 seconds
```

## Next Steps

- [ ] **Implement Tombstoning**: Properly handle deletions by marking keys as deleted.
- [ ] **Multi-Level SSTables**: Introduce multiple levels of SSTables for better compaction.
- [ ] **Concurrency Support**: Add thread-safe operations for concurrent access.
- [ ] **Optimize Bloom Filter**: Fine-tune Bloom filter parameters for better performance.
- [ ] **Add More Benchmarks**: Include benchmarks for insertions, deletions, and compactions.
- [ ] **Documentation**: Add detailed documentation for the code and APIs.
- [ ] **Error Handling**: Improve error handling and logging.

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes and push to the branch.
4. Submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
