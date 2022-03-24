#pragma once
#include "checker.h"

//КЛАСС КЛЕТКА
class Cell {
	Checker* _checker;           //это указатель на шашку
	bool _possibleMove = false;  //bool можно ли сходить на эту клетку или нельзя


	Checker* getChecker() { return _checker; } //возвращает указатель на шашку

	void setChecker(CheckerColor b_or_w) { _checker = new Checker(b_or_w); } //установить шашку на эту клетку по цвету

public:

	//Тут 2 конструктора
	ActiveCell() {} //этот используется тогда, когда на этой клетке нет шашки, просто выделяем память
	ActiveCell(CheckerColor b_or_w); //а этот используется тогда, когда на этой клетке есть шашка

	void drawCell(); //просто рисовка клетки
	void drawFrame(); //рисовка рамки (используется для рисовки рамок тех клеток, на которые можно сходить)

	bool isSelected(); //возвращает выделена ли шашка на этой клетке (true) или нет(false)
	bool isPossible() { return _possibleMove; } //возможен ли ход на эту клетку
	bool isFree();      //есть ли на этой клетке есть шашка (возвращает HAS_CHECKER из enum), если нет (HAS_NO_CHECKER)

	void selectChecker(); //выбрать клетку
	void selectCheckerOFF() { getChecker()->CheckerSelectOFF(); } //убрать выделение

	void setPost(CheckerHierarchy post); //установить должность для шашки

	void makePossibleMove() { _possibleMove = true; } //установить возможность хода на клетку 
	void makeImPossibleMove() { _possibleMove = false; } //установить невозможность хода на эту клетку

	//Получение цвета или должности 
	CheckerColor getCheckerColor();
	CheckerHierarchy getCheckerPost();

};
