#!/usr/bin/env python

import sys
import shutil
import subprocess

try:
    # Configure your favorite merge program here.
    MERGE = "vimdiff"
    
    # Get the paths provided by Subversion.
    BASE   = sys.argv[1]
    THEIRS = sys.argv[2]
    MINE   = sys.argv[3]
    MERGED = sys.argv[4]

    # Replace 'merged' file with a copy of 'mine'
    shutil.copy(MINE, MERGED)
    
    # Call the merge command (change the following line to make sense for
    # your merge program).
    cmd = [MERGE, MERGED, THEIRS]
    subprocess.check_call(cmd)
except:
    sys.exit(1)

# Return an errorcode of 0 if the conflict was resolved; 1 otherwise.
# Any other errorcode will be treated as fatal.
