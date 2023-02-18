#include "Player.h"
#include"PadInput.h"

Player::Player()
{
	player_x = 0;
	player_y = 0;
	hp = 0;
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
//�`�揈���ȊO
//-----------------------
void Player::Update()
{
	//A�{�^���������Ƃ�
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON)
	{
		a_button = true;
	}
	else //A�{�^����������Ă��Ȃ�������
	{
		a_button = false;
	}

	//B�{�^���������Ƃ�
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON)
	{
		b_button = true;
	}
	else //B�{�^����������Ă��Ȃ�������
	{
		b_button = false;
	}

	//Y�{�^���������Ƃ�
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_Y && PAD_INPUT::GetPadState() == PAD_STATE::ON)
	{
		y_button = true;
	}
	else //Y�{�^����������Ă��Ȃ�������
	{
		y_button = false;
	}

	//X�{�^���������Ƃ�
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_X && PAD_INPUT::GetPadState() == PAD_STATE::ON)
	{
		x_button = true;
	}
	else //X�{�^����������Ă��Ȃ�������
	{
		x_button = false;
	}
}

//-----------------------
//�`�揈���ȊO
//-----------------------
void Player::Draw()const
{
	if (x_button == true) 
	{
		DrawLine(100, 90, 600, 400, GetColor(255,0,0));
	}
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