#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>

int i = 1;					// LEPTETO AZ ARRAYBAN	
int idkeres;			// ARRAYBAN LEVO MODOSITASHOZ SZUKSEGES
int valtoztat;
bool kilepes = false;
int arr[250];
int test = 0;

std::ofstream file1("binary.bin", std::ios::in | std::ios::binary);
void ujadat(int *id, std::string *nev, int *kolcson)
{

	int bekero;					//  0 VAGY 1 ES KILEPO ES UJADAT FELVIVO				

	do {
		std::cout << "Szeretne uj adatot felvinni? 1 = IGEN  |  0 = NEM  : ";
		std::cin >> bekero;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Rossz karakter!";
			std::cin >> bekero;
		}

	} while (bekero > 1 || bekero < 0);
	if (bekero == 1)
	{

		std::cout << "Az azonosito : " << id[i] << std::endl;
		std::cout << " Kerem adja meg a nevet: ";
		std::cin.ignore();
		std::getline(std::cin, nev[i]);
		std::cout << " Kerem adja meg a kolcsonzott konyvek szamat! :";
		std::cin >> kolcson[i];
		while (1)
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Rossz karakter!";
				std::cout << " Kerem adja meg a kolcsonzott konyvek szamat! :";
				std::cin >> kolcson[i];
			}
			else
				break;
		}


		file1.open("binary.bin", std::ofstream::in | std::ofstream::out | std::ofstream::app);
		file1 << " ID : " << id[i] << "  ";
		file1 << "Nev: " << nev[i] << "  ";
		file1 << "Kolcsonzott konyvek: " << kolcson[i] << "\n";
		file1.close();


		i++;
		id[i] = i;

	}

}

std::ifstream& GotoLine(std::ifstream& file, unsigned int num)
{
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}






void kereses(int *id, std::string *nev, int *kolcson)
{


	do {
		std::cout << "Kerem adja meg a keresni kivant azonositot! ( 0 = KILEPES) : ";
		std::cin >> idkeres;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << " Rossz karakter! ";
			std::cout << "Kerem adja meg a keresni kivant azonositot! ( 0 = KILEPES) : ";
			std::cin >> idkeres;


		}
		if (idkeres == 0)
		{
			std::cout << " Kilepes...  \n";
			kilepes = true;
			break;
		}
	} while (idkeres < 1 || idkeres > 250);

	std::ifstream file1("binary.bin", std::ios::binary | std::ios::out);


	if (!kilepes)
	{
		for (int y = 0; y < i; ++y)
		{

			if (i < 2 || idkeres == 0 || idkeres >= i)
			{
				break;
			}

			if (id[y] = id[idkeres])
			{
				GotoLine(file1, idkeres);
				std::cout << "A keresett ertek: ";
				char c;
				do {
					(file1.get(c));
					if (c != '%')
						std::cout << c;
					else
					{
						std::cout << "Nem talahato!";
						kilepes = true;
						break;

					}



				} while (c != '\n');
				std::cout << "\n";


				file1.seekg(0, file1.end);
				int length = file1.tellg();
				file1.seekg(0, file1.beg);
				std::cout << " Osszes Karakterek szama: " << length << std::endl;
				file1.close();
				break;
			}
			else
				std::cout << "Nem talalhato!";
		}

	}

}

