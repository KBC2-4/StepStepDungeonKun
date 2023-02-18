#include "Player.h"
#include"PadInput.h"

Player::Player()
{
	player_x = 0;
	player_y = 0;
	hp = 3;
	button = 0;
	num = 0;
	player_mistake = false;
	button_flg = false;
	a_button = false;
	b_button = false;
	y_button = false;
	x_button = false;

}

Player::~Player()
{

}

//-----------------------
//描画処理以外
//-----------------------
void Player::Update()
{

	if (num >= 2)
	{
		Reset();
	}

	//Aボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::DOWN && a_button == false)
	{
		button += 1;
		a_button = true;
		button_flg = true;
	}

	//Bボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::DOWN && b_button == false)
	{
		button += 2;
		b_button = true;
		button_flg = true;
	}

	//Yボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_Y && PAD_INPUT::GetPadState() == PAD_STATE::DOWN && y_button == false)
	{
		button += 3;
		y_button = true;
		button_flg = true;
	}

	//Xボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_X && PAD_INPUT::GetPadState() == PAD_STATE::DOWN && x_button == false)
	{
		button += 4;
		x_button = true;
		button_flg = true;
	}
	if (button_flg == true)
	{
		++num;
		button_flg = false;
	}

}

//-----------------------
//描画処理以外
//-----------------------
void Player::Draw()const
{
	DrawFormatString(200, 200, GetColor(255, 0, 0), "%d", button);
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

//-----------------------
//各ボタンのフラグを取得する
//-----------------------

int  Player::GetButton()
{
	return button;
}

void Player::SetMistake(bool a)
{
	player_mistake = a;
}

void Player::Reset()
{
	a_button = false;
	b_button = false;
	y_button = false;
	x_button = false;
	button = 0;
	num = 0;
}
