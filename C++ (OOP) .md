#### Inheritance (Tính kế thừa ): 

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

#### Abstraction (Tính trừu tượng): 

trong lập trình hướng đối tượng là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý.

Có nghĩa là sử dụng một method ( nằm trong private hoặc protected), thông qua nó thì một method chính mới có được kết quả. giống như nâng cấp của tính đóng gói

#### Polymorphism (Tính đa hình) : 

là khi trong Class có những method trùng tên với nhau nhưng khác input parameter , vậy khi đó chương trình sẽ chạy method căn cứ theo input parameter mà chúng ta truyền vào kiểu dữ liệu sao cho phù hợp với input parameter của các methods cùng tên đó . Ví dụ :

    class TinhTong
      public:
      void Tong( int a , int b){
          cout << a +b << endl;
      void Tong ( float a , float b){
          cout << a +b << endl;
      void Tong ( int a , int b , int c){
          cout << a+ b +c<<endl;
          
#### Encapsulation (Tính đóng gói): 

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
    for (it = array.begin();it != array.end(); it++)
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
