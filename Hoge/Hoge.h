#pragma once

template <typename T1, typename T2>
class Hoge {

public:

	Hoge(T1 a, T2 b) : a(a), b(b) {}

	T1 Min() { return a < b ? a : static_cast<T1>(b); }

private:
	T1 a;
	T2 b;
};