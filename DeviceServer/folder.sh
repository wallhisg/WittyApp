#!/bin/sh
ROOT_BASE=$PWD
rm folder.md
find $ROOT_BASE -type d > folder.md
sed -i 's/^/"/' ./folder.md
sed -i 's/$/",/' ./folder.md
