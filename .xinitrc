#!/bin/sh

xrandr --output HDMI-0 --mode 1920x1080 --pos 0x0 --output DP-3 --mode 1920x1080 --pos 0x0 --output HDMI1 --mode 1920x1080 --pos 1920x0 &
sleep 2 && force-composition-pipeline &


userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

if [ -f $sysresources ]; then
    xrdb -merge $sysresources
fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then
    xrdb -merge "$userresources"
fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi


if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi

numlockx &
nitrogen --restore &
tray_app_launcher &
compton --config ~/.config/compton/compton.conf &
dwmblocks &
sleep 3 && ckb-next -b &

#exec openbox-session
#exec dwm
while true; do
    #Log stderror to a file
    #dwm 2> ~/.dwm.log
    #No error logging
    dwm >/dev/null 2>&1
done
