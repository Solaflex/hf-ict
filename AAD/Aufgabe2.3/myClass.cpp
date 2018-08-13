#include <C:\git\RunProject\RunProject\myHeader.h>

using namespace std;

bool StringUtil::anagramCheck(string s1, string s2) {

	int ASCII[256] = { 0 },StringSize;

	// Make a fast check if both strings are the same length
	if (s1.size() == s2.size()) {
		StringSize = s1.length();
		// Go through the string
		for (int i = 0; i < StringSize; i++) {
			ASCII[s1[i]]++;
			ASCII[s2[i]]--;
		}
		
		// Go through the ASCII array and check if we find another number then 0
		// If yes, the strings are not Anagrams
		for (int i = 0; i < 256; i++) {
			if (ASCII[i] != 0) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}