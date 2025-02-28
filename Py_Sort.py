import numpy as np
import time
import sys

input_file = sys.argv[1]

with open(input_file, "r") as f:
    data = list(map(int, f.read().split()))

start_time = time.time()
sorted_data = np.sort(data)
end_time = time.time()

duration = (end_time - start_time) * 1000  # Convert to milliseconds

# Ghi kết quả vào file output.txt
with open("output.txt", "w") as f:
    f.write(f"{duration:.6f}\n")