void adatmodositas(int *id, std::string *nev, int *kolcson)
{


	do {

		std::cout << "Kerem adja meg a megvaltoztatni  kivant rekord azonositojat! :  (KILEPES = 0) ";
		std::cin >> idkeres;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << " Rossz karakter! ";
			std::cout << "Kerem adja meg a megvaltoztatni  kivant rekord azonositojat! :  (KILEPES = 0) ";
			std::cin >> idkeres;
		}
		if (idkeres >= i || idkeres == 0)
		{
			std::cout << "Nincs eleg adat! \\ Kilepes... ";
			kilepes = true;
			break;
		}
	} while (idkeres < 1 || idkeres > 250);



	for (int i = 0; i < idkeres; ++i)
	{
		if (!kilepes)
		{
			if (id[i] = id[idkeres])
			{

				std::ifstream file1("binary.bin", std::ios::binary | std::ios::out);
				GotoLine(file1, idkeres);
				std::cout << "A keresett ertek: ";
				char c;
				do {
					(file1.get(c));
					if (c != '%')
						std::cout << c;
					else
					{
						std::cout << "Nem talahato!";
						kilepes = true;
						break;
					}



				} while (c != '\n');
				std::cout << "\n";
				file1.seekg(0, std::ios::beg);
				file1.close();

				if (!kilepes)
				{
					std::cout << "MEGTALALVA!" << std::endl;
					std::cout << "Azonosito : " << id[idkeres] << " Nev: " << nev[idkeres] << " Kolcsonzott konyvek szama : " << kolcson[idkeres] << std::endl;
					std::cout << " Meg szeretne valtoztatni az " << id[idkeres] << " azonositoju rekordot?  1 = IGEN	0 = NEM : ";
					std::cin >> valtoztat;
					if (valtoztat == 0)
					{
						std::cout << "Kilepes... \n";
						kilepes = true;
						break;
					}
					if (valtoztat == 1)
					{
						std::cout << " Az azonosito nem valtoztathato! " << std::endl;
						std::cout << " Az uj nev: ";
						std::cin.ignore();
						std::getline(std::cin, nev[idkeres]);
						std::cout << " A kolcsonzott konyvek szama: ";
						std::cin >> kolcson[idkeres];
						break;
					}
				}
				else
				{
					break;
				}
			}
		}

	}

}




void fajltorles(int *id, std::string *nev, int *kolcson)  //Kitörli a fájlban lévõ elemeket.
{
	if (!kilepes)
	{
		remove("binary.bin");
		std::ofstream file1("binary.bin", std::ios::in | std::ios::out | std::ios::binary);
		file1.open("binary.bin", std::ios::in | std::ios::out | std::ios::binary | std::ios::app);
		for (int x = 1; x < i; ++x)
		{
			if (arr[x] == x)
			{
				file1 << "%" << " ID : " << id[x] << "  ";
				file1 << "Nev: " << nev[x] << "  ";
				file1 << "Kolcsonzott konyvek: " << kolcson[x] << "          \n\0";
			}
			else
			{
				file1 << " ID : " << id[x] << "  ";
				file1 << "Nev: " << nev[x] << "  ";
				file1 << "Kolcsonzott konyvek: " << kolcson[x] << "          \n\0";
			}
			std::cout << std::endl;
			std::cout << "ARR:" << arr[x] << " : ";
			std::cout << " X :" << x;


		}
		std::cout << " ARRAY tartalma: \n";
		for (int i = 0; i < 30; ++i)
		{
			std::cout << i << ".elem : " << arr[i] << std::endl;
		}
		file1.close();
	}





}


void fajlundo(int *id, std::string *nev, int *kolcson)  //Visszavonja a törölt elemeket a fájlban.
{
	if (!kilepes)
	{
		remove("binary.bin");
		std::ofstream file1("binary.bin", std::ios::in | std::ios::out | std::ios::binary);
		file1.open("binary.bin", std::ios::in | std::ios::out | std::ios::binary | std::ios::app);
		for (int x = 1; x < i; ++x)
		{
			if (arr[x] == x)
			{
				file1 << " ID : " << id[x] << "  ";
				file1 << "Nev: " << nev[x] << "  ";
				file1 << "Kolcsonzott konyvek: " << kolcson[x] << "          \n\0";
			}
			else
			{
				file1 << " ID : " << id[x] << "  ";
				file1 << "Nev: " << nev[x] << "  ";
				file1 << "Kolcsonzott konyvek: " << kolcson[x] << "          \n\0";
			}
		}
	}
}


