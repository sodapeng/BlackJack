#include "cards.h"

/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
void shuffle(struct card ** array, int n);

char* get_suit_name(suit s);

char* get_rank_name(rank r);
