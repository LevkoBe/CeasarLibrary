#include "pch.h"
#include <utility>
#include <limits.h>
#include "Encrypt.h"
#include <iostream>
#include <windows.h>
#include <cctype>
#include <string>




std::string encrypt(std::string rawText, int key) {
	for (int i = 0; i < rawText.length(); i++) {
		char character = rawText[i];
		rawText[i] = static_cast<char>((character + key) % 128);
	}
	return rawText;
}

std::string decrypt(std::string rawText, int key) {
    std::string result = "";
    int originalLength = rawText.length() / 2;
    for (int i = 0; i < originalLength; i += 2) {
        std::string number = rawText.substr(i, 2);
        int character = std::stoi(number, nullptr, 16);
        result += static_cast<char>((128 + character - key) % 128);
    }
    return result;
}