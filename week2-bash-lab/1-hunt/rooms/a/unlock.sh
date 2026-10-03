#!/usr/bin/env bash
# Level 1 lock. Reading this file is allowed, but it's more fun to solve the hunt.
if [ -f used_key.txt ]; then
    echo "Unlocked! The secret word is: BANANASLUG"
    echo "Final step: the secret NUMBER is this script's exit code. How do you see it?"
    exit 42
elif [ -f key.txt ]; then
    echo "The key fits. Now rename key.txt to used_key.txt (with mv) and run ./unlock.sh again."
    exit 1
else
    echo "No key.txt in this directory ($(pwd)). Copy it here from the directory above."
    exit 2
fi
