#pragma once
#include <sstream>

#include "Object.h"


class FuzzyNumber : public Object {       //робота з нечіткими числами
	double x, l, r;       //поля для представленння нечітких чисел
public:
	FuzzyNumber();                          //конструктор за умовчанням(без параметрів)
	FuzzyNumber(double, double, double);    //конструктор ініціалізації
	FuzzyNumber(FuzzyNumber&, int);              //конструктор копіювання

	void set_x(double value_x);   //встановлення значення поля "x"
	void set_l(double value_l);   //встановлення значення поля "l"
	void set_r(double value_r);   //встановлення значення поля "r"

	double get_x()const;   //отримання значення поля "x"
	double get_l()const;   //отримання значення поля "l"
	double get_r()const;   //отримання значення поля "r"

	FuzzyNumber& operator =(const FuzzyNumber&);  //перевантаження операції "присвоєння"
	operator std::string();						  //приведення типу – перетворення у літерний рядок

	friend std::ostream& operator << (std::ostream&, const FuzzyNumber&);        //вивід на екран(перевантаженння операції "виводу")
	friend std::istream& operator >> (std::istream&, FuzzyNumber&);              //введення з клавіатури(перевантаженння операції "вводу")

	FuzzyNumber& operator ++ ();    //перевантаження операції "інкременту"(префіксна форма) --- x
	FuzzyNumber& operator -- ();    //перевантаження операції "дикременту"(префіксна форма) --- l

	FuzzyNumber operator ++ (int);  //перевантаження операції "інкременту"(постфіксна форма) --- r
	FuzzyNumber operator -- (int);  //перевантаження операції "дикременту"(постфіксна форма) --- x

	friend void operator +(FuzzyNumber&, FuzzyNumber&);   //функція: дія --- додавання
	friend void operator *(FuzzyNumber&, FuzzyNumber&);	//функція: дія --- множення
};

