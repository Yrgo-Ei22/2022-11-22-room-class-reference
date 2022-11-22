/********************************************************************************
* vector.hpp: Implementering av dynamiska vektorer via klassen vec.
********************************************************************************/
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>
#include <cstdlib>

/********************************************************************************
* vector: Generisk klass för implementering av dynamiska arrayer (vektorer) 
*         av godtycklig datatyp.
********************************************************************************/
template<class T>
class vector
{
private:
   T* data_ = nullptr;    /* Pekare till ett dynamiskt fält innehållande lagrad data. */
   std::size_t size_ = 0; /* Vektorns storlek, dvs. antalet lagrade element. */
public:

   /*****************************************************************************
   * vector: Tom konstruktor, initierar en ny tom vektor.
   *****************************************************************************/
   vector(void) { }

   /*****************************************************************************
   * vector: Konstruktor, initierar ny vektor av angiven storlek med angivet
   *         startvärde.
   *
   *         - start_size: Vektorns nya storlek (antalet element).
   *         - start_val : Referens till startvärde för alla element (default = 0).
   *****************************************************************************/
   vector(const std::size_t start_size,
          const T& start_val = static_cast<T>(0))
   {
      this->resize(start_size, start_val);
      return;
   }

   /*****************************************************************************
   * ~vector: Destruktor, frigör minne allokerat för vektorn innan objekt raderas.
   *****************************************************************************/
   ~vector(void)
   {
      this->clear();
      return;
   }

   /*****************************************************************************
   * data: Returnerar en pekare till innehållet lagrat i angiven array.
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
   * begin: Returnerar adressen till det första elementet i angiven vektor.
   *        Om vektorn är tom returneras en nullpekare.
   *****************************************************************************/
   T* begin(void) const
   {
      return this->data_;
   }

   /*****************************************************************************
   * end: Returnerar adressen direkt efter det sista elementet i angiven vektor.
   *      Om vektorn är tom returneras en nullpekare.
   *****************************************************************************/
   T* end(void) const
   {
      return this->data_ + this->size_;
   }

   /*****************************************************************************
   * last: Returnerar adressen till det sista elementet i angiven vektor.
   *       Om vektorn är tom returneras en nullpekare.
   *****************************************************************************/
   T* last(void) const
   {
      return this->size_ > 0 ? this->end() - 1 : nullptr;
   }

   /*****************************************************************************
   * clear: Tömmer angiven vektor.
   *****************************************************************************/
   void clear(void)
   {
      std::free(this->data_);
      this->data_ = nullptr;
      this->size_ = 0;
      return;
   }

   /*****************************************************************************
   * resize: Ändrar storlek på angiven vektor med angivet startvärde, där
   *         startvärdet är satt till 0 som default. Ifall vektorns storlek
   *         lyckas ändras till önskad storlek returneras 0, annars felkod 1.
   *
   *         - new_size : Vektorns nya storlek (antalet element).
   *         - start_val: Referens till startvärde för respektive element
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
   * push: Lägger till ett nytt element längst bak i angiven vektor. Ifall
   *       minnesallokeringen lyckas så returneras 0, annars felkod 1.
   *
   *       - new_element: Referens till det nya element som skall läggas till.
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
   * pop: Tar bort det sista elementet i angiven vektor om ett sådant finns.
   *      Om högst ett element finns lagrat i vektor så töms den helt. Ifall
   *      minnesallokeringen lyckas så returneras 0, annars felkod 1.
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
   * assign: Fyller vektor med heltal från angivet startvärde och inkrementerar
   *         varje element med angivet stegvärde. Som default används startvärde
   *         0 och stegvärde 1.
   *
   *        - start_val: Startvärde för första elementet (default = 0).
   *        - step_val : Stegvärde (defeault = 1).
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
   * print: Skriver ut innehållet lagrat i angiven vektor via angiven utström,
   *        där standardutenheten std::cout används som default för utskrift
   *        i terminalen.
   *
   *        - ostream: Referens till angiven utström (default = std::cout).
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