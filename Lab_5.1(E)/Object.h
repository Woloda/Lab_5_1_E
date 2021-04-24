﻿#pragma once

typedef unsigned int uns_i;    //синонім до типу даних "unsigned int" --- "uns_i"

class Object {   //лічильник кількості створених об’єктів
	static uns_i indicator;   //лічильник
public:
	static uns_i Display();  //вивід кількості створених об’єктів
	Object();    //конструктор за умовчанням(без параметрів) --- роль: створення об'єта і збільшення лічильника 
	~Object();   //деструктор --- звільнення пам'яті --- роль: звільнення пам'яті виділеної для об'єкта і зменшення лічильника
};