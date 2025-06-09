#!/bin/sh

if [ ! $# -eq 2 ]
then
	echo "Less Parameters than required"
	exit 1
fi

if [ ! -d $1 ]
then
	echo "Invalid Path\n"
	exit 1
fi

FILECNT=$(find $1 -type f | wc -l)
MATCHCNT=0

for FILE in $(find $1 -type f)
do
	MATCHES=$(grep -o "$2" "$FILE" | wc -l)
	MATCHCNT=$((MATCHCNT + MATCHES))
done

echo "The number of files are ${FILECNT} and the number of matching lines are ${MATCHCNT}"
