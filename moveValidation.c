//
// Created by Felix Schmidt on 09/05/2023.
//

#include "moveValidation.h"


int getColumnVerification(char cardValue, char cardSuit, List* column){
    Card bottomCard = getCardAt(column,column->size - 1);
    if(cardValue == 'A' && bottomCard.cardValue == '2'){
        return 1;
    } else if(cardValue == '2' ){
       if(bottomCard.cardValue == '3'){
           return 1;
       }
   } else if (cardValue == '3' && bottomCard.cardValue == '4'){
       return 1;
   }else if (cardValue == '4'  && bottomCard.cardValue == '5'){
       return 1;
   }else if (cardValue == '5' && bottomCard.cardValue == '6'){
       return 1;
   }else if (cardValue == '6' && bottomCard.cardValue == '7'){
       return 1;
   }else if (cardValue == '7' && bottomCard.cardValue == '8'){
       return 1;
   }else if (cardValue == '7' && bottomCard.cardValue == '8'){
       return 1;
   }else if (cardValue == '8' && bottomCard.cardValue == '9'){
       return 1;
   }else if (cardValue == '9' && bottomCard.cardValue == 'T'){
        return 1;
   }else if (cardValue == 'T' && bottomCard.cardValue == 'J'){
       return 1;
   }else if (cardValue == 'J' && bottomCard.cardValue == 'Q'){
        return 1;
   } else if (cardValue == 'Q' && bottomCard.cardValue == 'K'){
       return 1;
   } else if(cardValue == 'K' && column->size == 0){
               return 1;
       }
    return 0;
}
int getColumnToColumnVerification(Card card, List* column){
    Card bottomCard = getCardAt(column,column->size - 1);
    if(card.cardValue == 'A' && bottomCard.cardValue == '2'){
        return 1;
    } else if(card.cardValue == '2' && bottomCard.cardValue == '3'){
            return 1;
    } else if( card.cardValue == '3' && bottomCard.cardValue == '4'){
        return 1;
    }else if (card.cardValue == '4'  && bottomCard.cardValue == '5'){
        return 1;
    }else if (card.cardValue == '5' && bottomCard.cardValue == '6'){
        return 1;
    }else if  (card.cardValue == '6' && bottomCard.cardValue == '7'){
        return 1;
    }else if  (card.cardValue == '7' && bottomCard.cardValue == '8'){
        return 1;
    }else if  (card.cardValue == '8' && bottomCard.cardValue == '9'){
        return 1;
    }else if  (card.cardValue == '9' && bottomCard.cardValue == 'T'){
        return 1;
    }else if  (card.cardValue == 'T' && bottomCard.cardValue == 'J') {
        return 1;
    }else if(card.cardValue == 'J' && bottomCard.cardValue == 'Q'){
            return 1;
    } else if(card.cardValue == 'Q' && bottomCard.cardValue == 'K'){
            return 1;
    } else if(card.cardValue == 'K' && column->size == 0){
            return 1;
    }
    return 0;
}
int moveToFoundation(Card card, List* foundation) {
    Card topCard = getCardAt(foundation,foundation->size - 1);
    if(foundation->size == 0) {
        if (card.cardValue == 'A') {
            return 1;
        }
        }  else if(card.cardValue == '3' && topCard.cardValue == '2' && card.cardSuit == topCard.cardSuit){
                return 1;
        } else if( card.cardValue == '4' && topCard.cardValue == '3' && card.cardSuit == topCard.cardSuit){
            return 1;
        }else if (card.cardValue == '5'  && topCard.cardValue == '4' && card.cardSuit == topCard.cardSuit){
            return 1;
        }else if (card.cardValue == '6' && topCard.cardValue == '5' && card.cardSuit == topCard.cardSuit){
            return 1;
        }else if  (card.cardValue == '7' && topCard.cardValue == '6' && card.cardSuit == topCard.cardSuit){
            return 1;
        }else if  (card.cardValue == '8' && topCard.cardValue == '7' && card.cardSuit == topCard.cardSuit){
            return 1;
        }else if  (card.cardValue == '9' && topCard.cardValue == '8' && card.cardSuit == topCard.cardSuit){
            return 1;
        }else if  (card.cardValue == 'T' && topCard.cardValue == '9' && card.cardSuit == topCard.cardSuit) {
            return 1;
         } else if(topCard.cardValue == 'A' && card.cardValue == '2' && card.cardSuit == topCard.cardSuit){
            return 1;
         }else if(topCard.cardValue == 'T' && card.cardValue == 'J' && card.cardSuit == topCard.cardSuit){
            return 1;
        } else if(topCard.cardValue == 'J' && card.cardValue == 'Q' && card.cardSuit == topCard.cardSuit){
            return 1;
        } else if(topCard.cardValue == 'Q' && card.cardValue == 'K' && card.cardSuit == topCard.cardSuit){
            return 1;
        }
    else if(card.cardValue == 'K'){
            return 0; // should not happen
    }
    return 0;
}

