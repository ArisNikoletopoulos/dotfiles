#!/bin/sh

ICON1="" # icon for critical temperatures
ICON2="" # icon for normal temperatures
ICON3="" # icon for normal temperatures
ICON4="" # icon for normal temperatures
ICON5="" # icon for normal temperatures

temp1=35
temp2=55
temp3=65
temp4=75

temp=$(sensors | grep 'Package id 0:' | awk '{print $4}' | sed 's/+//'| sed 's/.0°C//')
temp=${temp%???}

if [ "$temp" -ge "$temp4" ] ; then
    echo "${ICON5}${temp}°C"
elif [ "$temp" -ge "$temp3" ] ; then
    echo "${ICON4}${temp}°C"
elif [ "$temp" -ge "$temp2" ] ; then
    echo "${ICON3}${temp}°C"
elif [ "$temp" -ge "$temp1" ] ; then
    echo "${ICON2}${temp}°C"
else
    echo "${ICON1}${temp}°C"
fi

