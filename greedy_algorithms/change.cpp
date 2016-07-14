#include <iostream>
using namespace std;

int get_change(int n) {
   int numcoins = 0;
   int totalcnt = 0;
   int remain = n;
   
    while( totalcnt != n)
    {
        if ( remain >= 10) 
        { 
	   totalcnt += 10;
	   numcoins++;	
	   remain -= 10;
	   continue;
 	 }

	if ( remain >= 5)
	{
		totalcnt += 5;
		remain -= 5;
		numcoins++;
		continue;
	}
	
	if ( remain >= 1)
	{
		totalcnt += 1;	
		remain -= 1;
		numcoins++;
		continue;
        }
   
    }
  return numcoins;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
