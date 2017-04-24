#ifndef RANDOM_GEN_H
#define RANDOM_GEN_H

#include <vector>

enum {
   GEN_OK,
   INVALID_RANGE,
   OUT_OF_RANGE,
   INVALID_INPUT
};

int gen(int min, int max, int num, std::vector<int> &container);


#endif
