#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

//by kevin agusto
//xrpl2
template <class apa_aja>
std::string to_string(apa_aja A)
{
 std::stringstream obj;
 std::string hasil;
 obj << A;
 obj >> hasil;
 return hasil;
}
std::string reverse(std::string str)
{
 std::string hasil = "";
 for (int i = (str.length()-1); i >= 0; i--)
 {
  hasil += str[i];
 }
 return hasil;
}
std::string cut(std::string str, int from, int to)
{
 std::string result = "";
 for (int i = from; i <= to; i++)
 {
  result+=str[i];
 }
 return result;
}
int index(char a, std::string b)
{
 for (int i = 0; i < b.length(); i++)
 {
  if (a==b[i])
  {return i;}
 }
 throw 1;
}
class number
{

 public:

  
  std::string numbers = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string real_numbers[36] = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35"};
  std::string the_number;
  int base;
  int max_len()
  {
   return to_string(this->numbers.length()).length();
  }
  int to_real(std::string oke)
  {
   std::string hasil = "";
   for (int i = 0; i < oke.length(); i++)
   {
    hasil+=this->real_numbers[index(oke[i], this->numbers)];
   }
   return stoi(hasil);
  }
  int to_real(char oke)
  {
   std::string hasil = "";
   hasil+=this->real_numbers[index(oke, this->numbers)];
   return stoi(hasil);
  }
  number(std::string angka, int basis): the_number(angka), base(basis)
  {
   //std::cout << "set number " << this->the_number << " with base " << basis << "\n";
  }

  void Y(std::string c, int to_base, char cara='N')
  {
   std::cout << "Konversi " << c << " dengan basis " << this->base << " ke basis " << to_base << "\n";
   if (cara=='Y')
   {
    std::cout << c << " angka aslinya adalah " << this->to_real(c) << "\n";
   }
   int a = this->to_real(c);

   std::string hasil = "";
   while (a>0)
   {
    hasil += this->numbers[a % to_base];
    if (cara=='Y')
    {
     std::cout << "moduluskan angka dengan basis tujuan: "<< a << " % " << to_base << " = " << a%to_base << "\n";
     std::cout << "lalu angka dibagi basis tujuan: " << a << " / " << to_base << " = " << a/to_base << "\n\n";
    }
    a /= to_base;
   }
   if (cara=='Y')
   {
    std::cout << "Hasilnya jadi " << hasil << " tapi dibalik, jadinya: ";
   }
   hasil = reverse(hasil);
   std::cout << "Hasil: " << hasil << "\n";
   this->the_number = hasil;
  }
  void Z(std::string c, int the_base, char cara)
  {
   std::cout << "Konversi " << c << " dengan basis " << this->base << " ke basis " << the_base << "\n";
   if (cara=='Y')
   {
    std::cout << "Pertama balik dulu: " << c << " jadi " << reverse(c) << "\n";
    std::cout << "kalikan angka per-angka dengan (basis pangkat angka ke-N) lalu tambahkan semua hasilnya. seperti ini\n";
   }
   c =  reverse(c);
   double hasil = 0;
   for (int i = 0; i < c.length(); i++)
   {
    if (cara=='Y')
    {std::cout << "(" << this->to_real(c[i]) << "x" << "(" << the_base << "^" << i << ")" << ") + ";}
    hasil += this->to_real(c[i])*(pow(the_base, i));
   }
   this->the_number = to_string(hasil);
   std::cout << "\n" << "Hasil: " << hasil << "\n\n";
  } 
  void convert(int to, char cara)
  {
   //binary, octal, decimal, hexadecimal
   if ((to%10)==0)
   {
    this->Z(this->the_number, this->base, cara);
   }
   else
   {
    convert(10, cara);
    this->Y(this->the_number, to, cara);
   }
   this->base = to;
  }
  void show_result()
  {
   std::cout << "Number: " << this->the_number << " in base: " << this->base << "\n";
  }
};
void spab(int x = 10)
{
 for (int i = 0; i < x;i++)
 {
  std::cout << "\n";
 }
}
void UI() //biar enak ngobrol sama user
{
 std::cout << "Konversi bilangan by kevin agusto\n\n";
 std::string input0;
 char cara = 'N';
 int input1, input2;
 std::cout << "Mau pakai cara? Y/N: ";
 std::cin >> cara;
 std::cout << "\n\n\n";
 while (1)
 {
  std::cout << "masukkan bilangan: ";
  std::cin >> input0;
  std::cout << "\n";

  std::cout << "masukkan basis awal bilangan: ";
  std::cin >> input1;
  std::cout << "\n";

  std::cout << "masukkan tujuan bilangan: ";
  std::cin >> input2;
  std::cout << "\n";
  
  number obj(input0, input1);
  obj.convert(input2, cara); 
 
  std::cout << "Tekan Enter...\n";
  std::cin.get();
  spab();
 }
}
int main()
{
 UI();
 //ga bisa oktal ke biner. jadi ke desimal dulu
 return 0;
}

