#!/bin/bash

if [[ -z "$1" ]]; then
	echo "Usage:"
	echo "  ./run {map_name.txt}"
	exit 1
fi

make && ./curse ../maps/$1 2> ../log.txt
