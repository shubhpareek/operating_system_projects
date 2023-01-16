#!/bin/bash

if [ $1 == 0 ]
then
	for i in {1..7}
	do
	a=$(head -1 tests/test${i} | sed "s/#//g")
	if [ $( bin/mat ${a} < tests/test${i} | diff tests/exptest${i} - | wc -l ) == 0 ]
	then 	
		echo "test${i} passed"
	else
		echo "test${i} failed"
	fi
	done
elif [ $1 -gt -1 ]
then
	a=$(head -1 tests/test${1} | sed "s/#//g")
	if [ $( bin/mat ${a} < tests/test${1} | diff tests/exptest${1} - | wc -l ) == 0 ]
	then 	
		echo "test${1} passed"
	else
		echo "test${1} failed"
	fi
else
	a=$(head -1 run.in | sed "s/#//g")
	bin/mat ${a} <run.in >run.out
fi
