
#include "gen.h"  
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>


int gen(int min, int max, int num, std::vector<int> &container)
{
   int range = 0;

   if (min < INT_MIN || max > INT_MAX || !(min <= max)) {
      std::cerr << "Invalid range!" << std::endl;
      return INVALID_RANGE;
   }
   
   if ((unsigned int) (max - min) > RAND_MAX) {
      std::cerr << "Range is too large (no more than " << INT_MAX << ")" << std::endl;
      return OUT_OF_RANGE;
   }

   if (num < 1) {
      std::cerr << "Invalid number of randoms." << std::endl;
      return INVALID_INPUT;
   }

   range = max - min + 1;
   //srand(time(NULL));

   for (int i = 0; i < num; i++) { 
      int number = rand() % range + min;
      std::cout << number << std::endl;
      container.push_back(number);
   }

   return GEN_OK;
}

