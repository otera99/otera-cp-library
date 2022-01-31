#include<atcoder/modint>

std::ostream& operator<<(std::ostream& out, const atcoder::modint1000000007 &e) {
    out << e.val();
    return out;
}

std::ostream& operator<<(std::ostream& out, const atcoder::modint998244353 &e) {
    out << e.val();
    return out;
}

std::ostream& operator<<(std::ostream& out, const atcoder::modint &e) {
    out << e.val();
    return out;
}