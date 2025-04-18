//"Copyright 2025 Owner"
#include "Automata.h"
#include <iostream>

Automata::Automata() {
	cash = 0;
	state = OFF;
	selectedDrink = -1;
	menu = { "Чай", "Латте", "Капучино", "Горячее молоко" };
	prices = { 50, 150, 120, 55 };
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
		std::cout << "Автомат включен. Ожидание действий." << std::endl;
	}
}

void Automata::off() {
	if (state == WAIT) {
		state = OFF;
		std::cout << "Автомат выключен." << std::endl;
	}else {
		std::cout << "Невозможно выключить автомат во время работы!" << std::endl;
	}
}

void Automata::coin(int amount) {
	if (amount <= 0) {
		std::cout << "Неверная сумма." << std::endl;
		return;
	}
	if (state == WAIT || state == ACCEPT) {
		state = ACCEPT;
		cash += amount;
		std::cout << "Внесено: " << amount << ". Текущий баланс: " << cash << std::endl;
	}
}

void Automata::getMenu() {
	std::cout << "Меню:" << std::endl;
	for (int i = 0; i < menu.size(); i++) {
		std::cout << i << ". " << menu[i] << " - " << prices[i] << " руб." << std::endl;
	}
}

STATES Automata::getState() {
	return state;
}

void Automata::choice(int drink) {
	if (state == ACCEPT) {
		if (drink >= 0 && drink < menu.size()) {
			std::cout << "Вы выбрали: " << menu[drink] << std::endl;
			selectedDrink = drink;
			state = CHECK;
		}else {
			std::cout << "Неверный индекс напитка" << std::endl;
		}
	}else {
		std::cout << "Некорректное состояние" << std::endl;
	}
}

void Automata::check() {
	if (state == CHECK) {
		if (cash >= prices[selectedDrink]) {
			state = COOK;
		}else {
			state = ACCEPT;
			std::cout << "Недостаточно средств. Требуется ещё " << (prices[selectedDrink] - cash) << " руб. " << std::endl;
		}
	}
}

void Automata::cancel() {
	if (state == ACCEPT || state == CHECK) {
		std::cout << "Отмена операции. Возврат денег: " << cash << " руб." << std::endl;
		cash = 0;
		state = WAIT;
	}else {
		std::cout << "Невозможно отменить в текущем состоянии." << std::endl;
	}
}

void Automata::cook() {
	if (state == COOK) {
		std::cout << "Приготовление " << menu[selectedDrink] << "..." << std::endl;
		int price = prices[selectedDrink];
		int change = cash - price;
		cash = 0;
		if (change > 0) {
			std::cout << "Возьмите сдачу: " << change << " руб." << std::endl;
		}
	}
}

void Automata::finish() {
	state = WAIT;
	selectedDrink = -1;
	std::cout << "Пожалуйста, заберите ваш напиток." << std::endl;
}