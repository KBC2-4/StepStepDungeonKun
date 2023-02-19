#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Stage.h"

enum class TILES {
	NONE,
	RED,
	GREEN,
	BLUE,
	YELLOW
};


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

	int guid_font;

	//開始までの時間
	int start_time;

	//1タイル当たりの制限時間
	int answer_time;

	//進んだ距離(1歩1m)
	int distance;

	enum class Answer {
		unanswered, //未回答
		wrong,		//不正解
		correct,	//正解
	};

	Answer answer;

	//リソース
	int background_image;

	//サウンドハンドル
	int correct_se;
	int wrong_se;
	int background_music;
	int tile_se[4];
	
	//各クラスオブジェクト
	Player* player;
	Stage* stage;

};