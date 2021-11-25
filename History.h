#include <cliext/vector>
#include <windows.h>

using namespace cliext;
using namespace System::Drawing;
using namespace System;

#pragma once
public ref class History {

#pragma region Constructros
	/// <summary>
	/// ����������� ������ History
	/// </summary>
	public: History() {
		this->current = 0;
		this->maxSize = 50;
	}

	/// <summary>
	/// ����������� ������ History
	/// </summary>
	/// <param name="maxSize">������������ ���������� ��������� �������. �� ��������� 50.</param>
	public: History(int maxSize) {
		this->current = 0;
		this->maxSize = maxSize;
	}
#pragma endregion

	protected: ~History() {
		delete history;
	}
	
	/// <summary>�������� �������.</summary>
	private: vector<Bitmap^> history;

	/// <summary>������ �������� ��������.</summary>
	private: int current;

	/// <summary>������������ ���������� ��������� �������.</summary>
	private: int maxSize;

	/// <summary>
	/// ���������� �������� � �������.
	/// ���� ������� ������� ������� ��������� - ����� ������� ����������� � �����.
	/// ���� ������� ������� �� ��������� - ��������� �� ������� �������� ���������, ����� ����� ������� ���������� � �����.
	/// </summary>
	/// <param name="bmp">����������� �������.</param>
	public: Void push(Bitmap^ bmp);

	/// <summary>
	/// ����������� ����� �� �������.
	/// </summary>
	/// <returns>
	/// ������ ������� ����� �����������.
	/// </returns>
	public: Bitmap^ back();

	/// <summary>
	/// ����������� ������ �� �������.
	/// </summary>
	/// <returns>
	/// ������ ������� ����� �����������.
	/// </returns>
	public: Bitmap^ forward();

	/// <summary>
	/// ����������� ����������� ����� �� �������.
	/// </summary>
	/// <returns>
	/// true, ���� ����������� ��������.
	/// false, ���� ����������� ����������.
	/// </returns>
	public: bool canBack();

	/// <summary>
	/// ����������� ����������� ����� �� �������.
	/// </summary>
	/// <returns>
	/// true, ���� ����������� ��������.
	/// false, ���� ����������� ����������.
	/// </returns>
	public: bool canForward();

	/// <summary>
	/// ��������� ������������� ���������� ��������� �������.
	/// </summary>
	/// <param name="maxSize">������������ ���������� ��������� �������.</param>
	public: Void setMaxSize(int maxSize);
};

