    #include<iostream>
    using namespace std;    
    
    bool numDigits(string word){
        return word.length() >= 3;
    }

    bool checkChar(char ch){
        return (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'));
    }

    bool isValid(string word){
        if (!numDigits(word)) {
            return false;
        }

        for (char s : word){
            if (!checkChar(s)){
                return false; // contains invalid character
            }
        }

        int countVowel = 0;
        int countConsonant = 0;

        for (char s : word){
            if (isdigit(s)) {
                continue; // ignore digits when counting vowel/consonant
            }

            // Convert to lowercase for easier comparison
            char ch = tolower(s);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                countVowel++;
            } else {
                countConsonant++;
            }
        }

        return (countVowel >= 1 && countConsonant >= 1);
    }