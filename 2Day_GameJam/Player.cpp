#include "Player.h"

Player::Player()
{
	player_x = 0;
	player_y = 0;
	player_mistake = false;
}

//-----------------------
//�`�揈���ȊO
//-----------------------
void Player::Update() 
{
	
}

//-----------------------
//�`�揈���ȊO
//-----------------------
void Player::Draw()const
{

}

//-----------------------
//HP�`�F�b�N����
//-----------------------
bool Player::CheckHp()
{
	if (hp < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}