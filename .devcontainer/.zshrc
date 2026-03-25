# === Powerlevel10k Prompt ===
# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

source ~/.powerlevel10k/powerlevel10k.zsh-theme

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

# === SSH Agent Management ===
# wsl only
# https://unix.stackexchange.com/a/316560
# Note that ssh-add without arguments adds ~/.ssh/id_rsa, ~/.ssh/id_ecdsa, ~/.ssh/id_ed25519.
# You might want to pass ssh-add arguments if your private keys are in another file.
# ~/.zshrc for zsh shell and ~/.profile for vscode extension
# if [ ! -S ~/.ssh/ssh_auth_sock ]; then
#   eval `ssh-agent` > /dev/null
#   ln -sf "$SSH_AUTH_SOCK" ~/.ssh/ssh_auth_sock
# fi
# export SSH_AUTH_SOCK=~/.ssh/ssh_auth_sock

# === History Configuration ===
HISTFILE=$HOME/.zsh_history
HISTSIZE=50000                # Max in-memory history entries
SAVEHIST=50000                # Max history entries saved to file (must match HISTSIZE)
setopt extended_history       # record timestamp of command in HISTFILE
setopt hist_expire_dups_first # delete duplicates first when HISTFILE size exceeds HISTSIZE
setopt hist_ignore_dups       # ignore duplicated commands history list
setopt hist_ignore_space      # ignore commands that start with space
setopt hist_verify            # show command with history expansion to user before running it
setopt share_history          # share command history data

# === Shell Options ===
setopt auto_pushd             # cd pushes to directory stack
setopt pushd_ignore_dups      # no duplicates in dir stack

# === Aliases ===
alias np="pnpm"
alias pn="pnpm"

# === Completions ===
# compinit initializes zsh's Tab completion system by scanning all completion
# definitions in $fpath. This is slow (~200ms), so we always use the cached
# dump (-C) and rebuild in the background when stale (>24h).
fpath=(~/.zsh/completions $fpath)
autoload -Uz compinit
compinit -C
if [[ -n ~/.zcompdump(#qN.mh+24) ]]; then
  compinit &!  # stale — rebuild in background, takes effect next shell
fi

# === Plugins ===
# Ensure plugins are loaded after compinit
. ~/.zsh/zsh-autosuggestions/zsh-autosuggestions.zsh

# Note the source command must be at the end of plugin loading.
. ~/.zsh/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

# https://github.com/zsh-users/zsh-history-substring-search
# Must be loaded after zsh-syntax-highlighting
. ~/.zsh/zsh-history-substring-search/zsh-history-substring-search.zsh

# === fnm (Node version manager) ===
eval "$(fnm env --use-on-cd --shell zsh)"

# === fzf ===
[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh

# === VS Code Terminal Shell Integration ===
# Enable rich shell integration in VS Code's integrated terminal
# https://code.visualstudio.com/docs/terminal/shell-integration
if [[ "$TERM_PROGRAM" == "vscode" ]]; then
  # Performance-first: inline the script path to avoid spawning Node on each shell startup
  if [[ "$OSTYPE" == darwin* ]]; then
    VS_CODE_ZSH_INTEGRATION="/Applications/Visual Studio Code.app/Contents/Resources/app/out/vs/workbench/contrib/terminal/common/scripts/shellIntegration-rc.zsh"
  else
    VS_CODE_ZSH_INTEGRATION="/usr/share/code/resources/app/out/vs/workbench/contrib/terminal/common/scripts/shellIntegration-rc.zsh"
  fi
  if [[ -r "$VS_CODE_ZSH_INTEGRATION" ]]; then
    . "$VS_CODE_ZSH_INTEGRATION"
  # Fallback to portable approach if the app path differs (e.g., non-standard install)
  elif command -v code >/dev/null 2>&1; then
    . "$(code --locate-shell-integration-path zsh)"
  fi
fi

# === Keybindings ===
bindkey "$terminfo[kcuu1]" history-substring-search-up
bindkey "$terminfo[kcud1]" history-substring-search-down

# === PATH ===
typeset -U path
export PATH="$HOME/.local/bin:$PATH"
