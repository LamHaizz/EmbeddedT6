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



## LINKED LIST

Linked list là tập hợp những node đơn lẻ dùng kỹ thuật node* next để đọc các node tiếp theo để liên kết các node lại với nhau gọi là mảng nhân tạo. Được tạo ra để khắc phục những nhược điểm của một mảng bình thường ở linked list chúng ta có thể dễ dàng thao tác các tác vụ như sữa đổi , xóa, thêm ,.. mà mảng bình thường không làm được. Được biết đến là kỹ thuật tạo ra mảng nhân tạo bằng struct 

Linked list sẽ hữu dụng và được sử dụng trong các trường hợp thay đổi các phần tử trong mảng và dễ dàng thay đổi được các node để các phần tử còn lại xê dịch theo một cách nhanh chóng. 

## C++

# CLASS:

Để tạo ra 1 class ta làm như sau: 

	Class < tên class > {

	};
 
Tiếp theo trong Class ta khai báo phạm vị truy cập và member của nó có thể bao gồm cả biến được gọi là thuộc tính ( property) và hàm được gọi là phương thức ( methods).

  ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/e31d7d48-8a8d-4000-a617-b52f083e13c1)

Để tạo object của một class và sử dụng các thuộc tính và phương thức ta làm như sau: 

  ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/e28d7a99-1e44-4898-a25b-d8cfe1a13f7c)

Bên cạnh đó object chỉ có thể truy cập vào những member thuộc phạm vi truy cập public còn những phạm vi truy cập khác thì nó không thể truy cập được.
 
## CONSTRUCTOR

Giống như một hàm nhưng không có kiểu void hay giá trị trả về , nó được dùng để khởi tạo những tham số ban đầu :

    DoiTuong(){
      Ten = "Thuan";
      Tuoi = 18;
      GioiTinh = "Nam";
      }
Constructor sẽ được khởi tạo trong object khi object đó được tạo.

- Constructor có tham số đầu vào:

      DoiTuong(string ten, int tuoi, string gioitinh){
        Ten = ten;
        Tuoi = Tuoi;
        GioiTinh = gioitinh;
        }
Khi đó muốn khởi tạo 1 object của Class có constructor có tham số đầu vào thì phải truyền tham số đầu vào cho object đó:

    DoiTuong dt("Hang", 18, "Nu");

Bên cạnh đó những tham số đầu vào có thể là những tham số mặc định do chúng ta truyền vào. Khi đó, một object được tạo ra mà không có tham số đầu vào thì nó sẽ lấy những thông tin từ tham số mặc định, còn khi có tham số đầu vào thì nó sẽ lấy thông tin của các tham số vừa nhập.

    DoiTuong(string ten = "Vu" , int tuoi = 19; string gioitinh = "Nam")

## STATIC

Khi khởi tạo biến static 1 lần duy nhất và tồn tại hết vòng đời của chương trình

Đối với Class , biến static sẽ là thuộc tính dùng chung cho tất cả các đối tượng , tức là có thể khai báo nhiều object , mỗi object có các thuộc tính khác nhau nhưng riêng static thì dùng chung và chỉ có một và tồn tại suốt chương trình.

  ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/bcfc75f2-f4ac-4d70-af94-b85f43689062)

  ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/9fa0f4bf-780d-4488-96ed-147329f7270b)

Kết quả in ra: 

  ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/a10fb0d4-8c6a-4cb8-89b0-71c9af886429)

Vậy làm sao để khi thoát ra hàm void test1() thì id được quay về giá trị 100 ban đầu ( nghĩa là sau khi thoát ra khỏi hàm sẽ thu hồi hết những vùng nhớ).

Do đó ta dùng Destructor để thu hồi vùng nhớ , được khai báo sau Constructor.

  ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/02c9659e-35a9-4a0d-98a3-5d36ab74cf54)

