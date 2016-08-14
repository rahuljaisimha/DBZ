#include <string>
#include <iostream>
#include "TypeList.h"

using std::string;

struct Attack{
	int charges;
	int damage;
	int effect;

	string name;

	Attack() = default;
	Attack(int _charges, int _damage,int _effect, string _name){
		charges = _charges;
		damage = _damage;
		name = _name;
		effect = _effect
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

template <typename... Args>
class Character{
	int hp;
	int charges = 0;

	string name;

public:
	Character() = default;
	Character(int _hp, string _name){
		hp = _hp;
		name = _name;
	}
	using Attacks = TypeList<Args...>;
};

class Goku : public Character<Punch, Kick, Megapunch, Megakick>{
public:
	Goku() : Character(180, "Goku"){

	}
};

int main(){
	Goku player{};
	return 0;
}
