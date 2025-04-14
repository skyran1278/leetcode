#!/bin/bash
gcc -v
g++ -v

# Install conda environment.
conda init zsh
conda config --set auto_activate_base false
conda env create -f environment.yml

# Install node packages.
pnpm install
