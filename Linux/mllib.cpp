#include <stdio.h>
#include <ctime>
#include <string>
#include <сstring>
#include <sstream>
#include <time.h>
#include <fstream>
#include <algorithm>

#define VERSION "v.0.1 | Created by DT.Cake"

using namespace std;
extern "C"
{
__attribute__((dllexport)) void RVExtension(char *dest, int num, const char *fnc);
__attribute__((dllexport)) int RVExtensionArgs(char *dest, int num, const char *fnc, const char **argv, int argc);
__attribute__((dllexport)) void RVExtensionVersion(char *dest, int num);
};

void RVExtension(char *dest, int num, const char *fnc)
{
    std::string str = fnc;

   if (!strncmp(fnc, "time", 2))
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

    std::strncpy(dest, s.c_str(), num - 1);
  } 
  else if (!strncmp(fnc, "about", 2)) 
  {
    std::strncpy_s(output, num, "Created by Cake from Dismal Team", num - 1);
  }
  else
  {
    std::strncpy_s(dest, num, "Avaliable Functions: time, logger, about", num - 1);    
  }
};
int RVExtensionArgs(char *dest, int num, const char *fnc, const char **argv, int argc)
{
  if (!strncmp(fnc, "logger", 2))
  {
    std::string logentry = argv[0];
    std::string ln = argv[1];
    std::string dir = argv[2];
    //Output it as the .dll result to arma 3
  std::strncpy_s(dest, num, "Log created!", num - 1);

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
  // std::string dir = "D:\\A3Logs";
  // CreateDirectoryA(dir, NULL);
  
  //define the path and filename and log it.
  string logname = dir + "/" + ln + ".txt";
  logname.erase(remove( logname.begin(), logname.end(), '\"' ),logname.end());

  std::ofstream log(logname, std::ios_base::app | std::ios_base::out);
  log << Day << "-" << Month << "-" << Year << " - " << Hour << ":" << Min << ":" << Sec << " :: " << logentry << "\n";
}
  return 0;
};
void RVExtensionVersion(char *dest, int num)
{
    std::strncpy_s(dest, VERSION, num - 1);
};