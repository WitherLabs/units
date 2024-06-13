#!/usr/bin/bash

if [ "$EUID" -ne 0 ]; then
    echo "Installer script must be run as root."
    exit 1
fi

INCLUDE_DIR="/usr/include"
MOONCAT_DIR="${MOONCAT_DIR_LIBRARY_HEADERS:-mooncat}/units"
INSTALL_DIR="$INCLUDE_DIR/$MOONCAT_DIR"

if [[ -e "$INSTALL_DIR" ]];
then
    echo "Skipping: creation of $INSTALL_DIR"
else
    echo "Creating: $INSTALL_DIR"
    mkdir -p "$INSTALL_DIR"
fi

if [[ "$(ls -ls | head -n 1 | cut -d' ' -f2)" -eq 0 ]]; then
    echo "Skipping: Cleanup. No files in $INSTALL_DIR"
else
    echo "Removing: Old files in $INSTALL_DIR"
    rm -rf "$INSTALL_DIR"/*
fi

INCLUDE_DIR="$(pwd)/include"

for FILE in "$INCLUDE_DIR/"*; do
    cp -rf "$FILE" "$INSTALL_DIR"
done

echo "Completed: Instalaltion"


