#include <stdio.h>
#include <ctime>
#include <string>
#include <sstream>
#include <time.h>
#include <iostream>

#define ABOUT "v.0.1 | Created by DT.Cake"

#include <windows.h>
#include <shellapi.h>
using namespace std;
extern "C"
{
   //--- Engine called on extension load 
    __declspec (dllexport) void __stdcall RVExtensionVersion(char *output, int outputSize);
    //--- STRING callExtension STRING
    __declspec (dllexport) void __stdcall RVExtension(char *output, int outputSize, const char *function);
};

void RVExtension(char *output, int outputSize, const char *function)
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int year = now->tm_year + 1900;
    string y = to_string(year);
    int month = now->tm_mon + 1;
    string m = to_string(month);
    int day = now->tm_mday;
    string d = to_string(day);
    int hour = now->tm_hour;
    string h = to_string(hour);    
    int min = now->tm_min;
    string M = to_string(min);    
    int sec = now->tm_sec;
    string S = to_string(sec);
    int wday = now->tm_wday;
    string w = to_string(wday);
    int yday = now->tm_yday;
    string Y = to_string(yday);
    int isdst = now->tm_isdst;
    string dst = to_string(isdst);
    
    string s = "[";

    s += y + "," + m + "," + d  + "," + h  + "," + M + "," + S + "," + w + "," + Y + "," + dst;

    s += "]";

    strncpy(output, s.c_str(), outputSize);
};

void __stdcall RVExtensionVersion(char *output, int outputSize)
{
    strncpy_s(output, outputSize, ABOUT, _TRUNCATE);
};

void __stdcall RVExtensionArgs(char *output, int outputSize, const char *function, const char **args, int argsCnt)
{
   time_t curtime;
   struct tm* loctime;
   char buffer[80];
   time(&curtime);
   loctime = localtime(&curtime);
   strftime(buffer, 80, "%Y,%m,%d",loctime);
   string s = buffer;

   strncpy(output, s.c_str(), outputSize);
};


