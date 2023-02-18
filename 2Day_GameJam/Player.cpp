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

	if (player_mistake == true)
	{
		hp -= 1;
		player_mistake = false;
	}

}

//-----------------------
//�`�揈���ȊO
//-----------------------
void Player::Draw()const
{
	/*if (x_button == true) 
	{
		DrawLine(100, 90, 600, 400, GetColor(255,0,0));
	}*/
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

bool Player::GetButton(int botton)
{
	switch (botton)
	{
	case 1: //A�{�^��
		return a_button;
		break;
	case 2: //B�{�^��
		return b_button;
		break;
	case 3: //Y�{�^��
		return y_button;
		break;
	case 4: //X�{�^��
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