#!/bin/sh

ICON="📦" # icon for critical temperatures

PACS=$(pacman -Qu | grep -Fcv "[ignored]")

if [ "$PACS" -gt "0" ] ; then
    echo "${ICON} ${PACS}"
else
    echo ""
fi
