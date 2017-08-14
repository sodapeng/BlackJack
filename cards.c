#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"

static const int NUM_CARDS = 52;

// initialize card array by suit and rank, then randomly shuffle the array
void initialize_card(struct card** card_array) {
  int index = 0;
  for (int suit = hearts; suit <= clubs; suit++) {
    for (int rank = two; rank <= ace; rank++) {
      card_array[index]->card_suit = suit;
      card_array[index]->card_rank = rank;
      index++;
    }
  }
  shuffle(card_array, NUM_CARDS);
 }

// create a standard 52-card deck
void* create_deck() {
	struct card ** card_array = (struct card **) calloc(NUM_CARDS, sizeof(struct card *));
  int i = 0;
  for (; i < NUM_CARDS; i++) {
    card_array[i] = (struct card *) malloc(sizeof(struct card));
  }
  struct deck * deck = (struct deck *) malloc(sizeof(struct deck));
  deck->card_array = card_array;
  deck->curindex = 0;
  initialize_card(card_array);
  return deck;
}

// free the deck memory and cards within it
void destroy_deck(void* deck) {
	struct card ** card_array = ((struct deck *) deck)->card_array;
  int i = 0;
  for (; i < NUM_CARDS; i++) {
    free(card_array[i]);
  }
  free(deck);
}

// Return the number of cards left in the deck
int number_of_cards_remaining_in_deck(void* deck) {
  return NUM_CARDS - ((struct deck *) deck)->curindex;
}

// return a card, removing it from the deck
// expect caller to free returned card
struct card* deal_card(void* deck) {
  if (number_of_cards_remaining_in_deck(deck) < 1) {
    printf("%s\n", "Not enough cards in the deck");
    return NULL;
  }
  struct deck * deck_ptr = (struct deck *) deck;
  struct card * card = malloc(sizeof(struct card));
  memcpy(card, deck_ptr->card_array[deck_ptr->curindex++], sizeof(struct card));
  return card;
}

// return the number of cards indicated and remove them from the deck
// expect caller to free returned cards and every card inside it
struct card** deal_cards(void* deck, int num_cards) {
  if (number_of_cards_remaining_in_deck(deck) < num_cards) {
    printf("%s\n", "Not enough cards in the deck");
    return NULL;
  }
  struct card ** cards = calloc(num_cards, sizeof(struct card *));
  int i = 0;
  for (; i < num_cards; i++) {
    cards[i] = deal_card(deck);
  }
  return cards;
}

// This will return the remaining cards in the deck, in their current order, without removing any
struct card** peek_at_deck(void* deck) {
  struct deck * deck_ptr = (struct deck *) deck;
  return &(deck_ptr->card_array[deck_ptr->curindex]);
}

// Return a string describing a card e.g. "four of hearts" or "king of clubs"
char* to_string(struct card* my_card) {
  int buf_size = 256;
  char* buf = calloc(buf_size, sizeof(char));
  snprintf(buf, buf_size, "%s of %s", get_rank_name(my_card->card_rank), get_suit_name(my_card->card_suit));
  return buf;
}
