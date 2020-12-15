#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "string"
#include "exceptions.hpp"
#include "initializer_list"
#include "vector"

namespace lieEngine {

    class object {
    protected:
        object *father{};
        bool updateable;
        bool on_delete;
    public:
        bool isOnDelete() const;

    protected:
        std::vector<object *> childs;
    public:
        bool isUpdateable() const;

        void setUpdateable(bool updateable);

        object *getFather() const;

        void setFather(object *father);

        virtual void update(double time) = 0;

        virtual void draw() = 0;

        virtual ~object() = default;

        virtual std::string serialize() = 0;

        explicit object(object *f);

        object(object *f, std::initializer_list<object *> _childs);
    };

} // namespace lieEngine
#endif // __OBJECT_H__