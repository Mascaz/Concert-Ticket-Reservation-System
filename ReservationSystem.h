#pragma once
#include <iostream>
#include <map>
#include <iomanip>
#include <random>

using namespace std;

class ReservationSystem
{
public:
	ReservationSystem(int spaces = 1); // default constructor and user defined constructor all in one, the only parameter needed is the amount of reservations needed in order to create a dynamic array big enough to hold everyone
	~ReservationSystem(); // destructor used to delete the spaces dynamic array
	virtual void reserve(); // reserves a seat or seats if enough spaces are available, gives a randomly generated confirmation number
	virtual void cancelReservations(); // cancels seats needs the randomly generated confirmation number given in the reserve function
	virtual void showAll(); // show all the information of the current seats available in inherited classes too 

	// GetSet functions

	int * getSpaces() const; // returns the pointer of the dynamic array spaces
	int  getAvailableSpaces() const; // returns the number of available spaces available
	int getSpacesReserved() const; // returns the amount of spaces reserved
	void setAvailableSpaces(int); // sets available spaces
	void setSpacesReserved(int); // sets spaces reserved
	map<int, int> & getReservationsNumber(); // returns the map so that it can be used by child classes

	//debug
	void displayMap(); // used to debug the map of the parent function

private:
	int *spaces; // a dynamic array that allows for a dynamic amount of spaces to be assigned to whatever needed 
	int availableSpaces; // keeps track of how many places are available, only parameter used in the constructor
	map<int, int> reservationsNumber; // stores the reservations made and their confirmation number
	int spacesReserved; // keeps track of how many spaces have been reserved for people
};