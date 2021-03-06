#include "gdfmm/gdfmm.h"
#include <math.h>

namespace gdfmm {

GDFMM::ExpCache::ExpCache(float sigma, int tableSize)
: lookupTable(new float[tableSize + 1]),
  tableSize_(tableSize) {

  lookupTable[0] = 1;
  for (int i=1; i<= tableSize; i++) {
    lookupTable[i] = expf( - 0.5 * (i / sigma) * (i / sigma) );
  }
}

float GDFMM::ExpCache::operator()(int d) {
  d = abs(d);
  assert(d <= tableSize_);

  return lookupTable[d];
}

}
