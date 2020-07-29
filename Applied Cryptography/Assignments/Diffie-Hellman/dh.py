import re

from statistics import mean

data = None
times = []

time_regex = re.compile(r'real\t(\d+)m(\d+.\d+).*\n')

with open('hash_times.txt', 'r') as file:
    data = file.readlines()
    
for line in data:
    match = time_regex.search(line)
    if match:
        times.append((float(match.group(1)) * 60.0) + float(match.group(2)))

print(f'min: {min(times)}, max: {max(times)}, mean: {mean(times):.3f}')

times = []

with open('hash_times_4096.txt', 'r') as file:
    data = file.readlines()
    
for line in data:
    match = time_regex.search(line)
    if match:
        times.append((float(match.group(1)) * 60.0) + float(match.group(2)))

print(f'min: {min(times)}, max: {max(times)}, mean: {mean(times):.3f}')

