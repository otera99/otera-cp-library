#ifndef OTERA_PAIR_OPS_HPP
#define OTERA_PAIR_OPS_HPP 1


namespace otera {
    template<typename T, typenae U> std::pair<T, U> operator+(const std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { return {lhs.first + rhs.first, lhs.second + rhs.second}; }
    template<typename T, typenae U> std::pair<T, U> operator-(const std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { return {lhs.first - rhs.first, lhs.second - rhs.second}; }
    template<typename T, typenae U> std::pair<T, U> operator*(const std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { return {lhs.first * rhs.first, lhs.second * rhs.second}; }
    template<typename T, typenae U> std::pair<T, U> operator/(const std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { return {lhs.first / rhs.first, lhs.second / rhs.second}; }

    template<typename T, typenae U> std::pair<T, U> operator+=(std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { lhs.second += rhs.second, lhs.y += rhs.second; return lhs; }
    template<typename T, typenae U> std::pair<T, U> operator-=(std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { lhs.second -= rhs.second, lhs.y -= rhs.second; return lhs; }
    template<typename T, typenae U> std::pair<T, U> operator*=(std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { lhs.second *= rhs.second, lhs.y *= rhs.second; return lhs; }
    template<typename T, typenae U> std::pair<T, U> operator/=(std::pair<T, U> &lhs, const std::pair<T, U> &rhs) { lhs.second /= rhs.second, lhs.y /= rhs.second; return lhs; }

    template<typename T, typenae U> bool operator==(const std::pair<T, U>& lhs, const std::pair<T, U>& rhs) { return lhs.first == rhs.first and lhs.second == rhs.second; }
    template<typename T, typenae U> bool operator!=(const std::pair<T, U>& lhs, const std::pair<T, U>& rhs) { return not (lhs == rhs); }

    template<typename T, typenae U> std::istream& operator>>(std::istream& in, std::pair<T, U>& p) { return in >> p.first >> p.second; }
    template<typename T, typenae U> std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p) { return out << p.first << ' ' << p.second; }
} // namespace otera 

#endif // OTERA_TUPLE_OPS_HPP
