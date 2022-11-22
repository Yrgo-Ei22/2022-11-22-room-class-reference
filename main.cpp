/********************************************************************************
* main.cpp: Implementering av dynamisk vektor för lagring av rumsdimensioner.
********************************************************************************/
#include "room.hpp"
#include "vector.hpp"

/********************************************************************************
* main: Lagrar dimensioner för tre rum i en vektor och skriver ut uppgifterna
*       i terminalen. Vektorklassens destruktor frigör minnet innan programmet
*       avslutas.
********************************************************************************/
int main(void)
{
   room r1(10, 5, 2.5);
   room r2(20, 10, 3);
   room r3(5, 5, 5);

   vector<room> v1;
   v1.push(r1);
   v1.push(r2);
   v1.push(r3);

   for (auto& i : v1)
   {
      i.print();
   }

   return 0;
}