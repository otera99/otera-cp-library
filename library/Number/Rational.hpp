#ifndef OTERA_RATIONAL_HPP
#define OTERA_RATIONAL_HPP 1

namespace otera{
    template<typename T>
    struct Rational {
        public:
            Rational() : Rational(0) {}
            Rational(T n) : num(n), den(1) {}
            Rational(T n, T d) {
                assert(d != 0);
                if(n == 0) num = 0, den = 1;
                else {
                    T g = std::gcd(n, d);
                    n /= g, d /= g;
                    if (d < 0) n = -n, d = -d;
                    num = n, den = d;
                }
            }

            T numerator() const { return num; }
            T denominator() const { return den; }

            // return (x > 0 ? 1 : x == 0 ? 0 : -1)
            int sgn() const {
                return -1 + (num >= 0) + (num > 0);
            }
            // return (l > r ? 1 : l == r ? 0 : -1)
            static int compare(const Rational &l, const Rational &r) {
                T g = std::abs(std::gcd(l.den, r.den));
                T val = r.den / g * l.num - l.den / g * r.num;
                return -1 + (val >= 0) + (val > 0);
            }

            friend bool operator<(const Rational &l, const Rational &r) {
                return compare(l, r) < 0;
            }
            friend bool operator>(const Rational &l, const Rational &r) {
                return compare(l, r) > 0;
            }
            friend bool operator<=(const Rational &l, const Rational &r) {
                return compare(l, r) <= 0;
            }
            friend bool operator>=(const Rational &l, const Rational &r) {
                return compare(l, r) >= 0;
            }
            friend bool operator==(const Rational &l, const Rational &r) {
                return compare(l, r) == 0;
            }
            friend bool operator!=(const Rational &l, const Rational &r) {
                return compare(l, r) != 0;
            }

            Rational operator+() const {
                return *this;
            }
            Rational operator-() const {
                return Rational(-num, den);
            }
            friend Rational operator+(const Rational &l, const Rational &r) {
                T lcm = l.den / std::gcd(l.den, r.den) * r.den;  
                lcm = std::abs(lcm);
                return Rational(l.num * (lcm / l.den) + r.num * (lcm / r.den), lcm);
            }
            friend Rational operator-(const Rational &l, const Rational &r) {
                T lcm = l.den / std::gcd(l.den, r.den) * r.den;
                lcm = std::abs(lcm);
                return Rational(l.num * (lcm / l.den) - r.num * (lcm / r.den), lcm);
            }
            friend Rational operator*(const Rational &l, const Rational &r) {
                T g1 = std::gcd(std::abs(l.num), std::abs(r.den));  g1 = std::abs(g1);
                T g2 = std::gcd(l.den, r.num);  g2 = std::abs(g2);
                return Rational((l.num / g1) * (r.num / g2), (l.den / g2) * (r.den / g1));
            }
            friend Rational operator/(const Rational &l, const Rational &r) {
                return l * r.inv();
            }
            Rational& operator+=(const Rational &r) {
                *this = *this + r;
                return *this;
            }
            Rational& operator-=(const Rational &r) {
                *this = *this - r;
                return *this;
            }
            Rational& operator*=(const Rational &r) {
                *this = *this * r;
                return *this;
            }
            Rational& operator/=(const Rational &r) {
                *this = *this / r;
                return *this;
            }
            Rational& operator++() {
                num += den;
                return *this;
            }
            Rational& operator--() {
                num -= den;
                return *this;
            }
            Rational inv() const {
                return Rational(den, num);
            }
            Rational abs() const {
                return Rational(std::abs(num), den);
            }
            Rational pow(long long _n) const {
                if(!_n) return Rational(1);
                Rational res = pow(_n>>1);
                res *= res;
                if(_n & 1) res *= *this;
                return res;
            }

            explicit operator int() const {
                return (int)(num / den);
            }
            explicit operator long long() const {
                return (long long)(num / den);
            }
            explicit operator double() const {
                return (double)num / (double)den;
            }
            explicit operator long double() const {
                return (long double)num / (long double)den;
            }

            T floor() const {
                return num >= 0 ? num / den : -(-num / den);
            }
            T ceil() const {
                return num >= 0 ? -(-num / den) : num / den;
            }

            friend std::ostream &operator<<(std::ostream &os, const Rational &r) {
                return os << r.num << "/" << r.den;
            }

        private:
            T num, den;
    };
}

template <typename T>
otera::Rational<T> max(const otera::Rational<T> &l, const otera::Rational<T> &r) {
    return l > r ? l : r;
}
template <typename T>
otera::Rational<T> min(const otera::Rational<T> &l, const otera::Rational<T> &r) {
    return l < r ? l : r;
}

#endif // OTERA_RATIONAL_HPP