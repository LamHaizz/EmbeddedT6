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

Khi khai báo 1 con trỏ trong C cần phải theo quy ước ví dụ: int* ptr = 0x01 ; ptr là tên của con trỏ cũng là một biến như a ở trên nhưng biến a dùng để lưu giá trị còn biến con trỏ ptr dùng để lưu địa chỉ của giá trị được trỏ vào ngoài ra con trỏ cũng có thể lưu địa chỉ của hàm , mảng.

Bên cạnh đó nếu muốn gán một địa chỉ của một biến có sẵn ta dùng như sau: int* ptr = &a; (quy tắc của C khi dùng ký hiệu &<đối tượng> dùng để tìm địa chỉ của đối tượng đó).

Có thể thấy giá trị của biến ptr(biến con trỏ) và &a(địa chỉ của a) là như nhau do ta gán địa chỉ của a cho biến ptr (ptr = &a)
Để lấy giá trị của một địa chỉ từ con trỏ: 
   
    int* ptr = &a;
    printf("Gia Trị: %d\n", *ptr);

#### CON TRỎ VOID

Con trỏ được khai báo kiểu dữ liệu nào thì chỉ lưu được địa chỉ chứa giá trị kiểu đó. Vì vậy có một con trỏ đặc biệt là CON TRỎ VOID, nó có thể trỏ đến địa chỉ của tất cả các đối tượng

![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/660ebbb9-ae9c-49a6-ba41-50cc97ff0058)

![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/f0d71392-8183-44b1-9f94-efc54e3cf4ae)

Để con trỏ void đọc được giá trị tại địa chỉ ta phải ép kiểu cho nó như sau: (<kiểu dữ liệu>*) ptr 

![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/a173ccb7-582d-40d9-a27c-dfb0021cd0c8)

![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/89a24016-51da-495b-853a-a258bd516a43)

#### CON TRỎ NULL

LƯU Ý : khi khai báo một con trỏ mà không gán địa chỉ cho nó thì lúc đó nó sẽ trỏ đến một địa chỉ rác , địa chỉ rác có thể là địa chỉ của một đối tượng trong chương trình dẫn đến chương trình có thể bị lỗi. Nên quy tắc khi khai báo con trỏ là phải gán cho nó một địa chỉ bằng một địa chỉ của biến, nếu chưa sử dụng bắt buộc phải gán cho nó bằng CON TRỎ NULL (là con trỏ có địa chỉ bằng 0 và giá trị bằng 0) hoặc khi một con trỏ không cần sử dụng nữa cũng phải gán bằng con trỏ NULL: int* ptr = NULL;

#### CON TRỎ HÀM

Là con trỏ lưu địa chỉ của hàm, nó có thể trỏ đến địa chỉ các hàm có cùng cấu trúc.

Cách khai báo một con trỏ hàm: void(*<tên hàm>)(< input parameter >); ví dụ: void(*ptr)(int,int)

![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/355bf684-6097-4794-bb64-71dc956d1497)

Ngoài ra thông qua con trỏ hàm có thể truyền một hàm làm input paramter của hàm khác

![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/6abb9596-9614-4a48-9745-db19400fd4c4)

Khi ta khai báo một con trỏ void gán với một địa chỉ hàm không xác định kiểu dữ liệu gì thì ta có thể ép kiểu cho nó về kiểu con trỏ hàm như sau :

      void *ptr = &tong; // hàm tổng cũng trả về giá trị void như  hình trên 
      ((void(*)(int,int))ptr)(8,9); // void(*)(int,int): đây là kiểu con trỏ mà ta muốn ép kiểu thành

#### POINTER TO POINTER
     
Pointers to pointers là một con trỏ chứa địa chỉ của một con trỏ khác.

Quy tắc khai báo:

    data_type_of_pointer **name_of_variable = & normal_pointer_variable;
      
ví dụ :

    int** ptp = 0xc1 // &ptr = 0xc1
    
![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/7c0c3a27-16ba-43b8-8fab-d6412e76e607)

    int main (int argc, char const argv[]){
    double d = 10.3;
    char string[] = "Hello";
    int* array[] = {&toanhoc, &d, string};
    printf("gia tri: %f\n", *
    
 

