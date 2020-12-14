#!/bin/sh
case $1 in
	1) setsid -f "$TERMINAL" -e popupgrade ;;
	3) notify-send "$(/usr/bin/pacman -Qu)" ;;
esac
