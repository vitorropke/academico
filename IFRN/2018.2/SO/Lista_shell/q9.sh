#!/bin/bash

now="$(date +'%H:%M:%S')"

if [ now = '00:00:00' ]
	then
		shutdown -r
fi
