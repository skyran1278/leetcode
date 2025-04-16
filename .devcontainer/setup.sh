#!/bin/bash
gcc -v
g++ -v

# Install python packages.
conda env create -f environment.yml

# Install node packages.
pnpm install
