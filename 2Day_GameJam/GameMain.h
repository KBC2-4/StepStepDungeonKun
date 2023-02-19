#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Stage.h"


class GameMain : public AbstractScene
{
public:
	GameMain();
	~GameMain();
	AbstractScene* Update() override;
	void Draw() const override;
private:

	//�X�^�[�g���̃J�E���g�_�E���p�t�H���g�n���h��
	int start_count_font;

	//1�^�C��������̐������ԗp�t�H���g�n���h��
	int answer_count_font;

	//�J�n�܂ł̎���
	int start_time;

	//1�^�C��������̐�������
	int answer_time;

	//�i�񂾋���(1��1m)
	int distance;

	//���\�[�X
	int background_image;

	int bgm;
	
	//�e�N���X�I�u�W�F�N�g
	Player* player;
	Stage* stage;

};