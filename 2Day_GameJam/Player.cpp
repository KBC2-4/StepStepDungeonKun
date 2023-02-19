#include "Player.h"
#include"PadInput.h"

Player::Player()
{
	player_x = 0;
	player_y = 0;
	hp = 3;
	button = 0;
	num = 0;
	images_num = 0;
	time = 0;
	player_mistake = false;
	button_flg = false;
	a_button = false;
	b_button = false;
	y_button = false;
	x_button = false;
	/*LoadDivGraph("Resource/Images/Stage/color_tile.png", 4, 2, 2, 25, 25, player_images);*/
}

Player::~Player()
{

}

//-----------------------
//描画処理以外
//-----------------------
void Player::Update()
{
	time++;
	if (images_num > 3)
	{
		images_num = 0;
	}
	//Aボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON && a_button == false)
	{
		button += 1;
		a_button = true;
		button_flg = true;
	}

	//Bボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON && b_button == false)
	{
		button += 0;
		b_button = true;
		button_flg = true;
	}

	//Yボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_Y && PAD_INPUT::GetPadState() == PAD_STATE::ON && y_button == false)
	{
		button += 3;
		y_button = true;
		button_flg = true;
	}

	//Xボタン押したとき
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_X && PAD_INPUT::GetPadState() == PAD_STATE::ON && x_button == false)
	{
		button += 2;
		x_button = true;
		button_flg = true;
	}

	if (button_flg == true)
	{
		++num;
		button_flg = false;
	}

	if (player_mistake == true || time % 600 == 0)
	{
		hp--;
		player_mistake = false;
		time = 0;
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

	//DrawGraph(100, 500, player_images[images_num], false);

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
