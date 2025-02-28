import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Áp dụng style của seaborn
sns.set_style("whitegrid")
sns.set_palette("muted")

# Dữ liệu thời gian chạy của các thuật toán
labels = [f'Test {i+1}' for i in range(10)]
quick_sort = [93, 173, 157, 175, 172, 172, 176, 199, 173, 46]
heap_sort = [330, 423, 423, 416, 408, 416, 408, 455, 424, 320]
merge_sort = [376, 488, 474, 486, 472, 502, 487, 486, 471, 380]
cpp_sort = [94, 235, 220, 219, 219, 219, 219, 220, 220, 103]
py_sort = [47, 47, 46, 46, 47, 58, 62, 47, 46, 46]

# Tạo biểu đồ
x = np.arange(len(labels))
width = 0.15  # Độ rộng của mỗi cột

fig, ax = plt.subplots(figsize=(12, 6))
ax.set_facecolor('#F5F5F5')  # Đặt nền của biểu đồ thành màu xám nhạt

ax.bar(x - 2*width, quick_sort, width, label='Quicksort', color=sns.color_palette("deep")[0])
ax.bar(x - width, heap_sort, width, label='Heapsort', color=sns.color_palette("deep")[1])
ax.bar(x, merge_sort, width, label='Mergesort', color=sns.color_palette("deep")[2])
ax.bar(x + width, cpp_sort, width, label='sort (C++)', color=sns.color_palette("deep")[3])
ax.bar(x + 2*width, py_sort, width, label='Py_sort', color=sns.color_palette("deep")[4])

# Thiết lập nhãn và tiêu đề
ax.set_xlabel('Test Cases', fontsize=12)
ax.set_ylabel('Thời gian thực hiện (ms)', fontsize=12)
ax.set_title('Kết quả thử nghiệm trên bộ dữ liệu', fontsize=14, fontweight='bold')
ax.set_xticks(x)
ax.set_xticklabels(labels, rotation=45)
ax.legend()

# Hiển thị giá trị trên các cột
for i in range(len(labels)):
    ax.text(i - 2*width, quick_sort[i] + 10, str(int(quick_sort[i])), ha='center', fontsize=10)
    ax.text(i - width, heap_sort[i] + 10, str(int(heap_sort[i])), ha='center', fontsize=10)
    ax.text(i, merge_sort[i] + 10, str(int(merge_sort[i])), ha='center', fontsize=10)
    ax.text(i + width, cpp_sort[i] + 10, str(int(cpp_sort[i])), ha='center', fontsize=10)
    ax.text(i + 2*width, py_sort[i] + 10, str(int(py_sort[i])), ha='center', fontsize=10)

# Hiển thị biểu đồ
plt.tight_layout()
plt.show()