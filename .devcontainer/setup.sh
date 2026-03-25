#!/bin/bash
gcc -v
g++ -v

# Set up zsh configuration by symlinking from the devcontainer directory to the home directory
ln -sf "$PWD/.devcontainer/.p10k.zsh" ~/
ln -sf "$PWD/.devcontainer/.zshrc" ~/

# Install python packages.
uv sync --locked

# Install node packages.
COREPACK_ENABLE_DOWNLOAD_PROMPT=0 pnpm install
