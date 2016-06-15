#pragma once

#include <windows.h>
#include <iostream>
#include <string>

const double PI = 3.1415926535897;

class Shape {
public:
	Shape(double x0 = 100, double y0 = 150, double rotate = 0, double rotateAngle = 0,
		double shapeSpeed = 0, std::string way = "right", COLORREF color = WHITE_PEN)
		:_x0(x0), _y0(y0), _rotate(rotate), _rotateAngle(rotateAngle),
		_shapeSpeed(shapeSpeed), _way(way), _color(color) {}

	virtual void getRotateOfShape(double, double) = 0;

	virtual void move(RECT) = 0;

	virtual void paint(HDC) = 0;

	virtual void clear(HWND, HDC, RECT) = 0;

	virtual ~Shape() = default;

protected:
	virtual void rotate() = 0;

	virtual void draw(HDC, POINT) = 0;

protected:
	double _x0, _y0;
	double _rotate;
	double _rotateAngle;
	double _shapeSpeed;
	std::string _way;
	POINT _point;
	COLORREF _color;
};

class Line : public Shape {
public:
	Line(double x0 = 100, double y0 = 150, double rotate = 0, double rotateAngle = 0,
		double shapeSpeed = 0, std::string way = "right", double lenght = 10, COLORREF color = WHITE_PEN)
		:Shape(x0, y0, rotate, rotateAngle, shapeSpeed, way, color), _lenght(lenght) {}

	void getRotateOfShape(double rotateAngle, double rotate) {
		_rotate = rotate;
		_rotateAngle = rotateAngle;
	}

	void move(RECT rect) {
		if (_way == "right")
			_x0 += _shapeSpeed;
		else if (_way == "left")
			_x0 -= _shapeSpeed;
		else if (_way == "top")
			_y0 -= _shapeSpeed;
		else if (_way == "bottom")
			_y0 += _shapeSpeed;
		if (_x0 > rect.right - _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 > rect.right + _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 < rect.left - _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 < rect.left + _lenght * cos(_rotate * PI / 180) / 2 ||
			_y0 < rect.top - _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 < rect.top + _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 > rect.bottom - _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 > rect.bottom + _lenght * sin(_rotate * PI / 180) / 2) {
			_shapeSpeed = -_shapeSpeed;
			_rotateAngle = -_rotateAngle;
		}
		rotate();
	}

	void paint(HDC hdc) {
		pen = CreatePen(PS_SOLID, 1, _color);
		SelectObject(hdc, pen);
		draw(hdc, _point);
		DeleteObject(pen);
	}

	void clear(HWND hWindow, HDC hdc, RECT rect) {
		pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		SelectObject(hdc, pen);
		draw(hdc, _point);
		DeleteObject(pen);
	}

	~Line() = default;

private:
	void rotate() {
		_rotate += _rotateAngle;
		_angle = _rotate * PI / 180;
		_dots[0].x = _x0 + _lenght * cos(_angle) / 2;
		_dots[0].y = _y0 - _lenght * sin(_angle) / 2;
		_dots[1].x = _x0 - _lenght * cos(_angle) / 2;
		_dots[1].y = _y0 + _lenght * sin(_angle) / 2;
	}

	void draw(HDC hdc, POINT point) {
		MoveToEx(hdc, _dots[0].x, _dots[0].y, &point);
		LineTo(hdc, _dots[1].x, _dots[1].y);
	}

private:
	double _lenght;
	double _angle;
	POINT _dots[2];
	HPEN pen;
};






class Parallelogram : public Shape {
public:

	Parallelogram(double x0 = 100, double y0 = 150, double rotate = 0, double rotateAngle = 0,
		double shapeSpeed = 0, std::string way = "right", double edge1 = 10, double edge2 = 15, double alpha = 60, COLORREF color = WHITE_PEN)
		:Shape(x0, y0, rotate, rotateAngle, shapeSpeed, way, color), _edge1(edge1), _edge2(edge2), _alpha(alpha) {
		_diagonal1 = sqrt(pow(_edge1, 2) + pow(_edge2, 2) - 2 * _edge1 * _edge2 * cos((180 - _alpha) * PI / 180));
		_diagonal2 = sqrt(pow(_edge1, 2) + pow(_edge2, 2) - 2 * _edge1 * _edge2 * cos(_alpha * PI / 180));
		_height = _edge1 * sin(_alpha * PI / 180);
	}

	void getRotateOfShape(double rotateAngle, double rotate) {
		_rotate = rotate;
		_rotateAngle = rotateAngle;
	}

	void move(RECT rect) {
		if (_way == "right")
			_x0 += _shapeSpeed;
		else if (_way == "left")
			_x0 -= _shapeSpeed;
		else if (_way == "top")
			_y0 -= _shapeSpeed;
		else if (_way == "bottom")
			_y0 += _shapeSpeed;
		if (_x0 > rect.right ||
			_x0 < rect.left ||
			_y0 < rect.top ||
			_y0 > rect.bottom) {
			_shapeSpeed = -_shapeSpeed;
			_rotateAngle = -_rotateAngle;
		}
		rotate();
	}

	void paint(HDC hdc) {
		if (isParallel()) {
			_brush = CreateSolidBrush(_color);
			draw(hdc, _point);
			DeleteObject(_brush);
		}
		else {
			TextOut(hdc, _x0, _y0, L"ERROR", strlen("ERROR"));
		}
	}

