# recommend: alias clink to python3 ~/clink.py or similar
from sys import argv
from os import system, path, listdir

def _assert(cond: bool, msg: str):
    if not cond:
        print(msg)
        exit(1)

util_folder_name = "C_Utils"
# ^ change this variable to alter the name of the Utility folder

out_file_name = "_final.c"
# ^ change this variable to alter the default name of the output file

args = argv[1:]

utils_requested = []
for arg in args:
    if not arg.endswith(".c") and arg != "-o":
        utils_requested.append(arg)

main_c_file = ""
for arg in args:
    if arg.endswith(".c"):
        main_c_file = arg
        break

if "-o" in args:
    out_file_name = args[-1]


for x, util in enumerate(utils_requested):
    utils_requested[x] = util + ".c"


utils_path = path.expanduser(f"~/{util_folder_name}")
_assert(path.isdir(utils_path), f"clink.py: UTILITY FOLDER (~/{util_folder_name}/) DOES NOT EXIST")
existing_utils = listdir(utils_path)

for util in utils_requested:
    _assert(util in existing_utils, "clink.py: NONEXISTENT UTIL LINKED")

all_files_array = []

utils_requested_with_path = [utils_path + f'/{util}' for util in utils_requested]

for util in utils_requested_with_path:
    with open(util, 'r') as f:
        all_files_array.append(f.readlines())

main_c_file_path = path.expanduser(main_c_file)
_assert(path.isfile(main_c_file_path), "clink.py: C FILE DOES NOT EXIST")

with open(main_c_file, 'r') as f:
    all_files_array.append(f.readlines())

includes = set()
for fileset in all_files_array:
    for line in fileset:
        if line.startswith("#include"):
            includes.add(line)

final_out_string = []
for include in includes:
    final_out_string.append(include)

for fileset in all_files_array:
    for line in fileset:
        if not line.startswith("#include"):
            final_out_string.append(line)

final_out_string = "".join(final_out_string)

with open(out_file_name, "w") as f:
    f.write(final_out_string)
