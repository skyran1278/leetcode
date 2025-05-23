FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-24.04

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
    chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>

RUN apt update && apt install -y openjdk-17-jdk

USER vscode
WORKDIR /home/vscode

RUN git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ~/.powerlevel10k
COPY --chown=vscode:vscode .p10k.zsh .

RUN git clone https://github.com/zsh-users/zsh-autosuggestions ~/.zsh/zsh-autosuggestions
RUN git clone https://github.com/lukechilds/zsh-nvm.git ~/.zsh/zsh-nvm
RUN git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ~/.zsh/zsh-syntax-highlighting
RUN git clone https://github.com/zsh-users/zsh-history-substring-search.git ~/.zsh/zsh-history-substring-search

RUN git clone https://github.com/skyran1278/zshrc.git ~/Documents/zshrc
RUN ln -sf ~/Documents/zshrc/.zshrc ~/.zshrc

# Download and install Miniconda
RUN arch="$(uname -m)" && \
    mkdir -p ~/miniconda3 && \
    if [ "$arch" = "x86_64" ]; then \
    wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda3/miniconda.sh; \
    elif [ "$arch" = "aarch64" ]; then \
    wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-aarch64.sh -O ~/miniconda3/miniconda.sh; \
    else \
    echo "❌ Unsupported architecture: $arch" && exit 1; \
    fi

# Install Miniconda silently
RUN bash ~/miniconda3/miniconda.sh -b -u -p ~/miniconda3

# Clean up installer
RUN rm ~/miniconda3/miniconda.sh

# Initialize conda in all shells (must be bash)
RUN bash -c "~/miniconda3/bin/conda init --all"

# Turn off auto-activation of base environment
RUN bash -c "~/miniconda3/bin/conda config --set auto_activate_base false"

