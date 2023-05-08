//
// Created by Abdis on 5/7/2023.
//

#ifndef UNTITLED1_VALIDATEMOVE_H
#define UNTITLED1_VALIDATEMOVE_H
int validate(char * suit,char *value);
int validate(char * suit,char *value) {
    if (*suit == 'S' || *suit == 'D' || *suit == 'H' || *suit == 'C') {
if(charConverter(*value)!=-1) {
    return 1;
}
        return 0;
    }
    else
        return 0;

}



int charConverter(char c) {
    if (c == 'A') {
        return 1;
    } else if (c == '2') {
        return 2;
    } else if (c == '3') {
        return 3;
    } else if (c == '4') {
        return 4;
    } else if (c == '5') {
        return 5;
    } else if (c == '6') {
        return 6;
    } else if (c == '7') {
        return 7;
    } else if (c == '8') {
        return 8;
    } else if (c == '9') {
        return 9;
    } else if (c == 'T') {
        return 10;
    } else if (c == 'J') {
        return 11;
    } else if (c == 'Q') {
        return 12;
    } else if (c == 'K') {
        return 13;
    } else {
        return -1; // invalid input
    }
}







#endif //UNTITLED1_VALIDATEMOVE_H
