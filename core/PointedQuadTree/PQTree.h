//
// Created by liember on 1/21/21.
//

#ifndef LIEENGINE_PQTREE_H
#define LIEENGINE_PQTREE_H

#include "PQTree_Node.hpp"
#include "Quadrant.h"
#include "memory"


namespace lieEngine::core::space {

    using namespace lieEngine::core;

    template<typename Units, typename object>
    class PQTree {
    private:
        std::size_t obj_counter;
        const unsigned obj_limit;
    public:
        PQTree_node<Units, object> *tree_root;
        const unsigned deep_limit;
        const Units size;
    public:
        PQTree(unsigned max_deep, Units radius, unsigned max_object = 4) :
                obj_limit(max_object),
                deep_limit(max_deep),
                size(radius * 2),
                tree_root(new PQTree_node<Units, object>(nullptr, radius * 2, -radius, -radius)) {}

        std::vector<object *> getNearOf(math::vector2d<Units> point) {}

        void insert(const math::vector2d<Units> &pos, object *obj) {
            obj_counter++;
            tree_root->insert(deep_limit, 0, obj_limit, pos, obj);
        }

    };
}
#endif //LIEENGINE_PQTREE_H
