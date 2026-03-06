# COP4533-PA2-GreedyAlgorithms
## Contributors:
| Name           | UFID     |
|:--------------:|:--------:|
| Alexis Simpson | 11302807 |
| Kevin Rhoads   | 21495455 |

## Installation and Usage:
### 1. Clone the repository
```
git clone https://github.com/alexissimpson COP4533-PA2-GreedyAlgorithms.git
```

### 2. Navigate to the project directory
```
cd COP455-PA2-GreedyAlgorithms
```

### 3. Make build directory
```
mkdir build
cd build
```

### 4. Generate CMake build files
```
cmake ..
```

### 5. Build executable
```
cmake --build .
```

### 6. Run executable with test input file
#### Other input files will be places in /data/input
```
./cache_evictions.exe test_input1.txt
```

## Dependencies:
Must have CMake installed to build. Installed at https://cmake.org/download/

## Expected Input / Ouput:
Example input files are listed under /data/input.
The input file will be specified in a command alongside the executable as shown in step 6 above(./cache_evictions.exe \<filename>)

Each of the cache eviction functions will be run upon execution.
The result of these operations will be written to the OUTPUT.txt file located at /data/output/OUTPUT.txt.

Example output for running test_input1.txt is located in test_output1.txt at /data/output/test_output1.txt.

## Written Component:
### 1. Empirical Comparison

### 2. Bad Sequence for LRU or FIFO

### 3. Prove OPTFF is Optimal
