/********************************************************************************
* vector.hpp: Implementering av dynamiska vektorer via klassen vec.
********************************************************************************/
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>
#include <cstdlib>

/********************************************************************************
* vector: Generisk klass f�r implementering av dynamiska arrayer (vektorer) 
*         av godtycklig datatyp.
********************************************************************************/
template<class T>
class vector
{
private:
   T* data_ = nullptr;    /* Pekare till ett dynamiskt f�lt inneh�llande lagrad data. */
   std::size_t size_ = 0; /* Vektorns storlek, dvs. antalet lagrade element. */
public:

   /*****************************************************************************
   * vector: Tom konstruktor, initierar en ny tom vektor.
   *****************************************************************************/
   vector(void) { }

   /*****************************************************************************
   * vector: Konstruktor, initierar ny vektor av angiven storlek med angivet
   *         startv�rde.
   *
   *         - start_size: Vektorns nya storlek (antalet element).
   *         - start_val : Referens till startv�rde f�r alla element (default = 0).
   *****************************************************************************/
   vector(const std::size_t start_size,
          const T& start_val = static_cast<T>(0))
   {
      this->resize(start_size, start_val);
      return;
   }

   /*****************************************************************************
   * ~vector: Destruktor, frig�r minne allokerat f�r vektorn innan objekt raderas.
   *****************************************************************************/
   ~vector(void)
   {
      this->clear();
      return;
   }

   /*****************************************************************************
   * data: Returnerar en pekare till inneh�llet lagrat i angiven array.
   *****************************************************************************/
   T* data(void) const
   {
      return this->data_;
   }

   /*****************************************************************************
   * size: Returnerar storleken (antalet element) i angiven vektor.
   *****************************************************************************/
   std::size_t size(void) const
   {
      return this->size_;
   }

   /*****************************************************************************
   * begin: Returnerar adressen till det f�rsta elementet i angiven vektor.
   *        Om vektorn �r tom returneras en nullpekare.
   *****************************************************************************/
   T* begin(void) const
   {
      return this->data_;
   }

   /*****************************************************************************
   * end: Returnerar adressen direkt efter det sista elementet i angiven vektor.
   *      Om vektorn �r tom returneras en nullpekare.
   *****************************************************************************/
   T* end(void) const
   {
      return this->data_ + this->size_;
   }

   /*****************************************************************************
   * last: Returnerar adressen till det sista elementet i angiven vektor.
   *       Om vektorn �r tom returneras en nullpekare.
   *****************************************************************************/
   T* last(void) const
   {
      return this->size_ > 0 ? this->end() - 1 : nullptr;
   }

   /*****************************************************************************
   * clear: T�mmer angiven vektor.
   *****************************************************************************/
   void clear(void)
   {
      std::free(this->data_);
      this->data_ = nullptr;
      this->size_ = 0;
      return;
   }

   /*****************************************************************************
   * resize: �ndrar storlek p� angiven vektor med angivet startv�rde, d�r
   *         startv�rdet �r satt till 0 som default. Ifall vektorns storlek
   *         lyckas �ndras till �nskad storlek returneras 0, annars felkod 1.
   *
   *         - new_size : Vektorns nya storlek (antalet element).
   *         - start_val: Referens till startv�rde f�r respektive element
   *                      (default = 0).
   *****************************************************************************/
   int resize(const std::size_t new_size,
              const T& start_val = static_cast<T>(0))
   {
      if (new_size == 0)
      {
         this->clear();
         return 0;
      }

      auto copy = (T*)std::realloc(this->data_, sizeof(T) * new_size);
      if (!copy) return 1;
      this->data_ = copy;
      this->size_ = new_size;

      for (auto& i : *this)
      {
         i = start_val;
      }

      return 0;
   }

   /*****************************************************************************
   * push: L�gger till ett nytt element l�ngst bak i angiven vektor. Ifall
   *       minnesallokeringen lyckas s� returneras 0, annars felkod 1.
   *
   *       - new_element: Referens till det nya element som skall l�ggas till.
   *****************************************************************************/
   int push(const T& new_element)
   {
      auto copy = (T*)std::realloc(this->data_, sizeof(T) * (this->size_ + 1));
      if (!copy) return 1;
      copy[this->size_++] = new_element;
      this->data_ = copy;
      return 0;
   }

   /*****************************************************************************
   * pop: Tar bort det sista elementet i angiven vektor om ett s�dant finns.
   *      Om h�gst ett element finns lagrat i vektor s� t�ms den helt. Ifall
   *      minnesallokeringen lyckas s� returneras 0, annars felkod 1.
   *****************************************************************************/
   int pop(void)
   {
      if (this->size_ <= 1)
      {
         this->clear();
         return 0;
      }
      else
      {
         auto copy = (T*)std::realloc(this->data_, sizeof(T) * (this->size_ - 1));
         if (!copy) return 1;
         this->data_ = copy;
         this->size_--;
         return 0;
      }
   }

   /*****************************************************************************
   * assign: Fyller vektor med heltal fr�n angivet startv�rde och inkrementerar
   *         varje element med angivet stegv�rde. Som default anv�nds startv�rde
   *         0 och stegv�rde 1.
   *
   *        - start_val: Startv�rde f�r f�rsta elementet (default = 0).
   *        - step_val : Stegv�rde (defeault = 1).
   *****************************************************************************/
   void assign(const T& start_val = static_cast<T>(0),
               const T& step_val = static_cast<T>(1))
   {
      auto num = start_val;

      for (auto& i : *this)
      {
         i = num;
         num += step_val;
      }

      return;
   }

   /*****************************************************************************
   * print: Skriver ut inneh�llet lagrat i angiven vektor via angiven utstr�m,
   *        d�r standardutenheten std::cout anv�nds som default f�r utskrift
   *        i terminalen.
   *
   *        - ostream: Referens till angiven utstr�m (default = std::cout).
   *****************************************************************************/
   void print(std::ostream& ostream = std::cout) const
   {
      if (this->size_ == 0) return;
      ostream << "--------------------------------------------------------------------------------\n";

      for (auto& i : *this)
      {
         ostream << i << "\n";
      }

      ostream << "--------------------------------------------------------------------------------\n\n";
      return;
   }
};

#endif /* VECTOR_HPP_ */