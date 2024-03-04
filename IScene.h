#pragma once
//シーンの種類、必要に応じて順次追加
enum  SCENE {
	TITLE,//タイトル
	STAGE,//ゲームプレイ
	CLEAR,//クリア
	GAMEOVER//ゲームオーバー
};
class IScene {
protected:
	//シーン番号を管理する変数
	static int sceneNo_;

public:
	//継承元で実装される関数
	//抽象クラスなので純粋仮想関数とする
	virtual void Iint() = 0;//初期化のようなもの
	virtual void Update() = 0;//アップデート
	virtual void Draw3D() = 0;//描画
	virtual void Draw2D() = 0;//描画
	
	virtual ~IScene();
	//シーン番号のゲッター
	int GetScene();
};
