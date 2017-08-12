// Shared definitions
typedef enum {hearts, diamonds, spades, clubs} suit;

typedef enum {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace} rank;

struct card {
	suit card_suit;
	rank card_rank;
};

struct deck {
  struct card ** card_array;
  int curindex;
};

// create a standard 52-card deck
void* create_deck();

// free the deck memory
void destroy_deck(void* deck);

// return a card, removing it from the deck
struct card* deal_card(void* deck);

// return the number of cards indicated and remove them from the deck
struct card** deal_cards(void* deck, int num_cards);

// Return the number of cards left in the deck
int number_of_cards_remaining_in_deck(void* deck);

// This will return the remaining cards in the deck, in their current order, without removing any
struct card** peek_at_deck(void* deck);

// Return a string describing a card e.g. "four of hearts" or "king of clubs"
char* to_string(struct card* my_card);
