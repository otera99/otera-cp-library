// UNFINISHED
#ifndef OTERA_FPS_HPP
#define OTERA_FPS_HPP 1

#include<atcoder/convolution>

namespace otera {
    template<typename T>
    struct fps : std::vector<T> {
        using std::vector<T>::vector;
        
        void shrink() {
            while(this->size() and this->back() == T(0)) {
                this->pop_back();
            }
        }

        void ensure(int n) {
            this->resize(n, T(0));
        }

        fps pre(int n) const {
            if((int)this->size() < n) {
                fps ret(*this);
                ret.resize(n, T(0));
                return ret;
            }
            return fps(begin(*this), begin(*this) + n);
        }

        fps rev(int n = -1) const {
            fps ret(*this);
            if(n != -1) ret.resize(n, T(0));
            reverse(begin(ret), end(ret));
            return ret;
        }

        fps operator+(const fps &r) const { return fps(*this) += r; }
        fps operator+(const T &v) const { return fps(*this) += v; }
        fps operator-(const fps &r) const { return fps(*this) -= r; }
        fps operator-(const T &v) const { return fps(*this) -= v; }
        fps operator*(const fps &r) const { return fps(*this) *= r; }
        fps operator*(const T &v) const { return fps(*this) *= v; }
        fps operator/(const fps &r) const { return fps(*this) /= r; }
        fps operator%(const fps &r) const { return fps(*this) %= r; }

        fps &operator+=(const fps &r) {
            if(r.size() > this->size()) this->resize(r.size());
            for(int i = 0; i < (int)r.size(); ++ i) (*this)[i] += r[i];
            return *this;
        }

        fps &operator-=(const fps &r) {
            if(r.size() > this->size()) this->resize(r.size());
            for(int i = 0; i < (int)r.size(); ++ i) (*this)[i] -= r[i];
            return *this;
        }

        fps &operator*=(const fps &r) {
            if(this->empty() or r.empty()) {
                this->clear();
                return *this;
            }
            auto ret = atcoder::convolution(*this, r);
            return *this = {begin(ret), end(ret)};
        }

        fps &operator/=(const fps &r) {
            if(this->size() < r.size()) {
                this->clear();
                return *this;
            }
            int n = (int)this->size() - r.size() + 1;
            return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
        }

        fps &operator%=(const fps &r) {
            return *this -= *this / r * r;
        }

        fps operator-() const {
            fps ret(this->size());
            for(int i = 0; i < (int)this->size(); ++ i) ret[i] = -(*this)[i];
            return ret;
        }

        fps &operator+=(const T &r) {
            if(this->empty()) this->resize(1);
            (*this)[0] += r;
            return *this;
        }

        fps &operator-=(const T &r) {
            if(this->empty()) this->resize(1);
            (*this)[0] -= r;
            return *this;
        }

        fps &operator*=(const T &v) {
            for(int i = 0; i < (int)this->size(); ++ i) (*this)[i] *= v;
            return *this;
        }

        fps operator>>(int sz) const {
            if((int)this->size() <= sz) return {};
            fps ret(*this);
            ret.erase(ret.begin(), ret.begin() + sz);
            return ret;
        }

        fps operator<<(int sz) const {
            fps ret(*this);
            ret.insert(ret.begin(), sz, T(0));
            return ret;
        }

        T operator()(T x) const {
            T r = 0, w = 1;
            for(auto &v : *this) {
                r += w * v;
                w *= x;
            }
            return r;
        }

        fps diff() const {
            const int n = (int) this->size();
            fps ret(std::max(0, n - 1));
            for(int i = 1; i < n; ++ i) ret[i - 1] = (*this)[i] * T(i);
            return ret;
        }

        fps integral() const {
            const int n = (int) this->size();
            fps ret(n + 1);
            ret[0] = T(0);
            for(int i = 0; i < n; ++ i) ret[i + 1] = (*this)[i] / T(i + 1);
            return ret;
        }

        fps inv(int deg = -1) const {
            assert(((*this)[0]) != T(0));
            if(deg == -1) deg = (int)this->size();
            fps ret({T(1) / (*this)[0]});
            for(int i = 1; i < deg; i <<= 1) {
                ret = (ret + ret - ret * ret * pre(i<<1)).pre(i<<1);
            }
            return ret.pre(deg);
        } 

        fps log(int deg = -1) const {
            assert((*this)[0] == T(1));
            if(deg == -1) deg = (int)this->size();
            return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
        }

        fps exp(int deg = -1) const {
            if(deg == -1) deg = (int)this->size();
            assert((*this)[0] == T(0));
            fps ret({T(1)});
            for(int i = 1; i < deg; i <<= 1) {
                ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
            }
            return ret.pre(deg);
        }

        fps pow(long long k, int deg = -1) const {
            const int n = (int)this->size();
            if(deg == -1) deg = n;
            if(k == 0) {
                fps ret(deg, T(0));
                ret[0] = T(1);
                return ret;
            }  
            for(int i = 0; i < n; i++) {
                if(i * k > deg) return fps(deg, T(0));
                if((*this)[i] != T(0)) {
                    T rev = T(1) / (*this)[i];
                    fps ret = ((((*this) * rev) >> i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));
                    ret = (ret << (i * k)).pre(deg);
                    if((int)ret.size() < deg) ret.resize(deg, T(0));
                    return ret;
                }
            }
            return FPS(deg, T{0});
        }
    };
} // namespace otera

#endif // OTERA_FPS_HPP