﻿#include "Object.h"

uns_i Object::indicator = 0;

uns_i Object::Display() { return indicator; }  //вивід кількості створених об’єктів

 //конструктор за умовчанням(без параметрів) --- роль: створення об'єта і збільшення лічильника 
Object::Object() { ++indicator; }

//деструктор --- звільнення пам'яті --- роль: звільнення пам'яті виділеної для об'єкта і зменшення лічильника
Object::~Object() { --indicator; }