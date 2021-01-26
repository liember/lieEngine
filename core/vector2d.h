//
// Created by liember on 12/16/20.
//

#ifndef LIEENGINE_VECTOR2D_H
#define LIEENGINE_VECTOR2D_H

#include <cmath>
#include <iostream>

namespace lieEngine::core::math {

    template<typename T>
    class vector2d {
    private:
        T x, y;

    public:
        vector2d(T nX = 0.0, T nY = 0.0) {
            SetXY(nX, nY);
        }

        void SetXY(T nX, T nY) {
            x = nX;
            y = nY;
        }

        [[maybe_unused]] void SetDM(T dir, T mag) {
            x = cos(dir) * mag;
            y = sin(dir) * mag;
        }

        [[maybe_unused]] [[nodiscard]] T GetDir() const {
            return atan2(y, x);
        }

        [[maybe_unused]] [[nodiscard]] T GetMag() const {
            return hypot(x, y);
        }

        [[maybe_unused]] vector2d &Rotate(T angle) {
            T s = sin(angle);
            T c = cos(angle);

            T nx = c * x - s * y;
            T ny = s * x + c * y;

            x = nx;
            y = ny;

            return (*this);
        }

        [[nodiscard]] T X() const { return x; }

        [[nodiscard]] T Y() const { return y; }

        vector2d &operator+=(const vector2d &v) {
            x += v.x;
            y += v.y;
            return (*this);
        }

        vector2d &operator-=(const vector2d &v) {
            x -= v.x;
            y -= v.y;
            return (*this);
        }

        vector2d &operator*=(T t) {
            x *= t;
            y *= t;
            return (*this);
        }

        vector2d &operator/=(T t) {
            T f = 1.0 / t;
            x *= f;
            y *= f;
            return (*this);
        }

        vector2d &operator&=(const vector2d &v) {
            x *= v.x;
            y *= v.y;
            return (*this);
        }

        vector2d operator-() const {
            return (vector2d(-x, -y));
        }

        vector2d operator+(const vector2d &v) const {
            return (vector2d(x + v.x, y + v.y));
        }

        vector2d operator-(const vector2d &v) const {
            return (vector2d(x - v.x, y - v.y));
        }

        vector2d operator*(T t) const {
            return (vector2d(x * t, y * t));
        }

        vector2d operator/(T t) const {
            T f = 1.0 / t;
            return (vector2d(x * f, y * f));
        }

        bool operator==(const vector2d &v) const {
            return ((x == v.x) && (y == v.y));
        }

        bool operator!=(const vector2d &v) const {
            return ((x != v.x) || (y != v.y));
        }

        friend std::ostream &operator<<(std::ostream &os, const vector2d &v) {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }

        friend std::istream &operator>>(std::istream &is, vector2d &v) {
            T tX, tY;
            is >> tX >> tY;
            v.SetXY(tX, tY);
            return is;
        }
    };
}

#endif //LIEENGINE_VECTOR2D_H
