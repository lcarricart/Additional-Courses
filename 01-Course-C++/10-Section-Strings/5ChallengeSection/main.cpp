#include <iostream>
#include <string>

using namespace std;

int main()
{
	string alphabet {"abcdefghijklmnopqrstuvwxyz:',.;()!?123 456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key_alphabet {"123hijklmnoa 456bcdefg789uvwxyzpqrstHIJKLMNOABCDEFGUVWXYZPQRST:',.;()!?"};
    //I could generate this key alphabet randomly each time the program executes to make it harder to break.
    string message;
    string message_encrypted;
    string message_decrypted;
    
    cout << "Enter your secret message: ";
    getline(cin, message); //It's interesting that cin.getline(message) no funciona acá, ni siquiera con las librerias. 
    cout << "\nEncrypting message..." << endl << endl;
    
    size_t position_alphabet {};
    char char_key {};
    
    for (size_t i{0} ; i < message.size() ; i++) {
        position_alphabet = alphabet.find(message.at(i));
        char_key = key_alphabet.at(position_alphabet);
        message_encrypted.push_back(char_key); 
    }
    
    cout << "Encrypted message: " << message_encrypted << endl << endl;
    cout << "Decrypting message..." << endl << endl;
    
    size_t position_key_alphabet {};
    char char_regular {};
    for (size_t i{0} ; i < message_encrypted.size() ; i++) {
        position_key_alphabet = key_alphabet.find(message_encrypted.at(i));
        char_regular = alphabet.at(position_key_alphabet);
        message_decrypted.push_back(char_regular);
    }
    
    cout << "Decrypted message: " << message_decrypted << endl << endl << endl;
    
    cout << "--------Alternate effective C++ solution-----------" << endl << endl;
    //This code will directly paste undefined characters that are not in our alphabets.
    string alfabeto {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"hijklmnoabcdefguvwxyzpqrstHIJKLMNOABCDEFGUVWXYZPQRST"};
    string secret_message;
    string encrypted_message;
    
    cout << "Enter your secret message: ";
    getline(cin, secret_message);
    
    cout << "\nEncrypting message..." << endl;
    
    for (char c: secret_message) {
        size_t position = alfabeto.find(c); //Same as I did.
        if (position != string::npos) {
            char new_char {key.at(position)};
            encrypted_message += new_char;
        }
        else {
            encrypted_message += c;
        }
    }
    
    cout << "\nEncrypted message: " << encrypted_message << endl << endl;
    
    /*The only difference compared with my method was the cleaniness of the code, all because of using C++ syntax.
    But mine is not less effective, they do exactly the same, so it's a well done job. Although, what's interesting
    is the way he concatenates the 'encrypted_message' variable using += on C++ strings. */
    
	return 0;
}
