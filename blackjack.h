// Compare two blackjack hands. Return a value < 0 if hand_one wins, a value of 0
// if the hands are equal and a value > 0 if hand_two wins
int blackjack_compare(struct card** hand_one, int num_cards_hand_one,
                      struct card** hand_two, int num_cards_hand_two);

// Blackjack to_string, should return the value of the hand or "BUST" if the total
// is over 21
char* blackjack_to_string(struct card** my_hand, int num_cards_in_hand);
