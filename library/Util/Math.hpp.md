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
  bundledCode: "#line 1 \"library/Util/Math.hpp\"\n\n\n\nnamespace otera {\n    //\
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
  path: library/Util/Math.hpp
  requiredBy: []
  timestamp: '2022-05-21 13:31:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Util/Math.hpp
layout: document
redirect_from:
- /library/library/Util/Math.hpp
- /library/library/Util/Math.hpp.html
title: library/Util/Math.hpp
---
