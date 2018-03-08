#include "ConcertSeats.h"


ConcertSeats::ConcertSeats(int rows, int columns):ReservationSystem()
{
	columnTotal = columns; // stores the number of columns
	rowTotal = rows; // stores the number of rows
	regularAdmission = new int[(columns + 1)*(rows + 1)]; // creates a new dynamic array with as many spaces as it needs to reserve, rows + 1 and columns + 1 in order to create index row and column
	vipAdmission = new int[((columns / 2) + 1)*((rows/2) + 1)]; // does the same thing for the vip admission dynamic array
	setAvailableSpaces(rows*columns); // makes available spaces as many as there are
	setSpacesReserved(0); // no spaces reserved when creation because reservation happens in the interface

	int rowCounter = 0; // used to count the columns so that the correct index is inputed in the array

	for (int i = 0; i < ((rows + 1)*(columns + 1)); i++) // regular admission dynamic array
	{
		if (i <= (columns + 1) || (i % (columns + 1)) == 0)
		{
			if (i < (columns + 1))
			{
				regularAdmission[i] = i; // assigns all values to the first row of elements which is just an index value
			}
			else 
			{
				regularAdmission[i] = rowCounter; // assigns the values of the column index
			}
		}

		else
		{
			regularAdmission[i] = 0; // gives all the remaining spaces a value of zero as to say not occupied
		}

		if ((i % (columns + 2)) == 0)
		{
			rowCounter++; // increases counter past the value of columns
		}
	}

	rowCounter = 0; // reset the counter to zero to be used by the other dynamic array

	for (int i = 0; i < (((columns / 2) + 1)*((rows / 2) + 1)); i++) // vip admission dynamic array, columns divided by two because vip admission is hlaf as big horizontally
	{
		if (i <= ((columns/2) + 1) || (i % ((columns/2) + 1)) == 0)
		{
			if (i < ((columns / 2) + 1))
			{
				vipAdmission[i] = i; // assigns all values to the first row of elements which is just an index value
			}
			else
			{
				vipAdmission[i] = rowCounter; // assigns the values of the column index
			}
		}

		else
		{
			vipAdmission[i] = 0; // gives all the remaining spaces a value of zero as to say not occupied
		}

		if ((i % ((columns / 2) + 2)) == 0)
		{
			rowCounter++; // increases counter past the value of columns
		}
	}
}
ConcertSeats::~ConcertSeats()
{
	delete[] regularAdmission; // deletes the dynamic array
	delete[] vipAdmission; // deletes the dynamic array
}
void ConcertSeats::reserve()
{
	showAll(); // shows all the seats for the user to see the available seats

	char areaChoice; // created to store where the user will want to reserve
	int choice; // created to store the value the user will input
	int row; // used to store the row the user picks
	int column; // used to store the column the user will pick
	string name; // used for the user to input his or her name into their confirmation information
	int confirmationNumber; // used to store the confirmation number created after the user decides where to create his or her reservation

	cout << "\nDo you want to reserve in VIP or Regular?" << endl;
	cout << "Enter V for VIP and R for Regular: ";
	cin >> areaChoice;

	if (areaChoice == 'r' || areaChoice == 'R')
	{
		cout << "\nPick the column you want to reserve in using the top row as the index of the columns" << endl;
		cout << "reserve in column: ";

		cin >> column; //  asks user to input his or her choice

		while (column > columnTotal || column < 1) // checks that the value of the column is within range
		{
			cout << "\nInvalid column value, try again" << endl;
			cin >> column;
		}

		cout << "\nNow pick a row you want to reserve in using the first column as the index of the row, the combination the two inputed values will be the spot you reserve" << endl;
		cout << "reserve in row: ";

		cin >> row; //  asks user to input his or her choice

		while (row > rowTotal || row < 1) // checks that the value of the row is within range
		{
			cout << "\nInvalid column value, try again" << endl;
			cin >> row;
		}

		choice = (((columnTotal + 1)*row) + column); // Calculates the correct place the seat is
		// multiplies the columns by the row inputted to get to the correct row and then just adds the first row to make up for the index row followed by whatever the user inputted

		regularAdmission[choice] = 11; // makes that space equal to eleven to show that it is occupied in the show all function and to not get it confused with the 01 index
		cout << endl;

		random_device rd; // obtain a random number from hardware
		mt19937 eng(rd()); // seed the generator
		uniform_int_distribution<> distr(500000, 999999); // define the range, regular gets numbers 500000, to 999999
	
		confirmationNumber = distr(eng); // stores the randomly generated confirmation number
	}
	else if (areaChoice == 'v' || areaChoice == 'V') 
	{
		cout << "\nPick the column you want to reserve in using the top row as the index of the columns" << endl;
		cout << "reserve in column: ";

		cin >> column; //  asks user to input his or her choice

		while (column > (columnTotal/2) || column < 1) // checks that the value of the column is within range
		{
			cout << "\nInvalid column value, try again" << endl;
			cin >> column;
		}

		cout << "\nNow pick a row you want to reserve in using the first column as the index of the row, the combination the two inputed values will be the spot you reserve" << endl;
		cout << "reserve in row: ";

		cin >> row; //  asks user to input his or her choice

		while ((row / 2) > rowTotal || row < 1) // checks that the value of the row is within range
		{
			cout << "\nInvalid column value, try again" << endl;
			cin >> row;
		}

		choice = ((((columnTotal/2) + 1)*row) + column); // Calculates the correct place the seat is
		// multiplies the columns by the row inputted to get to the correct row and then just adds the first row to make up for the index row followed by whatever the user inputted

		vipAdmission[choice] = 11; // makes that space equal to eleven to show that it is occupied in the show all function and to not get it confused with the 01 index
		cout << endl;

		random_device rd; // obtain a random number from hardware
		mt19937 eng(rd()); // seed the generator
		uniform_int_distribution<> distr(100000, 499999); // define the range, vip gets numbers 100000 to 499999
	
		confirmationNumber = distr(eng); // stores the randomly generated confirmation number
	}
	else
	{
		cout << "\ninvalid input, returning to interface" << endl;
		return;
	}

	
	showAll(); // shows all the seats for the user to see the seat he or she has reserved
	cout << endl;

	cout << "Seat reserved, here's your confirmation number for seat located in row " << row << " column "<< column << ": "<< confirmationNumber << endl;
	cout << "Please write down that number as it is the only way to make any changes to your reservation" << endl;
	cout << "Now input your full name so it can be saved alongside your confirmation number" << endl;

	cin.ignore(); // used to ignore any whitespace;
	getline(cin, name); // uses getline so that the last name can also be saved if the user inputs it

	getReservationsNumber()[choice] = confirmationNumber; // assigns the index of the seats with the confirmation number to store the information
	reservationsName[confirmationNumber] = name; // assigns the confirmation number with the name of the person who made the confirmation
}
void ConcertSeats::cancelReservations()
{
	bool confirmNumber; // used to tell the system whether the number was found in the map and also to confirm deletion
	int confirmationNumber; // confirmation number that the user inputs
	int index; // used to store the first value in the reservations map to then erase it if found
	string name; // used to store the name of the person who has the seat
	char deletion; // used for user to confirm deletion with a (y/n) yes or no and also to choose either VIP or Regular

	cout << endl;
	cout << "\nInput your confirmation number: ";
	cin >> confirmationNumber;

	for (auto p : getReservationsNumber()) // auto for loop to go through the map of confirmation numbers
	{
		if (p.second == confirmationNumber) // if the reservation number equals the number put in by the user the this statement happens
		{
			confirmNumber = true; // number found in the map
			index = p.first; // saves the number associated with the confirmation number
		}
		else
		{
			confirmNumber = false; // number not found in the map
		}
	}

	for (auto p : reservationsName) // auto for loop to go through the map of names 
	{
		if (p.first == confirmationNumber) // if the reservation number equals the number put in by the user the this statement happens
		{
			confirmNumber = true; // number found in the map
			name = p.second; // stores the name associated with the confirmation number
		}
		else
		{
			confirmNumber = false; // number not found in the map
		}
	}

	if (confirmNumber == true) // bool variable used 
	{
		cout << "Confirmation number belongs to " << name << endl;

		if (confirmationNumber < 500000) // uses the limit of the random number for VIP admissions to determine where the ticket is and what array to modify
		{
			cout << "Seat belongs to a VIP admission ticket\n" << endl;

			cout << "Are you sure you want to cancel reservation? (y/n): ";
			cin >> deletion; // user puts in if they really do want to delete the confirmation number
			if (deletion == 'y')
			{
				vipAdmission[index] = 0; // resets the space back to 0 to say it is unoccupied
				getReservationsNumber().erase(index); // deletes the confirmation number from the map 
				reservationsName.erase(confirmationNumber); // deletes the name associated with the confirmation number
			}
			else // other option ends the function
			{
				cout << "Seat remains reserved, returning to main interface..." << endl;
				cout << endl;
			}
		}
		else
		{
			cout << "Seat belongs to a regular admission ticket\n" << endl;

			cout << "Are you sure you want to cancel reservation? (y/n): ";
			cin >> deletion; // user puts in if they really do want to delete the confirmation number
			if (deletion == 'y')
			{
				regularAdmission[index] = 0; // resets the space back to 0 to say it is unoccupied
				getReservationsNumber().erase(index); // deletes the confirmation number from the map 
				reservationsName.erase(confirmationNumber); // deletes the name associated with the confirmation number
			}
			else // other option ends the function
			{
				cout << "Seat remains reserved, returning to main interface..." << endl;
				cout << endl;
			}
		}
	}

	else // if the number is not found the function ends
	{
		cout << "Confirmation Number not found, returning to main interface..." << endl;
	}
	cout << endl;
	showAll();
}
void ConcertSeats::showAll()
{
	cout << "00 = unoccupied\n11 = occupied\n" << endl;
	string space = string((columnTotal), ' ') ;

	cout << space << "---------------------------------------------------------------" << endl;
	cout << space << "---------------------------------------------------------------" << endl;
	cout << space << "---------------------------Stage-------------------------------" << endl;
	cout << space << "---------------------------------------------------------------" << endl;
	cout << space << "---------------------------------------------------------------" << endl;
	cout << endl;

	space = string((columnTotal), ' ');

	cout << space << "\t\tVIP Admission" << endl;

	for (int i = 0; i < ((rowTotal/2) + 1); i++)
	{
		cout << space;
		for (int j = 0; j < ((columnTotal/2) + 1); j++)
		{
			cout << setfill('0') << setw(2) << *(vipAdmission + i*((columnTotal/2) + 1) + j) << " ";
		}
		cout << endl;
	}

	cout << endl;

	space = string((columnTotal), ' ');
	string space2 = string((columnTotal/3), ' ');

	cout << space << "\t\tRegular Admission" << endl;

	for (int i = 0; i < (rowTotal + 1); i++)
	{
		cout << space2;
		for (int j = 0; j < (columnTotal + 1); j++)
		{
			cout << setfill('0') << setw(2) << *(regularAdmission + i*(columnTotal + 1) + j) << " ";
		}
		cout << endl;
	}
}