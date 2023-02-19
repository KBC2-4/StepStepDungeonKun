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

	//スタート時のカウントダウン用フォントハンドル
	int start_count_font;

	//1タイル当たりの制限時間用フォントハンドル
	int answer_count_font;

	//開始までの時間
	int start_time;

	//1タイル当たりの制限時間
	int answer_time;

	//進んだ距離(1歩1m)
	int distance;

	//リソース
	int background_image;

	int bgm;
	
	//各クラスオブジェクト
	Player* player;
	Stage* stage;

};