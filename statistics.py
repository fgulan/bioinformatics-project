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
    y_4_p = []
    y_15_p = []
    y_26_p = []
    y_4_np = []
    y_15_np = []
    y_26_np = []
    y_4_j = []
    y_15_j = []
    y_26_j = []
    ys = [ y_4_p, y_15_p, y_26_p, y_4_np, y_15_np, y_26_np, y_4_j, y_15_j, y_26_j]

    y_real_pack = {}
    y_real_npack = {}
    y_real_jan = {}

    for key, value in jan_dict.items():
        filename = key
        packed_value = packed_dict[key][index]
        jan_value = value[index]
        nonpacked_value = nonpacked_dict[key][index]
        if key.startswith("4"):
            seq_len = key.replace("4_", "").replace(".txt", "")
            y_4_p.append((packed_value, int(seq_len)))
        elif key.startswith("15"):
            seq_len = key.replace("15_", "").replace(".txt", "")
            y_15_p.append((packed_value, int(seq_len)))
        elif key.startswith("26"):
            seq_len = key.replace("26_", "").replace(".txt", "")
            y_26_p.append((packed_value, int(seq_len)))
        elif key.startswith("4"):
            seq_len = key.replace("4_", "").replace(".txt", "")
            y_4_np.append((nonpacked_value, int(seq_len)))
        elif key.startswith("15"):
            seq_len = key.replace("15_", "").replace(".txt", "")
            y_15_np.append((nonpacked_value, int(seq_len)))
        elif key.startswith("26"):
            seq_len = key.replace("26_", "").replace(".txt", "")
            y_26_np.append((nonpacked_value, int(seq_len)))
        elif key.startswith("4"):
            seq_len = key.replace("4_", "").replace(".txt", "")
            y_4_j.append((jan_value, int(seq_len)))
        elif key.startswith("15"):
            seq_len = key.replace("15_", "").replace(".txt", "")
            y_15_j.append((jan_value, int(seq_len)))
        elif key.startswith("26"):
            seq_len = key.replace("26_", "").replace(".txt", "")
            y_26_j.append((jan_value, int(seq_len)))
        else:
            y_real_pack[key.replace(".txt", "")] = jan_value
            y_real_npack[key.replace(".txt", "")] = jan_value
            y_real_jan[key.replace(".txt", "")] = jan_value

        print('{:24}|{:14}|{:17}|{:11}|'.format(filename, packed_value, nonpacked_value, jan_value))

    y_4_p = [y[0] for y in sorted(y_4_p, key=lambda x: x[1])]
    y_15_p = [y[0] for y in sorted(y_15_p, key=lambda x: x[1])]
    y_26_p = [y[0] for y in sorted(y_26_p, key=lambda x: x[1])]
    y_4_np = [y[0] for y in sorted(y_4_np, key=lambda x: x[1])]
    y_15_np = [y[0] for y in sorted(y_15_np, key=lambda x: x[1])]
    y_26_np = [y[0] for y in sorted(y_26_np, key=lambda x: x[1])]
    y_4_j = [y[0] for y in sorted(y_4_j, key=lambda x: x[1])]
    y_15_j = [y[0] for y in sorted(y_15_j, key=lambda x: x[1])]
    y_26_j = [y[0] for y in sorted(y_26_j, key=lambda x: x[1])]
    ys = [ y_4_p, y_15_p, y_26_p, y_4_np, y_15_np, y_26_np, y_4_j, y_15_j, y_26_j]

    print("y_4 = ", y_4_p)
    print("y_15 = ", y_15_p)
    print("y_26 = ",y_26_p)
    print()
    print("y_4n = ",y_4_np)
    print("y_15n = ",y_15_np)
    print("y_26n =",y_26_np)
    print()
    print("y_4j = ",y_4_j )
    print("y_15j = ",y_15_j)
    print("y_26j = ",y_26_j)

    print("LATEX")
    # for index, seq_len in enumerate([100, 1000, 10000, 100000, 1000000]):
    #     x = str(seq_len)
    #     for y_i in ys:
    #         x += " & $" + y_i[index] + "$"
    #     print(x + " \\\\ \hline")

    x = ""
    for y_i in y_real_jan:
        x = y_i + " & $" + y_real_jan[y_i] + "$"
        print(x + " \\\\ \hline")

    print()
print_stat("TREE MEMORY (kB):", 0)
print_stat("TREE TIME (us):", 1)
print_stat("RANK TIME (ns):", 2)
print_stat("SELECT TIME (ns):", 3)
print_stat("ACCESS TIME (ns):", 4)