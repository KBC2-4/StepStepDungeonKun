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

	//リソース
	int background_image;

	int bgm;

	//各クラスオブジェクト


};