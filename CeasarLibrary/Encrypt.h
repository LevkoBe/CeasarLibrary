#pragma once
#include <iostream>


#ifdef CEASARLIBRARY_EXPORTS
#define CEASARLIBRARY_API __declspec(dllexport)
#else
#define CEASARLIBRARY_API __declspec(dllimport)
#endif

extern "C" CEASARLIBRARY_API std::string encrypt(std::string rawText, int key);

extern "C" CEASARLIBRARY_API std::string decrypt(std::string rawText, int key);
