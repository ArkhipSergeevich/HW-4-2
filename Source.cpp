#include <iostream>
#include <fstream>
#include <string>

class addresses
{
public:
	void set_city(std::string _city)
	{
		city = _city;
	}
	void set_street(std::string _street)
	{
		street = _street;
	}
	void set_num_home(int _num_home)
	{
		num_home = _num_home;
	}
	void set_num_flat(int _num_flat)
	{
		num_flat = _num_flat;
	}
	std::string get_city()
	{
		return city;
	}
	std::string get_street()
	{
		return street;
	}
	int get_num_home()
	{
		return num_home;
	}
	int get_num_flat()
	{
		return num_flat;
	}
private:
	std::string city, street;
	int num_home, num_flat, size;
};
int open_file()
{
	int size = 0;
	std::ifstream in_file;
	std::ofstream out_file;
	in_file.open("in.txt");
	if (in_file.is_open())
	{
		in_file >> size;
		out_file.open("out.txt");
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
	return size;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	std::ifstream in_file;
	std::ofstream out_file;
	in_file.open("in.txt");
	int size;
	size = open_file();
	addresses* addresses_array = new addresses[size];
	for (int i = 0; i < size; i++)
	{
		std::string address;
		int address_int;
		std::ifstream in_file;
		int size;
		in_file.open("in.txt");
		in_file >> size;
		for (int i = 0; i < size; i++)
		{
			in_file >> address;
			addresses_array[i].set_city(address);
			in_file >> address;
			addresses_array[i].set_street(address);
			in_file >> address_int;
			addresses_array[i].set_num_home(address_int);
			in_file >> address_int;
			addresses_array[i].set_num_flat(address_int);
		}
	}

		std::string storage;
		int counter = 100;
		while (counter != 0)
		{
			for (int i = 0; i < size - 1; i++)
			{
				int k = i + 1;
				if (addresses_array[i].get_city() >= addresses_array[k].get_city())
				{
					storage = addresses_array[i].get_city();
					addresses_array[i].get_city() = addresses_array[k].get_city();
					addresses_array[k].get_city() = storage;
				}
				else
				{
					counter--;
				}
			}
		}
		out_file.open("out.txt");
		for (int i = 0; i < size; i++)
		{
			out_file << addresses_array[i].get_city() << ", ";
			out_file << addresses_array[i].get_street() << ", ";
			out_file << addresses_array[i].get_num_home() << ", ";
			out_file << addresses_array[i].get_num_flat() << std::endl;
		}
	delete[] addresses_array;
}