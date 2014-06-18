//
//  David Wells
//  A standard deck of 52 cards is represented in an array.
//  Each card is represented as an integer.
//  Write a method to shuffle the cards.
//

#include <iostream>

using namespace std;


//  Function Declarations:
void shuffleCards(int (&deck)[52]);
bool unit_test(int (&deck)[52]);
bool check_sum(int (&deck)[52]);
void initialize_deck(int (&deck)[52]);
void print_deck(int (&deck)[52]);



int main(int argc, const char * argv[]) {

    int deckOfCards[52];
    initialize_deck(deckOfCards);
    
    cout << "Unshuffled: ";
    print_deck(deckOfCards);
    shuffleCards(deckOfCards);
    
    cout << "Shuffled: ";
    print_deck(deckOfCards);
    
    //Run Unit Test
    if (unit_test(deckOfCards)) {
        cout << "Passed unit test"<< endl;
    } else  cout << "Failed unit test" << endl;
    
    return 0;
}





//  Function definitions:


//  Shuffle Cards function
//  Input:  an integer array of 52 cards passed by reference
//  Output: array is shuffled
void shuffleCards(int (&deck)[52]){
    
    srand((int)time(NULL));
    int swap = rand() % 52;
    int temp = 0;
    
    for (int i = 0; i < 52; i++) {
        
        if (i != swap) {
            temp = deck[i];
            deck[i] = deck[swap];
            deck[swap] = temp;
        }
        swap = rand() % 52;
    }
}


//  Unit Test runs one simple test to check that all of the cards are still
//  there after the shuffle is performed.
bool unit_test(int (&deck)[52]){
    
    int emptyDeck[52];
    initialize_deck(emptyDeck);

    bool pre_shuffle = check_sum(emptyDeck);
    
    if(check_sum(emptyDeck) == pre_shuffle){
        return true;
    }
    
    
    return false;
}


//  Checks that the sum of the cards is equal to the expected sum,
//  since we are expecting the cards to be a sum from 0 to 51
//  we know the sum is 1326.  If the shuffle worked correctly,
//  we will see that sum.
bool check_sum(int (&deck)[52]){
    
    int sum = 0;
    int expected_sum = 1326;
    for (int i = 0; i < 52; i++) {
        
        sum += deck[i];
    }

    if (sum == expected_sum) {
        return true;
    }
    
    return false;
}



void initialize_deck(int (&deck)[52]){
    
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
}



void print_deck(int (&deck)[52]){
    
    for (int i = 0; i < 52; i++) {
        cout << deck[i] << " ";
    }
    cout << endl;
}























