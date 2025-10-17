#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 1 варіант
class component {
private:
	string company_name;
public:

	component(string name) : company_name(name) {}

	void set_company_name(string name) { company_name = name; }
	string get_company_name() const { return company_name; }
};

class gpu : public component {
public:

	gpu(string company_name) : component(company_name) {}

	void info() const {
		cout << "QPU made by " << get_company_name() << endl;
	}
};

class memory : public component {
public:

	memory(string company_name) : component(company_name) {}

	void info() const {
		cout << "Memory made by " << get_company_name() << endl;
	}
};

class graphics_card : public gpu, public memory {
public:

	graphics_card(string gpu_company, string memory_company)
		: gpu(gpu_company), memory(memory_company) {}

	void info() const {
		gpu::info();
		memory::info();
	}
};

// 2 варіант

class character {
private:
	int hp;
public:

	character() : hp(100) {}
	character(int health) : hp(health) {}

	void set_hp(int health) { hp = health; }
	int get_hp() const { return hp; }
};

class warrior : virtual public character{
private:
	int strength;
public:

	warrior() : character(), strength(50) {}
	warrior(int health, int str) : character(health), strength(str) {}

	void set_strength(int str) { strength = str; }
	int get_strength() const { return strength; }

	void info() const {
		cout << "Warrior HP: " << get_hp() << ", Strength: " << strength << endl;
	}
};

class boss : virtual public character {
private:
	int power;
public:

	boss() : character(), power(100) {}
	boss(int health, int pow) : character(health), power(pow) {}

	void set_power(int pow) { power = pow; }
	int get_power() const { return power; }

	void info() const {
		cout << "Boss HP: " << get_hp() << ", Power: " << power << endl;
	}
};

class boss_warrior : public warrior, public boss {
private:
	string special_ability;
public:

	boss_warrior() : warrior(), boss(), special_ability("None") {}
	boss_warrior(int health, int str, int pow, string ability)
		: warrior(health, str), boss(health, pow), special_ability(ability) {}

	void set_special_ability(string ability) { special_ability = ability; }
	string get_special_ability() const { return special_ability; }

	void info() const {
		warrior::info();
		boss::info();
		cout << "Special Ability: " << special_ability << endl;
	}
};

int main()
{

	// 1 варіант
	/*graphics_card my_card("NVIDIA", "Samsung");
	my_card.info();*/



	// 2 варіант
	/*boss_warrior my_boss_warrior(100000, 70, 150, "Fireball");
	my_boss_warrior.info();*/


    return 0;
}

