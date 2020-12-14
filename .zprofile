#!/bin/zsh

typeset -U PATH path
path=("$HOME/.local/bin" "$path[@]")
export PATH
export TERMINAL="alacritty"
export BROWSER="brave"

export EDITOR="vim"
export VIMINIT='source $VIMRC'
export VIMRC='~/.vim/vimrc'  

