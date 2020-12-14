#!/bin/sh

CAPS=`xset q | grep Caps | awk '{print $4}'`
if [ "$CAPS" == "on" ]; then
	LANG=`setxkbmap -query | awk '/layout/{print toupper($2)}'`
else
	LANG=`setxkbmap -query | awk '/layout/{print $2}'`
fi
echo "$LANG"
