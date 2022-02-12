#include <iostream>
using namespace std;

int askForTime(string message);


int main() {

	char choice;
	int times = 0;
	char valinta = ' ';
	int total_hours = 0;
	int total_minutes = 0;

	bool run = true;

	while (run)
	{
		// Pyydä montako päivää käytät laskennassa
		cout << endl;
		cout << "Moneltako paivalta haluat laskea tunnit? \n";
		cin >> times;
		while (times > 5 || times < 0) // tarkistus, että ei lasketa yli 5 päivää.
		{
			cout << "Nyt taisi tulla liian monta paivaa laskettavaksi? " << "(" << times << ")" << endl;
			cin.clear();
			cout << "Moneltako paivalta haluat laskea tunnit? \n";
			cin >> times;
		}

		cout << "Anna tunnit ja minuutit muodossa (hhmm) Esimerkiksi 14:00 -> 1400" << endl << endl;

		for (int i = 0; i < times; i++)
		{
			int tunnit[100] = { 0 };
			int minuutit[100] = { 0 };

			int first, second;

			cout << endl;

			// Get times from user.
      first = askForTime("#" + to_string(i + 1) + " Lahto:  ");
      second = askForTime("#" + to_string(i + 1) + " Tulo:  ");

			// Convert both to minutes since midnight.

			first = (first / 100) * 60 + first % 100;
			second = (second / 100) * 60 + second % 100;

			// Work out time difference in minutes, taking into
			// account possibility that second time may be earlier.
			// In that case, it's treated as the following day.

			const int MINS_PER_DAY = 1440;
			int minutes = (second + MINS_PER_DAY - first) % MINS_PER_DAY;

			// Turn minutes into hours and residual minutes, then output.

			int hours = minutes / 60;
			minutes = minutes % 60;

			//Inputs the values in arrays
			for (int i = 0; i < times; i++)
			{
				tunnit[i] += hours;
				minuutit[i] += minutes;
			}

			// prints daily hours and minutes
			cout << "paiva #" << i + 1 << " = " << hours << " tuntia ja  " << minutes << " minuuttia." << endl;
			cout << "------------------------------------------------------------" << endl;
			cout << endl;


			// adds up daily calculations
			for (int i = 1; i <= times / 2; i++)
			{
				total_hours += tunnit[i];
				total_minutes += minuutit[i];

				if (total_minutes >= 60)
				{
					total_hours += total_minutes / 60;
					total_minutes = total_minutes % 60;
				}
			}

		}

		// prints total time if calculations are made on more than 1 day
		if (times > 1) {
			cout << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << " Kaikkinensa: " << total_hours << " " << "tuntia ja " << total_minutes << " " << " minuuttia" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}

		//prints leporkovaus if lepo is under 35 hours and days are more than 1
		if (total_hours < 35 && times >1)
		{

			total_hours += total_minutes / 60;
			total_minutes = total_minutes % 60;

			// prints only hours because minutes are 0
			if (total_minutes > 0) {

				int loma = 34;

				cout << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "Lepokorvausta maksettava " << loma - total_hours << " tunnilta";
				if (total_minutes == 0)
				{
					cout << endl;
				}
				// if minutes are over 0 it prints them also
				else {
					cout << " ja " << 60 - total_minutes << " minuutilta" << endl;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
			}
			else {
				int loma = 35;
				cout << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				cout << "Lepokorvausta maksettava " << loma - total_hours << " tunnilta";
				if (total_minutes == 0)
				{
					cout << endl;
				}
				else {
					cout << " ja " << 60 - total_minutes << " minuutilta" << endl;
				}
				cout << "--------------------------------------------------------------------------------" << endl;
			}
		}
		// text when lepo is more than 35
		else if (total_hours > 35 && times > 1)
			cout << "Lepokorvausta ei tarvitse maksaa, koska lepotunnit (" << total_hours << ") on yli 35 tunnin rajan." << endl;
			cout << endl;

		// question for new calculation if needed
		do {
			cout << "Lasketaanko uudelleen?(Y/N)" << endl;
			cin >> choice;
			choice = tolower(choice);//Put your letter to its lower case
		} while (choice != 'n' && choice != 'y');
		if (choice == 'n') {
			run = false;
		}
	}

	//works only on windows machine
	system("pause");
}

int askForTime(string message) {
  string time;

  cout << message; cin >> time;

  int chosenHour = stoi(time.substr(0, 2));
  int chosenMinutes = stoi(time.substr(2, 3));

  while (chosenHour > 23 || chosenHour <  0 || chosenMinutes > 59 || chosenMinutes < 0)
  {
    cout << "Tarkista kellonaika " << "(" << chosenHour << ":" << chosenMinutes << ")" << endl;
    cin.clear();
    cout << message; cin >> time;

    chosenHour = stoi(time.substr(0, 2));
    chosenMinutes = stoi(time.substr(2, 3));
  }

  return stoi(time);
}
