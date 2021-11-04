#include "Calendar.h"
#include "MyDate.h"
#include <iostream>
using namespace std;

const int Calendar::getOccupiedDates() const
{
	return this->_occupiedDates;
}

void Calendar::setOccupiedDates(int numberOfOccupiedDates)
{
	this->_occupiedDates = numberOfOccupiedDates;
}

MyDate& Calendar::getDateByIndex(int indx)
{
	int index = indx - 1;
	if (index < 0 || index>29 || _dates[index] == nullptr) //the index that the array has is 0-29, 
		throw "Error: you have to put a number between 1 to 30, the indexes of the array are 1 to 30";

	return *_dates[index];

}

void Calendar::setDate(int index, const MyDate& date)// sets the given date, in the cell with index=num, in the array
{
	int indx = index - 1;

	if (indx < 0 || indx>29) //the index that the array has is 0-29, 
		throw "Error: you have to put a number between 1 to 30, the indexes of the array are 1 to 30";

	if (this->isFree(indx+1) == true) //the cell is free update the _occupiedDates ! , no need for try and catch because the index is running from 1 to 30
		this->setOccupiedDates(this->_occupiedDates + 1);

	delete _dates[indx];
	_dates[indx] = nullptr;
	_dates[indx] = new MyDate(date);
}

//the function return true if the element in the array is free and false otherwise
bool Calendar::isFree(int index) const
{
	int indx = index - 1;

	if (indx < 0 || indx>29 )
		throw "Error: you have to put a number between 1 to 30, the indexes of the array are 1 to 30"; 

	if (this->_dates[indx] == nullptr)
		return true; //the element in the array is free 
	else
		return false; //the element in the array is occupied 
}


const int Calendar::firstFree() const
{
	for (int j = 0; j < 30; j++)
	{
		if (this->isFree(j+1) == true) //we found a free cell in the array, no need to use try and catch because the indexes of j running from 1 to 30
			return j+1; 
	} 

	throw "Error: the whole cells in the array are full, no free cells !"; // the array is full, there is no free cell
}

//inserts the given date to the first free cell in the array and returns true, if the array is full returns false
const bool Calendar::insert(const MyDate& date)
{
	int indxFree;
	try
	{
		indxFree = this->firstFree()-1;  //the first element in the array which his cell is free 
	}
	catch (const char* arrayFullException) // the array is full
	{
		cerr << arrayFullException << endl;
		return false; // the array is full
	} 

	this->setDate(indxFree+1, date); //using setDate, no need to use try and catch we already checked that the index is valid

	return true; 
}

//help method to implement the oldest method
//returns the first occupied cell in the array
const int Calendar::firstOccupied() const
{
	for (int j = 0; j < 30; j++)
	{
		if (this->isFree(j+1) == false) //we found an occupied cell in the array,  no need to use try and catch because the indexes of i running from 1 to 30
			return j+1;
	}
	
	throw "Error: the whole cells in the array are free, no occupied cells !"; // there is no occupied cell in the array
}

//return the oldest day 
const int Calendar::oldest() const
{
	int oldIndex = 0;
	int firstOccupiedIndex;
	
	try
	{
		firstOccupiedIndex = this->firstOccupied();
	}
	catch (const char* noOccupiedCellsException)
	{
		cerr << noOccupiedCellsException << endl;
		return -1;
	}


	MyDate* maxDate = this->_dates[firstOccupiedIndex] ;

	
	for (int i = firstOccupiedIndex; i < 30 ; i++)
	{
		if (this->isFree(i+1) == true) // free cell we don't need to check his date, no need for try and catch because the index is running from 1 to 30
			continue;

		MyDate* tempDate = this->_dates[i];
		
		if (maxDate->isBefore(*tempDate) == false) //the MaxDate is not the oldest, update it! 
		{
			maxDate = tempDate;
			oldIndex = i;
		}
	}

	return oldIndex+1;
}

int Calendar::datesNum() const 
{
	int count = 0;
	for (int i = 0; i < 30; i++)
	{
		if (this->isFree(i+1) == false) //the cell is occupied, no need for try and catch because the index is running from 1 to 30
			count++;
	}
	return count;
}

void Calendar::deleteAll()
{
	for (int i = 0; i < 30; i++)
	{
		if (this->isFree(i+1) == false) //the cell is occupied, no need for try and catch because the index is running from 1 to 30
		{
			delete _dates[i];
			_dates[i] = nullptr; //deallocate the myDate object dynamic memory (char*) in each cell of the array 
		}
	}
	_occupiedDates = 0;
}

void Calendar::deleteCell(int ind)
{
	int index = ind - 1;
	bool flag; 
	try
	{
		flag = this->isFree(index+1);
	}
	catch (char* indexException)
	{
		cerr << indexException << endl;
	}

	if (flag == false) //the cell is occupied
	{
		delete _dates[index]; //first, deallocate the myDate object dynamic memory (char*) in the cell of the array 
		_dates[index] = nullptr;
	}
	_occupiedDates--;
}


void Calendar::print() const //prints all dates in array
{
	bool flag = false; 

	for (int i = 0; i < 30; i++)
	{
		if (this->isFree(i+1) == false) //the cell is occupied, no need for try and catch because the index is running from 1 to 30
		{
			flag = true; 
			cout << "the index of the date in the calendar array is: " << i+1 <<endl;
			this->_dates[i]->print();
		}
	}

	if (flag == false)
		cout << "Empty Calender" << endl; 
}


Calendar::Calendar()
{
	for (int i = 0; i < 30; i++)
			this->_dates[i] = nullptr;
	this->_occupiedDates= 0;
}

Calendar::Calendar(const Calendar& dates) {
	this->_occupiedDates = dates._occupiedDates;

	MyDate* tempDate;

	for (int i = 0; i < 30; i++)
	{
		if (dates.isFree(i+1) == false) //the cell is occupied, no need for try and catch because the index is running from 1 to 30
		{
			this->_dates[i] = new MyDate(*dates._dates[i]);
		}
		else //the cell is free 
		{
			this->_dates[i] = nullptr;
		}
	}
}

Calendar::~Calendar()
{
	this->deleteAll();
}
