#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Enumeration Of card Suits.
 * @SPADE: Spades Suit.
 * @HEART: Hearts Suit.
 * @CLUB: Clubs Suit.
 * @DIAMOND: Diamonds Suit.
 */
typedef enum kind_e
{
        SPADE = 0,
        HEART,
        CLUB,
        DIAMOND
} kind_t;

/**
 * struct card_s - Playing Card
 *
 * @value: Value of the Card
 * From "Ace" to "King"
 * @kind: Kind of the Card
 */
typedef struct card_s
{
        const char *value;
        const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of Card
 *
 * @card: Pointer to Card Of the node
 * @prev: Pointer to Previous node Of the list
 * @next: Pointer to Next node Of the list
 */
typedef struct deck_node_s
{
        const card_t *card;
        struct deck_node_s *prev;
        struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
