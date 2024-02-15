// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40478 C/C++ Programming IV
// HW 3

#ifndef STREAMPROCESSOR_H
#define STREAMPROCESSOR_H

#include <iostream>
#include <string>
using namespace std;


class StreamProcessorAlgorithm
{
public:
    StreamProcessorAlgorithm(istream &in, ostream &out);
    virtual ~StreamProcessorAlgorithm();
    void process();
private:
    virtual bool filterToken(const string &token) const = 0;
    virtual void processToken(string &token) const = 0;
    istream &in_;
    ostream &out_;
};

class UppercasingSPA : public StreamProcessorAlgorithm
{
public:
    UppercasingSPA(istream &in, ostream &out) : 
        StreamProcessorAlgorithm(in, out) {}
    virtual bool filterToken(const string &token) const;
    virtual void processToken(string &token) const;
};

class DigitStrippingSPA : public StreamProcessorAlgorithm
{
public:
    DigitStrippingSPA(istream &in, ostream &out) : 
        StreamProcessorAlgorithm(in, out) {}
    static bool isDigit(char c);
    virtual bool filterToken(const string &token) const;
    virtual void processToken(string &token) const;
};
#endif
