// PAlogrithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <memory>

#include <Windows.h>

using namespace std;

CRITICAL_SECTION cs;


class CLock {
public:
	typedef void (CLock::*tBoolCast)();

public:
	CLock();
	CLock(CRITICAL_SECTION & _Section);
	CLock(CLock & _Rhs);
	CLock & operator = (CRITICAL_SECTION & _Section);
	CLock & operator = (CLock & _Rhs);
	~CLock();

	operator tBoolCast () const;

	void Release();

protected:
	CRITICAL_SECTION * m_Section;
};


CLock::CLock()
	: m_Section(0) {
}

CLock::CLock(CRITICAL_SECTION & _Section)
	: m_Section(&_Section) {
	if (m_Section)
		EnterCriticalSection(m_Section);
}

CLock::CLock(CLock & _Rhs)
	: m_Section(_Rhs.m_Section) {
	_Rhs.m_Section = 0;
}

CLock & CLock::operator = (CRITICAL_SECTION & _Section) {
	if (&_Section != m_Section) {
		Release();
		m_Section = &_Section;
		if (m_Section)
			EnterCriticalSection(m_Section);
	}
	return *this;
}

CLock & CLock::operator = (CLock & _Rhs) {
	if (&_Rhs != this) {
		Release();
		m_Section = _Rhs.m_Section;
		_Rhs.m_Section = 0;
	}
	return *this;
}

CLock::~CLock() {
	Release();
}

CLock::operator CLock::tBoolCast() const {
	if (m_Section)
		return &CLock::Release;
	else
		return 0;
}

void CLock::Release() {
	if (m_Section) {
		LeaveCriticalSection(m_Section);
		m_Section = NULL;
	}
}


int main()
{
	cout << "hi";

	InitializeCriticalSection(&cs);

	{
		CLock l(cs);
	}

	{
		CLock l(cs);
	}

	{
		CLock l(cs);
	}

	{
		CLock l(cs);
	}
	{
		CLock l(cs);
	}

	
    return 0;
}