Bên cạnh đó các Object được khởi tạo và lưu ở phân vùng nhớ stack vì nó là biến cục bộ nên khi thoát ra khỏi test1() thì vùng nhớ của các Object được tạo (dt, dt1, dt2) sẽ bị thu hồi hết, trước khii bị thu hồi chương trình sẽ gọi Destructor ~DoiTuong sẽ được chạy và thu hồi Object từ cuối đến đầu tiên lần lượt dt2 -> dt1 -> dt và biến static id bắt đầu lại từ 100 trong hàm test2().

 ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/11eec37c-2d27-4aa2-b58a-283b15f614d0)

 ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/395608c8-e27f-4fd2-a7e1-d6253faad1ad)


Ngoài ra những biến static thuộc Class thì bắt buộc khởi tạo lần đầu để cấp địa chỉ. Những Object khác nhau nhưng khi trỏ về member static thì đều trỏ về 1 địa chỉ chung. Nên khi thay đổi địa chỉ 1 Object trỏ vào static (dt.static_var) thì các địa chỉ của object khác trỏ đến static cũng sẽ thay đổi theo (dt1.static_var ,dt2.static_var).

 ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/311bb77b-6fde-4c17-a69e-fc7efc6e35b5)

 ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/86dca800-4135-45e1-8423-be588ddd75ed)

 ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/22673967-8489-4f64-96f7-c1831c482601)

 ![image](https://github.com/LamHaizz/EmbeddedT6/assets/136157764/993cae1f-2c4d-4cf0-9077-218255b06c32)

##OOP

#### INHERITANCE (Tính kế thừa ): 

trong lập trình hướng đối tượng , một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó.

Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trong C++. 
Bên cạnh đó Class con cũng có thể bổ sung những member của riêng nó.

    Class DoiTuong{
      Public:
        string TEN;
        int TUOI;
        string DIA_CHI;
        void hienThi();
      };

  Thì chúng ta sử dụng tính kế thừa khi khai báo class con như sau:

    class SinhVien: public DoiTuong{   // kế thừa class cha
      public:
        int MSSV;
        void hienThi();   // phương thức gi đè 
    };

Khi ta muốn sử dụng và định nghĩa lại một method của Class cha thì đó là phương thức ghi đè 

Lưu ý: Khi phạm vi truy cập của các propreties của class cha là PRIVATE thì chỉ có class cha mới có thể truy cập và sử dụng được những properties đó , Class con chỉ có thể sử dụng những properties và methods không thuộc phạm vi truy cập PRIVATE của Class cha.

Vậy để Class con có thể truy cập và sử dụng member của class cha ta dùng PROTECTED thay cho PRIVATE , nhưng đối với OBject thì chỉ truy cập đến những member ở phạm vi truy cập PUBLIC.

#### ABSTRACTION (Tính trừu tượng): 

trong lập trình hướng đối tượng là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý.

Có nghĩa là sử dụng một method ( nằm trong private hoặc protected), thông qua nó thì một method chính mới có được kết quả. giống như nâng cấp của tính đóng gói

#### POLYMORPHISM (Tính đa hình) : 

là khi trong Class có những method trùng tên với nhau nhưng khác input parameter , vậy khi đó chương trình sẽ chạy method căn cứ theo input parameter mà chúng ta truyền vào kiểu dữ liệu sao cho phù hợp với input parameter của các methods cùng tên đó . Ví dụ :

    class TinhTong
      public:
      void Tong( int a , int b){
          cout << a +b << endl;
      void Tong ( float a , float b){
          cout << a +b << endl;
      void Tong ( int a , int b , int c){
          cout << a+ b +c<<endl;
          
#### ENCAPSULATION (Tính đóng gói): 

trong lập trình hướng đối tượng có ý nghĩa không cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó.

Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu =>> CÁC PROPERTY phải nằm ở trong protected hoặc private.

#### TEMPLATE:

Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau Ví dụ : cũng mang tính chất đa hình.

    template <typename bien>
    
    bien tong(bien a, bien b){
      return (bien)(a+b);
    }
    int main{
    tong ( 6 ,7); // kq la 13

Khi muốn khai báo template với 2 tham số khác nhau :

    template <typename bien, typename bien2>
    
* NAMESPACE: Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau.

Tình huống sử dụng: có 2 file A và B có cùng tên hàm hoặc biến ( nhưng giá trị khác nhau) thì phải sử dụng namespace để cho compiler hiểu , tránh bị lỗi.

Có thể sử dụng cú pháp using namespace fileA để sử dụng trực tiếp các biến hoặc hàm trong fileA, không cần phải thông qua fileA::biến.

#### VIRTUAL FUNCTION: 

Hàm ảo được sử dụng trong trường hợp một method trong class cha được class con kế thừa và muốn sử dụng override ( thay đổi method đó) =>> đặc tính overload.

Ví dụ

    class Sinhvien{
      protected:
        virtual char *comment(){
        return (char*)"class sinh vien";
      }
      public
      void display(){
      printf("%s\n",comment());
        }
    };
    class hocsinh : pubic Sinhvien{
      private:
        char *comment(){
        return (char*)"class hoc sinh";
    };
    int main(){
      hocsinh hs;
    hs.display; // in ra class hoc sinh
    return 0;
    }

Khi gọi comment() chương trình sẽ load lại comment() mới nhất ở Class con và thực hiện phương thức ghi đè
    
CHÚ Ý: Khi thiết kế các method và các method đó được các Class con kế thừa và ghi đè để sử dụng được thì bắt buộc chúng ta phải thêm virtual function.

#### VECTOR: LÀ MỘT CLASS.

Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp trong vector.

Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình.

Ví dụ:

    vector<int> array;

    array.push_back(7);        // thêm phần tử 7

    array.push_back(3);        // thêm phần tử 3

    array.push_back(5);         // thêm phần tử 5
    
    array.push_back(1);         // thêm phần tử 1

    array.insert(array.begin()+1, 35);  //Chèn 1 phần tử 35 vào ví trị thứ 1

    array.pop_back();           // xóa phần tử ở cuối 

    array.erase(array.begin()+1);       // xóa phần tử ở vị trí thứ 1

    array.clear();                  // xóa tất cả
    
    for ( int = 0; i < array.size(); i++){
      cout<< array[i]<<endl;
    }
    for ( int item : array){
      count << item << endl; }// for cải tiến của c ++ tương tự như thằng trên

* AUTO : được dùng khi khai báo một biến mà không xác định kiểu dữ liệu của nó là gì , nó sẽ phụ thuộc vào giá trị mà ta gán cho biến đó.
      
#### LIST: 

Cũng tương tự như array nhưng mỗi địa chỉ của member trong list là riêng biệt, không liền kề nhau. Đây cũng là sự khác nhau giữ vector (các địa chỉ liền kề ) và list 

Khi làm việc với list muốn thay đổi giá trị, thêm chèn vào mảng phải thông qua interator.

    list<int> array;

    array.push_back(5);

    array.push_back(3);

    array.push_back(2);

    list<int>::iterator it;

    int i = 0;
    for (it = array.begin();it != array.end(); it++)        // khi muốn chèn thêm 1 node 
    {
        if(i == 1){
            array.insert(it, 27);
        }
        i++;
    }

    for (it = array.begin();it != array.end(); it++)
    {
        cout<<*it<<endl;
    }

#### LAMBDA

 Là một function , một hàm cục bộ . Cấu trúc của nó như sau:

[capture clause] (parameter) -> returntype
{
    definition of method
}

Ví dụ:

     int a = 10;

     auto func = [a](int b) {    // khai bao một lambda, [a] là biến cho phép sử dụng toàn cục với tham số truyền vào là b = 18
         return a + b;
    };

    cout<<func(18)<<endl;

Nếu không muốn sử dụng biến ngoài

    auto func = [](int a, int b){
        return a + b;
    };

    cout<<func(18, 2)<<endl;

Nếu sử dụng nhiều biến bên ngoài ta làm như sau :

    int a = 10;
    int f = 30;
    int k = 40;
    
    auto func = [=](int a, int b) -> int {       // thêm = vào trong []
        return a + b + f + k;                    
    };
    

