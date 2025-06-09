#!/bin/sh

if [ ! $# -eq 2 ]
then
	echo "Less Parameters than required"
	exit 1
fi

FILEPATH=$(dirname $1)

if ! mkdir -p "$FILEPATH"
then
	echo "Failed to create the File"
	exit 1
fi

if ! echo "$2" > "$1"
then
	echo "Failed to create the File"
	exit 1
fi
