#pragma once
#include "MyDate.h"

class Calendar
{
public:

	//constructors 
	Calendar();
	Calendar(const Calendar& dates);//copy constructor

	~Calendar();

	//getters and setters

	const int getOccupiedDates() const; //return the number of occupied dates in the calendar 

	void setOccupiedDates(int numberOfOccupiedDates);

	MyDate& getDateByIndex(int index); //throw 

	void setDate(int indx, const MyDate& date); //sets the given date, in the cell with index=num, in the array, throw
	
	bool isFree(int indx) const;//checks if the cell num in the array id free or no , (throw)

	const int firstFree() const;// returns the num of the first cell that is free (throw)

	const int firstOccupied() const; //returns the first occupied cell in the array (throw)

	const bool insert(const MyDate& date);//inserts the given date to the first free cell in the array and returns true, if the array is full,returns false

	const int oldest() const; //returns the index of the cell in the array that has the oldest date

	int datesNum() const;// returns the number of cells with date

	void deleteAll();// deletes all the cells in the array

	void deleteCell(int index);// delete the cell with index=num (throw), exact method as delete in the word document, I couldn't use delete because it is a reserved word

	void print() const;//prints all dates in array

private:
	MyDate* _dates[30];
	int _occupiedDates;

};

	