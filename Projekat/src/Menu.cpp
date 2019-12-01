//============================================================================
// File Name   : Menu.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Menu.h"

Menu::Menu()
{
}

bool Menu::is_id_valid(std::string id) const { return true; }

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

void Menu::display_info() const
{
	std::cout << "Autori ovog projekta su: \n"
		<< "Dejan Todorovic (sw17-2018)\n"
		<< "Milos Panic (sw19-2018)\n";
}

void Menu::read_students(std::string input_path)
{
	//napravi se file sa imenom in;
	// in >> gs;
	// provera gresaka i to.
}

void Menu::display_students() const
{
	gs.display();
}

void Menu::display_students_sorted() const
{
	gs.display_sorted();
}

void Menu::display_highest_score() const
{
	gs.display_highest();
}