import os

PACKED_PATH = "tests/packed/measurements/"
NONPACKED_PATH = "tests/nonpacked/measurements/"
JAN_PATH = "tests/jan/measurements/"

def read_file(filepath):
    file = open(filepath, "r")
    lines = []

    for line in file:
        line = line.replace('\n', "")
        lines.append(line)
    
    tree_mem = lines[0].replace("Tree memory consumption (kB): ", "")
    tree_time = lines[1].replace("Tree creation time (us): ", "")
    rank_time = lines[2].replace("Average rank time (ns): ", "")
    select_time = lines[3].replace("Average select time (ns): ", "")
    access_time = lines[4].replace("Average access time (ns): ", "")

    return tree_mem, tree_time, rank_time, select_time, access_time

jan_dict = dict()
packed_dict = dict()
nonpacked_dict = dict()

for filename in os.listdir(JAN_PATH):
    if ".txt" not in filename:
        continue
    jan_dict[filename] = read_file(JAN_PATH + filename)
    packed_dict[filename] = read_file(PACKED_PATH + filename)
    nonpacked_dict[filename] = read_file(NONPACKED_PATH + filename)

def print_stat(desc, index):
    print("\n" + desc)
    print("        FILENAME        |    PACKED    |    NONPACKED    |    JAN    |")
    for key, value in jan_dict.items():
        filename = key
        packed_value = packed_dict[key][index]
        nonpacked_value = nonpacked_dict[key][index]
        jan_value = value[index]
        print('{:24}|{:14}|{:17}|{:11}|'.format(filename, packed_value, nonpacked_value, jan_value))

print_stat("TREE MEMORY:", 0)
print_stat("TREE TIME:", 1)
print_stat("RANK TIME:", 2)
print_stat("SELECT TIME:", 3)
print_stat("ACCESS TIME:", 4)