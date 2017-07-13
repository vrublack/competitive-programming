import sys
import os
import subprocess as sp
from shutil import copyfile

this_dir = os.path.dirname(sys.argv[0]).replace('/', '\\')
cpp_dir = sys.argv[1]

# all the problems are in different branches of the git repo in cpp_dir
all_branches = [b[2:] for b in sp.check_output(['git', '-C', cpp_dir, 'branch']).decode('utf-8').split('\n')]

if not os.path.exists('cpp'):
    os.makedirs('cpp')

cpp_originalpath = os.path.join(cpp_dir, 'main.cpp')
for branch in all_branches:
    cpp_destpath = os.path.join(this_dir, 'cpp', branch + '.cpp')
    sp.call(['git', '-C', cpp_dir, 'checkout', branch])
    # copy file into current directory
    try:
        copyfile(cpp_originalpath, cpp_destpath)
    except FileNotFoundError:
        pass

print('Done.')
