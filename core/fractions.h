//
// Created by liember on 12/16/20.
//

#ifndef LIEENGINE_FRACTIONS_H
#define LIEENGINE_FRACTIONS_H

namespace lieEngine::core::math {

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <exception>
#include <utility>

    class Fraction {
    private:
        long numerator{}, denominator{};

        long euclidean(long a, long b);

    public:
        Fraction();

        [[maybe_unused]] explicit Fraction(double Number);

        [[maybe_unused]] explicit Fraction(const std::string &FractionString);

        ~Fraction() = default;

        [[nodiscard]] long getNumerator() const;

        [[nodiscard]] long getDenominator() const;

        void setNumerator(long Numerator);

        void setDenominator(long Denominator);

        bool reduce();

        void convertDoubleToFraction(double Number);

        [[nodiscard]] double convertFractionToDouble() const;

        bool convertStringToFraction(const std::string &FractionString);

        bool operator<(const Fraction &fraction) const;

        bool operator<=(const Fraction &fraction) const;

        bool operator>(const Fraction &fraction) const;

        bool operator>=(const Fraction &fraction) const;

        bool operator==(const Fraction &fraction) const;

        bool operator!=(const Fraction &fraction) const;

        long operator%(const Fraction &fraction) const;

        explicit operator double() const;

        explicit operator float() const;

        explicit operator long() const;

        explicit operator std::string() const;

        Fraction operator+(const Fraction &fraction) const;

        Fraction operator+=(const Fraction &fraction);

        Fraction operator-=(const Fraction &fraction);

        Fraction operator-(const Fraction &fraction) const;

        Fraction operator*(const Fraction &fraction) const;

        Fraction operator*=(const Fraction &fraction);

        Fraction operator/(const Fraction &fraction) const;

        Fraction operator/=(const Fraction &fraction);

        Fraction operator~();

        Fraction operator++();

        Fraction operator--();
    };

    std::ostream &operator<<(std::ostream &out, Fraction &Fraction);

    std::istream &operator>>(std::istream &in, Fraction &Fraction);

    Fraction::Fraction() {
        this->numerator = 0;
        this->denominator = 0;
    }

    [[maybe_unused]] Fraction::Fraction(double Number) {
        this->convertDoubleToFraction(Number);
    }

    [[maybe_unused]] Fraction::Fraction(const std::string &FractionString) {
        this->convertStringToFraction(FractionString);
    }


    long Fraction::euclidean(long a, long b) {
        return b == 0 ? a : this->euclidean(b, a % b);
    }

    long Fraction::getNumerator() const {
        return this->numerator;
    }

    long Fraction::getDenominator() const {
        return this->denominator;
    }

    void Fraction::setNumerator(long Numerator) {
        this->numerator = Numerator;
    }

    void Fraction::setDenominator(long Denominator) {
        this->denominator = Denominator;
    }

    bool Fraction::reduce() {
        long gcd(this->euclidean(this->numerator, this->denominator));

        if (1 < gcd) {
            this->numerator /= gcd;
            this->denominator /= gcd;

            return true;
        } else {
            return false;
        }
    }

    void Fraction::convertDoubleToFraction(double Number) {
        this->denominator = 1;

        while (((double) (int) Number) != Number) {
            Number = Number * 10;
            this->denominator = this->denominator * 10;
        }

        this->numerator = (long) Number;

        this->reduce();
    }

    double Fraction::convertFractionToDouble() const {
        return (double) this->numerator / (double) this->denominator;
    }

    bool Fraction::convertStringToFraction(const std::string &FractionString) {
        std::size_t pos = FractionString.find('/');

        if (pos != std::string::npos) {
            try {
                this->numerator = atol(FractionString.substr(0, pos).c_str());
                this->denominator = atol(FractionString.substr(pos + 1).c_str());
            } catch (...) {
                return false;
            }

            return this->denominator != 0;
        }

        return false;
    }

