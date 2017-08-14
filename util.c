#include <stdlib.h>
#include "util.h"

/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
void shuffle(struct card ** array, int n)
{
    if (n > 1)
    {
        int i;
        for (i = 0; i < n - 1; i++)
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          struct card * t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

char* get_suit_name(suit s)
{
   switch (s)
   {
      case hearts: return "hearts";
      case diamonds: return "diamonds";
      case spades: return "spades";
      case clubs: return "clubs";
   }
}

char* get_rank_name(rank r)
{
   switch (r)
   {
      case two: return "two";
      case three: return "three";
      case four: return "four";
      case five: return "five";
      case six: return "six";
      case seven: return "seven";
      case eight: return "eight";
      case nine: return "nine";
      case ten: return "ten";
      case jack: return "jack";
      case queen: return "queen";
      case king: return "king";
      case ace: return "ace";
   }
}

int get_rank_value(rank r)
{
   switch (r)
   {
      case two: return 2;
      case three: return 3;
      case four: return 4;
      case five: return 5;
      case six: return 6;
      case seven: return 7;
      case eight: return 8;
      case nine: return 9;
      case ten: return 10;
      case jack: return 10;
      case queen: return 10;
      case king: return 10;
      case ace: return 11;
   }
}
