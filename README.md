# otera-cp-library

[![Actions Status](https://github.com/otera99/otera-cp-library/workflows/verify/badge.svg)](https://github.com/otera99/otera-cp-library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://otera99.github.io/otera-cp-library/)

## 概要

競技プログラミング向けの C++ ライブラリである．
なお，[AtCoder Library (ACL)](https://github.com/atcoder/ac-library) の使用を前提としているものもある．

## ライブラリの使用方法

`otera`フォルダに`library`フォルダ下にあるライブラリを全て置いているので、`otera`フォルダのファイルをincludeすると使用できる.

`expander.py`というスクリプト(python3.5 or later)で、`python3 path/to/otera-cp-library/expander.py --lib path/to/otera-cp-library main.cpp`とすると、`combined_otera.cpp`が生成され、`otera`フォルダ下にライブラリが全て展開される(AtCoderなどのACLに対応しているジャッジではこちらを提出する).
なお、`-ac`オプションをつけて実行すると、[AtCoder Library (ACL)](https://github.com/atcoder/ac-library)のコードも全て展開され、`combined.cpp`も生成される(CodeforcesなどのACLに対応してないジャッジではこちらを提出する).

なお、[cp-commands](https://github.com/otera99/cp-commands)を用いることで、ライブラリの展開と合わせて，[oj](https://aresune.com/?_=%2Fonline-judge-tools%2Foj%23%2F57C5Qg75s5BqH5nOjgXq3c%3D)でのテストなどをまとめて行うことができる．

## ライブラリの追加方法

`library`フォルダ下に`.hpp`ファイルのライブラリを追加してから`library_generater.py`というスクリプト(python3.5 or later)を走らせると、`otera`フォルダ下にライブラリが生成される．

## バグ報告など

[@otera1999](https://twitter.com/otera1999) まで報告を頂けるとありがたいです．

## ライセンス

`otera`内のファイルは全て，[CC0](https://creativecommons.org/publicdomain/zero/1.0/legalcode) を採用しています．