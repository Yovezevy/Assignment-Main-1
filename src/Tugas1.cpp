#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

int yearsOld(tm* inputTgl, tm* currentTgl);
int monthsOld(tm* inputTgl, tm* currentTgl);
string dayOfDate(tm* inputTgl);

int main(int argc, char ** argv) 
{
    time_t currentTime;
    time(&currentTime);
    tm* currentTgl = localtime(&currentTime);

    int yearinput, monthinput, dayinput;
    string inputstr;
    char ch;
    
    cin >> inputstr;
    stringstream ss(inputstr);
    ss >> dayinput >> ch >> monthinput >> ch >> yearinput;

    tm* inputTgl = new tm();
    inputTgl->tm_year = yearinput-1900;
    inputTgl->tm_mon = monthinput-1;
    inputTgl->tm_mday = dayinput;

    int ageOfYear = yearsOld(inputTgl, currentTgl);
    int ageOfMonth = monthsOld(inputTgl, currentTgl);
    string dayName = dayOfDate(inputTgl);

    cout << ageOfYear << " " << ageOfMonth << " " << dayName << endl;

    return 0;
}

int yearsOld(tm* inputTgl, tm* currentTgl)
{
    int umur = currentTgl->tm_year - inputTgl->tm_year;
    
    if (currentTgl->tm_mon < inputTgl->tm_mon || 
       (currentTgl->tm_mon == inputTgl->tm_mon && currentTgl->tm_mday < inputTgl->tm_mday)) {
        umur--;
    }
    
    return umur;
}

int monthsOld(tm* inputTgl, tm* currentTgl)
{
    int totalBulan = (currentTgl->tm_year - inputTgl->tm_year) * 12 + (currentTgl->tm_mon - inputTgl->tm_mon);
    
    if (currentTgl->tm_mday < inputTgl->tm_mday) {
        totalBulan--;
    }
    
    return totalBulan;
}

string dayOfDate(tm* inputTgl)
{
    tm tempTgl = *inputTgl;
    mktime(&tempTgl);
    
    string namaHari[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    
    return namaHari[tempTgl.tm_wday];
}
