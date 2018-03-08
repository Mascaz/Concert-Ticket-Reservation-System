#include "ReservationSystem.h"



ReservationSystem::ReservationSystem(int slots)
{
	spaces = new int[(slots*2)]; // creates a new dynamic array with as many spaces as it needs to reserve
	availableSpaces = slots; // makes available spaces as many as there are
	spacesReserved = 0; // no spaces reserved when creation because that happens in the interface

	for (int i = 0; i < (slots*2); i++)
	{
		if (i < slots)
		{
			spaces[i] = (i + 1); // assigns all values to the first row of elements which is just an index value
		}
		
		else
		{
			spaces[i] = 0; // gives all the remaining spaces a value of zero as to say not occupied
		}
	}

}
ReservationSystem::~ReservationSystem()
{
	delete[] spaces; // deletes the dynamic array
}
void ReservationSystem::reserve()
{
	showAll(); // shows all the seats for the user to see the available seats

	int choice; // created to store the value the user will input

	cout << "\nPick a spot you want to reserve using the top row as the index of the bottom row" << endl;
	cout << "reserve: ";
	
	cin >> choice; //  asks user to input his or her choice
	choice += 49; // adds plus fifty to it in order to make it a valid number in the array and subtracts one in order to make up for array values starting at zero therefore it adds 49
	spaces[choice] = 1; // makes that space equal to one to show that it is occupied in the show all function
	cout << endl;

	showAll(); // shows all the seats for the user to see the seat he or she has reserved
	cout << endl;

	int confirmationNumber; // used to store the confirmation number created in the next few lines

	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(100000, 999999); // define the range

	confirmationNumber = distr(eng);

	cout << "Seat reserved, here's your confirmation number: " << confirmationNumber << endl;
	cout << "Please write down that number as it is the only way to make any changes to your reservation";

	choice -= 49; // reverts the variable back to the original user input in order to store the original value in that map alongside the confirmation number
	reservationsNumber[choice] = confirmationNumber; // assigns the index of the seats with the confirmation number to store the information

}
void ReservationSystem::cancelReservations()
{
	bool confirmNumber; // used to tell the system whether the number was found in the map and also to confirm deletion
	int confirmationNumber; // confirmation number that the user inputs
	int index; // used to store the index value of the map
	char deletion; // used for user to confirm deletion with a (y/n) yes or no 

	cout << endl;
	cout << "\nInput your confirmation number: ";
	cin >> confirmationNumber;

	for (auto p : reservationsNumber) // auto for loop to go through the map
	{
		if (p.second == confirmationNumber) // if the reservation number equals the number put in by the user the this statement happens
		{
			confirmNumber = true; // number found in the map
			index = p.first; // index is saved
		}
		else
		{
			confirmNumber = false; // number not found in the map
		}
	}

	if (confirmNumber == true) // bool variable used 
	{
		cout << "Confirmation number belongs to seat " << index << endl;
		cout << "Are you sure you want to cancel reservation? (y/n): ";
		cin >> deletion; // user puts in if they really do want to delete the confirmation number
		if (deletion == 'y')
		{
			reservationsNumber.erase(index); // deletes the confirmation number from the map 
			spaces[(index + 49)] = 0; // resets the space back to 0 to say it is unoccupied
		}
		else // other option ends the function
		{
			cout << "Seat remains reserved, returning to main interface..." << endl;
			cout << endl;
		}
	}

	else // if the number is not found the function ends
	{
		cout << "Confirmation Number not found, returning to main interface..." << endl;
	}
}

void ReservationSystem::showAll()
{
	cout << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < ((availableSpaces + spacesReserved)); j++) // adds available spaces plus spaces reserved to get the amount of colummns
		{
			cout << setfill('0') << setw(2) << *(spaces + i*((availableSpaces + spacesReserved)) + j) << " "; // sets fill so that the rows and collumns always match no matter the int value
		}
		cout << endl;
	}
}

						// GetSet functions

int * ReservationSystem::getSpaces() const
{
	return spaces;
}
int  ReservationSystem::getAvailableSpaces() const
{
	return availableSpaces;
}
int ReservationSystem::getSpacesReserved() const
{
	return spacesReserved;
}
void ReservationSystem::setAvailableSpaces(int avSpaces)
{
	availableSpaces = avSpaces;
}
void ReservationSystem::setSpacesReserved(int SpacReserv)
{
	spacesReserved = SpacReserv;
}
map<int, int> & ReservationSystem::getReservationsNumber()
{
	return reservationsNumber;
}
void ReservationSystem::displayMap() 
{
	cout << "Reservations Number map" << endl;
	for (auto p : reservationsNumber)
	{
		cout << p.first << "    " << p.second<< endl;
	}
}