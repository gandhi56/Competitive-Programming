#!/bin/bash
find . -name "*.out" -type f
find . -name "*.ans" -type f
find . -name "*.in" -type f
find . -name "*.sw[klmnop]" -type f
echo Should I delete these files?[y/n]


read user
if [ "$user" == "y" ]; then
	echo Deleting...
	find . -name "*.out" -type f -delete
	find . -name "*.ans" -type f -delete
	find . -name "*.in" -type f -delete
	find . -name "*.sw[klmnop]" -type f -delete
fi
