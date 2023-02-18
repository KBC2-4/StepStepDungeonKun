#include "Player.h"
#include"PadInput.h"

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
	//Aボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON)
	{

	}
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