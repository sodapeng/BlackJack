// Compare two poker hands. Return a value < 0 if hand_one wins, a value of 0
// if the hands are equal and a value > 0 if hand_two wins.
// Poker hands are always 5 cards, so no need to pass that in as an argument.
int poker_compare(struct card** hand_one, struct card** hand_two);

// poker to_string. See the wikipedia page for hand definitions. Poker hands are always
// five cards, no need to specify the hand length.
//Examples include:
// Ace high
// Pair of jacks
// Two pairs, nines and fives
// Three queens
// Straight, eight high
// Flush, ten high
// Full house, sixes over threes
// four sevens
// straight flush, eight high
// royal flush
char* poker_to_string(struct card** my_hand);
