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
| Input File      | k | m | FIFO | LRU | OPTFF |
|:---------------:|:-:|:-:|:----:|:---:|:-----:|
| test_input1.txt |10 |60 |  51  | 51  |  41   |
| test_input2.txt | 5 |75 |  52  | 55  |  32   |
| test_input3.txt | 8 |80 |  42  | 45  |  28   |

For each of the test files above, OPTFF had significantly fewest misses.

FIFO consistently had fewer misses than LRU but the difference in misses wasn't as large as the difference between the misses for these eviction policies and OPTFF.

### 2. Bad Sequence for LRU or FIFO
For k = 3, there exists a request sequence for which OPTFF incurs strictly fewer misses than LRU and FIFO.

Example sequence: 1 4 5 3 2 4 2 1 1 3

| Eviction Policy | Misses |
|:---------------:|:------:|
|      OPTFF      |   6    |
|       LRU       |   8    |
|      FIFO       |   8    |

This request sequence shows that there does exist a request sequence with k=3 for which OPTFF incures strictly fewer misses than LRU and FIFO. This sequence uses k=3, m=10 and has the requests as shown above. When you run each cache eviction policy, OPTFF incurs only 6 misses while LRU and FIFO both had only 8 misses.

### 3. Prove OPTFF is Optimal
Let A be any offline algorithm that knows the full request sequence.  
#### Base Case:
Both caches are empty and misses<sub>OPTFF</sub> = misses<sub>A</sub>.  
#### Inductive Hypothesis:
Assume there exists an algorithm A' that agrees with OPTFF for requests r<sub>1</sub> through r<sub>i</sub> with misses<sub>A'</sub> $\le$ misses<sub>A</sub>.  
#### Inductive Step:
Consider request r<sub>i+1</sub> for caches OPTFF and A':
- Case 1: Both algorithms have a cache hit
  - Caches remain identical, misses<sub>OPTFF</sub> = misses<sub>A'</sub> $\le$ misses<sub>A</sub>
- Case 2: Both algorithms have a cache miss and evict the same data
  - Caches remain identical, misses<sub>OPTFF</sub> = misses<sub>A'</sub> $\le$ misses<sub>A</sub>
- Case 3: Both algorithms have a cache miss and evict different data
  - Let m be the data evicted by OPTFF and n be the data evicted by A'
  - Let A'' be an algorithm with identical behavior to A' but at request r<sub>i+1</sub> A'' evicts m instead of n
  - A'' has identical cache contents to OPTFF through r<sub>i+1</sub>
  - Since OPTFF chose m, it follows that n is requested before m
  - Until n is requested, A'' and A' have the same behavior
  - Case 3a: A'' evicts n before n was requested
    - A'' and A' have the same contents
    - When n is requested, neither has missed more than the other so it remains that misses<sub>OPTFF</sub> = misses<sub>A''</sub> $\le$ misses<sub>A'</sub> $\le$ misses<sub>A</sub>
  - Case 3b: A'' doesn't evict n before n was requested
    - A'' holds n while A' doesn't, so A'' hits when n is requested wherea A' misses
    - A' misses once more than A', so it remains that misses<sub>OPTFF</sub> = misses<sub>A''</sub> $\le$ misses<sub>A'</sub> $\le$ misses<sub>A</sub>
