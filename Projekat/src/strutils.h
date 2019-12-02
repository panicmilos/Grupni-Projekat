//============================================================================
// File Name	   : strutils.h
// Authors		   : Milos Panic
// Created         : 01.12.2019.
// Last Modified   : 01.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj moduo sadrzi sve dodatne funkcije nad stringovima.
//============================================================================

#pragma once
#include <string>

int find_last_char_in_string(std::string str, char c);
int count_words(std::string& str);