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
//�`�揈���ȊO
//-----------------------
void Player::Update()
{

	if (num >= 2)
	{
		Reset();
	}

	//A�{�^���������Ƃ�
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::DOWN && a_button == false)
	{
		button += 1;
		a_button = true;
		button_flg = true;
	}

	//B�{�^���������Ƃ�
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::DOWN && b_button == false)
	{
		button += 2;
		b_button = true;
		button_flg = true;
	}

	//Y�{�^���������Ƃ�
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_Y && PAD_INPUT::GetPadState() == PAD_STATE::DOWN && y_button == false)
	{
		button += 3;
		y_button = true;
		button_flg = true;
	}

	//X�{�^���������Ƃ�
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
//�`�揈���ȊO
//-----------------------
void Player::Draw()const
{
	DrawFormatString(200, 200, GetColor(255, 0, 0), "%d", button);
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

//-----------------------
//�e�{�^���̃t���O���擾����
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
