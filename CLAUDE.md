# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a multi-language coding practice repository covering LeetCode problems, Cracking the Coding Interview (CTCI), Hello Algo. Problems are solved primarily in **C++** and **TypeScript**, with some **Python**.

## Commands

### TypeScript / Node.js

```bash
pnpm install          # Install dependencies
pnpm test             # Run Jest in watch mode
pnpm lint             # ESLint with auto-fix
pnpm format           # Prettier with auto-format
```

Run a single test file:

```bash
pnpm exec jest "path/to/file.test.ts" --no-coverage
```

Press `F5` to run the current file and view debug console output in VS Code. (Ignore module warning error.)

### C++

Create a new problem scaffold:

```bash
sh scripts/create_leetcode_file.sh <folder name>
```

Press `F5` to run and compile all `.cpp` files in a problem directory:

```bash
g++ -fdiagnostics-color=always -g -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++23 "path/to/dir/"*.cpp -o path/to/dir/Solution.out
./path/to/dir/Solution.out
```

### Python

```bash
uv sync --locked                      # Install Python dependencies
uv run scripts/timing_stats.py       # Analyze @brief timing annotations
```

## Project Structure

```
leetcode/                          # LeetCode problems — JS/TS files
Cracking the Coding Interview/     # CTCI chapters 1–8 — C++ and TypeScript
  1 Arrays and Strings/
  2 Linked Lists/
  3 Stacks and Queues/
  4 Trees and Graphs/
  5 Bit Manipulation/
  7 Object-Oriented Design/
  8 Recursion and Dynamic Programming/
Hello Algo/                        # Algorithm implementations — C++
Algorithms/                        # Sedgewick Algorithms 4th ed. — Java
scripts/
  create_leetcode_file.sh          # Scaffold a new C++ solution
  timing_stats.py                  # Aggregate @brief timings via PySpark
```

## Language Conventions

### C++

- Standard: **C++23** with `-Werror` (all warnings are errors)
- Formatting: clang-format with **Google** base style (`.clang-format`)
- Each problem lives in its own directory; all `.cpp` files there are compiled together
- Shared data structures (e.g., `TreeNode`, `ListNode`) are defined inline in each `Solution.cpp` — no shared headers
- Track attempt timing in `@brief` comments:
  ```cpp
  /**
   * @brief 45m (editorial)   // stuck, studied the editorial / hint
   * @brief 8m (recall)       // redo within ~1 week of an (editorial) attempt
   * @brief -- (untimed)      // solved but forgot to time it
   * @brief 15m 30s           // clean independent solve — counts toward stats
   * O(n)
   * O(n)
   */
  ```
  Only untagged `@brief` lines feed `timing_stats.py`. Tagged lines (`editorial` / `recall` / `untimed`) preserve history without polluting the baseline.

### TypeScript

- ESLint: `typescript-eslint` strict + stylistic type-checked rules
- Prettier: single quotes, trailing commas, sorted imports via `@ianvs/prettier-plugin-sort-imports`
- Each problem has a `<name>.ts` solution and a `<name>.test.ts` Jest test file
- Unused args prefixed with `_` are allowed; unused variables emit warnings, not errors

### Python

- Requires Python 3.10+, managed with `uv`
- Dependencies: `pyspark` (used for timing analysis)
