@echo off
setlocal enabledelayedexpansion

:: Biên dịch các chương trình C++
g++ Quick_Sort.cpp -o Quick_Sort.exe
g++ Merge_Sort.cpp -o Merge_Sort.exe
g++ Heap_Sort.cpp -o Heap_Sort.exe
g++ Cpp_Sort.cpp -o Cpp_Sort.exe

:: Xóa nội dung cũ của file kết quả
echo. > Sorting_Time.txt

:: Lặp qua từng file input
for %%X in (01 02 03 04 05 06 07 08 09 10) do (
    echo Test %%X: >> Sorting_Time.txt
    for %%A in (Quick_Sort.exe Merge_Sort.exe Heap_Sort.exe Cpp_Sort.exe) do (
        echo Running %%A with Input_Data\input_%%X.txt...
        
        :: Chạy thuật toán và ghi kết quả vào output.txt
        %%A Input_Data\input_%%X.txt 
        
        :: Đọc thời gian từ output.txt
        set /p TIME_RESULT=<output.txt

        :: Ghi kết quả vào Sorting_Time.txt
        echo %%A : !TIME_RESULT! ms >> Sorting_Time.txt
    )
    echo. >> Sorting_Time.txt
)

echo Experiment completed. Results saved in Sorting_Time.txt.
