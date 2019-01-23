#ifndef _BIGINT
#define _BIGINT


#include <bits/stdc++.h>
using namespace std;
struct bigint {
	static const long long BASE = 1000000000;
	static const long long WIDTH = 9;
	vector<long long> s;
	bool flag;
	bigint(long long num = 0) {
		*this = num;    // 构造函数
	}
	bigint operator = (long long num) {
		// 赋值运算符
		s.clear();
		if (num < 0) {
			flag = 0;
			num = -num;
		} else
			flag = 1;
		do {
			s.push_back(num % BASE);
			num /= BASE;
		} while (num > 0);
		return *this;
	}
	bigint operator = (const string &str) {
		// 赋值运算符
		s.clear();
		if (str[0] == '-')
			flag = 0;
		else
			flag = 1;
		string strr = str;
		if (flag == 0)
			strr.erase(0, 1);
		long long x, len = (strr.length() - 1) / WIDTH + 1;
		long long i = 0;
		for (; i < len; i++) {
			long long end = strr.length() - i * WIDTH;
			long long start = max(0ll, end - WIDTH);
			sscanf(strr.substr(start, end - start).c_str(), "%lld", &x);
			s.push_back(x);
		}
		return *this;
	}
	bigint operator + (const bigint &b) const {
		bigint c, d;
		if (b.flag == 0) {
			bigint B = b;
			B.flag = 1;
			if (flag == 0) {
				d = *this;
				d.flag = 1;
				c = d + B;
				c.flag = 0;
				return c;
			}
			return *this - B;
		}
		if (flag == 0) {
			c = *this;
			c.flag = 1;
			return b - c;
		}
		c.s.clear();
		for (int i = 0, g = 0;; i++) {
			if (g == 0 && i >= s.size() && i >= b.s.size())
				break;
			long long x = g;
			if (i < s.size())
				x += s[i];
			if (i < b.s.size())
				x += b.s[i];
			c.s.push_back(x % BASE);
			g = x / BASE;
		}
		return c;
	}

	bigint operator * (const bigint &b) const {
		bigint c, t;
		c = 0;
		long long flagg;
		if (b.flag == flag)
			flagg = 1;
		else
			flagg = 0;
		t.flag = 1;
		c.flag = 1;
		for (int i = 0; i < s.size(); i++) {
			t.s.clear();
			long long x, g;
			long long j;
			t.s.insert(t.s.begin(), i, 0);
			for (j = g = 0;; j++) {
				x = g;
				if (g == 0 && j >= b.s.size()) {
					break;
				}
				if (j < b.s.size())
					x += (long long)s[i] * (long long)b.s[j];
				t.s.push_back(x % BASE);
				g = x / BASE;
			}
			c = c + t;
		}
		c.flag = flagg;
		if (c.s.back() == 0) {
			vector<long long>::iterator it = c.s.end();
			for (it--; it != c.s.begin(); it--) {
				if (*it != 0)
					break;
			}
			it++;
			c.s.erase(it, c.s.end());
		}
		if (c.s.empty())
			c.s.push_back(0);
		return c;
	}
	bigint operator * (const int &b) const {
		bigint c = b;
		return c * (*this);
	}
	bigint operator * (const long long &b) const {
		bigint c = b;
		return c * (*this);
	}
	bigint operator ^ (int b) const {
		bigint ans = 1, base = *this;
		while (b) {
			if (b & 1) {
				ans = base * ans;
			}
			base = base * base;
			b >>= 1;
		}
		return ans;
	}
	bigint operator += (const bigint &b) const {
		return *this + b;
	}
	bool operator < (const bigint &b) const {
		if (b.flag == 0 && b.flag != flag)
			return false;
		if (s.size() != b.s.size())
			return s.size() < b.s.size();
		for (int i = s.size() - 1; i >= 0; i--)
			if (s[i] != b.s[i])
				return s[i] < b.s[i];
		return false;
	}
	bool operator > (const bigint &b) const {
		return b < *this;
	}
	bool operator <= (const bigint &b) const {
		return !(b < *this);
	}
	bool operator >= (const bigint &b) const {
		return !(*this < b);
	}
	bool operator != (const bigint &b) const {
		return b < *this || *this < b;
	}
	bool operator == (const bigint &b) const {
		return !(b < *this) && !(*this < b);
	}

