//============================================================================
// File Name	   : Menu.cpp
// Authors		   : Milos Panic
// Created         : 01.12.2019.
// Last Modified   : 02.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj moduo sadrzi sve dodatne funkcije menija koji omogucava
// interakciju sa korisnikom kao i dva korisnicka izuzetka za pogresno ime datoteke
// i pogresan sadrzaj.
//============================================================================

#include "Menu.h"

Menu::Menu()
{
}

/*
 * Funkcija koja ispisuje stavke menija na standardnom izlazu.
*/
void Menu::display_menu() const
{
	std::cout << "1. Prikazi osnovne informacije o autorima\n"
		<< "2. Ucitaj studente iz datoteke\n"
		<< "3. Prikazi informacije o studentu\n"
		<< "4. Prikazi studente sa najboljim prosekom\n"
		<< "5. Sortiraj\n"
		<< "6. Prikazi informacije o svim studentima\n"
		<< "7. Upisi studente u izlaznu datoteku\n"
		<< "8. Izlaz iz programa\n";
}

/*
 * Funkcija koja ispisuje informacije o autorima na standardnom izlazu.
*/
void Menu::display_info() const
{
	std::cout << "Autori ovog projekta su: \n"
		<< "Dejan Todorovic (sw17-2018)\n"
		<< "Milos Panic (sw19-2018)\n";
}

/*
 * Funkcija koja ucitava studente sa textualne ulazne putanje i stavlja ih u
 * promenjivu gs.
 *
 * @param input_path - ulazna putanja na kojoj se otvara ulazni tok.
 * @throws InvalidFile - u slucaju da na ulaznoj putanji ne postoji
 * datoteka iz koje se moze citati.
 * @throws InvalidData - u slucaju da se u datoteci iz koje se cita
 * nalazi los sadrzaj.
*/
void Menu::read_students_from_txt(const std::string& input_path)
{
	std::ifstream in(input_path);

	if (!in.is_open())
	{
		throw InvalidFile();
	}

	in >> gs;

	if (in.fail() || gs.check_for_duplicates())
	{
		throw InvalidData();
	}

	in.close();
}

/*
 * Funkcija koja ucitava studente sa binarne ulazne putanje i stavlja ih u
 * promenjivu gs.
 *
 * @param input_path - ulazna putanja na kojoj se otvara ulazni tok.
 * @throws InvalidFile - u slucaju da na ulaznoj putanji ne postoji
 * datoteka iz koje se moze citati.
 * @throws InvalidData - u slucaju da se u datoteci iz koje se cita
 * nalazi los sadrzaj.
*/
void Menu::read_students_from_binary(const std::string& input_path)
{
	std::ifstream in(input_path, std::ios::binary);

	if (!in.is_open())
	{
		throw InvalidFile();
	}

	gs.read_from_binary_file(in);

	if (in.fail() || gs.check_for_duplicates())
	{
		throw InvalidData();
	}

	in.close();
}

/*
 * Funkcija koja poziva ucitavanje studenata sa binarne ili textualne
 * ulazne datoteke u zavisnosti sadrzaja promenjive type. Ucitane
 * studente stavlja u gs.
 *
 * @param input_path - ulazna putanja na kojoj se otvara ulazni tok.
 * @param type - tip ulazne datoteke, "t" za textualne i "b" za binarne.
 * @throws InvalidFile - u slucaju da na ulaznoj putanji ne postoji
 * datoteka iz koje se moze citati.
 * @throws InvalidData - u slucaju da se u datoteci iz koje se cita
 * nalazi los sadrzaj.
 * @exception - svi ostali izuzeci koji mogu nastati usred rada sa
 * binarnim datotekama.
*/
void Menu::read_students(const std::string& input_path, const std::string& type)
{
	try
	{
		if (type == "t")
		{
			read_students_from_txt(input_path);
		}
		else
		{
			read_students_from_binary(input_path);
		}
	}
	catch (const Menu::InvalidFile & excp)
	{
		throw excp;
	}
	catch (const Menu::InvalidData & excp)
	{
		throw excp;
	}
	catch (const std::exception & e)
	{
		throw e;
	}
}

/*
 * Funkcija koja zahteva od korisnika da unese broj indexa studenta a zatim
 * ispisuje informacije o tom studentu ili poruku u slucaju da nema studenta
 * sa zadatim indexom.
*/
void Menu::display_student() const
{
	std::string id;

	std::cout << "Unesite indeks: ";
	std::cin >> id;

	gs.display_one_student(id);
}

/*
 * Funkcija koja ispisuje sve studente na standardni izlaz u nesortiranom poretku.
*/
void Menu::display_students() const
{
	gs.display();
}

/*
 * Funkcija koja ispisuje sve studente na standardni izlaz u sortiranom poretku.
 * Sortira se prvo po prezimena, pa imenu i na kraju broju indexa.
*/
void Menu::display_students_sorted() const
{
	gs.display_sorted();
}

/*
 * Funkcija koja ispisuje n studenata sa najboljim prosekom.
*/
void Menu::display_highest_score() const
{
	gs.display_highest();
}

/*
 * Funkcija koja ispisuje sve studente na izlaznu putanju. U slucaju da je tip binaran
 * upis se vrsi i u binarnu i u textualnu datoteku.
 *
 * @param output_path - izlazna putanja na kojoj se otvara izlazni tok.
 * @param type - tip ulazne datoteke, "t" za textualne i "b" za binarne.
 */
void Menu::write_students(const std::string& output_path, const std::string& type)
{
	if (type == "b")
	{
		write_students_to_binary_file(output_path);
	}

	std::ofstream out(output_path + ".txt");

	gs.write_to_file(out);

	out.close();
}

/*
 * Funckija koja ispisuje sve studente u binarnu datoteku na zadatoj putanji.
 *
 * @param output_path - izlazna putanja na kojoj se otvara izlazni tok.
*/
void Menu::write_students_to_binary_file(const std::string& output_path)
{
	std::ofstream out(output_path + ".bin", std::ios::binary | std::ios::out);

	gs.write_to_binary_file(out);

	out.close();
}