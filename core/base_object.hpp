#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "string"
#include "initializer_list"
#include "vector"
#include "utility"
#include "exceptions.hpp"

namespace lieEngine {

    class base_object {
    protected:
        bool update_state;
        bool on_delete;
    public:

        explicit base_object() {
            update_state = true;
            on_delete = false;
        }

        virtual ~base_object() = default;

        [[nodiscard]] bool isOnDelete() const {
            return on_delete;
        }

        [[nodiscard]] bool isUpdate() const {
            return update_state;
        }

        void setUpdate(bool state) {
            update_state = state;
        }

        virtual void update(double time) = 0;

        virtual std::string serialize() = 0;
    };

} // namespace lieEngine
#endif // __OBJECT_H__