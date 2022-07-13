#include <iostream>
#include <fstream>
#include <string.h>
#include "Produse.h";
#include "User.h";

int main() {
	int ok, c;

	User* u = new User();
	u->MainMenu();
	while (true) {
		std::cin >> c;
		std::cout << std::endl;
		switch (c)
		{
		case 1:
			ok = u->login();
			if (ok != 0)
			{
				if (ok == 2)
				{

					u = new Administrator();
					u->MainMenu();

				}
				else {
					u = new Client();
					u->MainMenu();
				}
			}
			else {
				u->MainMenu();
			}
			break;
		case 2:
			u->registration();
			break;
		case 3:
			std::cout << "\t\t\t Thank you!\n\n";
			exit(0);
			break;
		default:
			system("cls");
			std::cout << "\t\t\t Please select from the option given above \n" << std::endl;
			u->MainMenu();
		}
	}

}