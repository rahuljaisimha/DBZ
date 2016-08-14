#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include "Character.h"
#include <iostream>
#include <memory>

# define CHARACTER_OF decltype

using std::string;

struct Attack{
	int charges;
	int damage;

	string name;

	Attack() = default;
	Attack(int _charges, int _damage, string _name){
		charges = _charges;
		damage = _damage;
		name = _name;
	}

	virtual void doAttack(Character& attacker, Character& defender){
		attacker.decreaseCharge(charges);
		defender.pendingDamage += damage;
	}

};

class Punch : public Attack{
public:
	Punch() : Attack(1, 10, "Punch"){

	}
};

class Kick : public Attack{
public:
	Kick() : Attack(2, 20, "Kick"){

	}
};

class Megapunch : public Attack{
public:
	Megapunch() : Attack(3, 30, "Megapunch"){

	}
};

class Megakick : public Attack{
public:
	Megakick() : Attack(4, 40, "Megakick"){

	}
};

class Dodge : public Attack{
public:
	Dodge() : Attack(0, 0, "Dodge"){

	}

	virtual void doAttack(Character& attacker, Character& defender) override{
		attacker.dodging = true;
	}
};

class Block : public Attack{
public:
	Block() : Attack(0, 0, "Block"){

	}

	virtual void doAttack(Character& attacker, Character& defender) override{
		attacker.blocking = true;
	}
};

class Charge : public Attack{
public:
	Charge() : Attack(0, 0, "Charge"){

	}

	virtual void doAttack(Character& attacker, Character& defender) override{
		attacker.addCharge();
	}
};


// Messiest part of the code. Find a way to refactor this function
template<typename T>
std::shared_ptr<Attack> getAttack(T player, int index){
	if(index == 0){
		using Att = typename CHARACTER_OF(player)::Attacks::template type<0>;
		std::shared_ptr<Attack> m = std::make_shared<Att>();
		return m;
	} else if(index == 1){
		using Att = typename CHARACTER_OF(player)::Attacks::template type<1>;
		std::shared_ptr<Attack> m = std::make_shared<Att>();
		return m;
	} else if(index == 2){
		using Att = typename CHARACTER_OF(player)::Attacks::template type<2>;
		std::shared_ptr<Attack> m = std::make_shared<Att>();
		return m;
	} else if(index == 3){
		using Att = typename CHARACTER_OF(player)::Attacks::template type<3>;
		std::shared_ptr<Attack> m = std::make_shared<Att>();
		return m;
	} else if(index == 4){
		using Att = typename CHARACTER_OF(player)::Attacks::template type<4>;
		std::shared_ptr<Attack> m = std::make_shared<Att>();
		return m;
	} else if(index == 5){
		using Att = typename CHARACTER_OF(player)::Attacks::template type<5>;
		std::shared_ptr<Attack> m = std::make_shared<Att>();
		return m;
	} else if(index == 6){
		using Att = typename CHARACTER_OF(player)::Attacks::template type<6>;
		std::shared_ptr<Attack> m = std::make_shared<Att>();
		return m;
	}
	using Att = typename CHARACTER_OF(player)::Attacks::template type<0>;
	std::shared_ptr<Attack> m = std::make_shared<Att>();
	return m;
}

#endif //ifndef ATTACK_H
