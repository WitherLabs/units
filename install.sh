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

SOURCE_DIR="$(pwd)/src"

for FILE in "$SOURCE_DIR/"*.hh; do
    NEW_FILENAME="$(basename $FILE | cut -d'.' -f1)"
    cp "$FILE" "$INSTALL_DIR/$NEW_FILENAME"
done

cp -rf "$SOURCE_DIR/impl" "$INSTALL_DIR"

echo "Completed: Instalaltion"