void torles(int *id, std::string *nev, int *kolcson)
{

	do {
		std::cout << "Kerem adja meg a keresni kivant azonositot! ( 0 = KILEPES) : ";
		std::cin >> idkeres;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << " Rossz karakter! ";
			std::cout << "Kerem adja meg a keresni kivant azonositot! ( 0 = KILEPES) : ";
			std::cin >> idkeres;

		}
		if (idkeres == 0 || idkeres >= i)
		{
			std::cout << "  Rossz adat \\  Kilepes...  \n";
			kilepes = true;
			break;
		}
	} while (idkeres < 1 || idkeres > 250);

	std::ifstream file1("binary.bin", std::ios::binary | std::ios::out);


	if (!kilepes)
	{
		for (int y = 0; y < i; ++y)
		{


			if (id[y] = id[idkeres])
			{
				GotoLine(file1, idkeres);
				std::cout << "A keresett ertek: ";
				char c;
				do {
					(file1.get(c));
					std::cout << c;



				} while (c != '\n');
				std::cout << "\n";
				file1.close();
				std::cout << "Biztosan torolni szeretne a rekorodot? 1 = IGEN	0 = NEM" << std::endl;
				std::cin >> valtoztat;

				if (valtoztat != 1)
				{
					kilepes = true;
					break;
				}
				else
				{
					test = idkeres;
					arr[test] = idkeres;
					break;
				}



			}
			else
				std::cout << "Nem talalhato!";
		}


	}
}

void listazas(int *id, std::string *nev, int *kolcson)
{
	std::ifstream file1("binary.bin", std::ios::binary | std::ios::out);

	file1.seekg(0, std::ios::beg);
	std::cout << " Listazas: " << std::endl;
	char c;
	std::cout << "  ID         Nev       Kolcsonzott Konyvek \n";
	std::cout << "---------------------------------------------------\n";
	do
	{
		(file1.get(c));
		if (c != '%')
			std::cout << c;
		else
		{
			file1.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

	} while (!file1.eof());


}

void remove()
{
	file1.close();
	if (!std::remove("binary.bin"))
		std::cout << "Elozo fajl torlese kesz!\n";


}



int main()
{
	remove();
	int id[250];
	std::string nev[250];
	int  kolcson[250];
	memset(id, 0, 250);
	memset(arr, 0, 250);
	id[1] = 1;
	int bekeres;
	do {
		std::cout << " \n Parancsok: 1 = Bekeres | 2 = Kereses | 3 =  Adatmodositas | 4 = Torles | 5 = Listazas | 0 = Kilepes" << std::endl;
		std::cout << " Parancs sorszam : ";
		std::cin >> bekeres;
		while (1)
		{
			if (std::cin.fail() || bekeres > 6 || bekeres < 0)
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Rossz karakter!" << std::endl;
				std::cin >> bekeres;
			}
			if (!std::cin.fail())
				break;
		}
		switch (bekeres)
		{
		case 1:
		{
			ujadat(id, nev, kolcson);
			break;
		}
		case 2:
		{
			kereses(id, nev, kolcson);
			kilepes = false;
			break;

		}
		case 3:
		{

			adatmodositas(id, nev, kolcson);
			if (!kilepes)
				fajltorles(id, nev, kolcson);
			kilepes = false;
			break;


		}
		case 4:
		{
			torles(id, nev, kolcson);
			if (!kilepes)
				fajltorles(id, nev, kolcson);
			kilepes = false;
			break;



		}
		case 5:
		{
			listazas(id, nev, kolcson);
			kilepes = false;
			break;
		}
		case 0:
		{
			unsigned int x;
			do {
				std::cout << " Biztosan ki szeretne lepni?( 1 = IGEN  0 = NEM) " << std::endl;
				std::cin >> x;

				while (1)
				{
					if (std::cin.fail() || x > 1 || x < 0)
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << " Rossz karakter!  " << std::endl;
						std::cin >> x;
					}
					else
						break;


				}
				if (x == 1)
				{
					std::cout << "Vissza szeretne vonni a kitorolt elemeket? ( 1 = Visszavonas | 0 =  Torolve hagyas) \n ";
					std::cin >> valtoztat;
					while (1)
					{
						if (std::cin.fail() || x > 1 || x < 0)
						{
							std::cin.clear();
							std::cin.ignore(32767, '\n');
							std::cout << " Rossz karakter!  " << std::endl;
							std::cin >> valtoztat;
						}
						else
							break;
						if (valtoztat == 1)
						{
							fajlundo(id, nev, kolcson);
							system("pause");
							return 0;
						}
						else
							continue;
					}
				}

			} while (x > 1 || x < 0);

		}

		return 0;
		}

	} while (1);
}