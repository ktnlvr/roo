#!/usr/bin/env python3

from os import walk, curdir, system, makedirs
from os.path import join

print("Collecting sources...")
sources = []
for root, _, filenames in walk(curdir):
    for filename in filenames:
        if filename.endswith(('.cpp')):
            source_path = join(root, filename)
            sources.append(join(root, filename))
            print(source_path)


sources = ' '.join(sources)
STD = "c++17"
CXX = "clang++"
CXXFLAGS = f"-g -Wall -Werror -Wpedantic -std={STD}"
out = "./build/debug/main"

command = f"{CXX} {CXXFLAGS} -o {out} -Isrc {sources}"

print("Building...")
makedirs(join(curdir, "build", "debug"), exist_ok=True)
print(command)
system(command)
