#include "Player.h"

Player::Player()
{
	player_x = 0;
	player_y = 0;
	player_mistake = false;
}

//-----------------------
//描画処理以外
//-----------------------
void Player::Update() 
{
	
}

//-----------------------
//描画処理以外
//-----------------------
void Player::Draw()const
{

}

//-----------------------
//HPチェック処理
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