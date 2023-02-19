#include "Player.h"
#include"PadInput.h"
#define _USE_MATH_DEFINES
#include <math.h>

Player::Player()
{
	player_x = 0;
	player_y = 0;
	hp = 3;
	button = 0;
	num = 0;
	images_num = 0;
	player_mistake = false;
	button_flg = false;
	a_button = false;
	b_button = false;
	y_button = false;
	x_button = false;
	LoadDivGraph("Resource/Images/Player/human.png", 4, 4, 1, 30, 60, player_images);
}

Player::~Player()
{

}

//-----------------------
//描画処理以外
//-----------------------
void Player::Update()
{
	if (images_num > 3)
	{
		images_num = 0;
		Reset();
	}
	//次のタイルの色[0:赤, 1:緑, 2:青, 3:黄]
	//Aボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON && a_button == false)
	{
		button += 2;
		a_button = true;
		button_flg = true;
	}

	//Bボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON && b_button == false)
	{
		button += 1;
		b_button = true;
		button_flg = true;
	}

	//Yボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_Y && PAD_INPUT::GetPadState() == PAD_STATE::ON && y_button == false)
	{
		button += 4;
		y_button = true;
		button_flg = true;
	}

	//Xボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_X && PAD_INPUT::GetPadState() == PAD_STATE::ON && x_button == false)
	{
		button += 3;
		x_button = true;
		button_flg = true;
	}

	if (button_flg == true)
	{
		++num;
		button_flg = false;
	}

	if (player_mistake == true)
	{
		hp--;
		player_mistake = false;
	}

}

//-----------------------
//描画処理以外
//-----------------------
void Player::Draw()const
{
	DrawFormatString(200, 200, GetColor(255, 0, 0), "%d", button);
	DrawFormatString(500, 500, GetColor(255, 255, 255), "%d", num);
	DrawFormatString(700, 300, GetColor(255, 255, 0), "%d",hp );

	DrawRotaGraph(100 , 400, 1.0, M_PI / 180 * 0, player_images[images_num], TRUE);

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


int Player::Getnum()
{
	return num;
}

void Player::SetImagesNum(int a)
{
	images_num += a;
}
