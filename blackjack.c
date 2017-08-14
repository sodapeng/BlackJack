#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"

// evaluate the max score of current hand less or equal to 21, 
// return -1 if exceeds 21
int blackjack_score(struct card** hand, int num_cards) {
	int res = 0, aces = 0;
	for(int i = 0; i < num_cards; i++) {
		int val = get_rank_value(hand[i]->card_rank);
		res += val;
		if(val > 10){
			aces++;
		}
	}

	for(int i = 0; i < aces && res > 21; i++){
		res -= 10;
	}

	if(res > 21){
		res = -1;
	}

	return res;

}

// Compare two blackjack hands. Return a value < 0 if hand_one wins, a value of 0
// if the hands are equal and a value > 0 if hand_two wins
int blackjack_compare(struct card** hand_one, int num_cards_hand_one,
                      struct card** hand_two, int num_cards_hand_two){

	return blackjack_score(hand_two, num_cards_hand_two) - blackjack_score(hand_one, num_cards_hand_one);

}

// Blackjack to_string, should return the value of the hand or "BUST" if the total
// is over 21
char* blackjack_to_string(struct card** my_hand, int num_cards_in_hand) {
	int score = blackjack_score(my_hand, num_cards_in_hand);
	int buf_size = 256;
	char* buf = calloc(buf_size, sizeof(char));
	if(score > 0){
		snprintf(buf, buf_size, "%d", score);
	}else{
		strcpy(buf, "BUST");
	}
	return buf;
}
