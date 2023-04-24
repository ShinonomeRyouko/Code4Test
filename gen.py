import sys
import os

# Given the class names, generate corresponding files in each folder if not exist.
if len(sys.argv) != 4:
    sys.exit("Must pass common header txt, solution name txt and projec root dir!")

absolute_path = sys.argv[3]
class_name_str = ""
with open(absolute_path + "/" + sys.argv[1]) as file:
    class_name_str += file.read() 
class_name_str += " "
with open(absolute_path + "/" + sys.argv[2]) as file:
    class_name_str += file.read()
class_name_list = class_name_str.split()

folders = ["include", "src", "test"]
suffixes = [".h", ".cpp", "_test.cpp"]

# read template file content.
file_data = ["sample.h", "sample.cpp", "sample_test.cpp"]
for index in range(len(file_data)):
    with open(absolute_path + "/template/" + file_data[index]) as file:
        file_data[index] = file.read()

for class_name in class_name_list:
    for index in range(len(folders)):
        fname = absolute_path + "/" + folders[index] + "/" + class_name + suffixes[index]
        if os.path.isfile(fname):
            continue
        # create file if not exist
        with open(fname, 'w') as file:
            file.write(file_data[index].replace("sample", class_name))
