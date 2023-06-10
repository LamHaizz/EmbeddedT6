# EmbeddedT6

## COMPILER
Compiler là phần mềm chuyển những ngôn ngữ bậc cao dựa theo các quy tắc của ngôn ngữ đó thành ngôn ngữ máy , ví dụ ở ngôn ngữ C là quá trình biên dịch một file main.c thành file main.exe thông qua 4 quá trình:

    ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/5d9f6ebc-4a8b-440b-9ebf-1bb62adf52d6)

   - Quá trình tiền xử lý (pre-processor): là quá trình xảy ra khi dùng include gộp các file vào một file duy nhất , bắt đầu là một file main.c/.cpp/.h (source code) bao gồm các hàm và các thư viện qua quá trình tiền xử lý các file main.c trở thành main.i khi gộp các file lại với nhau.

     Câu lệnh : gcc -E main.c -o main.i.
  
  - Quá trình compiler : từ file main.i tạo ra file main.s (Assembly code).

     Câu lệnh : gcc main.i -S -o main.s.

  - Quá trình Assembler : từ main.s tạo ra main.o (object files) + libaries (icon, giao diện, ...).
     
     Câu lệnh : gcc -c main.s -o main.o.

  - Quá trình cuối Linker : từ Object file bao gồm file lập trình và fie thư viện phương tiện thông qua quá trình Linker sắp xếp vào file main.exe (excutable) cũng như một file nén như zip/rar.
