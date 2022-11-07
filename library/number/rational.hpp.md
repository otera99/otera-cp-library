---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1611.test.cpp
    title: test/yukicoder/1611.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/number/rational.hpp\"\n\n\n\nnamespace otera{\n\
    \    template<typename T>\n    struct rational {\n        public:\n          \
    \  rational() : rational(0) {}\n            rational(T n) : num(n), den(1) {}\n\
    \            rational(T n, T d) {\n                assert(d != 0);\n         \
    \       if(n == 0) num = 0, den = 1;\n                else {\n               \
    \     T g = std::gcd(n, d);\n                    n /= g, d /= g;\n           \
    \         if (d < 0) n = -n, d = -d;\n                    num = n, den = d;\n\
    \                }\n            }\n\n            T numerator() const { return\
    \ num; }\n            T denominator() const { return den; }\n\n            //\
    \ return (x > 0 ? 1 : x == 0 ? 0 : -1)\n            int sgn() const {\n      \
    \          return -1 + (num >= 0) + (num > 0);\n            }\n            //\
    \ return (l > r ? 1 : l == r ? 0 : -1)\n            static int compare(const rational\
    \ &l, const rational &r) {\n                T g = std::abs(std::gcd(l.den, r.den));\n\
    \                T val = r.den / g * l.num - l.den / g * r.num;\n            \
    \    return -1 + (val >= 0) + (val > 0);\n            }\n\n            friend\
    \ bool operator<(const rational &l, const rational &r) {\n                return\
    \ compare(l, r) < 0;\n            }\n            friend bool operator>(const rational\
    \ &l, const rational &r) {\n                return compare(l, r) > 0;\n      \
    \      }\n            friend bool operator<=(const rational &l, const rational\
    \ &r) {\n                return compare(l, r) <= 0;\n            }\n         \
    \   friend bool operator>=(const rational &l, const rational &r) {\n         \
    \       return compare(l, r) >= 0;\n            }\n            friend bool operator==(const\
    \ rational &l, const rational &r) {\n                return compare(l, r) == 0;\n\
    \            }\n            friend bool operator!=(const rational &l, const rational\
    \ &r) {\n                return compare(l, r) != 0;\n            }\n\n       \
    \     rational operator+() const {\n                return *this;\n          \
    \  }\n            rational operator-() const {\n                return rational(-num,\
    \ den);\n            }\n            friend rational operator+(const rational &l,\
    \ const rational &r) {\n                T lcm = l.den / std::gcd(l.den, r.den)\
    \ * r.den;  \n                lcm = std::abs(lcm);\n                return rational(l.num\
    \ * (lcm / l.den) + r.num * (lcm / r.den), lcm);\n            }\n            friend\
    \ rational operator-(const rational &l, const rational &r) {\n               \
    \ T lcm = l.den / std::gcd(l.den, r.den) * r.den;\n                lcm = std::abs(lcm);\n\
    \                return rational(l.num * (lcm / l.den) - r.num * (lcm / r.den),\
    \ lcm);\n            }\n            friend rational operator*(const rational &l,\
    \ const rational &r) {\n                T g1 = std::gcd(std::abs(l.num), std::abs(r.den));\
    \  g1 = std::abs(g1);\n                T g2 = std::gcd(l.den, r.num);  g2 = std::abs(g2);\n\
    \                return rational((l.num / g1) * (r.num / g2), (l.den / g2) * (r.den\
    \ / g1));\n            }\n            friend rational operator/(const rational\
    \ &l, const rational &r) {\n                return l * r.inv();\n            }\n\
    \            rational& operator+=(const rational &r) {\n                *this\
    \ = *this + r;\n                return *this;\n            }\n            rational&\
    \ operator-=(const rational &r) {\n                *this = *this - r;\n      \
    \          return *this;\n            }\n            rational& operator*=(const\
    \ rational &r) {\n                *this = *this * r;\n                return *this;\n\
    \            }\n            rational& operator/=(const rational &r) {\n      \
    \          *this = *this / r;\n                return *this;\n            }\n\
    \            rational& operator++() {\n                num += den;\n         \
    \       return *this;\n            }\n            Rational& operator--() {\n \
    \               num -= den;\n                return *this;\n            }\n  \
    \          rational inv() const {\n                return rational(den, num);\n\
    \            }\n            rational abs() const {\n                return rational(std::abs(num),\
    \ den);\n            }\n            rational pow(long long _n) const {\n     \
    \           if(!_n) return rational(1);\n                rational res = pow(_n>>1);\n\
    \                res *= res;\n                if(_n & 1) res *= *this;\n     \
    \           return res;\n            }\n\n            explicit operator int()\
    \ const {\n                return (int)(num / den);\n            }\n         \
    \   explicit operator long long() const {\n                return (long long)(num\
    \ / den);\n            }\n            explicit operator double() const {\n   \
    \             return (double)num / (double)den;\n            }\n            explicit\
    \ operator long double() const {\n                return (long double)num / (long\
    \ double)den;\n            }\n\n            T floor() const {\n              \
    \  return num >= 0 ? num / den : -(-num / den);\n            }\n            T\
    \ ceil() const {\n                return num >= 0 ? -(-num / den) : num / den;\n\
    \            }\n\n            friend std::ostream &operator<<(std::ostream &os,\
    \ const rational &r) {\n                return os << r.num << \"/\" << r.den;\n\
    \            }\n\n        private:\n            T num, den;\n    };\n}\n\ntemplate\
    \ <typename T>\notera::rational<T> max(const otera::rational<T> &l, const otera::rational<T>\
    \ &r) {\n    return l > r ? l : r;\n}\ntemplate <typename T>\notera::rational<T>\
    \ min(const otera::rational<T> &l, const otera::rational<T> &r) {\n    return\
    \ l < r ? l : r;\n}\n\n\n"
  code: "#ifndef OTERA_RATIONAL_HPP\n#define OTERA_RATIONAL_HPP 1\n\nnamespace otera{\n\
    \    template<typename T>\n    struct rational {\n        public:\n          \
    \  rational() : rational(0) {}\n            rational(T n) : num(n), den(1) {}\n\
    \            rational(T n, T d) {\n                assert(d != 0);\n         \
    \       if(n == 0) num = 0, den = 1;\n                else {\n               \
    \     T g = std::gcd(n, d);\n                    n /= g, d /= g;\n           \
    \         if (d < 0) n = -n, d = -d;\n                    num = n, den = d;\n\
    \                }\n            }\n\n            T numerator() const { return\
    \ num; }\n            T denominator() const { return den; }\n\n            //\
    \ return (x > 0 ? 1 : x == 0 ? 0 : -1)\n            int sgn() const {\n      \
    \          return -1 + (num >= 0) + (num > 0);\n            }\n            //\
    \ return (l > r ? 1 : l == r ? 0 : -1)\n            static int compare(const rational\
    \ &l, const rational &r) {\n                T g = std::abs(std::gcd(l.den, r.den));\n\
    \                T val = r.den / g * l.num - l.den / g * r.num;\n            \
    \    return -1 + (val >= 0) + (val > 0);\n            }\n\n            friend\
    \ bool operator<(const rational &l, const rational &r) {\n                return\
    \ compare(l, r) < 0;\n            }\n            friend bool operator>(const rational\
    \ &l, const rational &r) {\n                return compare(l, r) > 0;\n      \
    \      }\n            friend bool operator<=(const rational &l, const rational\
    \ &r) {\n                return compare(l, r) <= 0;\n            }\n         \
    \   friend bool operator>=(const rational &l, const rational &r) {\n         \
    \       return compare(l, r) >= 0;\n            }\n            friend bool operator==(const\
    \ rational &l, const rational &r) {\n                return compare(l, r) == 0;\n\
    \            }\n            friend bool operator!=(const rational &l, const rational\
    \ &r) {\n                return compare(l, r) != 0;\n            }\n\n       \
    \     rational operator+() const {\n                return *this;\n          \
    \  }\n            rational operator-() const {\n                return rational(-num,\
    \ den);\n            }\n            friend rational operator+(const rational &l,\
    \ const rational &r) {\n                T lcm = l.den / std::gcd(l.den, r.den)\
    \ * r.den;  \n                lcm = std::abs(lcm);\n                return rational(l.num\
    \ * (lcm / l.den) + r.num * (lcm / r.den), lcm);\n            }\n            friend\
    \ rational operator-(const rational &l, const rational &r) {\n               \
    \ T lcm = l.den / std::gcd(l.den, r.den) * r.den;\n                lcm = std::abs(lcm);\n\
    \                return rational(l.num * (lcm / l.den) - r.num * (lcm / r.den),\
    \ lcm);\n            }\n            friend rational operator*(const rational &l,\
    \ const rational &r) {\n                T g1 = std::gcd(std::abs(l.num), std::abs(r.den));\
    \  g1 = std::abs(g1);\n                T g2 = std::gcd(l.den, r.num);  g2 = std::abs(g2);\n\
    \                return rational((l.num / g1) * (r.num / g2), (l.den / g2) * (r.den\
    \ / g1));\n            }\n            friend rational operator/(const rational\
    \ &l, const rational &r) {\n                return l * r.inv();\n            }\n\
    \            rational& operator+=(const rational &r) {\n                *this\
    \ = *this + r;\n                return *this;\n            }\n            rational&\
    \ operator-=(const rational &r) {\n                *this = *this - r;\n      \
    \          return *this;\n            }\n            rational& operator*=(const\
    \ rational &r) {\n                *this = *this * r;\n                return *this;\n\
    \            }\n            rational& operator/=(const rational &r) {\n      \
    \          *this = *this / r;\n                return *this;\n            }\n\
    \            rational& operator++() {\n                num += den;\n         \
    \       return *this;\n            }\n            Rational& operator--() {\n \
    \               num -= den;\n                return *this;\n            }\n  \
    \          rational inv() const {\n                return rational(den, num);\n\
    \            }\n            rational abs() const {\n                return rational(std::abs(num),\
    \ den);\n            }\n            rational pow(long long _n) const {\n     \
    \           if(!_n) return rational(1);\n                rational res = pow(_n>>1);\n\
    \                res *= res;\n                if(_n & 1) res *= *this;\n     \
    \           return res;\n            }\n\n            explicit operator int()\
    \ const {\n                return (int)(num / den);\n            }\n         \
    \   explicit operator long long() const {\n                return (long long)(num\
    \ / den);\n            }\n            explicit operator double() const {\n   \
    \             return (double)num / (double)den;\n            }\n            explicit\
    \ operator long double() const {\n                return (long double)num / (long\
    \ double)den;\n            }\n\n            T floor() const {\n              \
    \  return num >= 0 ? num / den : -(-num / den);\n            }\n            T\
    \ ceil() const {\n                return num >= 0 ? -(-num / den) : num / den;\n\
    \            }\n\n            friend std::ostream &operator<<(std::ostream &os,\
    \ const rational &r) {\n                return os << r.num << \"/\" << r.den;\n\
    \            }\n\n        private:\n            T num, den;\n    };\n}\n\ntemplate\
    \ <typename T>\notera::rational<T> max(const otera::rational<T> &l, const otera::rational<T>\
    \ &r) {\n    return l > r ? l : r;\n}\ntemplate <typename T>\notera::rational<T>\
    \ min(const otera::rational<T> &l, const otera::rational<T> &r) {\n    return\
    \ l < r ? l : r;\n}\n\n#endif // OTERA_RATIONAL_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/number/rational.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:48:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1611.test.cpp
documentation_of: library/number/rational.hpp
layout: document
redirect_from:
- /library/library/number/rational.hpp
- /library/library/number/rational.hpp.html
title: library/number/rational.hpp
---
