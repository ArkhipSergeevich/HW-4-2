#include <iostream>
#include <string>
#include <fstream>

class addresses
{
public:
	void open_file_first(); //This function opens files, determines the number of addresses and deletes all data from the file out.txt
	void open_file();  // This is copy of "open_file_first" but without the numbers counter and deleter
	int one_address_input(int index_of_string);
	void one_address_output();
	addresses(std::string city_, std::string street_, int num_home_, int num_flat_);
	std::string city;
private:
	std::string street;
	int num_home = 0, num_flat = 0, size = 0;
	std::ifstream in_file;
	std::ofstream out_file;
	std::string mycop; // This is a class field used to skip some strings in the file
};
addresses::addresses(std::string city_, std::string street_, int num_home_, int num_flat_)
{
	city = city_;
	street = street_;
	num_home = num_home_;
	num_flat = num_flat_;
}

void addresses::open_file_first()
{
	in_file.open("in.txt");
	if (in_file.is_open())
	{
		in_file >> size;
		out_file.open("out.txt"); // I use the "usual" opening to delete all the data from the file
		out_file.close();
		out_file.open("out.txt", std::ios_base::app);  // I open the file again this way to be able write down addresses one at a time
		if (out_file.is_open())
		{
			out_file << "Number of addresses: " << size << std::endl;
		}
		else
		{
			std::cout << "file (out_file) is not open\n";
		}
	}
	else
	{
		std::cout << "file (in_file) is not open\n";
	}
}
void addresses::open_file()
{
	in_file.open("in.txt");
	if (in_file.is_open())
	{
		in_file >> size;
		out_file.open("out.txt", std::ios_base::app);
		if (out_file.is_open()) {}
		else
		{
			std::cout << "file (out_file) is not open\n";
		}
	}
	else
	{
		std::cout << "file (in_file) is not open\n";
	}
}
int addresses::one_address_input(int index_of_string)
{
	for (int i = 0; i < index_of_string; i++)
	{
		in_file >> mycop;  // Skipping previous addresses 
	}
	in_file >> city;
	in_file >> street;
	in_file >> num_home;
	in_file >> num_flat;
	return 0;
}
void addresses::one_address_output()
{
	out_file << city << " ";
	out_file << street << " ";
	out_file << num_home << " ";
	out_file << num_flat << "\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int index_of_string = 0; // This variable I use for set the number of strings to skip
	addresses address1("something", "something", 0, 0);
	addresses address2("something", "something", 0, 0);
	addresses address3("something", "something", 0, 0);
	address1.open_file_first();
	address1.one_address_input(index_of_string);
	index_of_string += 4;
	address2.open_file();
	address2.one_address_input(index_of_string);
	index_of_string += 4;
	address3.open_file();
	address3.one_address_input(index_of_string);
	if (address1.city < address2.city)
	{
		if (address1.city < address3.city)
		{
			address1.one_address_output();
			if (address2.city < address3.city)
			{
				address2.one_address_output();
				address3.one_address_output();
			}
			else
			{
				address3.one_address_output();
				address2.one_address_output();
			}
		}
		else
		{
			address3.one_address_output();
			address1.one_address_output();
			address2.one_address_output();
		}	
	}
	if (address1.city > address2.city)
	{
		if (address2.city < address3.city)
		{
			address2.one_address_output();
			if (address1.city < address3.city)
			{
				address1.one_address_output();
				address3.one_address_output();
			}
			else
			{
				address3.one_address_output();
				address1.one_address_output();
			}
		}
		else
		{
			address3.one_address_output();
			address2.one_address_output();
			address1.one_address_output();
		}
	}
}