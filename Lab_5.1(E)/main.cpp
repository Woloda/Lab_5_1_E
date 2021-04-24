#include <iostream>

#include "FuzzyNumber.h"
#include "Object.h"
#include "Me_Error_size_memorry.h"
#include "My_Error_Range.h"


int main(void) {
	using std::cout;

	std::cout << "\n\n////////////////////////////////////////////////////////////11111111\n";

	//визначається власний виняток
	try {	//захищений(контрольований) блок
		FuzzyNumber A(12.0, 6.0, 7.0), B(2.0, 3.0, 4.0), C;
		cout << "\nDani(value) chusla A: " << A;
		cout << A.operator std::string();

		cout << "\n\nDani(value) chusla B: " << B;
		cout << B.operator std::string();

		cout << "\n\nAddit object A i B: ";
		A + B;

		cout << "\n\nMulti object A i B: ";
		A* B;
	}
	catch (My_Error_Range* a) {		//зловлює помилку "My_Error_Range"
		std::cout << a->What();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////2222222\n";

	//використання стандартного винятка
	try { //захищений(контрольований) блок
		FuzzyNumber A_1, B_1, C_1;

		std::cin >> A_1;
		std::cin >> B_1;

		cout << "\nDani(value) chusla A_1: " << A_1;
		cout << A_1.operator std::string();

		cout << "\n\nDani(value) chusla B_1: " << B_1;
		cout << B_1.operator std::string();

		cout << "\n\nAddit object A_1 i B_1: ";
		A_1 + B_1;

		cout << "\n\nMulti object A_1 i B_1: ";
		A_1 * B_1;
	}
	catch (std::out_of_range obj_1) {		// зловлює помилку "out_of_range"
		std::cout << obj_1.what();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////3333333\n";

	//використання винятків - нащадки від стандартних винятків;
	try { //захищений(контрольований) блок
		int size(0);
		std::cout << "\n\nVvedit size masuva: ";  std::cin >> size;

		if ((size < 2) || (size > 80'000'000))
			throw Me_Error_size_memorry("!!!Incorrectly allocated memory!!!");		//генерування об'єкта винятка
		FuzzyNumber* masuv = new FuzzyNumber[size];
		delete [] masuv;
	}
	catch (Me_Error_size_memorry& obj_2) {		// зловлює помилку "Me_Error_size_memorry"
		std::cout << obj_2.What();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////44444444\n";

	cout << "\n\nThe number of objects created: " << Object::Display();
	FuzzyNumber l;
	cout << "\nThe number of objects created: " << Object::Display();
	{
		FuzzyNumber g;
		cout << "\nThe number of objects created: " << Object::Display();
	}
	cout << "\nThe number of objects created: " << Object::Display();

	std::cout << "\n\n";
	system("pause");
	return 0;
}