	void clear(HWND hWindow, HDC hdc, RECT rect) {
		if (isParallel()) {
			_brush = CreateSolidBrush(RGB(0, 0, 0));
			draw(hdc, _point);
			DeleteObject(_brush);
		}
		else {
			TextOut(hdc, _x0, _y0, L"     ", strlen("     "));
		}
	}

	~Parallelogram() = default;

private:
	bool isParallel() {
		if (_alpha == 90 || _edge1 == _edge2)
			return false;
		return true;
	}

	void rotate() {
		_rotate += _rotateAngle;
		_alpha1 = (pow(_edge1, 2) + (pow(_diagonal2, 2) - pow(_diagonal2, 2)) / 4) / (_edge1 * _diagonal1);
		_gamma = acos((pow(_edge1, 2) + (pow(_diagonal2, 2) - pow(_diagonal1, 2)) / 4) / (_edge1 * _diagonal2));
		double beta1 = asin(_edge1 * sin(_alpha * PI / 180) / _diagonal1);
		double beta2 = 180 - _alpha1 - _gamma;
		_dots[0].x = _x0 - (_diagonal2 / 2) * cos((beta2 + _rotate) * PI / 180);
		_dots[0].y = _y0 - (_height / 2) * sin(_rotate * PI / 180);
		_dots[1].x = _x0 + (_diagonal1 / 2) * cos((beta1 + _rotate) * PI / 180);
		_dots[1].y = _y0 - (_height / 2) * sin(_rotate * PI / 180);
		_dots[2].x = _x0 + (_diagonal2 / 2) * cos((beta2 + _rotate) * PI / 180);
		_dots[2].y = _y0 + (_height / 2) * sin(_rotate * PI / 180);
		_dots[3].x = _x0 - (_diagonal1 / 2) * cos((beta1 + _rotate)* PI / 180);
		_dots[3].y = _y0 + (_height / 2) * sin(_rotate * PI / 180);
	}

	void draw(HDC hdc, POINT _point) {
		BeginPath(hdc);
		Polyline(hdc, _dots, 4);
		CloseFigure(hdc);
		EndPath(hdc);
		SelectObject(hdc, _brush);
		SetPolyFillMode(hdc, WINDING);
		FillPath(hdc);
	}

private:
	double _edge1, _edge2, _gamma;
	double _alpha, _alpha1;
	POINT _dots[4];
	HBRUSH _brush;
	double _diagonal1, _diagonal2, _height;
};





class Triangle : public Shape {
public:
	Triangle(double x0 = 100, double y0 = 150, double rotate = 0, double rotateAngle = 0,
		double shapeSpeed = 0, std::string way = "right", double lenght = 100, COLORREF color = WHITE_PEN)
		:Shape(x0, y0, rotate, rotateAngle, shapeSpeed, way, color), _lenght(lenght) {}

	void getRotateOfShape(double rotate, double rotateAngle) {
		_rotate = rotate;
		_rotateAngle = rotateAngle;
	}

	void move(RECT rect) {
		if (_way == "right")
			_x0 += _shapeSpeed;
		else if (_way == "left")
			_x0 -= _shapeSpeed;
		else if (_way == "top")
			_y0 -= _shapeSpeed;
		else if (_way == "bottom")
			_y0 += _shapeSpeed;
		if (_x0 > rect.right - _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 > rect.right + _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 < rect.left - _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 < rect.left + _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 < rect.left - _lenght * sin(_rotate * PI / 180) / 2 ||
			_x0 < rect.left + _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 < rect.top - _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 < rect.top + _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 > rect.bottom - _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 > rect.bottom + _lenght * sin(_rotate * PI / 180) / 2) {
			_shapeSpeed = -_shapeSpeed;
			_rotateAngle = -_rotateAngle;
		}
		rotate();
	}

	void paint(HDC hdc) {
		_brush = CreateSolidBrush(_color);
		draw(hdc, _point);
		DeleteObject(_brush);
	}

	void clear(HWND hWindow, HDC hdc, RECT rect) {
		_brush = CreateSolidBrush(RGB(0, 0, 0));
		draw(hdc, _point);
		DeleteObject(_brush);
	}

	~Triangle() = default;

private:
	void rotate() {
		_rotate += _rotateAngle;
		_dots[0].x = _x0 - _lenght * cos((45 + _rotate) * PI / 180) / 2;
		_dots[0].y = _y0 - _lenght * sin((45 + _rotate) * PI / 180) / 2;
		_dots[1].x = _x0 - _lenght * cos((45 - 90 + _rotate) * PI / 180) / 2;
		_dots[1].y = _y0 - _lenght * sin((45 - 90 + _rotate) * PI / 180) / 2;
		_dots[2].x = _x0 - _lenght * cos((45 - 180 + _rotate) * PI / 180) / 2;
		_dots[2].y = _y0 - _lenght * sin((45 - 180 + _rotate) * PI / 180) / 2;
	}

	void draw(HDC hdc, POINT _point) {
		BeginPath(hdc);
		Polyline(hdc, _dots, 3);
		CloseFigure(hdc);
		EndPath(hdc);
		SelectObject(hdc, _brush);
		SetPolyFillMode(hdc, WINDING);
		FillPath(hdc);
	}

private:
	double _lenght;
	double _angle;
	POINT _dots[3];
	HBRUSH _brush;
};