    bool Fraction::operator<(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) < (fraction.getNumerator() * this->denominator);
    }

    bool Fraction::operator<=(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) <= (fraction.getNumerator() * this->denominator);
    }

    bool Fraction::operator>(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) > (fraction.getNumerator() * this->denominator);
    }

    bool Fraction::operator>=(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) >= (fraction.getNumerator() * this->denominator);
    }

    bool Fraction::operator==(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) == (fraction.getNumerator() * this->denominator);
    }

    bool Fraction::operator!=(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) != (fraction.getNumerator() * this->denominator);
    }

    long Fraction::operator%(const Fraction &fraction) const {
        long result;

        result = ((this->numerator * fraction.getDenominator()) % (this->denominator * fraction.getNumerator())) /
                 (this->denominator * fraction.getDenominator());

        return result;
    }

    Fraction::operator double() const {
        return this->convertFractionToDouble();
    }

    Fraction::operator float() const {
        return (float) this->convertFractionToDouble();
    }

    Fraction::operator long() const {
        return (long) this->convertFractionToDouble();
    }

    Fraction::operator std::string() const {
        std::stringstream output;
        output << this->getNumerator() << "/" << this->getDenominator();

        return output.str();
    }

    Fraction Fraction::operator+(const Fraction &fraction) const {
        Fraction resultFraction;

        if (this->denominator == fraction.getDenominator()) {
            resultFraction.setNumerator(this->numerator + fraction.getNumerator());
            resultFraction.setDenominator(this->denominator);
        } else {
            resultFraction.setNumerator(
                    (this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator));
            resultFraction.setDenominator(this->denominator * fraction.getDenominator());
        }

        return resultFraction;
    }

    Fraction Fraction::operator+=(const Fraction &fraction) {
        if (this->denominator == fraction.getDenominator()) {
            this->numerator += fraction.getNumerator();
        } else {
            this->numerator =
                    (this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator);
            this->denominator *= fraction.getDenominator();
        }

        return *this;
    }

    Fraction Fraction::operator-(const Fraction &fraction) const {
        Fraction resultFraction;

        if (this->denominator == fraction.getDenominator()) {
            resultFraction.setNumerator(this->numerator - fraction.getNumerator());
            resultFraction.setDenominator(this->denominator);
        } else {
            resultFraction.setNumerator(
                    (this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator));
            resultFraction.setDenominator(this->denominator * fraction.getDenominator());
        }

        return resultFraction;
    }

    Fraction Fraction::operator-=(const Fraction &fraction) {
        if (this->denominator == fraction.getDenominator()) {
            this->numerator -= fraction.getNumerator();
        } else {
            this->numerator =
                    (this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator);
            this->denominator *= fraction.getDenominator();
        }

        return *this;
    }

    Fraction Fraction::operator*(const Fraction &fraction) const {
        Fraction resultFraction;

        resultFraction.setNumerator(this->numerator * fraction.getNumerator());
        resultFraction.setDenominator(this->denominator * fraction.getDenominator());

        return resultFraction;
    }

    Fraction Fraction::operator*=(const Fraction &fraction) {
        this->denominator *= fraction.getDenominator();
        this->numerator *= fraction.getNumerator();

        return *this;
    }

    Fraction Fraction::operator/(const Fraction &fraction) const {
        Fraction resultFraction;

        resultFraction.setDenominator(this->denominator * fraction.getNumerator());
        resultFraction.setNumerator(this->numerator * fraction.getDenominator());

        return resultFraction;
    }

    Fraction Fraction::operator/=(const Fraction &fraction) {
        this->denominator *= fraction.getNumerator();
        this->numerator *= fraction.getDenominator();

        return *this;
    }

    Fraction Fraction::operator~() {
        Fraction resultFraction;

        if (this->numerator > this->denominator) {
            return *this;
        } else {
            resultFraction.setNumerator(this->denominator - this->numerator);
            resultFraction.setDenominator(this->denominator);

            return resultFraction;
        }
    }

    Fraction Fraction::operator++() {
        this->numerator += 1;

        return *this;
    }

    Fraction Fraction::operator--() {
        this->numerator -= 1;

        return *this;
    }

    std::ostream &operator<<(std::ostream &out, Fraction &Fraction) {
        out << Fraction.getNumerator() << "/" << Fraction.getDenominator();

        return out;
    }

    std::istream &operator>>(std::istream &in, Fraction &Fraction) {
        std::string input;

        in >> input;

        if (!Fraction.convertStringToFraction(input)) {
            // Throw own exception object
            throw std::exception();
        }

        return in;
    }
}
#endif //LIEENGINE_FRACTIONS_H
