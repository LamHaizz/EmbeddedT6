# EmbeddedT6

## COMPILER

Compiler là phần mềm chuyển những ngôn ngữ bậc cao dựa theo các quy tắc của ngôn ngữ đó thành ngôn ngữ máy , ví dụ ở ngôn ngữ C là quá trình biên dịch một file main.c thành file main.exe thông qua 4 quá trình:

   
![maxresdefault](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/aa494495-e98f-455e-9d39-f8157bb32fb5)

    
   - Quá trình tiền xử lý (pre-processor): là quá trình xảy ra khi dùng include gộp các file vào một file duy nhất , bắt đầu là một file main.c/.cpp/.h (source code) bao gồm các hàm và các thư viện qua quá trình tiền xử lý các file main.c trở thành main.i khi gộp các file lại với nhau.

     Câu lệnh : gcc -E main.c -o main.i.
  
  - Quá trình compiler : từ file main.i tạo ra file main.s (Assembly code).

     Câu lệnh : gcc main.i -S -o main.s.

  - Quá trình Assembler : từ main.s tạo ra main.o (object files) + libaries (icon, giao diện, ...).
     
     Câu lệnh : gcc -c main.s -o main.o.

  - Quá trình cuối Linker : từ Object file bao gồm file lập trình và fie thư viện phương tiện thông qua quá trình Linker sắp xếp vào file main.exe (excutable) cũng như một file nén như zip/rar.


## POINTER

Ví dụ khi ta khai báo 1 biến int a = 10; thì máy tính sẽ lưu giá trị của a ở phân vùng nhớ RAM một địa chỉ nào đó ví dụ: địa chỉ 0x01 đại diện cho a

   ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/5430f3ae-8a2b-47ad-94ba-36e587021f51)

Khi khai báo 1 con trỏ trong C cần phải theo quy ước ví dụ: int* ptr = 0x01 ; ptr là tên của con trỏ cũng là một biến như a ở trên nhưng biến a dùng để lưu giá trị còn biến con trỏ ptr dùng để lưu địa chỉ của giá trị được trỏ vào ngoài ra con trỏ cũng có thể lưu địa chỉ của hàm , mảng


#### POINTER IN POINTER
