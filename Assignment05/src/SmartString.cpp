#include "SmartString.h"
#include <iostream>
using namespace std;

SmartString::SmartString()
{
    text=NULL; //By default text will be NULL.
    length=0; //length will be zero.
}

SmartString::~SmartString()
{
    delete[] text; //Delocating the memory.
}
int SmartString::CalculateTextLength(const char*addressOfFirst)
{
    int countt=0;
    char character=*(addressOfFirst); //de-referencing.
    while (character!='\0') //de-referencing every address of the array until '\0' is detected which shows that array is ended.
    {
        countt+=1;
        character=*(addressOfFirst+countt);
    }
    return countt;
}

void SmartString::CopyText(char* dest, const char* src)
{
    int countt=0;
    int length1;
    char character=*(src);
    length1=CalculateTextLength(src);
    char*destination=new char[length1]; //Making the new array of the same length as source to copy paste source's data into it.
    while (character!='\0')
    {
        destination[countt]=character;
        countt+=1;
        character=*(src+countt);

    }
    text=destination; //Updating text.
}

SmartString::SmartString(const SmartString& S)
{
    length=CalculateTextLength(S.text); //Updating length attribute of class with length of Object's text.
    CopyText(text,S.text); //To copy value of Object's text into class's attribute named text which is an array.
}

SmartString::SmartString(const char* src)
{
    length=CalculateTextLength(src); //Updating length attribute of class with length of input array.
    CopyText(text,src); //To copy value of Input array's text into class's attribute named text which is an array.
}

void SmartString::Join(const SmartString& S)
{
    int additionalLen; //Stores length of S.text.
    int finalLen; //Stored total length of text and S.text.
    additionalLen=CalculateTextLength(S.text); //Calculating length of Object's text.
    char* originalText=text; //Storing value of text in another array.
    finalLen=length+additionalLen;
    delete[] text; //Deleting text.
    text=NULL;
    char* finalArray;
    finalArray= new char[finalLen]; //Creating a new dynamic array.
    for (int i=0; i<finalLen; i++)
    {
        if (i<length)
        {
            finalArray[i]=originalText[i]; //First putting all elements of text array into final array.
        }
        else
        {
            finalArray[i]=S.text[i-length]; //Then putting all elements of Object's text array into final array.
        }
    }
    text=finalArray; //Updating text array.
}

void SmartString::Join(const char* newTextArray)
{
    int additionalLen;
    int finalLen;
    additionalLen=CalculateTextLength(newTextArray); //Calculating length of NewTextArray's text.
    char* originalText=text;
    finalLen=length+additionalLen;
    char* finalArray= new char[finalLen];
    for (int i=0; i<finalLen; i++)
    {
        if (i<length)
        {
            finalArray[i]=originalText[i]; //First putting all elements of text array into final array.
        }
        else
        {
            finalArray[i]=newTextArray[i-length]; //Then putting all elements of Input array's text array into final array.
        }
    }
    text=finalArray;
}

SmartString SmartString::operator+(const SmartString& Obj1)
{
    SmartString Obj2(text);
    Obj2.Join(Obj1); //Joining Object1's text to Object2's text.
    return Obj2;
}

SmartString SmartString::operator+(const char*Array)
{
    SmartString Obj2(text);
    Obj2.Join(Array); //Joining Array's text to Object2's text.
    return Obj2;
}

SmartString& SmartString::operator=(const SmartString&Obj1)
{
    delete text;
    length=CalculateTextLength(Obj1.text); //Updating length attribute with the length of Object1's length.
    char*text=new char[length];
    CopyText(text,Obj1.text); //Copying Object1's value to text.
    return *this; //Returing the reference of current Object.

}

SmartString& SmartString::operator=(const char*additionalTextArray)
{
    delete text;
    length=CalculateTextLength(additionalTextArray); //Updating length attribute with the length of Input Array's length.
    char*text=new char[length];
    CopyText(text,additionalTextArray); //Copying Input Array's value to text.
    return *this; //Returing the reference of current Object.

}

SmartString& SmartString::operator+=(const SmartString&Obj1)
{
    int additionalLen;
    int finalLen;
    additionalLen=CalculateTextLength(Obj1.text);
    char* originalText=text;

    finalLen=length+additionalLen;
    delete text;
    text=NULL;
    char* finalArray;
    finalArray= new char[finalLen];
    for (int i=0; i<finalLen; i++)
    {
        if (i<length)
        {
            finalArray[i]=originalText[i];
        }
        else
        {
            finalArray[i]=Obj1.text[i-length];
        }
    }
    text=finalArray;
    length=finalLen;
    return *this;
}

SmartString& SmartString::operator+=(const char*additionalArray)
{
    int additionalLen;
    int finalLen;
    additionalLen=CalculateTextLength(additionalArray);
    char* originalText=text;

    finalLen=length+additionalLen;
    delete text;
    text=NULL;
    char* finalArray;
    finalArray= new char[finalLen];
    for (int i=0; i<finalLen; i++)
    {
        if (i<length)
        {
            finalArray[i]=originalText[i];
        }
        else
        {
            finalArray[i]=additionalArray[i-length];
        }
    }
    text=finalArray;
    length=finalLen;
    return *this;
}

bool SmartString::operator==(const SmartString&Obj1)
{
    for (int i=0; i<length; i++) //Runs a loop on the length of the text.
    {
        if (Obj1.text[i]!=text[i]) //Compares i character of arrayI with i character of Object's text.
        {
            return false; //The moment some character doesn't match false is returned.
        }
    }
    return true; //If loop finishes and every character matched so return true.
}

bool SmartString::operator==(const char* arrayI)
{
    for (int i=0; i<length; i++) //Runs a loop on the length of the text.
    {
        if (arrayI[i]!=text[i]) //Compares i character of arrayI with i character of text.
        {
            return false; //The moment some character doesn't match false is returned.
        }
    }
    return true; //If loop finishes and every character matched so return true.
}

int SmartString::Length() //getter function for length attribute which is private.
{
    return length;
}

void SmartString::Show()
{
    cout<<"Length: "<<length<<endl;
    cout<<"Text: "<<text<<endl;
}
