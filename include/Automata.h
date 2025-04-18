#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <string>
#include <vector>


enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK,
};

class Automata {
    private:
        int cash;
        std::vector<std::string> menu;
        std::vector<int> prices;
        STATES state;
        int selectedDrink;
    public:
        Automata();
        void on();
        void off();
        void coin(int);   
        void getMenu();
        STATES getState();
        void choice(int);
        void check();
        void cancel();
        void cook();
        void finish();
};

#endif // INCLUDE_AUTOMATA_H_