#pragma once

class Player
{
private:
	float player_x; //プレイヤー座標
	float player_y; //プレイヤー座標
	int hp; //使うかわからんけど
	int time;
	int button; //数字で管理します、
	int num;
	int player_images[4];
	int images_num;
	bool player_mistake; //プレイヤーがミスをしたらtrue
	bool button_flg; 
	bool a_button; //aボタンのフラグ
	bool b_button; //bボタンのフラグ
	bool y_button; //yボタンのフラグ
	bool x_button; //xボタンのフラグ
	
public:

	Player(); //コンストラクタ
	~Player(); //デストラクタ //未定

	void Update(); //描画以外の処理
	void Draw()const; //描画のみko
	int Getnum();
	bool CheckHp(); //HPをチェック処理
	void Reset();
	int  GetButton(); // 1,Aボタン 2,Bボタン  3,Yボタン 4,Xボタン
	void SetMistake(bool a); //フラグを設定する
	void SetImagesNum(int a);

};

