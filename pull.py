import sys
import os
import subprocess as sp
from shutil import copyfile
# https://github.com/soon/CodeforcesAPI
from codeforces import CodeforcesAPI

api = CodeforcesAPI()
problemset = list(api.problemset_problems()['problems'])


def add_header(fpath, header_attr):
    header_lines = ['    ' + attr[0] + ': ' + attr[1] for attr in header_attr]
    header_str = '/**\n' + '\n'.join(header_lines) + '\n' + '*/'
    with open(fpath, 'r') as original: data = original.read()
    with open(fpath, 'w') as modified: modified.write(header_str + '\n' * 2 + data)


this_dir = os.path.dirname(sys.argv[0]).replace('/', '\\')
cpp_dir = sys.argv[1]

# all the problems are in different branches of the git repo in cpp_dir
all_branches = [b[2:] for b in sp.check_output(['git', '-C', cpp_dir, 'branch']).decode('utf-8').split('\n')]

cpp_originalpath = os.path.join(cpp_dir, 'main.cpp')
for branch in all_branches:

    if branch.startswith('cf'):
        type = 'Codeforces'
    elif branch.startswith('gcj'):
        type = 'Google-Code-Jam'
    elif branch.startswith('gcpc'):
        type = 'ICPC'
    elif branch.startswith('snippet'):
        type = 'Snippets'
    else:
        type = 'Misc'

    cpp_destfolder = os.path.join(this_dir, 'cpp', type)
    if not os.path.exists(cpp_destfolder):
        os.makedirs(cpp_destfolder)
    cpp_destpath = os.path.join(this_dir, 'cpp', type, branch + '.cpp')

    sp.call(['git', '-C', cpp_dir, 'checkout', branch])
    last_message = sp.check_output(['git', '-C', cpp_dir, 'log', '-1', '--pretty=%B']).decode('utf-8').strip()
    last_commit_date = sp.check_output(['git', '-C', cpp_dir, 'log', '-1', '--format=%cd']).decode('utf-8').strip()
    # copy file into current directory
    try:
        copyfile(cpp_originalpath, cpp_destpath)
        header = [('Author', 'Valentin Rublack'), ('Status', last_message), ('Last modified', last_commit_date)]
        if type not in ['Snippets', 'Misc']:
            header.append(('Competition', type))

        if type == 'Codeforces':
            problem_id = branch[branch.find('_') + 1:]
            contest = int(problem_id[:-1])
            index = problem_id[-1]
            header.append(('Problem id', problem_id))

            for p in problemset:
                if p.contest_id == contest and p.index == index:
                    header.append(('Problem name', p.name))
                    break

        add_header(cpp_destpath, header)
    except FileNotFoundError:
        pass

print('Done.')
