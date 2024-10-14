// Encrypt and Decrypt Text
# include <iostream>

using namespace std;

string ReadWord()
{
    cout << "Please enter a word: ";
    string word;
    getline(cin, word);
    return word;
}

string Encrypt(string word, short EncryptionKey)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = word[i] + EncryptionKey;
    }
    return word;
}

string Decrypt(string word, short EncryptionKey)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = word[i] - EncryptionKey;
    }
    return word;
}

int main()
{
    const short EncryptionKey = 2;
    string word = ReadWord();
    string wordAfterEncryption = Encrypt(word, EncryptionKey);
    string wordAfterDecryption = Decrypt(wordAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption: " << word;
    cout << "\nText After Encryption: " << wordAfterEncryption;
    cout << "\nText After Decryption: " << wordAfterDecryption;
}