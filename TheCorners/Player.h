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

	virtual void Init();

	void SetActive();
	void SetPassive();

	bool IsActive() const;

	void UnselectAllFigure();

	std::vector<std::shared_ptr<Figure>> GetFigures();
	void Update(float dtAsSeconds);

	void SetScale(float scale);
	int GetIndexSelectedFigure();

protected:
	std::vector<std::shared_ptr<Figure>> m_figures;
	float m_scale;

private:
	bool m_isActive;
};
