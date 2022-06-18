#!/bin/sh
ROOT_BASE=$PWD
rm list_folder.txt
find $ROOT_BASE -type d > list_folder.txt
sed -i 's/^/"/' ./list_folder.txt
sed -i 's/$/",/' ./list_folder.txt
