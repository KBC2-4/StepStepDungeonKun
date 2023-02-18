#pragma once

class Player
{
private:
	float player_x; //プレイヤー座標
	float player_y; //プレイヤー座標
	int hp; //使うかわからんけど
	bool player_mistake; //プレイヤーがミスをしたらtrue
public:

	Player(); //コンストラクタ
	~Player(); //デストラクタ //未定

	
	void Update(); //描画以外の処理
	void Draw()const; //描画のみ
	bool CheckHp();
};

