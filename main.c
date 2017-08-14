#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "blackjack.h"
// #include "poker.h"

#define NUM_CARDS_IN_DECK 52
#define POKER 0

void
deal_one_hand_of_blackjack() {
  // Create a deck
  printf("\tcreating a blackjack_deck\n");
  int num_cards_to_request_hand_1 = 3;
  int num_cards_to_request_hand_2 = 3;
  void *deck = create_deck();

  // FIXME
  struct card** peek = peek_at_deck(deck);

  printf("\nPeek first ten cards: \n");
  for(int i = 0; i < 10; i++) {
    printf("\t%s \n", to_string(peek[i]));
  }
  printf("\n");

  // request four cards
  struct card** blackjack_hand_1 = deal_cards(deck, num_cards_to_request_hand_1);
  char* blackjack_hand_1_string;

  blackjack_hand_1_string =  blackjack_to_string(blackjack_hand_1, num_cards_to_request_hand_1);
  printf("\tblackjack hand 1: %s\n", blackjack_hand_1_string);

  // request three cards
  struct card** blackjack_hand_2 = deal_cards(deck, num_cards_to_request_hand_2);
  char* blackjack_hand_2_string;
  blackjack_hand_2_string =  blackjack_to_string(blackjack_hand_2, num_cards_to_request_hand_2);
  printf("\tblackjack hand 2: %s\n", blackjack_hand_2_string);

  // Compare the two hands to see who wins
  int hand_comparison = blackjack_compare(blackjack_hand_1, num_cards_to_request_hand_1,
                        blackjack_hand_2, num_cards_to_request_hand_2);
  if (hand_comparison < 0) {
    printf("\t\thand 1 wins\n");
  } else if (hand_comparison == 0) {
    printf("\t\tdraw\n");
  } else {
    printf("\t\thand 2 wins\n");
  }

  // free the hands and strings
  free(blackjack_hand_1_string);
  for (int i=0; i<num_cards_to_request_hand_1; i++) {
    free(blackjack_hand_1[i]);
  }
  free(blackjack_hand_1);
  free(blackjack_hand_2_string);
  for (int i=0; i<num_cards_to_request_hand_2; i++) {
    free(blackjack_hand_2[i]);
  }
  free(blackjack_hand_2);

  // Now destroy the deck
  destroy_deck(deck);
}

void
create_and_destroy_deck() {
  // Create a deck
  void *deck = create_deck();

  // verify the deck size
  int cards_left = number_of_cards_remaining_in_deck(deck);
  printf("\tThere are %d cards left in the deck\n", cards_left);

  // Now destroy the deck
  destroy_deck(deck);
}

void
deal_one_card() {
  // Create a deck
  void *deck = create_deck();

  // Deal a card
  struct card* one_card = deal_card(deck);
  printf("\tCard is the %d of %d\n", one_card->card_rank, one_card->card_suit);

  char* card_string;
  card_string = to_string(one_card);
  printf("\t%s\n", card_string);

  // free the string that was returned
  free(card_string);

  int cards_left = number_of_cards_remaining_in_deck(deck);
  printf("\tThere are %d cards left in the deck\n", cards_left);

  // free the card that we were dealt
  free(one_card);

  // Now destroy the deck
  destroy_deck(deck);
}

void
deal_one_hand() {
  // Create a deck
  void *deck = create_deck();

  // request two cards
  struct card** my_hand = deal_cards(deck, 5);

  char* card_string;
  // print and then free free each card
  for (int i=0; i<5; i++) {
    card_string = to_string(my_hand[i]);
    printf("\t%s\n", card_string);

    // free the card string and then the card
    free(card_string);
    free(my_hand[i]);
  }

  // How many cards are left in the deck?
  int cards_left = number_of_cards_remaining_in_deck(deck);
  printf("\tThere are %d cards left in the deck\n", cards_left);

  // free the point to the pointers
  free(my_hand);

  // Now destroy the deck
  destroy_deck(deck);
}

int
main() {
  printf("Cards time\n");

  printf("test 1\n");
  create_and_destroy_deck();

  printf("test 2\n");
  deal_one_card();

  printf("test 3\n");
  deal_one_hand();

  printf("test 4\n");
  deal_one_hand_of_blackjack();

  return 0;
}
