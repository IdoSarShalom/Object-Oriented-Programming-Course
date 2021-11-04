#include <iostream>
#include "MyDate.h" 
#include "Calendar.h"

using namespace std;

int main()
{
	char* n = nullptr;
	MyDate date(-3,-12,-3, n); //using the constructor with invalid parameters 
	date.print();

	try
	{
		date.setDay(100);
	}
	catch (char* dayException)
	{
		cerr << "Error: " << dayException << endl;
	}

	date.setDate(2001, 11, 3); 
	date.setComment("The date of my birthday !"); 
	date.print();
	
	int day = date.getDay();  //using get method
	cout << "the day is: " << day << endl;

	MyDate date2(date);	//using copy-constructor
	date2.print(); 
	
	date2.setDate(2020, 12, 30);
	date2.setComment("Two last days of the year!");
	date2.print();
	date2.inc().inc();
	date2.setComment("New year!");
	date2.print();

	date2.init();
	date2.setComment("The date of submission");
	date2.print();

	bool isDateBefore = date.isBefore(date2);
	cout << isDateBefore << endl; // 1=true , 0 = false

	Calendar c1;

	try
	{
		c1.setDate(1+1, date2);
	}
	catch(char* DateException)
	{
		cerr << DateException << endl;
	}
	

	try
	{
		c1.setDate(111 + 1, date2);
	}
	catch (char* DateException)
	{
		cerr << DateException << endl;
	}
	

	try
	{
		c1.setDate(10 + 1, date);
	}
	catch (char* DateException)
	{
		cerr << DateException << endl;
	}

	
	cout << c1.getOccupiedDates() << endl;

	bool ret1 = c1.isFree(1+1);
	bool ret2 = c1.isFree(11+1);

	cout << ret1 << " " << ret2 << "\n";

	int x;
	try 
	{
		x = c1.firstFree();
	}
	catch (char* firstFreeException)
	{
		cerr << firstFreeException << endl; 
	}
	cout << "the first index the array is free: "<< x << endl;

	int y; 
	try
	{
		y = c1.firstOccupied();
	}
	catch (char* firstOccupiedException)
	{
		cerr << firstOccupiedException << endl;
	}
	cout << "the first index the array is occupied: " << y << endl;

	
	c1.insert(date);
	try
	{
		x = c1.firstFree();
	}
	catch (char* firstFreeException)
	{
		cerr << firstFreeException << endl;
	}
	c1.print();
	cout << "the first index the array is free: " << x << endl;

	MyDate date3(1948, 12, 5,"History of Israel !");
	try
	{
		c1.setDate(20, date3);
	}
	catch (char* DateException)
	{
		cerr << DateException << endl;
	}
	
	int ret3 = c1.oldest();

	cout << "the index of the oldest date in the calendar is : " << ret3 << endl;

	int ret4 = c1.datesNum();
	cout << "the number of cells in the array with occupied dates is : " << ret4 <<endl;

	c1.deleteCell(20);
	int ret5 = c1.datesNum();
	cout << "the number of cells in the array with occupied dates is : " << ret5 << endl;

	system("pause");
}


