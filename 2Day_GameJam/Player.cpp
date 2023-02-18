#include "Player.h"
#include"PadInput.h"

Player::Player()
{
	player_x = 0;
	player_y = 0;
	hp = 3;
	a_button=false;
	b_button=false;
	y_button=false;
	x_button=false;
	player_mistake = false;
	
}

Player::~Player()
{

}

//-----------------------
//描画処理以外
//-----------------------
void Player::Update()
{
	//Aボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON)
	{
		a_button = true;
	}
	else //Aボタンが押されていなかったら
	{
		a_button = false;
	}

	//Bボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON)
	{
		b_button = true;
	}
	else //Bボタンが押されていなかったら
	{
		b_button = false;
	}

	//Yボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_Y && PAD_INPUT::GetPadState() == PAD_STATE::ON)
	{
		y_button = true;
	}
	else //Yボタンが押されていなかったら
	{
		y_button = false;
	}

	//Xボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_X && PAD_INPUT::GetPadState() == PAD_STATE::ON)
	{
		x_button = true;
	}
	else //Xボタンが押されていなかったら
	{
		x_button = false;
	}

	if (player_mistake == true)
	{
		hp -= 1;
		player_mistake = false;
	}

}

//-----------------------
//描画処理以外
//-----------------------
void Player::Draw()const
{
	/*if (x_button == true) 
	{
		DrawLine(100, 90, 600, 400, GetColor(255,0,0));
	}*/
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

bool Player::GetButton(int botton)
{
	switch (botton)
	{
	case 1: //Aボタン
		return a_button;
		break;
	case 2: //Bボタン
		return b_button;
		break;
	case 3: //Yボタン
		return y_button;
		break;
	case 4: //Xボタン
		return x_button;
		break;
	default:
		break;
	}
}

void Player::SetMistake(bool a)
{
	player_mistake = a;
}