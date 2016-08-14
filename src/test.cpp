#include <string>
#include <iostream>
#include <stdlib.h>
#include "TypeList.h"
#include "Attack.h"

# define CHARACTER_OF decltype

using std::string;

template <typename... Args>
struct CharacterWithAttacks : public Character{
	CharacterWithAttacks() = default;
	CharacterWithAttacks(int _hp, string _name) : Character(_hp, _name) {}
	using Attacks = TypeList<Args...>;
};

class Goku : public CharacterWithAttacks<Charge, Punch, Kick, Megapunch, Megakick, Dodge, Block>{
public:
	Goku() : CharacterWithAttacks(180, "Goku"){

	}
};



int probabilities[] = {20, 10, 8, 6, 4, 8, 5};

static constexpr int probTotal = 61;

int main(){
	Goku player{};
	Goku enemy{};

	CHARACTER_OF(player)::Attacks::type<0> a;

	while(player.getHp() > 0 && enemy.getHp() > 0){

		// print attacks
		std::cout<<"Use an attack: \n";
		int i = 0;
		while(i < CHARACTER_OF(player)::Attacks::length){
			Attack* m = getAttack(player, i);
			std::cout << i << "\t" << m->name << "\n";
			i++;
		}

		// obtain input
		int in;
		std::cin >> in;
		Attack* playerAttack = getAttack(player, in);

		// check if enough charges
		if(playerAttack->charges > player.charges){
			std::cout << "Not enough charges! You only have "
					<< playerAttack->charges<<" charges\n";
			continue;
		}

		// "AI"
		int r = (rand() % probTotal) + 1;
		int aiIndex = -1;
		while(r > 0){
			aiIndex++;
			r -= probabilities[aiIndex];
		}
		Attack* enemyAttack = getAttack(enemy, aiIndex);
		while(enemyAttack->charges > enemy.charges){
			r = (rand() % probTotal) + 1;
			aiIndex = -1;
			while(r > 0){
				r -= probabilities[aiIndex];
				aiIndex++;
			}
			enemyAttack = getAttack(enemy, aiIndex);
		}

		// handle attacks
		playerAttack->doAttack(player, enemy);
		enemyAttack->doAttack(enemy, player);

		player.handlePendingAttacks();
		enemy.handlePendingAttacks();

		// print that shit out
		std::cout << std::endl;
		std::cout << "You used " << playerAttack->name << std::endl;
		std::cout << "Opponent used " << enemyAttack->name << std::endl;
		std::cout << "Your HP: " << player.hp << " | Charges: " << player.charges << std::endl;
		std::cout << "Enemy HP: " << enemy.hp << " | Charges: " << enemy.charges << std::endl;
		std::cout << std::endl;

	}
	return 0;
}
