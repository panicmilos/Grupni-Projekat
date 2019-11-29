//============================================================================
// File Name   : Menu.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts here

#include "Menu.h"

Menu::Menu()
{
}

bool Menu::is_id_valid(string id) const { return true; }
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

void Menu::read_students() {
	// citanje studenata iz datoteke
}
void Menu::display_students() const
{
	// poziv metode iz gS
}
void Menu::display_students_sorted() const
{
	// poziv metode iz gS
}
void Menu::display_highest_score() const
{
	// poziv metode iz gS
}