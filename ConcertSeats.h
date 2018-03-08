#pragma once
#include "ReservationSystem.h"
#include <string>

class ConcertSeats : public ReservationSystem
{
public:
	ConcertSeats(int rows = 1, int columns = 1); // user defined and default constructor combined
	~ConcertSeats();
	void reserve(); // reserves a seat or seats if enough spaces are available, gives a randomly generated confirmation number
	void cancelReservations(); // moves a reservation off the map
	void showAll(); // show all the information of the current seats 

	//GetSet Functions


private:
	int rowTotal, columnTotal; // rows and columns of the reservation space, used for reference in the class
	int ticketsAvailable; // Total tickets available across all sections
	int *regularAdmission; // normal admission multidimensional array, most seats available
	int *vipAdmission; // VIP Tickets multidimensional array, least available
	map <int, string> reservationsName; // stores the seat assigned and the person assigned to it works in conjunction with reservationsNumber map                    
};