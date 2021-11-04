#pragma once
class MyDate
{
private:
	int _day;
	int _month;
	int _year;
	char* _comment = nullptr;

public:
	//getters and setters 
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	char* getComment() const;

	void setDay(const int day); //while using it the programmer need to use try and catch 
	void setMonth(const int month); //while using it the programmer need to use try and catch 
	void setYear(const int year);  //while using it the programmer need to use try and catch 
	void setComment(const char* comment);  //while using it the programmer need to use try and catch  

	void setDate(const int year, const int month, const int day);// check if the date is valid, for each part of the date that isn't valid, the method sets it to 1.

	//constructors 
	MyDate(); //default 
	MyDate(const int year, const int month, const int day, const char* comment);
	MyDate(const MyDate& date); //copy constructor



	MyDate& inc(); //increment 1 day to the current date

	void init(); //set the date to the date of submission (30.8.2020)

	const bool isBefore(const MyDate& date2) const; //is true if date is before date2, else false

	//void changeComment(const char* comment); //same method as the setComment !

	void print() const; 


	~MyDate();
};

