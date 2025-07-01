#pragma once

#include <iostream>
#include <cstdlib>	// srand()
#include <typeinfo>	// std::bad_cast

class Base
{
	private:
	public:
		virtual	~Base();
};

class A : public Base
{
	private:
	public:
};

class B : public Base
{
	private:
	public:
};

class C : public Base
{
	private:
	public:
};

/* subject: These four classes don’t have to be designed in the Orthodox Canonical Form.*/