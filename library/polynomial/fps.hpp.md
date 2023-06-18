---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/polynomial/fps.hpp\"\n// UNFINISHED\n#ifndef OTERA_FPS_HPP\n\
    #define OTERA_FPS_HPP 1\n\n#include<atcoder/convolution>\n\nnamespace otera {\n\
    \    template<typename T>\n    struct fps : std::vector<T> {\n        using std::vector<T>::vector;\n\
    \        \n        void shrink() {\n            while(this->size() and this->back()\
    \ == T(0)) {\n                this->pop_back();\n            }\n        }\n\n\
    \        void ensure(int n) {\n            this->resize(n, T(0));\n        }\n\
    \n        fps pre(int n) const {\n            if((int)this->size() < n) {\n  \
    \              fps ret(*this);\n                ret.resize(n, T(0));\n       \
    \         return ret;\n            }\n            return fps(begin(*this), begin(*this)\
    \ + n);\n        }\n\n        fps rev(int n = -1) const {\n            fps ret(*this);\n\
    \            if(n != -1) ret.resize(n, T(0));\n            reverse(begin(ret),\
    \ end(ret));\n            return ret;\n        }\n\n        fps operator+(const\
    \ fps &r) const { return fps(*this) += r; }\n        fps operator+(const T &v)\
    \ const { return fps(*this) += v; }\n        fps operator-(const fps &r) const\
    \ { return fps(*this) -= r; }\n        fps operator-(const T &v) const { return\
    \ fps(*this) -= v; }\n        fps operator*(const fps &r) const { return fps(*this)\
    \ *= r; }\n        fps operator*(const T &v) const { return fps(*this) *= v; }\n\
    \        fps operator/(const fps &r) const { return fps(*this) /= r; }\n     \
    \   fps operator%(const fps &r) const { return fps(*this) %= r; }\n\n        fps\
    \ &operator+=(const fps &r) {\n            if(r.size() > this->size()) this->resize(r.size());\n\
    \            for(int i = 0; i < (int)r.size(); ++ i) (*this)[i] += r[i];\n   \
    \         return *this;\n        }\n\n        fps &operator-=(const fps &r) {\n\
    \            if(r.size() > this->size()) this->resize(r.size());\n           \
    \ for(int i = 0; i < (int)r.size(); ++ i) (*this)[i] -= r[i];\n            return\
    \ *this;\n        }\n\n        fps &operator*=(const fps &r) {\n            if(this->empty()\
    \ or r.empty()) {\n                this->clear();\n                return *this;\n\
    \            }\n            auto ret = atcoder::convolution(*this, r);\n     \
    \       return *this = {begin(ret), end(ret)};\n        }\n\n        fps &operator/=(const\
    \ fps &r) {\n            if(this->size() < r.size()) {\n                this->clear();\n\
    \                return *this;\n            }\n            int n = (int)this->size()\
    \ - r.size() + 1;\n            return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n\
    \        }\n\n        fps &operator%=(const fps &r) {\n            return *this\
    \ -= *this / r * r;\n        }\n\n        fps operator-() const {\n          \
    \  fps ret(this->size());\n            for(int i = 0; i < (int)this->size(); ++\
    \ i) ret[i] = -(*this)[i];\n            return ret;\n        }\n\n        fps\
    \ &operator+=(const T &r) {\n            if(this->empty()) this->resize(1);\n\
    \            (*this)[0] += r;\n            return *this;\n        }\n\n      \
    \  fps &operator-=(const T &r) {\n            if(this->empty()) this->resize(1);\n\
    \            (*this)[0] -= r;\n            return *this;\n        }\n\n      \
    \  fps &operator*=(const T &v) {\n            for(int i = 0; i < (int)this->size();\
    \ ++ i) (*this)[i] *= v;\n            return *this;\n        }\n\n        fps\
    \ operator>>(int sz) const {\n            if((int)this->size() <= sz) return {};\n\
    \            fps ret(*this);\n            ret.erase(ret.begin(), ret.begin() +\
    \ sz);\n            return ret;\n        }\n\n        fps operator<<(int sz) const\
    \ {\n            fps ret(*this);\n            ret.insert(ret.begin(), sz, T(0));\n\
    \            return ret;\n        }\n\n        T operator()(T x) const {\n   \
    \         T r = 0, w = 1;\n            for(auto &v : *this) {\n              \
    \  r += w * v;\n                w *= x;\n            }\n            return r;\n\
    \        }\n\n        fps diff() const {\n            const int n = (int) this->size();\n\
    \            fps ret(std::max(0, n - 1));\n            for(int i = 1; i < n; ++\
    \ i) ret[i - 1] = (*this)[i] * T(i);\n            return ret;\n        }\n\n \
    \       fps integral() const {\n            const int n = (int) this->size();\n\
    \            fps ret(n + 1);\n            ret[0] = T(0);\n            for(int\
    \ i = 0; i < n; ++ i) ret[i + 1] = (*this)[i] / T(i + 1);\n            return\
    \ ret;\n        }\n\n        fps inv(int deg = -1) const {\n            assert(((*this)[0])\
    \ != T(0));\n            if(deg == -1) deg = (int)this->size();\n            fps\
    \ ret({T(1) / (*this)[0]});\n            for(int i = 1; i < deg; i <<= 1) {\n\
    \                ret = (ret + ret - ret * ret * pre(i<<1)).pre(i<<1);\n      \
    \      }\n            return ret.pre(deg);\n        } \n\n        fps log(int\
    \ deg = -1) const {\n            assert((*this)[0] == T(1));\n            if(deg\
    \ == -1) deg = (int)this->size();\n            return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n        }\n\n        fps exp(int deg = -1) const {\n     \
    \       if(deg == -1) deg = (int)this->size();\n            assert((*this)[0]\
    \ == T(0));\n            fps ret({T(1)});\n            for(int i = 1; i < deg;\
    \ i <<= 1) {\n                ret = (ret * (pre(i << 1) + T(1) - ret.log(i <<\
    \ 1))).pre(i << 1);\n            }\n            return ret.pre(deg);\n       \
    \ }\n\n        fps pow(long long k, int deg = -1) const {\n            const int\
    \ n = (int)this->size();\n            if(deg == -1) deg = n;\n            if(k\
    \ == 0) {\n                fps ret(deg, T(0));\n                ret[0] = T(1);\n\
    \                return ret;\n            }  \n            for(int i = 0; i <\
    \ n; i++) {\n                if(i * k > deg) return fps(deg, T(0));\n        \
    \        if((*this)[i] != T(0)) {\n                    T rev = T(1) / (*this)[i];\n\
    \                    fps ret = ((((*this) * rev) >> i).log(deg) * k).exp(deg)\
    \ * ((*this)[i].pow(k));\n                    ret = (ret << (i * k)).pre(deg);\n\
    \                    if((int)ret.size() < deg) ret.resize(deg, T(0));\n      \
    \              return ret;\n                }\n            }\n            return\
    \ FPS(deg, T{0});\n        }\n    };\n} // namespace otera\n\n#endif // OTERA_FPS_HPP\n"
  code: "// UNFINISHED\n#ifndef OTERA_FPS_HPP\n#define OTERA_FPS_HPP 1\n\n#include<atcoder/convolution>\n\
    \nnamespace otera {\n    template<typename T>\n    struct fps : std::vector<T>\
    \ {\n        using std::vector<T>::vector;\n        \n        void shrink() {\n\
    \            while(this->size() and this->back() == T(0)) {\n                this->pop_back();\n\
    \            }\n        }\n\n        void ensure(int n) {\n            this->resize(n,\
    \ T(0));\n        }\n\n        fps pre(int n) const {\n            if((int)this->size()\
    \ < n) {\n                fps ret(*this);\n                ret.resize(n, T(0));\n\
    \                return ret;\n            }\n            return fps(begin(*this),\
    \ begin(*this) + n);\n        }\n\n        fps rev(int n = -1) const {\n     \
    \       fps ret(*this);\n            if(n != -1) ret.resize(n, T(0));\n      \
    \      reverse(begin(ret), end(ret));\n            return ret;\n        }\n\n\
    \        fps operator+(const fps &r) const { return fps(*this) += r; }\n     \
    \   fps operator+(const T &v) const { return fps(*this) += v; }\n        fps operator-(const\
    \ fps &r) const { return fps(*this) -= r; }\n        fps operator-(const T &v)\
    \ const { return fps(*this) -= v; }\n        fps operator*(const fps &r) const\
    \ { return fps(*this) *= r; }\n        fps operator*(const T &v) const { return\
    \ fps(*this) *= v; }\n        fps operator/(const fps &r) const { return fps(*this)\
    \ /= r; }\n        fps operator%(const fps &r) const { return fps(*this) %= r;\
    \ }\n\n        fps &operator+=(const fps &r) {\n            if(r.size() > this->size())\
    \ this->resize(r.size());\n            for(int i = 0; i < (int)r.size(); ++ i)\
    \ (*this)[i] += r[i];\n            return *this;\n        }\n\n        fps &operator-=(const\
    \ fps &r) {\n            if(r.size() > this->size()) this->resize(r.size());\n\
    \            for(int i = 0; i < (int)r.size(); ++ i) (*this)[i] -= r[i];\n   \
    \         return *this;\n        }\n\n        fps &operator*=(const fps &r) {\n\
    \            if(this->empty() or r.empty()) {\n                this->clear();\n\
    \                return *this;\n            }\n            auto ret = atcoder::convolution(*this,\
    \ r);\n            return *this = {begin(ret), end(ret)};\n        }\n\n     \
    \   fps &operator/=(const fps &r) {\n            if(this->size() < r.size()) {\n\
    \                this->clear();\n                return *this;\n            }\n\
    \            int n = (int)this->size() - r.size() + 1;\n            return *this\
    \ = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n        }\n\n        fps &operator%=(const\
    \ fps &r) {\n            return *this -= *this / r * r;\n        }\n\n       \
    \ fps operator-() const {\n            fps ret(this->size());\n            for(int\
    \ i = 0; i < (int)this->size(); ++ i) ret[i] = -(*this)[i];\n            return\
    \ ret;\n        }\n\n        fps &operator+=(const T &r) {\n            if(this->empty())\
    \ this->resize(1);\n            (*this)[0] += r;\n            return *this;\n\
    \        }\n\n        fps &operator-=(const T &r) {\n            if(this->empty())\
    \ this->resize(1);\n            (*this)[0] -= r;\n            return *this;\n\
    \        }\n\n        fps &operator*=(const T &v) {\n            for(int i = 0;\
    \ i < (int)this->size(); ++ i) (*this)[i] *= v;\n            return *this;\n \
    \       }\n\n        fps operator>>(int sz) const {\n            if((int)this->size()\
    \ <= sz) return {};\n            fps ret(*this);\n            ret.erase(ret.begin(),\
    \ ret.begin() + sz);\n            return ret;\n        }\n\n        fps operator<<(int\
    \ sz) const {\n            fps ret(*this);\n            ret.insert(ret.begin(),\
    \ sz, T(0));\n            return ret;\n        }\n\n        T operator()(T x)\
    \ const {\n            T r = 0, w = 1;\n            for(auto &v : *this) {\n \
    \               r += w * v;\n                w *= x;\n            }\n        \
    \    return r;\n        }\n\n        fps diff() const {\n            const int\
    \ n = (int) this->size();\n            fps ret(std::max(0, n - 1));\n        \
    \    for(int i = 1; i < n; ++ i) ret[i - 1] = (*this)[i] * T(i);\n           \
    \ return ret;\n        }\n\n        fps integral() const {\n            const\
    \ int n = (int) this->size();\n            fps ret(n + 1);\n            ret[0]\
    \ = T(0);\n            for(int i = 0; i < n; ++ i) ret[i + 1] = (*this)[i] / T(i\
    \ + 1);\n            return ret;\n        }\n\n        fps inv(int deg = -1) const\
    \ {\n            assert(((*this)[0]) != T(0));\n            if(deg == -1) deg\
    \ = (int)this->size();\n            fps ret({T(1) / (*this)[0]});\n          \
    \  for(int i = 1; i < deg; i <<= 1) {\n                ret = (ret + ret - ret\
    \ * ret * pre(i<<1)).pre(i<<1);\n            }\n            return ret.pre(deg);\n\
    \        } \n\n        fps log(int deg = -1) const {\n            assert((*this)[0]\
    \ == T(1));\n            if(deg == -1) deg = (int)this->size();\n            return\
    \ (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n        }\n\n    \
    \    fps exp(int deg = -1) const {\n            if(deg == -1) deg = (int)this->size();\n\
    \            assert((*this)[0] == T(0));\n            fps ret({T(1)});\n     \
    \       for(int i = 1; i < deg; i <<= 1) {\n                ret = (ret * (pre(i\
    \ << 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n            }\n            return\
    \ ret.pre(deg);\n        }\n\n        fps pow(long long k, int deg = -1) const\
    \ {\n            const int n = (int)this->size();\n            if(deg == -1) deg\
    \ = n;\n            if(k == 0) {\n                fps ret(deg, T(0));\n      \
    \          ret[0] = T(1);\n                return ret;\n            }  \n    \
    \        for(int i = 0; i < n; i++) {\n                if(i * k > deg) return\
    \ fps(deg, T(0));\n                if((*this)[i] != T(0)) {\n                \
    \    T rev = T(1) / (*this)[i];\n                    fps ret = ((((*this) * rev)\
    \ >> i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));\n                    ret\
    \ = (ret << (i * k)).pre(deg);\n                    if((int)ret.size() < deg)\
    \ ret.resize(deg, T(0));\n                    return ret;\n                }\n\
    \            }\n            return FPS(deg, T{0});\n        }\n    };\n} // namespace\
    \ otera\n\n#endif // OTERA_FPS_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/polynomial/fps.hpp
  requiredBy: []
  timestamp: '2023-06-18 12:48:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/polynomial/fps.hpp
layout: document
redirect_from:
- /library/library/polynomial/fps.hpp
- /library/library/polynomial/fps.hpp.html
title: library/polynomial/fps.hpp
---
