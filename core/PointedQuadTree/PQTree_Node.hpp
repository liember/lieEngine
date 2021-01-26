//
// Created by liember on 1/21/21.
//

#ifndef LIEENGINE_PQTREE_NODE_H
#define LIEENGINE_PQTREE_NODE_H

#include "vector2d.h"
#include "base_object.hpp"
#include "Quadrant.h"

#include "memory"
#include "array"
#include "vector"
#include "utility"

/*
 * что быстрее?
 * паралельно сотсавить списки задач и потом обработать их (легче распаралелить на N  потоков)
 * или паралельно решить задачи без списков (надо как то подумать как распаралелить более чем на 4 потока)
 *
 * структура индексации
 * |2|1|
 * |3|4|
 */

namespace lieEngine::core::space {

    /**
     *
     * class for qd_tree structure creation
     * @tparam UNITS units dimension of space
     * @tparam object type of containing object
     */
    template<typename UNITS, typename object>
    class PQTree_node : public lieEngine::core::space::Quadrant<UNITS> {
    public:
        PQTree_node<UNITS, object> *father;
        std::vector<PQTree_node<UNITS, object>> childs;
        std::vector<std::pair<math::vector2d<UNITS>, object *>> objects;


    public:
        PQTree_node(PQTree_node<UNITS, object> *f, const Quadrant<UNITS> &rect) :
                Quadrant<UNITS>(rect),
                father(f) {
        }

        PQTree_node(PQTree_node<UNITS, object> *f, UNITS size, UNITS x, UNITS y) :
                Quadrant<UNITS>(size, x, y),
                father(f) {
        }

        ~PQTree_node() = default;

        void insert(const int deep_limit, const int current_deep, const int max_objs, const math::vector2d<UNITS> &pos,
                    object *obj) {
            if (current_deep < deep_limit) {
                if (isLeaf()) {
                    if (isNotFull(max_objs)) {
                        hard_insert(pos, obj);
                    } else {
                        split();
                        insert(deep_limit, current_deep, max_objs, pos, obj);
                    }
                } else {
                    childs[calculateIndexOf(pos)].insert(deep_limit, current_deep + 1, max_objs, pos, obj);
                }
            } else
                hard_insert(pos, obj);
        }

        auto calculateIndexOf(const math::vector2d<UNITS> &pos) {
            const auto center = this->center();
            if (pos.X() > center.X())
                if (pos.Y() > center.Y())
                    return 0;
                else
                    return 3;
            else if (pos.Y() > center.Y())
                return 1;
            else
                return 2;
        }

        bool isLeaf() {
            return childs.empty();
        }

        bool isNotFull(int limit) {
            return objects.size() < limit;
        }

        /**
         * warning
         * insert object in this node without size and childs check
         * @param pos position of object
         * @param obj pointer on object
         */
        void hard_insert(const math::vector2d<UNITS> &pos, object *obj) {
            objects.emplace_back(pos, obj);
        }

        bool split() {
            if (childs.empty()) {
                auto center = this->center();
                auto new_size = this->sideSize() / 2;

                childs.emplace_back(this, new_size, center.X(), center.Y());
                childs.emplace_back(this, new_size, center.X() - new_size, center.Y());
                childs.emplace_back(this, new_size, center.X() - new_size, center.Y() - new_size);
                childs.emplace_back(this, new_size, center.X(), center.Y() - new_size);

                for (auto[xy, obj]: objects) {
                    childs[calculateIndexOf(xy)].hard_insert(xy, obj);
                }
                objects.clear();
                return true;
            }
            return false;
        }

        // TODO make serialization method
        [[nodiscard]] std::string serialize() const override {
            std::stringstream ss;
            ss << "Quadrant lalalal ";
            return ss.str();
        }

    };

}
#endif //LIEENGINE_PQTREE_NODE_H
