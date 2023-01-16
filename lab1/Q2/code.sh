#!/bin/bash
if [[ $# == 1 ]]
then 
	cd "$1"
elif [[ $# -gt 1 ]]
then
	echo "error: too many arguments"
	echo "pass directory name as argument"
	echo "if no arguments are passed the directory name is same as current directory"
	exit
fi
#loop through the files in the directory this occours lexicographically
for file1 in *
do
	# check for regular files
	if [[ -f ./"${file1}" && ! -d ./"${file1}" && ! -L ./"${file1}" && ! -p ./"${file1}" ]]
	then
		#loop through files to find if there is a matching file
		for file2 in *
		do
			# check for regular files
			if [[ -f ./"${file2}" && ! -d ./"${file2}" && ! -L ./"${file2}" && ! -p ./"${file2}" ]]
			then
				# check if we are not comparing the same file
				if [[ ./"${file1}" != ./"${file2}" ]]
				then
					# if the contents match then make a soft link
					if [[ $(diff ./"${file1}" ./"${file2}" | wc -m) == 0 ]]
					then
						rm ./"${file2}"
						ln -s ./"${file1}" ./"${file2}"
					fi
				fi
			fi
		done
	fi
done
