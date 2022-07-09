#pragma once

class User {
public:
	virtual void MainMenu() {

		std::cout << "\t| Press 1 to Login         |" << std::endl;
		std::cout << "\t| Press 2 to Register      |" << std::endl;
		std::cout << "\t| Press 3 to Exit          |" << std::endl;
		std::cout << "\n\t\t\t Please enter your choice : ";


	}
	int login() {
		int count{};
		std::string userID = "", Lpassword = "", id, pass;
		system("cls");
		std::cout << "\t\t\t Please enter the username and password :" << std::endl;
		std::cout << "\t\t\t Username ";
		std::cin >> userID;
		std::cout << "\t\t\t Password ";
		std::cin >> Lpassword;
		system("cls");


		std::ifstream input("records.txt");

		while (input >> id >> pass)
		{

			if (id == userID && pass == Lpassword)
			{
				count = 1;
				system("cls");
			}
		}
		input.close();

		std::ifstream ain("admin.txt");

		if (count == 1)
		{
			while (ain >> id >> pass) {

				if (id == userID && pass == Lpassword) {
					return 2;
				}
			}
			std::cout << userID << "\n Your Login is successfull \n Thanks for logging in! \n";
			return 1;

		}
		else {
			std::cout << "\n Login error please check your username and password\n";
			return 0;

		}
		ain.close();
	}
	void registration()
	{
		std::string ruserID, rpassword, rid, rpass;
		system("cls");
		std::cout << "\t\t\t Enter the username : ";
		std::cin >> ruserID;
		std::cout << "\t\t\t Enter the password : ";
		std::cin >> rpassword;
		std::ifstream fin("records.txt");

		if (fin >> ruserID)
		{
			system("cls");
			std::cout << " You are already registered " << std::endl;
			MainMenu();

		}
		else {
			std::ofstream fout("records.txt", std::ios::app);
			fout << ruserID << " " << rpassword << std::endl;
			system("cls");
			std::cout << "\n\t\t\t Registration is successfull! \n";
			MainMenu();
		}
	}

};

class Administrator : public User {
	void MainMenu() override {
		int a;

		std::cout << "\t| 1)Add items        |" << std::endl;
		std::cout << "\t| 2)Delete items     |" << std::endl;
		std::cout << "\t| 3)Add admin        |" << std::endl;
		std::cout << "\t| 4)Exit             |" << std::endl;
		std::cout << "\n\t\t\t Please enter your choice : ";
		std::cin >> a;
		std::cout << std::endl;
		switch (a)
		{
		case 1:
			Add_items();
			break;
		case 2:
			Delete_items();
			break;
		case 3:
			Add_admin();
			break;
		case 4:
			exit(0);
			break;
		default:
			system("cls");
			std::cout << "\t\t\t Please select from the option given above \n" << std::endl;
			MainMenu();

		}


	}
	void Add_items() {

	}
	void Delete_items() {

	}
	void Add_admin() {

	}
};
class Client : public User {
	void MainMenu() override {
		int m;

		std::cout << "\t| 1) Add items into the shopping cart    |" << std::endl;
		std::cout << "\t| 2) Remove items from the shoping cart  |" << std::endl;
		std::cout << "\t| 3) Exit                                |" << std::endl;
		std::cout << "\n\t\t\t Please enter yout choice : ";
		std::cin >> m;
		std::cout << std::endl;
		switch (m)
		{
		case 1:
			Add_item();
			break;
		case 2:
			Remove_item();
			break;
		case 3:
			exit(0);
			break;
		default:
			system("cls");
			std::cout << "\t\t\t Please select from the option given above \n" << std::endl;
			MainMenu();
		}


	}
	void Add_item() {

	}
	void Remove_item() {

	}
};