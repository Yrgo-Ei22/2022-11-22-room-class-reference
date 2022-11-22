/********************************************************************************
* room.hpp: Inneh�ller funktionalitet f�r lagring, ber�kning samt utskrift
*           av parametrar f�r rum via strukten room.
********************************************************************************/
#ifndef ROOM_HPP_
#define ROOM_HPP_

/* Inkluderingsdirektiv: */
#include <iostream> /* Inneh�ller funktionalitet f�r inmatning och utskrift. */

/********************************************************************************
* room: Strukt f�r lagring, ber�kning samt utskrift av parametrar f�r rum.
********************************************************************************/
struct room
{
   double length = 0; /* Rummets l�ngd i meter. */
   double width = 0;  /* Rummets bredd i meter. */
   double height = 0; /* Rummets h�jd i meter. */

   /********************************************************************************
   * room: Initierar nytt room-objekt med angivna parametrar.
   *
   *       - length: Rummets l�ngd i meter.
   *       - width : Rummets bredd i meter.
   *       - height: Rummets h�jd i meter.
   ********************************************************************************/
   room(const double length,
      const double width,
      const double height)
   {
      this->length = length;
      this->width = width;
      this->height = height;
      return;
   }

   /********************************************************************************
   * clear: Nollst�ller parametrar f�r angivet rum.
   ********************************************************************************/
   void clear(void)
   {
      this->length = 0;
      this->width = 0;
      this->height = 0;
      return;
   }

   /********************************************************************************
   * get_area: Returnerar arean f�r angivet rum i kvadratmeter.
   ********************************************************************************/
   double get_area(void) const
   {
      return this->length * this->width;
   }

   /********************************************************************************
   * get_volume: Returnerar volymen f�r angivet rum i kubikmeter.
   ********************************************************************************/
   double get_volume(void) const
   {
      return this->length * this->width * this->height;
   }

   /********************************************************************************
   * print: Skriver ut l�ngd, bredd, h�jd, area samt volym f�r angivet rum via
   *        angiven utstr�m, d�r standardutenhet std::cout anv�nds som default
   *        f�r utskrift i terminalen.
   *
   *        - ostream: Referens till angiven utstr�m (default = std::cout).
   ********************************************************************************/
   void print(std::ostream& ostream = std::cout) const
   {
      ostream << "-----------------------------------------------------------------------------\n";

      ostream << "Length: " << this->length << " m\n";
      ostream << "Width: " << this->width << " m\n";
      ostream << "Height: " << this->height << " m\n";

      ostream << "Area: " << this->get_area() << " m^2\n";
      ostream << "Volume: " << this->get_volume() << " m^3\n";

      ostream << "-----------------------------------------------------------------------------\n\n";
      return;
   }
};

#endif /* ROOM_HPP_ */
