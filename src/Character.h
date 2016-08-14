#include <string>

using std::string;

struct Character{
	int hp;
	int charges = 0;

	bool blocking = false;
	bool dodging = false;
	int pendingDamage = 0;

	string name;

	Character() = default;
	Character(int _hp, string _name){
		hp = _hp;
		name = _name;
	}
	int getHp(){
		return hp;
	}
	int addCharge(int add = 1){
		charges += add;
		return charges;
	}
	int decreaseCharge(int dec){
		charges -= dec;
		return charges;
	}
	int decreaseHp(int amount){
		hp -= amount;
		return hp;
	}

	void handlePendingAttacks(){
		if(!blocking && !dodging){
			hp -= pendingDamage;
		}
		blocking = false;
		dodging = false;
		pendingDamage = 0;
	}

};
