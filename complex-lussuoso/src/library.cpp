#include "library.hpp"  // Исправлено с library.hpp на complex.h
#include <cmath>
#include <stdexcept>

namespace template_library {
    Complex::Complex() : m_real(0.0), m_imag(0.0) {}
    
    Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}
    
    double Complex::real() const {
        return m_real;
    }

    double Complex::imag() const {
        return m_imag;
    }

    Complex Complex::operator+(const Complex& other) const {
        return Complex(m_real + other.m_real, m_imag + other.m_imag);
    }

    Complex Complex::operator-(const Complex& other) const {
        return Complex(m_real - other.m_real, m_imag - other.m_imag);
    }

    Complex Complex::operator*(const Complex& other) const {
        return Complex(
            m_real * other.m_real - m_imag * other.m_imag,
            m_real * other.m_imag + m_imag * other.m_real
        );
    }

    Complex Complex::operator/(const Complex& other) const {
        double denominator = other.m_real * other.m_real + other.m_imag * other.m_imag;  // Исправлено deno на denominator
        if (denominator == 0) {
            throw std::runtime_error("Division by zero complex number");
        }
        return Complex(
            (m_real * other.m_real + m_imag * other.m_imag) / denominator,
            (m_imag * other.m_real - m_real * other.m_imag) / denominator
        );    
    }

    Complex operator*(double m, const Complex& other) {  // Убрана лишняя точка с запятой
        return Complex(m * other.m_real, m * other.m_imag);
    }

    Complex operator*(const Complex& other, double m) {
        return Complex(m * other.m_real, m * other.m_imag);
    }

    std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.m_real;
        if (c.m_imag >= 0) {
            os << " + " << c.m_imag << "i)";
        } else {
            os << " - " << -c.m_imag << "i)";
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Complex& c) {
        char ch;
        is >> ch; 
        is >> c.m_real;
        is >> ch; 
        double imagAbs;
        is >> imagAbs;
        if (ch == '-') {
            imagAbs = -imagAbs;
        }
        c.m_imag = imagAbs;
        is >> ch; // 'i'
        is >> ch; // ')'
        return is;
    }
}