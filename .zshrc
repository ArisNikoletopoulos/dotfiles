

export ZSH_COMPDUMP="/home/amnesia/.cache/zcompdump-${SHORT_HOST}-${ZSH_VERSION}"
export HISTFILE="$HOME/.cache/zsh_history"
export ZSH="/home/amnesia/.oh-my-zsh"
ZSH_THEME="robbyrussell"
plugins=(
	zsh-autosuggestions
	zsh-syntax-highlighting	
)
source $ZSH/oh-my-zsh.sh


alias n="nordvpn"
alias nc="nordvpn connect"
alias nd="nordvpn disconnect"

alias v="vim"
alias sv="sudo vim"
alias r="ranger"

alias config='/usr/bin/git --git-dir=$HOME/.dotfiles/ --work-tree=$HOME'

