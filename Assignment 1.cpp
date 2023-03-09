//************************************************************************** 
//
// Programming Excerise 1   
// CLASS: COSC 2336.S01
// AUTHOR: TYLER ECHOLS 
// DAtE: Sep 2017  
//
//************************************************************************** 

#include <iostream>

using namespace std;

#include "UBArray.h"
#include <string.h>
#include <string>

void Func(const UBArray <int, string> &);
void Func2(const UBArray <string, int> &);


void main()
{
	UBArray <int, string>			UB1;
	UBArray <int, string>	        UB2;
	UBArray <int, string>			UB3;
	UBArray <int, string>			UB4;

	UBArray <string, int>			UB5;
	UBArray <string, int>			UB6;


	cout << "indication of the array with int and string " << endl;

	UB1["A"] = 22;
	UB1["C"] = -99;
	UB1["E"] = 555;
	UB1["I"] = -3333;
	UB1["o"] = 777777;

	cout << "Testing the non-constant operator: " << endl;

	cout << UB1["o"] << endl;
	cout << UB1["A"] << endl;
	cout << UB1["I"] << endl;
	cout << UB1["C"] << endl;
	cout << UB1["E"] << endl;
	cout << UB1["b"] << endl;
	cout << UB1["Z"] << endl;

	cout << "\nTesting the constant subscript operator: " << endl;

	Func(UB1);
	Func(UB3);

	cout << "\nTesting the At method: " << endl;

	UB1.At("U") = 12345;
	cout << UB1.At("U") << endl;

	cout << "\nAt method complete " << endl;

	cout << "\nTesting the Remove method: " << endl;

	cout << UB1.Remove("U") << endl; 
	cout << UB1["U"] << endl;		 
	cout << UB1.Remove("E") << endl; 
	cout << UB1["E"] << endl;		
	cout << UB1.Remove("XY") << endl;  

	cout << "\nTesting Remove method complete " << endl;

	cout << "Testing Size method: " << endl;
	cout << UB1.Size() << endl; 
	cout << UB3.Size() << endl; 

	cout << "\nSize method complete " << endl;

	UB1["B"] = 10;
	cout << "\nTesting GetFirst method: " << endl;
	cout << UB1.GetFirst() << endl; 
	try
	{
		cout << "\nTesting GetFirst exception handling: " << endl;
		UB3.GetFirst();
	}
	catch (UBArray <int, string>::Exceptions e)
	{
		if (e == UBArray<int, string>::ArrayEmpty)
		{
			cout << "Exception: ArrayEmpty" << endl;
		}
		else
		{
			cout << "Exception: GetFirst unknown exception" << endl;
		}
	}

	cout << "\nGetFirst method complete " << endl;

	cout << "\nTesting GetLast method: " << endl;
	cout << UB1.GetLast() << endl; 
	try
	{
		cout << "\nTesting GetLast exception handling: " << endl;
		UB3.GetLast();
	}
	catch (UBArray <int, string>::Exceptions e)
	{
		if (e == UBArray<int, string>::ArrayEmpty)
		{
			cout << "Exception: ArrayEmpty" << endl;
		}
		else
		{
			cout << "Exception: GetLast unknown exception" << endl;
		}
	}

	cout << "\nGetLast method complete " << endl;


	cout << "\nTesting GetNext method: " << endl;
	UB1.GetFirst();
	cout << UB1.GetNext() << endl; 
	try
	{
		cout << "\nTesting GetNext exception handling: " << endl;
		UB4.GetNext();
	}
	catch (UBArray <int, string>::Exceptions e)
	{
		if (e == UBArray<int, string>::InteratorNotInitiailized)
		{
			cout << "Exception: IterAtorNotInitialized" << endl;
		}
		else
		{
			cout << "Exception: GetNext unknown exception" << endl;
		}
	}

	try
	{
		UB1.GetLast();
		UB1.GetNext();
	}
	catch (UBArray <int, string>::Exceptions e)
	{
		if (e == UBArray<int, string>::NoNextElement)
		{
			cout << "Exception: NoNextElement" << endl;
		}
		else
		{
			cout << "Exception: GetNext unknown exception" << endl;
		}
	}

	cout << "\nGetNext method complete " << endl;


	cout << "\nTesting GetPrev method: " << endl;
	UB1.GetLast();
	cout << UB1.GetPrev() << endl; 
	try
	{
		cout << "\nTesting GetPrev exception handling: " << endl;
		UB4.GetPrev();
	}
	catch (UBArray <int, string>::Exceptions e)
	{
		if (e == UBArray<int, string>::InteratorNotInitiailized)
		{
			cout << "Exception: IterAtorNotInitialized" << endl;
		}
		else
		{
			cout << "Exception: GetPrev unknown exception" << endl;
		}
	}

	try
	{
		UB1.GetFirst();
		UB1.GetPrev(); 
	}
	catch (UBArray <int, string>::Exceptions e)
	{
		if (e == UBArray<int, string>::NoPrevElement)
		{
			cout << "Exception: NoPrevElement" << endl;
		}
		else
		{
			cout << "Exception: GetPrev unknown exception" << endl;
		}
	}


	cout << "\nGetPrev method complete " << endl;


	cout << "\nTesting DeleteAll method" << endl;
	UB1.DeleteAll();

	cout << "\nDeleteAll method complete " << endl;

	cout << "Array with String and Int" << endl;

	UB5[0] = "j";
	UB5[2] = "k";
	UB5[6] = "l";
	UB5[12] = "m";

	cout << "Testing the non-constant subscript operator: " << endl;

	cout << UB5[0] << endl;
	cout << UB5[2] << endl;
	cout << UB5[6] << endl;
	cout << UB5[12] << endl;
	cout << UB5[20] << endl;

	cout << "non-constant subscript operator complete " << endl;

	cout << "\nTesting the constant subscript operator: " << endl;

	Func2(UB5);
	Func2(UB6);

	cout << "\nconstant subscript operator complete " << endl;

	cout << "\nTesting the At method: " << endl;

	UB5.At(30) = "v";
	cout << UB5.At(30) << endl;

	cout << "\nAt method complete " << endl;

	cout << "\nTesting the Remove method: " << endl;

	cout << UB5.Remove(30) << endl; 
	cout << UB5[30] << endl;		 
	cout << UB5.Remove(40) << endl;

	cout << "\nRemove method complete " << endl;

	cout << "\nTesting Size method: " << endl;
	cout << UB5.Size() << endl; 
	cout << UB6.Size() << endl;

	cout << "\nSize method complete " << endl;

	cout << "\nTesting GetFirst method: " << endl;
	cout << UB5.GetFirst() << endl; 
	try
	{
		cout << "\nTesting GetFirst exception handling: " << endl;
		UB6.GetFirst();
	}
	catch (UBArray <string, int>::Exceptions e)
	{
		if (e == UBArray<string, int>::ArrayEmpty)
		{
			cout << "Exception: ArrayEmpty" << endl;
		}
		else
		{
			cout << "Exception: GetFirst unknown exception" << endl;
		}
	}

	cout << "\nGetFirst method complete " << endl;

	cout << "\nTesting GetLast method: " << endl;
	UB5[30] = "v";
	cout << UB5.GetLast() << endl; 
	try
	{
		cout << "Testing GetLast exception handling: " << endl;
		UB6.GetLast();
	}
	catch (UBArray <string, int>::Exceptions e)
	{
		if (e == UBArray<string, int>::ArrayEmpty)
		{
			cout << "Exception: ArrayEmpty" << endl;
		}
		else
		{
			cout << "Exception: GetLast unknown exception" << endl;
		}
	}

	cout << "\nGetLast method complete " << endl;

	cout << "\nTesting GetNext method: " << endl;
	UB5.GetFirst();
	cout << UB5.GetNext() << endl; 
	try
	{
		cout << "Testing GetNext exception handling: " << endl;
		UB6.GetNext();
	}
	catch (UBArray <string, int>::Exceptions e)
	{
		if (e == UBArray<string, int>::InteratorNotInitiailized)
		{
			cout << "Exception: IterAtorNotInitialized" << endl;
		}
		else
		{
			cout << "Exception: GetNext unknown exception" << endl;
		}
	}

	try
	{
		UB5.GetLast();
		UB5.GetNext();
	}
	catch (UBArray <string, int>::Exceptions e)
	{
		if (e == UBArray<string, int>::NoNextElement)
		{
			cout << "Exception: NoNextElement" << endl;
		}
		else
		{
			cout << "Exception: GetNext unknown exception" << endl;
		}
	}

	cout << "\nGetNext method complete " << endl;

	cout << "\nTesting GetPrev method: " << endl;
	UB5.GetLast();
	cout << UB5.GetPrev() << endl; 
	try
	{
		cout << "Testing GetPrev exception handling: " << endl;
		UB6.GetPrev();
	}
	catch (UBArray <string, int>::Exceptions e)
	{
		if (e == UBArray<string, int>::InteratorNotInitiailized)
		{
			cout << "Exception: IterAtorNotInitialized" << endl;
		}
		else
		{
			cout << "Exception: GetPrev unknown exception" << endl;
		}
	}

	try
	{
		UB5.GetFirst();
		UB5.GetPrev(); 
	}
	catch (UBArray <string, int>::Exceptions e)
	{
		if (e == UBArray<string, int>::NoPrevElement)
		{
			cout << "Exception: NoPrevElement" << endl;
		}
		else
		{
			cout << "Exception: GetPrev unknown exception" << endl;
		}
	}

	cout << "\nGetPrev method complete " << endl;

	cout << "\nTesting DeleteAll method" << endl;
	UB1.DeleteAll();

	cout << "\nDeleteAll method complete " << endl;

}

