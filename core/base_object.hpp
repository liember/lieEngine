#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "string"
#include "initializer_list"
#include "vector"
#include "utility"
#include "exceptions.hpp"
#include "sstream"

namespace lieEngine::core {

    class [[maybe_unused]] base_object {
    protected:
        bool update_state;
        bool on_delete;
    public:

        explicit base_object() : update_state(true), on_delete(false) {};

        virtual ~base_object() = default;

        [[nodiscard]] virtual std::string serialize() const  = 0;

        [[maybe_unused]] [[nodiscard]] bool isOnDelete() const { return on_delete; }

        [[nodiscard]] bool isUpdate() const { return update_state; }

        [[maybe_unused]] void setUpdateState(bool state) { update_state = state; }
    };

} // namespace lieEngine
#endif // __OBJECT_H__