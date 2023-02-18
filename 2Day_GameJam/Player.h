#pragma once

class Player
{
private:
	float player_x; //プレイヤー座標
	float player_y; //プレイヤー座標
	int hp; //使うかわからんけど
	bool player_mistake; //プレイヤーがミスをしたらtrue
	bool a_button; //aボタンのフラグ
	bool b_button; //bボタンのフラグ
	bool y_button; //yボタンのフラグ
	bool x_button; //xボタンのフラグ

public:

	Player(); //コンストラクタ
	~Player(); //デストラクタ //未定

	void Update(); //描画以外の処理
	void Draw()const; //描画のみ
	bool CheckHp(); //HPをチェック処理
	bool GetButton(int botton); // 1,Aボタン 2,Bボタン  3,Yボタン 4,Xボタン
	void SetMistake(bool a); //フラグを設定する
};

