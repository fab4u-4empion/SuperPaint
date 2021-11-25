#include <cliext/vector>
#include <windows.h>

using namespace cliext;
using namespace System::Drawing;
using namespace System;

#pragma once
public ref class History {

#pragma region Constructros
	/// <summary>
	/// Конструктор класса History
	/// </summary>
	public: History() {
		this->current = 0;
		this->maxSize = 50;
	}

	/// <summary>
	/// Конструктор класса History
	/// </summary>
	/// <param name="maxSize">Максимальное количество элементов истории. По умолчанию 50.</param>
	public: History(int maxSize) {
		this->current = 0;
		this->maxSize = maxSize;
	}
#pragma endregion

	protected: ~History() {
		delete history;
	}
	
	/// <summary>Элементы истории.</summary>
	private: vector<Bitmap^> history;

	/// <summary>Индекс текущего элемента.</summary>
	private: int current;

	/// <summary>Максимальное количество элементов истории.</summary>
	private: int maxSize;

	/// <summary>
	/// Добавление элемента в историю.
	/// Если текущий элемент истории последний - новый элемент добавляется в конец.
	/// Если текущий элемент не последний - следующие за текущим элементы удаляются, затем новый элемент помещается в конец.
	/// </summary>
	/// <param name="bmp">Добавляемый элемент.</param>
	public: Void push(Bitmap^ bmp);

	/// <summary>
	/// Перемещение назад по истории.
	/// </summary>
	/// <returns>
	/// Теущий элемент после перемещения.
	/// </returns>
	public: Bitmap^ back();

	/// <summary>
	/// Перемещение вперед по истории.
	/// </summary>
	/// <returns>
	/// Теущий элемент после перемещения.
	/// </returns>
	public: Bitmap^ forward();

	/// <summary>
	/// Возможность перемещения назад по истории.
	/// </summary>
	/// <returns>
	/// true, если перемещение возможно.
	/// false, если перемещение невозможно.
	/// </returns>
	public: bool canBack();

	/// <summary>
	/// Возможность перемещения назад по истории.
	/// </summary>
	/// <returns>
	/// true, если перемещение возможно.
	/// false, если перемещение невозможно.
	/// </returns>
	public: bool canForward();

	/// <summary>
	/// Установка максимального количества элементов истории.
	/// </summary>
	/// <param name="maxSize">Максимальное количество элементов истории.</param>
	public: Void setMaxSize(int maxSize);
};

