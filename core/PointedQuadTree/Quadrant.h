//
// Created by liember on 1/21/21.
//

#ifndef LIEENGINE_RECTANGLE_H
#define LIEENGINE_RECTANGLE_H

#include "vector2d.h"
#include "base_object.hpp"
#include <algorithm>
#include "sstream"

namespace lieEngine::core::space {

    using namespace lieEngine::core;

    /**
     * persistent data structure for PQTree
     * @tparam T number type for coords and size
     */
    template<class T>
    class Quadrant : public lieEngine::core::base_object {
    private:
        math::vector2d <T> position;
        T side_size;
    public:
        //TODO serialization method
        [[nodiscard]] std::string serialize() const override {
            std::stringstream ss;
            ss << "Quadrant { position { x:" << position.X() << " y:" << position.Y() << " } side size:" << side_size
               << " }";
            return ss.str();
        }

        constexpr Quadrant(const Quadrant<T> &source) noexcept:
                position(source.position), side_size(source.side_size) {}

        constexpr Quadrant(T side, math::vector2d <T> &pos) noexcept:
                side_size(side), position(pos) {}

        constexpr Quadrant(T side, T x, T y) noexcept:
                side_size(side), position(x, y) {}

        constexpr T posX() const { return position.X(); }

        constexpr T posY() const { return position.Y(); }

        constexpr T sideSize() const { return side_size; }

        constexpr math::vector2d <T> center() const {
            auto half_side = side_size / 2;
            math::vector2d <T> res(position.X() + half_side, position.Y() + half_side);
            return res;
        }

        /**
        *
        * @param point which shoud find in quadrant
        * @return true if point containing by this quadrant
        */
        // TODO make branch prediction benchmark
        // 25% that point containing in this quadrant because we use 4 quadrants
        constexpr bool contains(math::vector2d <T> point) const {
            if (point.X() > position.X() && point.X() < position.X() + side_size) {
                if (point.Y() > position.Y() && point.Y() < position.Y() + side_size) {
                    return true;
                }
            }
            return false;
        }

        constexpr T intersectArea(const Quadrant<T> &q) const {
            return f(position.X(), position.Y(), position.X() + side_size, position.Y() + side_size, q.position.X(),
                     q.position.Y(), q.position.X() + q.side_size, q.position.Y() + q.side_size);
        }

    private:
        /**
         *
         * @param x1 left low point X of first quad
         * @param y1 left low point Y of first quad
         * @param x2 right up point X of first quad
         * @param y2 right up point Y of first quad
         * @param x3 left low point X of second quad
         * @param y3 left low point Y of second quad
         * @param x4 left up point X of second quad
         * @param y4 left up point Y of second quad
         * @return intersect area
         */
        constexpr T f(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) const {
            auto left = std::max(x1, x3);
            auto top = std::min(y2, y4);
            auto right = std::min(x2, x4);
            auto bottom = std::max(y1, y3);

            auto width = right - left;
            auto height = top - bottom;

            if (width < 0 || height < 0)
                return 0;

            return width * height;
        }
    };
}
#endif //LIEENGINE_RECTANGLE_H
