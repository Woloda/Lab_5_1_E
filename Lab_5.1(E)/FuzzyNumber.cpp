#include <stdexcept>
#include <iostream>
#include <string>

#include "My_Error_Range.h"
#include "FuzzyNumber.h"


FuzzyNumber::FuzzyNumber() {  //конструктор за умовчанням(без параметрів)
	x = 0;
	l = 0;
	r = 0;
}

FuzzyNumber::FuzzyNumber(double value_x, double value_l, double value_r)	//конструктор ініціалізації
throw(My_Error_Range) {
	if (((value_x - value_l) > value_x) || (value_x > (value_x + value_r)))
		throw new My_Error_Range("\n\n!!!Incorrectly entered data!!!");		//генерування об'єкта винятка
	
	x = value_x;
	l = value_l;
	r = value_r;
}

FuzzyNumber::FuzzyNumber(FuzzyNumber& obj, int) {  //конструктор копіювання
	x = obj.x;
	l = obj.l;
	r = obj.r;
}

void FuzzyNumber::set_x(double value_x)   //встановлення значення поля "x"
{
	x = value_x;
}
void FuzzyNumber::set_l(double value_l)   //встановлення значення поля "l"
{
	l = value_l;
}
void FuzzyNumber::set_r(double value_r)   //встановлення значення поля "r"
{
	r = value_r;
}

double FuzzyNumber::get_x()const  //отримання значення поля "x"
{
	return x;
}
double FuzzyNumber::get_l()const  //отримання значення поля "l"
{
	return l;
}
double FuzzyNumber::get_r()const  //отримання значення поля "r"
{
	return r;
}

FuzzyNumber& FuzzyNumber::operator =(const FuzzyNumber& obj) {   //перевантаження операції "присвоєння"
	x = obj.x;
	l = obj.l;
	r = obj.r;

	return *this;
}

FuzzyNumber::operator std::string() {   //приведення типу – перетворення у літерний рядок
	std::stringstream sout;
	sout << "\n\nZnachenuya danoho obyekta: ";
	sout << "\nznachenie x: " << x;
	sout << "\nznachenie l: " << l;
	sout << "\nznachenie r: " << r;

	return sout.str();
}

//вивід на екран(перевантаженння операції "виводу")
std::ostream& operator << (std::ostream& out, const FuzzyNumber& obj) {
	out << "\nZnachenuya danoho nechitkoho chusla: ( " << obj.x - obj.l << ", " << obj.x << ", " << obj.x + obj.r << " )";
	return out;
}

//введення з клавіатури(перевантаженння операції "вводу")
std::istream& operator >> (std::istream& in, FuzzyNumber& obj) throw (std::out_of_range) {
	double a{}, b{}, c{};

	std::cout << "\nVvedit dani(value) object : ";
	std::cout << "\n\nVvedit znachenie x: "; in >> a;
	std::cout << "Vvedit znachenie l: "; in >> b;
	std::cout << "Vvedit znachenie r: "; in >> c;

	/*Використання стандартного винятка
	Успадкований від std :: logic_error.
	Визначає виняток, яке повинно бути кинуто в тому випадку,
	коли відбувається вихід за межі допустимого діапазону значень об'єкта*/
	if (((a - b) > a) || (a > (a + c)))
		throw std::out_of_range{ "\n\n!!!Data entered incorrectly!!!" };	//генерування об'єкта винятка

	obj.x = a;
	obj.l = b;
	obj.r = c;

	return in;
}

FuzzyNumber& FuzzyNumber::operator ++ () {   //перевантаження операції "інкременту"(префіксна форма) --- x
	++x;
	return *this;
}

FuzzyNumber& FuzzyNumber::operator -- () {   //перевантаження операції "дикременту"(префіксна форма) --- l
	--l;
	return *this;
}

FuzzyNumber FuzzyNumber::operator ++ (int) {  //перевантаження операції "інкременту"(постфіксна форма) --- r
	FuzzyNumber a(*this);
	r++;
	return a;
}

FuzzyNumber FuzzyNumber::operator -- (int) {  //перевантаження операції "дикременту"(постфіксна форма) --- x
	FuzzyNumber a(*this);
	x--;
	return a;
}