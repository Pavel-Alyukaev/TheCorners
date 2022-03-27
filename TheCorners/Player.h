// ****************************************************************************
//  Player.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once

class Figure;
class Player
{
public:
	Player();

	void Init();

	void SetActive();
	void SetPassive();

	void UnselectAllFigure();

	std::vector<std::shared_ptr<Figure>> GetFigure();
	void Update(float dtAsSeconds);

	void SetScale(float scale);
	int GetindexSelectedFigure();


private:
	bool m_isActive;

	std::vector<std::shared_ptr<Figure>> m_figures;



	float m_scale;
};


