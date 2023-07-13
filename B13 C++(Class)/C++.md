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






  
