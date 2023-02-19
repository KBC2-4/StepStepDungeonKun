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

	int count_font;

	//�J�n�܂ł̎���
	int start_time;

	//1�^�C��������̐�������
	int answer;

	//���\�[�X
	int background_image;

	int bgm;
	
	//�e�N���X�I�u�W�F�N�g
	Player* player;
	Stage* stage;

};