void Func(const UBArray <int, string> & UB)
{
	try
	{
		cout << UB["o"] << endl;
		cout << UB["C"] << endl;
		cout << UB["E"] << endl;
		cout << UB["b"] << endl;
		cout << "\nTesting constant subscript operator exception handling: " << endl;
		cout << UB["D"] << endl;
	}
	catch (UBArray<int, string>::Exceptions e)
	{
		if (e == UBArray<int, string>::InvalidIndex)
		{
			cout << "Exception: Index not found" << endl;
		}
		else
		{
			if (e == UBArray<int, string>::ArrayEmpty)
			{
				cout << "Exception: Array Empty" << endl;
			}
			else
			{
				cout << "Exception: constant subscript operAtor, unknown exception" << endl;
			}
		}
	}
}

void Func2(const UBArray <string, int> & UB)
{
	try
	{
		cout << UB[0] << endl;
		cout << UB[2] << endl;
		cout << UB[6] << endl;
		cout << UB[12] << endl;
		cout << "\nTesting constant subscript operAtor exception handling: " << endl;
		cout << UB[25] << endl;
	}

	catch (UBArray<string, int>::Exceptions e)
	{
		if (e == UBArray<string, int>::InvalidIndex)
		{
			cout << "Exception: Index not found" << endl;
		}
		else
		{
			if (e == UBArray<string, int>::ArrayEmpty)
			{
				cout << "Exception: Array Empty" << endl;
			}
			else
			{
				cout << "Exception: constant subscript operAtor, unknown exception" << endl;
			}
		}
	}
}