#!/bin/sh
case $1 in
	1) setsid -f termite -e ~/scripts/popupgrade.sh ;;
	3) notify-send "$(/usr/bin/pacman -Qu)" ;;
esac
