#include "cell.h"

//конструктор (второй) класса активной шашки
Cell::Cell(CheckerColor b_or_w) {
	setChecker(b_or_w); //устанавливает шашку на эту клетку, запускается конструктор класса "Checker"
}

//есть ли на этой клетке шашка
bool Cell::isFree() {
	if (getChecker() != nullptr) { //через getChecker мы возвращаем указатель на шашку, и если указатель не равен NULL
		return HAS_CHECKER; //То возвраащем HAS_CHECKER
	}
	else //если null, то возвращаем шашки_нет
		return HAS_NO_CHECKER;
}

//выделена ли эта клетка или нет
//используется тогда, когда программе нужно найти возможные ходы для этой шашки
bool Cell::isSelected() {
	if (isFree() == HAS_CHECKER) //если на клетке есть шашка
		return getChecker()->isSelected(); //то возвращаем информацию о выделении этой шашки (выделена или нет она)
	else
		return false;
}
//PS getChecker()->isSelected() вызывает функцию isSelected класса Checker!

//Опять проверка
void Cell::selectChecker() {
	if (isFree() == HAS_CHECKER) //если на клетке есть шашка
		getChecker()->CheckerSelect(); //то мы вызываем функцию выделения ДЛЯ ЭТОЙ ШАШКИ
}

//получить цвет
CheckerColor Cell::getCheckerColor() {
	if (isFree() == HAS_CHECKER) //если на клетке есть шашка
		return getChecker()->getColor(); //получаем ее цвет
	else
		return EXCEPTION_COLOR; //если шашки нет то исключение
}

//устанавливает должность
void Cell::setPost(CheckerHierarchy post) {
	if (isFree() == HAS_CHECKER) { //если есть шашка на клетке
		getChecker()->setPost(post); //вызываем функцию для этой шашки setPost(post)
	}
}

//получить должность
CheckerHierarchy Cell::getCheckerPost() {
	if (isFree() == HAS_CHECKER)
		return getChecker()->getPost();
	else
		return EXCEPTION_POST;
}

//рисовка рамки зеленого цвета по краям клетки
void Cell::drawFrame() {
	glLineWidth(4.0); //толщина линии
	glBegin(GL_LINE_STRIP); //рисует линию
	glColor3f(0, 1, 0);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glEnd();
}
