#include "ReservationSystem.h"
#include "ConcertSeats.h"



int main()
{
	int rows;
	int columns;
	cout << "Input the size of your concert seats, take in mind that the VIP area will be a quarter the size of the regular admissions and will be closer to the stage\n\nEven numbers are required in order for the program to work successfully\n" << endl;
	cout << "Input the number of rows: ";
	cin >> rows;
	while ((rows % 2) == 1) // checks to see that the number is even
	{
		cout << "Number must be even\nTry again: ";
		cin >> rows;
	}
	cout << "Input the number of columns: ";
	cin >> columns;
	while ((columns % 2) == 1) // checks to see that the number is even
	{
		cout << "Number must be even\nTry again: ";
		cin >> columns;
	}

	cout << "\n\nConcert Created!\n" << endl;



	ConcertSeats Orchestra(rows, columns);
	
	int choose; // used for the user to choose what they want to do inside the interface

	cout << "Welcome to the concert interface\n" << endl;
	
	Orchestra.showAll();

	do {
		cout << "\nWhat do you wish to do?" << endl;
		cout << "\n\t1) Reserve seats\n" << "\t2) Cancel Reservations\n" << "\t3) Exit interface\n\n";

		cout << "Use the index numbers to pick a selection: ";
		cin >> choose;
		if (choose == 1)
		{
			Orchestra.reserve();
		}
		else if (choose == 2)
		{
			Orchestra.cancelReservations();
		}
		else if (choose == 3)
		{
			cout << "Exiting out of interface...\n" << endl;
		}
		else
		{
			cout << "invalid input, number must be a selection. Try again" << endl;
		}
	} while (choose != 3);

	cout << "Quit successfully out of interface\n";

	system("pause");
	return 0;
}


