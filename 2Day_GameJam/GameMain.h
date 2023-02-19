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

	//開始までの時間
	int start_time;

	//1タイル当たりの制限時間
	int answer;

	//リソース
	int background_image;

	int bgm;
	
	//各クラスオブジェクト
	Player* player;
	Stage* stage;

};