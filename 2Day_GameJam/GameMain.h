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

	//���\�[�X
	int background_image;

	int bgm;

	//�e�N���X�I�u�W�F�N�g


};