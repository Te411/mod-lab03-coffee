// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialState) {
    Automata automata;
    EXPECT_EQ(automata.getState(), OFF);
}

TEST(AutomataTest, SwitchOn) {
    Automata automata;
    automata.on();
    EXPECT_EQ(automata.getState(), WAIT);
}

TEST(AutomataTest, InsertCoin) {
    Automata automata;
    automata.on();
    automata.coin(100);
    EXPECT_EQ(automata.getState(), ACCEPT);
}

TEST(AutomataTest, SelectDrink) {
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.choice(2);
    EXPECT_EQ(automata.getState(), CHECK);
}

TEST(AutomataTest, CheckSufficientFunds) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice(1);
    automata.check();
    EXPECT_EQ(automata.getState(), ACCEPT);
}

TEST(AutomataTest, CookDrink) {
    Automata automata;
    automata.on();
    automata.coin(150);
    automata.choice(1);
    automata.check();
    automata.cook();
    automata.finish();
    EXPECT_EQ(automata.getState(), WAIT);
}

TEST(AutomataTest, CancelOperation) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.cancel();
    EXPECT_EQ(automata.getState(), WAIT);
}

TEST(AutomataTest, OffAutomata) {
    Automata automata;
    automata.on();
    automata.off();
    EXPECT_EQ(automata.getState(), OFF);
}

TEST(AutomataTest, NotEnoughFundsForDrink) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice(2);
    automata.check();
    EXPECT_EQ(automata.getState(), ACCEPT);
}

TEST(AutomataTest, DrinkPreparation) {
    Automata automata;
    automata.on();
    automata.coin(150);
    automata.choice(2);
    automata.check();
    automata.cook();
    automata.finish();
    EXPECT_EQ(automata.getState(), WAIT);
}

TEST(AutomataTest, InvalidCoin) {
    Automata automata;
    automata.on();
    automata.coin(-50);
    EXPECT_EQ(automata.getState(), WAIT);
}

TEST(AutomataTest, SelectInvalidDrink) {
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.choice(10);
    EXPECT_EQ(automata.getState(), ACCEPT);
}