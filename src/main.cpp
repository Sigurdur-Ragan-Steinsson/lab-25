#include <iostream>

using namespace std;

struct Date {
 int year;
 int month;
 int day;
};

bool isleap(int year){
  
  if (year % 4 != 0){
    return false;
  }
  else {
    if (year % 100 != 0){
      return true;
    }
    else {
      if (year % 400 != 0){
        return false;
      }
      else{
        return true;
      }
    }
  }
}

int monthLength(int yearNum, int monthNum){
  int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30,31};
  if((monthNum > 13) || (monthNum < 1))
    return 0;
  else{
    if((isleap(yearNum)) && (monthNum == 2))
      return month[2] + 1;
    else
     return month[monthNum];
  };

};

int dayOfYear(Date date){
  int total = 0;
  for(int i = date.month - 1; i > 0; i--){
    total += monthLength(date.year, i);
  }
  total += date.day;
  return total;
};

int main(int argc, char **argv) {
	 Date d;
 cout << "Enter year month day: ";
 cin >> d.year >> d.month >> d.day;
 cout << dayOfYear(d) << endl;
 return 0;
}