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
  bundledCode: "#line 1 \"library/Util/PairOps.hpp\"\n\n\n\n\nnamespace otera {\n\
    \    template<typename T, typenae U> std::pair<T, U> operator+(const std::pair<T,\
    \ U> &lhs, const std::pair<T, U> &rhs) { return {lhs.first + rhs.first, lhs.second\
    \ + rhs.second}; }\n    template<typename T, typenae U> std::pair<T, U> operator-(const\
    \ std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { return {lhs.first - rhs.first,\
    \ lhs.second - rhs.second}; }\n    template<typename T, typenae U> std::pair<T,\
    \ U> operator*(const std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { return\
    \ {lhs.first * rhs.first, lhs.second * rhs.second}; }\n    template<typename T,\
    \ typenae U> std::pair<T, U> operator/(const std::pair<T, U> &lhs, const std::pair<T,\
    \ U> &rhs) { return {lhs.first / rhs.first, lhs.second / rhs.second}; }\n\n  \
    \  template<typename T, typenae U> std::pair<T, U> operator+=(std::pair<T, U>\
    \ &lhs, const std::pair<T, U> &rhs) { lhs.second += rhs.second, lhs.y += rhs.second;\
    \ return lhs; }\n    template<typename T, typenae U> std::pair<T, U> operator-=(std::pair<T,\
    \ U> &lhs, const std::pair<T, U> &rhs) { lhs.second -= rhs.second, lhs.y -= rhs.second;\
    \ return lhs; }\n    template<typename T, typenae U> std::pair<T, U> operator*=(std::pair<T,\
    \ U> &lhs, const std::pair<T, U> &rhs) { lhs.second *= rhs.second, lhs.y *= rhs.second;\
    \ return lhs; }\n    template<typename T, typenae U> std::pair<T, U> operator/=(std::pair<T,\
    \ U> &lhs, const std::pair<T, U> &rhs) { lhs.second /= rhs.second, lhs.y /= rhs.second;\
    \ return lhs; }\n\n    template<typename T, typenae U> bool operator==(const std::pair<T,\
    \ U>& lhs, const std::pair<T, U>& rhs) { return lhs.first == rhs.first and lhs.second\
    \ == rhs.second; }\n    template<typename T, typenae U> bool operator!=(const\
    \ std::pair<T, U>& lhs, const std::pair<T, U>& rhs) { return not (lhs == rhs);\
    \ }\n\n    template<typename T, typenae U> std::istream& operator>>(std::istream&\
    \ in, std::pair<T, U>& p) { return in >> p.first >> p.second; }\n    template<typename\
    \ T, typenae U> std::ostream& operator<<(std::ostream& out, const std::pair<T,\
    \ U>& p) { return out << p.first << ' ' << p.second; }\n} // namespace otera \n\
    \n\n"
  code: "#ifndef OTERA_PAIR_OPS_HPP\n#define OTERA_PAIR_OPS_HPP 1\n\n\nnamespace otera\
    \ {\n    template<typename T, typenae U> std::pair<T, U> operator+(const std::pair<T,\
    \ U> &lhs, const std::pair<T, U> &rhs) { return {lhs.first + rhs.first, lhs.second\
    \ + rhs.second}; }\n    template<typename T, typenae U> std::pair<T, U> operator-(const\
    \ std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { return {lhs.first - rhs.first,\
    \ lhs.second - rhs.second}; }\n    template<typename T, typenae U> std::pair<T,\
    \ U> operator*(const std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { return\
    \ {lhs.first * rhs.first, lhs.second * rhs.second}; }\n    template<typename T,\
    \ typenae U> std::pair<T, U> operator/(const std::pair<T, U> &lhs, const std::pair<T,\
    \ U> &rhs) { return {lhs.first / rhs.first, lhs.second / rhs.second}; }\n\n  \
    \  template<typename T, typenae U> std::pair<T, U> operator+=(std::pair<T, U>\
    \ &lhs, const std::pair<T, U> &rhs) { lhs.second += rhs.second, lhs.y += rhs.second;\
    \ return lhs; }\n    template<typename T, typenae U> std::pair<T, U> operator-=(std::pair<T,\
    \ U> &lhs, const std::pair<T, U> &rhs) { lhs.second -= rhs.second, lhs.y -= rhs.second;\
    \ return lhs; }\n    template<typename T, typenae U> std::pair<T, U> operator*=(std::pair<T,\
    \ U> &lhs, const std::pair<T, U> &rhs) { lhs.second *= rhs.second, lhs.y *= rhs.second;\
    \ return lhs; }\n    template<typename T, typenae U> std::pair<T, U> operator/=(std::pair<T,\
    \ U> &lhs, const std::pair<T, U> &rhs) { lhs.second /= rhs.second, lhs.y /= rhs.second;\
    \ return lhs; }\n\n    template<typename T, typenae U> bool operator==(const std::pair<T,\
    \ U>& lhs, const std::pair<T, U>& rhs) { return lhs.first == rhs.first and lhs.second\
    \ == rhs.second; }\n    template<typename T, typenae U> bool operator!=(const\
    \ std::pair<T, U>& lhs, const std::pair<T, U>& rhs) { return not (lhs == rhs);\
    \ }\n\n    template<typename T, typenae U> std::istream& operator>>(std::istream&\
    \ in, std::pair<T, U>& p) { return in >> p.first >> p.second; }\n    template<typename\
    \ T, typenae U> std::ostream& operator<<(std::ostream& out, const std::pair<T,\
    \ U>& p) { return out << p.first << ' ' << p.second; }\n} // namespace otera \n\
    \n#endif // OTERA_TUPLE_OPS_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/Util/PairOps.hpp
  requiredBy: []
  timestamp: '2022-10-10 05:27:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Util/PairOps.hpp
layout: document
redirect_from:
- /library/library/Util/PairOps.hpp
- /library/library/Util/PairOps.hpp.html
title: library/Util/PairOps.hpp
---
