#!/bin/bash
gcc -v
g++ -v

# Install python packages.
uv sync --locked

# Install node packages.
pnpm install
