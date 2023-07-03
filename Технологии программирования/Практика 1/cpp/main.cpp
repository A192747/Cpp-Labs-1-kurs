#include <iostream>
#include "Square.h"
#include "Rhombus.h"
#include "MyExeption.h"

int main()
{

	/*    
	Базовая гарантия : все ресурсы корректно освобождаются, объекты
	пригодны для дальнейшего использования, но их состояние может быть изменено.
	*/
	std::cout << "******************************************\n";
	std::cout << "************* Basic Warranty *************\n";
	std::cout << "******************************************\n\n";

	Square square;
	//	размер стороны кравдрата при его создании равен 0
	std::cout << "Square side size before setting the value: " << square.getSide() << "\n";
	//	установим значение длинны стороны ромба в пределах от 1 до 99
	square.side(22);
	std::cout << "Square side size after setting the value 22: " << square.getSide() << "\n";
	std::cout << "Trying to set the side value 100..."  << "\n";
	try
	{
	//	попытаемся установить размер стороны квадрата свыше 99
		square.side(100);
	//	так как значение, которое мы пытаемся установить переменной side_ выходит за 
	//	допустимые пределы от 0 по 99, то значение стороны квадрата установится равным 1 и выбросится исключение 
	}
	catch (Wrong_Side_Size& e)
	{
		std::cerr << e.what();
	}
	//	размер стороны кравдрата после сработавшего исключения
	std::cout << "Square side size after error and setting the value 100: " << square.getSide() << "\n\n\n\n";
	

	/*
	Строгая гарантия : состояние программы остаётся таким же, как до
	вызова метода, сгенерировавшего исключение.
	*/
	std::cout << "******************************************\n";
	std::cout << "************* Strict Warranty ************\n";
	std::cout << "******************************************\n\n";
	Rhombus rhombus;
	//	размер стороны ромба при его создании равен 0
	std::cout << "Rhombus side size before setting the value: " << rhombus.getSide() << "\n";
	//	установим значение длинны стороны ромба в пределах от 1 до 99
	rhombus.side(55);
	std::cout << "Rhombus side size after setting the value 55: " << rhombus.getSide() << "\n";
	std::cout << "Trying to set the side value 100..." << "\n";
	try
	{
		//	попытаемся установить размер стороны ромба свыше 99
		square.side(100);
		//	так как значение, которое мы пытаемся установить переменной side_ выходит за 
		//	допустимые пределы от 0 по 99, то значение стороны ромба останется прежним и выбросится исключение 
	}
	catch (Wrong_Side_Size& e)
	{
		std::cerr << e.what();
	}
	//	размер стороны кравдрата после сработавшего исключения
	std::cout << "Rhombus side size after error and setting the value 100: " << rhombus.getSide() << "\n\n\n\n";


	/*
	Гарантия отсутствия исключений: метод/функция ни при каких условиях
	не генерирует исключений. Такие методы необходимы для обеспечения
	базовой и строгой гарантий.
	*/
	std::cout << "******************************************\n";
	std::cout << "********* No Exception Guarantee *********\n";
	std::cout << "******************************************\n\n";

	//конструктор копирования в данном случае не выбрасывает исключений
	Rhombus rhombusOne;
	rhombusOne.side(2);
	Rhombus rhombusTwo(rhombusOne);

	std::cout << "Length of the side of the first rhombus : " << rhombusOne.getSide() << "\n";
	std::cout << "Length of the side of the second rhombus : " << rhombusTwo.getSide() << "\n";

	return 0;
}
