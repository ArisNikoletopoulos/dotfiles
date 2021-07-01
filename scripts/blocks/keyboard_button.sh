#!/bin/sh
case $1 in
	1)	~/.local/bin/keyboard_layout_toggle && sigdwmblocks 6
	;;
esac
