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
RUN git clone --depth=1 https://github.com/zsh-users/zsh-autosuggestions ~/.zsh/zsh-autosuggestions
RUN git clone --depth=1 https://github.com/zsh-users/zsh-syntax-highlighting.git ~/.zsh/zsh-syntax-highlighting
RUN git clone --depth=1 https://github.com/zsh-users/zsh-history-substring-search.git ~/.zsh/zsh-history-substring-search

RUN git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf
RUN ~/.fzf/install --all --no-bash --no-fish

# Download and install fnm
RUN curl -fsSL https://fnm.vercel.app/install | bash
RUN mkdir -p ~/.zsh/completions
RUN /home/vscode/.local/share/fnm/fnm completions --shell zsh > ~/.zsh/completions/_fnm
RUN /home/vscode/.local/share/fnm/fnm install --lts --corepack-enabled

# Download and install uv
COPY --from=ghcr.io/astral-sh/uv:latest /uv /uvx /bin/
RUN uv generate-shell-completion zsh > ~/.zsh/completions/_uv
RUN uvx --generate-shell-completion zsh > ~/.zsh/completions/_uvx
