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

     toanhoc(&tong, 4, 7);
     toanhoc(&hieu, 24,7);

Hoặc khi ta khai báo một con trỏ void gán với một địa chỉ hàm không xác định kiểu dữ liệu gì thì ta có thể ép kiểu cho nó về kiểu con trỏ hàm như sau :

      void *ptr = &tong; // hàm tổng cũng trả về giá trị void như  hình trên 
      ((void(*)(int,int))ptr)(8,9); // void(*)(int,int): đây là kiểu con trỏ mà ta muốn ép kiểu thành

#### POINTER TO POINTER
     
Pointers to pointers là một con trỏ chứa địa chỉ của một con trỏ khác.

Quy tắc khai báo:

    data_type_of_pointer **name_of_variable = & normal_pointer_variable;
      
ví dụ :

    int** ptp = 0xc1 // &ptr = 0xc1
    
    int main (int argc, char const argv[]){
    double d = 10.3;
    char string[] = "Hello";
    int* array[] = {&toanhoc, &d, string};
    printf("gia tri: %f\n", *(double*)array[1]);


## PHÂN VÙNG NHỚ

  ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/0f1c1e22-f3bc-4215-8cea-6c9c1676ccb5)

#### Text :
 
   – Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.
   
   – Chứa khai báo hằng số trong chương trình (.rodata)

   Khi chúng ta viết chương trình (file head) để nạp cho vi điều khiển thì khi đó file head sẽ được lưu ở bộ nhớ flash. Khi chương trình chạy sẽ có một bước copy chương trình ở bộ nhớ flash để gán sang bộ nhớ RAM thì đó chương trình mới bắt đầu chạy khi đó source được lưu ở bộ nhớ RAM thực chất là đang được lưu ở phân vùng Text hoặc các hằng số khi được khai báo cũng được lưu ở phân vùng text và tất cả chỉ được đọc và không được sửa đổi. 

   ví dụ:

         const int i = 10;

         int main(int argc, char const *argv[])
         {
            printf("i = %d\n", i); /// vì i là hằng số lưu ở phân vùng text nên chỉ có thể đọc lấy ra sử dụng 
            i = 4; // chương trình báo lỗi vì i là hằng số lưu ở phân vùng text nên không thể gán lại giá trị cho i 
            return 0;
         }
         
   
#### Data:

   – Quyền truy cập là read-write.
   
   – Chứa biến toàn cục or biến static (toàn cục, cục bộ) với giá trị khởi tạo khác không.
   
   – Được giải phóng khi kết thúc chương trình. Ví dụ khi nạp chương trình vào vi điều khiển , khi tắt nguồn thì những biến toàn cục và static dùng để khai báo lúc đó sẽ được thu hồi vùng nhớ trên RAM.  

   ví dụ 

         #include <stdio.h>

         int i = 10; // biến toàn cục

         void tong(){
            int x; // biến cục bộ
         }
   
#### Bss:

   – Quyền truy cập là read-write.
   
   – Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.
   
   – Được giải phóng khi kết thúc chương trình.
   
   ví dụ :
   
          int i;
          static int x = 0;

   LƯU Ý: Khi ta gán lại một giá trị cho i khi sử dụng trong hàm thì biến i vẫn được lưu ở phân vùng BSS chứ không phải sẽ chuyển sang phân vùng data , việc phân vùng nhớ chỉ căn cứ vào lúc khởi tạo đầu tiên.
 
    
 #### Stack:
 
   – Quyền truy cập là read-write.
   
   – Được sử dụng cấp phát cho biến local, input parameter của hàm,…
   
   – Sẽ được giải phóng khi ra khỏi block code/hàm

   Ví dụ :

         int tong(int a, int b){ // input parameter a , b sẽ được lưu ở phân vùng stack
            int c; // biến cục bộ được lưu ở Pv stack
            c= a + b;
            return c;
         } // sau khi chương trình thoát ra khỏi hàm vùng nhớ sẽ bị thu hồi

   ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/34364b0a-3cee-460d-b200-24bc0b59664e)

LƯU Ý : Khi viết chương trình chỉ muốn đọc giá trị biến truyền vào thì input parameter chỉ cần khai báo biến bình thường , còn nếu muốn thay đổi giá trị của biến truyền vào thì input parameter phải truyền con trỏ.
         
#### Heap:

   – Quyền truy cập là read-write.
   
   – Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
   
   – Sẽ được giải phóng khi gọi hàm free,…

![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/39c92a6c-ba5f-45c1-86b4-ab8cd8856f2c)

![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/06994292-7f25-433d-9e0f-9a1e33ed06e6)

Bởi vì kiểu int có kích thước là 4 byte nên địa chỉ của 2 member liền kề nhau trong mảng array cách nhau là 4 byte ( với uint8_t là 1 byte , uint16_t là 2 byte)

Kỹ thuật cấp phát động để tạo ra một mảng và kích thước có thể thay đổi được , khi sử dụng cấp phát động sẽ được lưu ở phân vùng Heap

ví dụ: 

       int* array = (int *)malloc(sizeof(int)*4); // malloc là một con trỏ void , nên muốn cấp mảng kiểu gì thì phải ép kiểu cho nó (int*)malloc(sizeof(<kiểu dữ liệu>* <số phần tử trong mảng>))
   
       for (int i = 0; i < 4; i++)
       {
           array[i] = 3*i
       }
       
       for (int i = 0; i < 4; i++)
       {
           printf("i = ")
       }
       
       return 0;

Khi muốn thay đổi kích thước của mảng array trên ta dùng hàm realloc:

     array = (int *)realloc(array, sizeof(int)* 7)// truyền vào địa chỉ của mảng , kích thước muốn thay đổi cho mảng 

LƯU Ý : Phân vùng Stack hệ điều hành tự động giải phóng , phần cùng Heap là do người dùng tự giải phóng bằng câu lệnh free()

## VARIABLE NÂNg CAO

#### BIẾN STATIC CỤC BỘ : 

Là biến chỉ có giá trị trong hàm chứa nó được khởi tạo 1 lần và tồn tại hết vòng đời của chương trình nên khi gọi lại biến vẫn được lưu giá trị trước đó

      void count (){
          static int temp = 0; //0xc1
   
          printf("temp: %d\n", temp);
   
          temp++;
      }

      int main (int argc,char const *argv[])
      {
          count(); // khởi tạo biến static sau đó in temp rồi +1 cho giá trị của biến temp
   
          count(); // khi gọi lần 2 ko khởi tạo lại biến static và tiếp tục chương trình
   
          count(); // khi gọi lần 3 cũng bỏ qua bước khởi tạo và chạy tiếp 
   
          return 0;
      }

![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/ebbc8a51-e5a7-4fd9-8b6b-e081daf5890b)

#### STATIC TOÀN CỤC

Là những biến toàn cục mà các hàm khác có thể láy được nhưng nó vẫn giữ đặc trưng của biến static là chỉ dùng cho file chứa nó ( static cục bộ cũng vậy) , các file khác không lấy nó dùng được

#### ỨNG DỤNG BIẾN STATIC 

Khi viết chương trình bao gồm nhiều chương trình nhỏ , trong quá trình các tạo các hàm dùng biến static để khi người khác sử dụng thư viện chỉ để lấy ra được kết quả và tránh được việc can thiệp vào quá trình xử lý

#### BIẾN VOLATILE

Được sử dụng khi giá trị của biến có thể thay đổi không báo trước, tránh việc sai sót do tính năng optimize của compiler.

      volatile int data = readADC();// Báo cho compiler không được optimize biến này

