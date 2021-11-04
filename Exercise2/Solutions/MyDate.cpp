#include "MyDate.h" 
#include <iostream>
using namespace std;

int MyDate::getDay() const
{
	return this->_day;
}

int MyDate::getMonth() const
{
	return this->_month;
}

int MyDate::getYear() const
{
	return this->_year;
}

char* MyDate::getComment() const
{
	return this->_comment;
}

void MyDate::setDay(const int day) {
	if (day < 1 || day>31)// the day has to be positive, and in the longest months there are 31 days,so it can not be larger than 31
		throw "invalid day, the day is initialized to 1";
	else if (this->_month == 2 && day > 28) //in February there are 28 days, not more than that
		throw  "invalid day, the day is initialized to 1";
	else if ((this->_month == 4 || this->_month == 6 || this->_month == 9 || this->_month == 11) && day > 30)//according to the first if, the range of days is 1-31, so if the month is not 4,6,9,11,2, the day can be 31 and we won't get exception
		throw  "invalid day, the day is initialized to 1";

	this->_day = day;
}

void MyDate::setMonth(const int month)
{
	if (month < 1 || month>12)
		throw "invalid month, the month is initialized to 1";
	this->_month = month;
}

void MyDate::setYear(const int year) {
	if (year < 0)
		throw "invalid year, the year is initialized to 1";
	this->_year = year;
}

void MyDate::setComment(const char* comment) {
	if (comment == nullptr) //the pointer does not point to a char
		throw "invalid comment, the comment is initialized to: 'no comment yet' ";
	if (this->_comment != nullptr)
	{
		delete[] _comment;
		_comment = nullptr;
	}
	
	delete[] _comment;
	_comment = nullptr;

	this->_comment = new char[strlen(comment) +1]; //+1 for the \0 
	strcpy_s(this->_comment, strlen(comment) + 1, comment);
}

void MyDate::setDate(const int year, const int month, const int day)
{
	try // tries to set the given year
	{
		this->setYear(year);
	}
	catch (const char* yearException) //sets the year to 1 if it isn't positive
	{
		cerr << "Error: " << yearException << endl;
		this->setYear(1);
	}
	try //tries to set the given month
	{
		this->setMonth(month);
	}
	catch (const char* monthException) //sets the month to 1, if it isn't in range of 1-12
	{
		cerr << "Error: " << monthException << endl;
		this->setMonth(1);
	}
	try //tries to set the given day 
	{
		this->setDay(day);
	}
	catch (const char* dayException) //if it doesn't match to the numbers of days in the month, sets it to 1
	{
		cerr << "Error: " << dayException << endl;
		this->setDay(1);
	}
}

//constructors

MyDate::MyDate() 
{
	this->_day = 1;
	this->_month = 1;
	this->_year = 2020;

	const char *c = "no comment yet";
	this->_comment = new char[strlen(c) + 1]; //+1 for the \0 
	strcpy_s(this->_comment, strlen(c) + 1, c);
}

MyDate::MyDate(const int year, const int month, const int day, const char* comment)
{
	this->setDate(year, month, day);
	try
	{
		this->setComment(comment);
	}
	catch (const char* commentException)
	{
		cerr << "Error: " << commentException << endl;

		delete[] _comment;

		const char *c = "no comment yet";
		this->_comment = new char[strlen(c) + 1]; //+1 for the \0 
		strcpy_s(this->_comment, strlen(c) + 1, c);

	}	
}


MyDate::MyDate(const MyDate& date) //copy - constructor 
{
	this->setDate(date.getYear(), date.getMonth(), date.getDay());
	this->setComment(date.getComment()); //no need to check for exception because there is not way that an object created with an invalid comment
}



MyDate& MyDate::inc()
{
	int newDay = this->getDay() + 1; 

	try  //checks if the given day, wasn't the last day in the given month
	{
		this->setDay(newDay);
	}
	catch (...) //if the day, was the last, changes the month to the next month, and the day becomes the first day of the next month
	{	
		this->setDay(1);
		int newMonth = this->getMonth() + 1;
		try //check if the given month, wasn't the last month 
		{
			this->setMonth(newMonth);
		}
		catch (...) //if the month was the last, change the year to the next year, and the month becomes the first month of the next year
		{
			this->setMonth(1);
			int newYear = this->getYear() + 1;
			this->setYear(newYear); //we cannot work with an object who has a negative year because it could not be created with an initialized negative year, therefore we do not need to check for exceptions 
		}
	}
	return *this;
}


void MyDate::init()
{
	this->setDate(2020, 8, 30);
}

//the implementation uses more brackets than needed, because it is more readable for a person and can easily distinguish the transitions from line to line
const bool MyDate::isBefore(const MyDate& date2) const
{
	if (this->_year < date2.getYear()) // if the year is earlier, of course the date is before 
	{
		return true;
	}
	else
	{
		if (this->_year == date2.getYear()) // it's not enough, the month can be earlier
		{
			if (this->_month < date2.getMonth())
			{
				return true;
			}
			else
			{
				if (this->_month == date2.getMonth()) //it's not enough, the day can be earlier
				{
					if (this->_day < date2.getDay())
					{
						return true;
					}
					else
					{
						return false; //if the day is equal or bigger automatically the date is equal or bigger
					}
				}
				else
				{
					return false; //same year but not before in the months 
				}
			}
		}
		else
		{
			return false;
		}
	}
}


void MyDate::print() const
{
	if (this->getDay() < 10)
		cout << "0";
	cout << this->getDay() << "/";
	if (this->_month < 10)
		cout << "0";
	cout << this->getMonth() << "/";
	if (this->_year < 10)
		cout << "000";
	else if (this->_year < 100)
		cout << "00";
	else if (this->_year < 1000)
		cout << "0";
	cout << this->getYear() << endl;

	//no need to check for exceptions because the object could not be created with an initialized invalid comment  
	if (_comment != nullptr)
		cout << "the comment of the date is: " << "'" <<   this->_comment << "'" << endl;

}


MyDate::~MyDate()
{
	delete[] this->_comment; 
	_comment = nullptr;
}

