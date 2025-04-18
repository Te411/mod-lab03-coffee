//"Copyright 2025 Owner"
#include "Automata.h"
#include <iostream>

Automata::Automata() {
	cash = 0;
	state = OFF;
	selectedDrink = -1;
	menu = { "Tea", "Latte", "Cappuccino", "Hot milk" };
	prices = { 50, 150, 120, 55 };
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
		std::cout << "Machine is on. Waiting for action." << std::endl;
	}
}

void Automata::off() {
	if (state == WAIT) {
		state = OFF;
		std::cout << "The machine is turned off." << std::endl;
	} else {
		std::cout << "It is impossible to turn off the machine during operation!" << std::endl;
	}
}

void Automata::coin(int amount) {
	if (amount <= 0) {
		std::cout << "Incorrect amount." << std::endl;
		return;
	}
	if (state == WAIT || state == ACCEPT) {
		state = ACCEPT;
		cash += amount;
		std::cout << "Contributed: " << amount << ". Current balance: " << cash << std::endl;
	}
}

void Automata::getMenu() {
	std::cout << "Menu:" << std::endl;
	for (int i = 0; i < menu.size(); i++) {
		std::cout << i << ". " << menu[i] << " - " << prices[i] << " rub." << std::endl;
	}
}

STATES Automata::getState() {
	return state;
}

void Automata::choice(int drink) {
	if (state == ACCEPT) {
		if (drink >= 0 && drink < menu.size()) {
			std::cout << "You have chosen: " << menu[drink] << std::endl;
			selectedDrink = drink;
			state = CHECK;
		} else {
			std::cout << "Invalid drink index" << std::endl;
		}
	} else {
		std::cout << "Incorrect state" << std::endl;
	}
}

void Automata::check() {
	if (state == CHECK) {
		if (cash >= prices[selectedDrink]) {
			state = COOK;
		} else {
			state = ACCEPT;
			std::cout << "Insufficient funds." << std::endl;
		}
	}
}

void Automata::cancel() {
	if (state == ACCEPT || state == CHECK) {
		std::cout << "Cancel transaction. Refund. " << std::endl;
        cash = 0;
		state = WAIT;
	} else {
		std::cout << "Cannot cancel in current state." << std::endl;
	}
}

void Automata::cook() {
	if (state == COOK) {
		std::cout << "Preparation " << menu[selectedDrink] << "..." << std::endl;
		int price = prices[selectedDrink];
		int change = cash - price;
		cash = 0;
		if (change > 0) {
			std::cout << "Take the change: " << change << " rub." << std::endl;
		}
	}
}

void Automata::finish() {
	state = WAIT;
	selectedDrink = -1;
	std::cout << "Please, take your drink.." << std::endl;
}
