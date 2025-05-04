#!/bin/bash

# Script: create_leetcode_file.sh
# Purpose: Creates a directory and a basic C++ solution file for a LeetCode problem.
# Usage: ./create_leetcode_file.sh <problem_title>...
# Example: ./create_leetcode_file.sh two sum

# --- Configuration ---

# Base directory for all LeetCode problems
BASE_DIR="leetcode"

# Default C++ template content
CPP_TEMPLATE=$(cat << 'EOF'
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


EOF
)

# --- Script Logic ---

# Check if a problem title was provided
if [ $# -eq 0 ]; then
    echo "Error: No problem title provided."
    echo "Usage: $0 <problem_title>"
    echo "Example: $0 two sum"
    exit 1
fi

# Join all arguments to form the problem title (handles spaces)
PROBLEM_TITLE="$@"

# Construct the full directory path
TARGET_DIR="$BASE_DIR/$PROBLEM_TITLE"

# Construct the full file path for the C++ solution
SOLUTION_FILE="$TARGET_DIR/Solution.cpp"

# Create the target directory, including any parent directories if needed (-p)
mkdir -p "$TARGET_DIR"
if [ $? -ne 0 ]; then
    echo "Error: Failed to create directory '$TARGET_DIR'."
    exit 1
fi

# Check if the solution file already exists
if [ -f "$SOLUTION_FILE" ]; then
    echo "File '$SOLUTION_FILE' already exists. Skipping creation."
else
    # Create and populate the solution file using the template
    echo "$CPP_TEMPLATE" > "$SOLUTION_FILE"
    if [ $? -ne 0 ]; then
        echo "Error: Failed to create file '$SOLUTION_FILE'."
        # Optional: Clean up the created directory if file creation fails
        # rmdir "$TARGET_DIR" &> /dev/null
        exit 1
    fi
    echo "Successfully created '$SOLUTION_FILE'."
fi

code "$SOLUTION_FILE"

exit 0