	bigint operator - (const bigint &b) const {
		if (b.flag == 0) {
			bigint B = b;
			B.flag = 1;
			return *this + B;
		}
		bigint A, B;
		A = *this;
		B = b;
		A.flag = 1;
		B.flag = 1;
		bigint c;
		if (A < B) {
			swap(A, B);
			c.flag = 0;
		}
		c.s.clear();
		long long i, g, x;
		i = g = 0;
		while (1) { //for (int i = 0, g = 0;; i++)
			if (i >= A.s.size() && i >= B.s.size())
				break;
			x = A.s[i];
			x -= g;
			g = 0;
			if (i < B.s.size())
				x -= B.s[i];
			if (x < 0) {
				x += BASE;
				g = 1;
			}
			c.s.push_back(x % BASE);
			i++;
		}
		if (c.s.back() == 0) {
			vector<long long>::iterator it = c.s.end();
			for (it--; it != c.s.begin(); it--) {
				if (*it != 0)
					break;
			}
			it++;
			c.s.erase(it, c.s.end());
		}
		if (c.s.empty())
			c.s.push_back(0);
		return c;
	}
	bigint operator - (const int &b) const {
		bigint c = b;
		return *this - c;
	}
	bigint operator - (const long long &b) const {
		bigint c = b;
		return *this - c;
	}
	bigint operator -= (const bigint &b) const {
		return *this - b;
	}
	bigint operator ! (void)const { //阶乘
		bigint ans = (long long)1;
		for (bigint i = ans; i <= *this; i = i + (long long)1) {
			ans = i * ans;
		}
		return ans;
	}
	bigint operator / (const bigint &b) const {
		//A/B
		bigint A, B, c, ans;
		if (b.flag == flag)
			ans.flag = 1;
		else
			ans.flag = 0;
		if (b > *this)
			return 0;
		if (b == *this)
			return 1;
		c.s.clear();
		ans.s.clear();
		A = *this;
		B = b;
		A.flag = B.flag = c.flag = 1;
		long long zero = (A.s.size() - b.s.size());
		B.s.insert(B.s.begin(), zero, 0);
		while (!B.s.empty() && B >= b) {
			long long x = 0;
			while (A >= B) {
				A = A - B;
				x++;
			}
			c.s.push_back(x);
			B.s.erase(B.s.begin());
		}
		if (!c.s.empty())
			for (vector<long long>::reverse_iterator it = c.s.rbegin(); it != c.s.rend(); it++) {
				ans.s.push_back(*it);
			}
		else
			ans.s.push_back(0);
		if (ans.s.empty())
			ans.s.push_back(0);
		if (ans.s.back() == 0) {
			vector<long long>::iterator it = ans.s.end();
			for (it--; it != ans.s.begin(); it--) {
				if (*it != 0)
					break;
			}
			it++;
			ans.s.erase(it, ans.s.end());
		}
		/***************
		A 为余数
		***************/
		return ans;
	}
	bigint operator % (const long long &b) const {
		bigint c;
		long long x;
		c.s.clear();
		for (int i = 0; i < s.size(); i++) {
			x = s[i] % b;
			c.s.push_back(x);
		}
		c.flag = 1;
		if (b < 0 && flag != 0)
			c.flag = 0;
		if (b > 0 && flag == 0)
			c.flag = 0;
		return c;
	}
	bigint operator % (const bigint &b) const {
		//A/B
		bigint A, B;
		bool flagg;
		if (b > *this)
			return 0;
		if (b == *this)
			return 1;
		A = *this;
		B = b;
		if (A.flag == B.flag)
			flagg = 1;
		else
			flagg = 0;
		A.flag = B.flag = 1;
		long long zero = (A.s.size() - b.s.size());
		B.s.insert(B.s.begin(), zero, 0);
		while (!B.s.empty() && B >= b) {
			while (A >= B) {
				A = A - B;
			}
			B.s.erase(B.s.begin());
		}
		/***************
		A 为余数
		***************/
		A.flag = flagg;
		return A;
	}
};
ostream &operator << (ostream &out, const bigint &x) {
	if (x.flag == 0)
		out << '-';
	out << x.s.back();
	for (int i = x.s.size() - 2; i >= 0; i--) {
		char buf[20];
		sprintf(buf, "%lld", x.s[i]);
		for (int j = 0; j < strlen(buf); j++)
			out << buf[j];
	}
	return out;
}
istream &operator >> (istream &in, bigint &x) {
	string s;
	if (!(in >> s))
		return in;
	x = s;
	return in;
}
#endif
