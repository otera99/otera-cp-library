---
title: マージ過程を表す森
documentation_of: ../../../library/DataStructure/MergeHistoryForest.hpp
---

- 概要

UnionFindと同様にして使うと、マージ過程を表す森を構築し、ある時点から辿り着ける頂点の集合をEuler Tour上の区間として表現できる。

なお、生成される森は、高々$2 n - 1$頂点の有向森として`std::vector<std::vector<int>>`で隣接リストとして表現される。

### マージ
- シグネチャ
```cp
void merge(int a, int b)
```

- 概要

要素$a$と$b$がまだマージされていないなら、マージしつつ、マージ過程を表す頂点を生成し、$a$と$b$に辺をはる

### 同時にマージ
- シグネチャ
```cp
void merge_simultaneously(std::vector<std::pair<int, int>> edges)
```

- 概要

`edges`に`std::pair<int, int>`として含まれるそれぞれの要素$a$と$b$がまだマージされていないなら、マージしつつ、`edges`に含まれる全てのマージ過程を表すような頂点を生成し（このマージ過程で同時にマージされたものは一頂点で表現される）、全てのマージした頂点に有向辺をはる