// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40478 C/C++ Programming IV
// HW 3

#include "StreamProcessor.h"
#include <vector>
#include <algorithm>
using namespace std;

// Constructor
StreamProcessorAlgorithm::StreamProcessorAlgorithm(istream &in, ostream &out)
    : in_(in), out_(out)
{

}

// Destuctor
StreamProcessorAlgorithm::~StreamProcessorAlgorithm()
{

}

// Process function implementation
void
StreamProcessorAlgorithm::process()
{
    string token;
    while (in_ >> token)
    {
        if (filterToken(token))
        {
            processToken(token);
            out_ << token << " ";
        }
    }
}

// filterToken that allows all tokens to pass through
bool
UppercasingSPA::filterToken(const string &token) const
{
    return true;
}

// change all characters to upper within each token
void
UppercasingSPA::processToken(string &token) const
{
    for (char &c : token)
    {
        c = toupper(c);
    }
}

// function that checks if the char is a digit
bool
DigitStrippingSPA::isDigit(char c)
{
    return isdigit(static_cast<unsigned char>(c));
}

// filterToken that contains at least one digit
bool
DigitStrippingSPA::filterToken(const string &token) const
{

    for (const char &c : token)
    {
        if (isDigit(c))
        {
            return true;
        }
    }
    return false; 
}

// strip all digits(0-9) within the token
void
DigitStrippingSPA::processToken(string &token) const
{
    token.erase(remove_if(token.begin(), token.end(), isDigit), token.end());
}
