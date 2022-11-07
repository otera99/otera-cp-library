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
  bundledCode: "#line 1 \"library/util/math.hpp\"\n\n\n\nnamespace otera {\n    //\
    \ return floor(x / y)\n    template<typename T>\n    constexpr inline T fld(const\
    \ T x, const T y) {\n        if((x ^ y) >= 0) return x / y;\n        if(y > 0)\
    \ return (x - (y - 1)) / y;\n        else return (x - (y + 1)) / y;\n    }\n \
    \   // return ceil(x / y)\n    template<typename T>\n    constexpr inline T ced(const\
    \ T x, const T y) {\n        if((x ^ y) <= 0) return x / y;\n        if(y > 0)\
    \ return (x + (y - 1)) / y;\n        else return (x + (y + 1)) / y;\n    }\n \
    \   // return x % y\n    template<typename T>\n    constexpr inline T rem(const\
    \ T x, const T y) {\n        assert(y > 0);\n        if(x > 0) return x % y;\n\
    \        else return (y - x % y) % y;\n    }\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_MATH_HPP\n#define OTERA_MATH_HPP 1\n\nnamespace otera {\n \
    \   // return floor(x / y)\n    template<typename T>\n    constexpr inline T fld(const\
    \ T x, const T y) {\n        if((x ^ y) >= 0) return x / y;\n        if(y > 0)\
    \ return (x - (y - 1)) / y;\n        else return (x - (y + 1)) / y;\n    }\n \
    \   // return ceil(x / y)\n    template<typename T>\n    constexpr inline T ced(const\
    \ T x, const T y) {\n        if((x ^ y) <= 0) return x / y;\n        if(y > 0)\
    \ return (x + (y - 1)) / y;\n        else return (x + (y + 1)) / y;\n    }\n \
    \   // return x % y\n    template<typename T>\n    constexpr inline T rem(const\
    \ T x, const T y) {\n        assert(y > 0);\n        if(x > 0) return x % y;\n\
    \        else return (y - x % y) % y;\n    }\n} // namespace otera\n\n#endif //\
    \ OTERA_MATH_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/util/math.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:48:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/math.hpp
layout: document
redirect_from:
- /library/library/util/math.hpp
- /library/library/util/math.hpp.html
title: library/util/math.hpp
---
