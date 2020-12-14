#!/bin/sh

LISTPATH="/home/amnesia/Scripts/iconlists/"
cat $LISTPATH$(printf '%s\n' $LISTPATH*.list | sed 's,'"$LISTPATH"',,' | sed 's,\.list,,' | dmenu -l 20 -fn Roboto:size=20)".list" | dmenu -l 20 -fn Roboto:size=20 | awk '{print $1}' | tr -d '\n' | xclip -selection clipboard

ICON=$(xclip -o -selection clipboard)
LEN=${#ICON}
if [ $LEN -gt 0 ]
then
    notify-send "Copied to clipboard:   $ICON   "
fi
