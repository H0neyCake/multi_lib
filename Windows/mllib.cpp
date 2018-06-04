#include <stdio.h>
#include <ctime>
#include <string>
#include <sstream>
#include <time.h>
#include <fstream>
#include <windows.h>

#define VERSION "v.0.1 | Created by DT.Cake"

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
    std::string str = function;

   if (!strncmp(function, "time", 2))
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
  }
  else if (!strncmp(function, "logger", 2)) 
  {
    //Output it as the .dll result to arma 3
  strncpy_s(output, outputSize, "Log created!", _TRUNCATE);

  //Get current Server Time for loggin
  time_t currentTime;
  struct tm *localTime;

  time(&currentTime);                   // Get the current time
  localTime = localtime(&currentTime);  // Convert the current time to the local time

  //Convert them to strings
  string Day = to_string(localTime->tm_mday);
  string Month = to_string(localTime->tm_mon + 1);
  string Year = to_string(localTime->tm_year + 1900);
  string Hour = to_string(localTime->tm_hour);
  string Min = to_string(localTime->tm_min);
  string Sec = to_string(localTime->tm_sec);

  //Create Dir for Logging
  CreateDirectoryA("A3Logs", NULL);

  //define the path and filename and log it.
  string logname = string("A3Logs/") + Day + "-" + Month + "-" + Year + ".txt";
  std::ofstream log(logname, std::ios_base::app | std::ios_base::out);
  log << Day << "-" << Month << "-" << Year << " - " << Hour << ":" << Min << ":" << Sec << " :: " << function << "\n";
  }
  else if (!strncmp(function, "about", 2)) 
  {
    strncpy_s(output, outputSize, "Created by Cake from Dismal Team", outputSize - 1);
  }
  else
  {
    strncpy_s(output, outputSize, "Avaliable Functions: time, logger, about", outputSize - 1);
    
  }
};

void __stdcall RVExtensionVersion(char *output, int outputSize)
{
    strncpy_s(output, outputSize, VERSION, _TRUNCATE);
};