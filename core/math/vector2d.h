//
// Created by liember on 12/16/20.
//

#ifndef LIEENGINE_VECTOR2D_H
#define LIEENGINE_VECTOR2D_H

#include <cmath>
#include <iostream>

namespace lieEngine::math {

    class vector2d {
    private:
        double x{}, y{};

    public:
        explicit vector2d(double nX = 0.0, double nY = 0.0);

        void SetXY(double nX, double nY);

        [[maybe_unused]] void SetDM(double dir, double mag);

        [[maybe_unused]] [[nodiscard]] double GetDir() const;

        [[maybe_unused]] [[nodiscard]] double GetMag() const;

        [[nodiscard]] double X() const;

        [[nodiscard]] double Y() const;

        vector2d &operator+=(const vector2d &v);

        vector2d &operator-=(const vector2d &v);

        vector2d &operator*=(double t);

        vector2d &operator/=(double t);

        vector2d &operator&=(const vector2d &v);

        vector2d operator-() const;

        vector2d operator+(const vector2d &v) const;

        vector2d operator-(const vector2d &v) const;

        vector2d operator*(double t) const;

        vector2d operator/(double t) const;

        bool operator==(const vector2d &v) const;

        bool operator!=(const vector2d &v) const;

        [[maybe_unused]] vector2d &Rotate(double angle);

        friend std::ostream &operator<<(std::ostream &os, const vector2d &v);

        friend std::istream &operator>>(std::istream &is, vector2d &v);
    };

    vector2d::vector2d(double nX, double nY) {
        SetXY(nX, nY);
    }

    void vector2d::SetXY(double nX = 0.0, double nY = 0.0) {
        x = nX;
        y = nY;
    }

    [[maybe_unused]] void vector2d::SetDM(double dir, double mag) {
        x = cos(dir) * mag;
        y = sin(dir) * mag;
    }

    [[maybe_unused]] double vector2d::GetDir() const {
        return atan2(y, x);
    }

    [[maybe_unused]] double vector2d::GetMag() const {
        return hypot(x, y);
    }

    double vector2d::X() const {
        return x;
    }

    double vector2d::Y() const {
        return y;
    }

    vector2d &vector2d::operator+=(const vector2d &v) {
        x += v.x;
        y += v.y;
        return (*this);
    }

    vector2d &vector2d::operator-=(const vector2d &v) {
        x -= v.x;
        y -= v.y;
        return (*this);
    }

    vector2d &vector2d::operator*=(double t) {
        x *= t;
        y *= t;
        return (*this);
    }

    vector2d &vector2d::operator/=(double t) {
        double f = 1.0 / t;
        x *= f;
        y *= f;
        return (*this);
    }

    vector2d &vector2d::operator&=(const vector2d &v) {
        x *= v.x;
        y *= v.y;
        return (*this);
    }

    vector2d vector2d::operator-() const {
        return (vector2d(-x, -y));
    }

    vector2d vector2d::operator+(const vector2d &v) const {
        return (vector2d(x + v.x, y + v.y));
    }

    vector2d vector2d::operator-(const vector2d &v) const {
        return (vector2d(x - v.x, y - v.y));
    }

    vector2d vector2d::operator*(double t) const {
        return (vector2d(x * t, y * t));
    }

    vector2d vector2d::operator/(double t) const {
        double f = 1.0 / t;
        return (vector2d(x * f, y * f));
    }

    bool vector2d::operator==(const vector2d &v) const {
        return ((x == v.x) && (y == v.y));
    }

    bool vector2d::operator!=(const vector2d &v) const {
        return ((x != v.x) || (y != v.y));
    }

    [[maybe_unused]] vector2d &vector2d::Rotate(double angle) {
        double s = sin(angle);
        double c = cos(angle);

        double nx = c * x - s * y;
        double ny = s * x + c * y;

        x = nx;
        y = ny;

        return (*this);
    }

    std::ostream &operator<<(std::ostream &os, const vector2d &v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    std::istream &operator>>(std::istream &is, vector2d &v) {
        double tX, tY;
        is >> tX >> tY;
        v.SetXY(tX, tY);
        return is;
    }

}

#endif //LIEENGINE_VECTOR2D_H
