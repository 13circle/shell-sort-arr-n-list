#!/bin/bash

# Clone project
if [ ! -z pa1 ]; then
  echo ""
  echo "Creating project..."
  git clone https://github.com/13circle/shell-sort-arr-n-list pa1 > /dev/null 2>&1
  rm -rf pa1/.git pa1/README.md pa1/.gitignore
  echo "Project created successfully. (Directory \"./pa1\" is created)"
  echo ""
else
  echo ""
  echo "Error: Project directory \"./pa1\" already exists."
  echo ""
fi

# C Make
echo ""
echo "Building project..."
sleep 3
make -C pa1
echo "Project built in successfully."
echo ""

