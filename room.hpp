/********************************************************************************
* room.hpp: Innehåller funktionalitet för lagring, beräkning samt utskrift
*           av parametrar för rum via strukten room.
********************************************************************************/
#ifndef ROOM_HPP_
#define ROOM_HPP_

/* Inkluderingsdirektiv: */
#include <iostream> /* Innehåller funktionalitet för inmatning och utskrift. */

/********************************************************************************
* room: Strukt för lagring, beräkning samt utskrift av parametrar för rum.
********************************************************************************/
struct room
{
   double length = 0; /* Rummets längd i meter. */
   double width = 0;  /* Rummets bredd i meter. */
   double height = 0; /* Rummets höjd i meter. */

   /********************************************************************************
   * room: Initierar nytt room-objekt med angivna parametrar.
   *
   *       - length: Rummets längd i meter.
   *       - width : Rummets bredd i meter.
   *       - height: Rummets höjd i meter.
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
   * clear: Nollställer parametrar för angivet rum.
   ********************************************************************************/
   void clear(void)
   {
      this->length = 0;
      this->width = 0;
      this->height = 0;
      return;
   }

   /********************************************************************************
   * get_area: Returnerar arean för angivet rum i kvadratmeter.
   ********************************************************************************/
   double get_area(void) const
   {
      return this->length * this->width;
   }

   /********************************************************************************
   * get_volume: Returnerar volymen för angivet rum i kubikmeter.
   ********************************************************************************/
   double get_volume(void) const
   {
      return this->length * this->width * this->height;
   }

   /********************************************************************************
   * print: Skriver ut längd, bredd, höjd, area samt volym för angivet rum via
   *        angiven utström, där standardutenhet std::cout används som default
   *        för utskrift i terminalen.
   *
   *        - ostream: Referens till angiven utström (default = std::cout).
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
