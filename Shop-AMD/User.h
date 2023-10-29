#pragma once
#include<string.>


void delete_line(const char* file_name, int n)
{
	char c;
	int line_no = 1;

	std::ifstream is(file_name);
	std::ofstream ofs;
	ofs.open("temp.txt", std::ofstream::out);

	while (is.get(c))
	{
		if (c == '\n')
			line_no++;
		
		if (line_no != n)
			ofs << c;
	}
	
	ofs.close();
	is.close();
	remove(file_name);	
	rename("temp.txt", file_name);
}


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
			while (ain >> id ) 
			{
				if (id == userID ) {
					return 2;
				}
			}
			std::cout << userID << "\n Your Login is successfull \n Thanks for logging in! \n";
			return 1;
		}

		else 
		{
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
		bool good = true;

		while (fin >> rid >>rpass ) 
		{
			if (rid == ruserID) {
				good = false;
			}
		}
		
		if (good)
		{
			std::ofstream fout("records.txt", std::ios::app);
			fout << ruserID << " " << rpassword << std::endl;
			system("cls");
			std::cout << "\n\t\t\t Registration is successfull! \n";
		}

		else 
		{
			system("cls");
			std::cout << " You are already registered " << std::endl;
		}
		MainMenu();
	}

};

class Administrator : public User
{
	void MainMenu() override 
	{
		int a;

		std::cout << "\t| 1)Add items        |" << std::endl;
		std::cout << "\t| 2)Delete items     |" << std::endl;
		std::cout << "\t| 3)Add admin        |" << std::endl;
		std::cout << "\t| 4)Logout           |" << std::endl;
		std::cout << "\t| 5)Exit             |" << std::endl;
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
			system("cls");
			User::MainMenu();
			break;

		case 5:
			exit(0);
			break;

		default:
			system("cls");
			std::cout << "\t\t\t Please select from the option given above \n" << std::endl;
			MainMenu();
		}
	}

	void Add_items()
	{
		int i;
		Produs* p;
		int  cores,threads,TDP, nms, memory;
		float weight, height, price;

		std::string socket, frequency,resolution,tech,Name;
		std::cout << "\t| 1) CPU  |" << std::endl;
		std::cout << "\t| 2) APU  |" << std::endl;
		std::cout << "\t| 3) GPU  |" << std::endl;
		std::cout << "\t| 4) Back |" << std::endl;
		std::cout << "\t| 5) Exit |" << std::endl;
		std::cout << "\n\t\t\tPlease enter your choice : ";
		std::cin >> i;
		std::cout << std::endl;
		
		switch (i)
		{
		case 1:
			std::cout << "eu\n";
			
			std::cin >> weight >> height >> TDP >> nms 
				>> memory >> frequency >> cores >> threads
				>> socket >> price >> Name;
			
			p = new CPU(price, Name, cores, threads,
				socket, weight, height, TDP, nms, 
				memory, frequency);
			
			p->Pafisare();
			break;

		case 2:
			std::cin >> weight >> height >> TDP >> nms >> memory 
				>> frequency >> cores >> threads >> socket 
				>> resolution >> tech >> price >> Name;
			
			p = new APU(price, Name, weight, height, TDP, nms,
				memory, frequency, cores, threads, socket, 
				resolution, tech);
			
			p->Pafisare();
			break;

		case 3:
			std::cin >> weight >> height >> TDP >> nms >> 
				memory >> frequency >> resolution >> tech 
				>> price >> Name;
			
			p = new GPU(price, Name, resolution, tech, 
				weight, height, TDP, nms, memory, frequency);
			
			p->Pafisare();
			break;

		case 4:
			MainMenu();
			break;

		case 5:
			exit(0);
			break;
		}
	}

	void Delete_items() {
		int u,i=1,a;
		std::string tip;
		Produs* p;
		int  cores, threads, TDP, nms, memory;
		float weight, height;
		std::string socket, frequency, resolution, tech;

		std::cout << "\t| 1) CPU  |" << std::endl;
		std::cout << "\t| 2) APU  |" << std::endl;
		std::cout << "\t| 3) GPU  |" << std::endl;
		std::cout << "\t| 4) Back |" << std::endl;
		std::cout << "\t| 5) Exit |" << std::endl;
		std::cout << "\n\t\t\tPlease enter your choice : ";
		std::cout << std::endl;
		std::ifstream pin("Produse.txt");

		while (pin>>tip) 
		{
			if (tip == "CPU")
			{
				a = 1;
			}

			else if(tip=="APU")
			{
				a = 2;
			}

			else
			{
				a = 3;
			}

			switch (a) 
			{
			case 1:
				pin >> weight >> height >> TDP >> nms 
					>> memory >> frequency >> cores 
					>> threads >> socket;

				std::cout<<"(" << i << ") Product name : ";
				std::cout << std::endl;
				break;

			case 2:
				pin >> weight >> height >> TDP >> nms >> 
					memory >> frequency >> cores >> threads
					>> socket >> resolution >> tech;

				std::cout << "(" << i << ") Product name : ";
				std::cout << std::endl;
				break;

			case 3:
				pin >> weight >> height >> TDP >> nms >>
					memory >> frequency  >> resolution >> tech;

				std::cout << "(" << i << ") Product name : ";
				std::cout << std::endl;
				break;
			}
			i++;
		}
		std::cout << "Product delete : ";

		while (std::cin >> u)
		{
			if (u <= 0 || u > i) 
			{
				std::cout << "wrong number try again ";
			}

			else 
			{
				system("cls");
				delete_line("Produse.txt", u);
				std::cout << "Delete succesfull!\n";
			}
		}
		MainMenu();
	}

	void Add_admin() 
	{
		std::string auserID, rpassword, aid, rpass;

		system("cls");
		std::cout << "\t\t\t Enter the username : ";
		std::cin >> auserID;
		std::ifstream fin("records.txt");
		bool good = true;

		while (fin >> aid >> rpass) 
		{
			if (aid == auserID) 
			{
				good = false;
			}	
		}

		if (good)
		{
			std::ofstream fout("admin.txt", std::ios::app);
			fout << std::endl;
			fout << auserID << std::endl;
			system("cls");
			std::cout << "\n\t\t\t  successfull! \n";
		}

		else 
		{
			system("cls");
			std::cout << " This user is already an administrator!  " << std::endl;
		}
		MainMenu();
	}
};
class Client : public User 
{
	void MainMenu() override 
	{
		int m;

		std::cout << "\t| 1) Add items into the shopping cart    |" << std::endl;
		std::cout << "\t| 2) Remove items from the shoping cart  |" << std::endl;
		std::cout << "\t| 3) Logout                              |" << std::endl;
		std::cout << "\t| 4) Exit                                |" << std::endl;
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
			system("cls");
			User::MainMenu();
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

	void Add_item() 
	{
		int u, i = 1, a,s;
		std::string tip;
		Produs* p;
		int  cores, threads, TDP, nms, memory;
		float weight, height, price;
		std::string socket, frequency, resolution, tech, Name;
		
		std::cout << "Please select product" << std::endl;
		std::ifstream pin("Produse.txt");
		
		while (pin >> tip) 
		{
			if (tip == "CPU")
			{
				a = 1;
			}
			
			else if (tip == "APU")
			{
				a = 2;
			}
			
			else 
			{
				a = 3;
			}
			
			switch (a)
			{
			case 1:
				pin >> price >> Name >> weight >> height >> TDP 
					>> nms >> memory >> frequency >> cores >> threads
					>> socket;

				std::cout << "(" << i << ")" << Name << " " << price;
				std::cout << std::endl;
				break;

			case 2:
				pin >> price >> Name >> weight >> height >> TDP 
					>> nms >> memory >> frequency >> cores >> threads
					>> socket >> resolution >> tech;

				std::cout << "(" << i << ")" << Name << " " << price;
				std::cout << std::endl;
				break;

			case 3:
				pin >> price >> Name >> weight >> height >> TDP >> nms 
					>> memory >> frequency >> resolution >> tech;

				std::cout << "(" << i << ")" << Name << " " << price;
				std::cout << std::endl;
				break;
			}
			i++;
		}
		
		std::cout << "Product number : ";

		while (std::cin >> u)
		{
			if (u <= 0 || u > i)
			{
				std::cout << "wrong number try again ";
			}

			else 
			{
				system("cls");
				std::ofstream sout("ShopingCart.txt", std::ios::app);
				i = 1;
				bool ok = false;

				while (pin >> tip && !ok) 
				{
					if (tip == "CPU")
					{
						a = 1;
					}

					else if (tip == "APU") 
					{
						a = 2;
					}

					else 
					{
						a = 3;
					}

					switch (a) 
					{
					case 1:
						pin >> price >> Name >> weight >> height >> TDP 
							>> nms >> memory >> frequency >> cores >> 
							threads >> socket;
						
						if (i == u)
						{
							ok = true;
							sout << weight << " " << height << " " << TDP 
								<< " " << nms << " " << memory << " " 
								<< frequency << " " << cores << " " 
								<< threads << " " << socket<<std::endl;
						}
						break;

					case 2:
						pin >> price >> Name >> weight >> height 
							>> TDP >> nms >> memory >> frequency 
							>> cores >> threads >> socket >> resolution
							>> tech;
						
						if (i == u) 
						{
							ok = true;
							sout << weight << " " << height << " " 
								<< TDP << " " << nms << " " << memory 
								<< " " << frequency << " " << cores << " " 
								<< threads << " " << socket << std::endl;
						}
						break;

					case 3:
						pin >> price >> Name >> weight >> height 
							>> TDP >> nms >> memory >> frequency 
							>> resolution >> tech;
						
						if (i == u) 
						{
							ok = true;
							sout << weight << " " << height << " " 
								<< TDP << " " << nms << " " << memory
								<< " " << frequency << " " << cores << " " 
								<< threads << " " << socket << std::endl;
						}
						break;
					}
					i++;

					if (ok) 
					{
						std::cout << "Multumim pentru alegere!" << std::endl;
						break;
					}
				}
			}
		}
	}

	void Remove_item() 
	{
		int u, i = 1, a;
		std::string tip;
		Produs* p;
		int  cores, threads, TDP, nms, memory;
		float weight, height, price;
		std::string socket, frequency, resolution, tech, Name;
			
		std::cout << std::endl;
		std::ifstream sin("ShopingCart.txt");

		while (sin >> tip) 
		{
			if (tip == "CPU")
			{
				a = 1;
			}

			else if (tip == "APU") 
			{
				a = 2;
			}

			else 
			{
				a = 3;
			}

			switch (a) 
			{
			case 1:
				sin >>price >> Name >>weight >> height 
					>> TDP >> nms >> memory >> frequency
					>> cores >> threads >> socket;

				std::cout << "(" << i << ") Product name : ";
				std::cout << std::endl;
				break;

			case 2:
				sin >> price >> Name >> weight >> height 
					>> TDP >> nms >> memory >> frequency 
					>> cores >> threads >> socket >> resolution 
					>> tech;

				std::cout << "(" << i << ") Product name : ";
				std::cout << std::endl;
				break;

			case 3:
				sin >>  price >> Name >> weight >> height 
					>> TDP >> nms >> memory >> frequency 
					>> resolution >> tech;

				std::cout << "(" << i << ") Product name : ";
				std::cout << std::endl;
				break;
			}
			i++;
		}
		std::cout << "Product delete : ";

		while (std::cin >> u)
		{
			if (u <= 0 || u > i)
			{
				std::cout << "wrong number try again ";
			}

			else
			{
				system("cls");
				delete_line("ShopingCart.txt", u);
				std::cout << "Delete succesfull!\n";
			}
		}
		MainMenu();
	}	
};