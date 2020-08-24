#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "core.hpp"

#include <string>

/* components is 

- data ( just contain data )
- updaters ( update object every frame )
- modificators ( use data from out of object and updates in separately of update sycle )

*/
namespace Component
{

    namespace Data
    {
        class String : public std::string
        {
        };

        class Integer
        {
        private:
            long _value;

        public:
            long Get() const { return _value; }
            explicit Integer(long value) { _value = value; }

            void Set(int n_val) { _value = n_val; }
            void operator+=(Integer i);
            void operator+=(long i);
            void operator-=(Integer i);
            void operator-=(long i);
            void operator*=(Integer i);
            void operator*=(long i);
            void operator/=(Integer i);
            void operator/=(long i);
        };

        class Floating
        {
        private:
            double _value;

        public:
            double Get() const { return _value; }
            void Set(double n_val) { _value = n_val; }
            explicit Floating(double value) { _value = value; }

            void operator+=(Floating i);
            void operator+=(long i);
            void operator-=(Floating i);
            void operator-=(long i);
            void operator*=(Floating i);
            void operator*=(long i);
            void operator/=(Floating i);
            void operator/=(long i);
        };
    } // namespace Data

    namespace Updater
    {
        namespace
        {
            class Updateable
            {
            private:
            public:
                virtual void Update() = 0;
                Updateable();
                virtual ~Updateable() {}
            };

        } // namespace

        template <class T>
        class Speed : public Updateable
        {
        private:
            T _val;
            T &pos;

        public:
            void Set(T n_val) { _val = n_val; }
            void Update() override { pos += _val.Get(); }
            Speed(T &pos_data, T val) : pos(pos_data), _val(val) {}
            ~Speed();
        };

    } // namespace Updater

    namespace Modificator
    {
        class ClickArea
        {
        private:
            const Component::Data::Floating &x_pos;
            const Component::Data::Floating &y_pos;
            const Component::Data::Integer &width;
            const Component::Data::Integer &height;

            const Core::Coursor &mouse;

            bool clicked;
            bool holded;
            bool hovered;

        public:
            bool isClecked() const;
            bool isHovered() const;
            bool isHold() const;

            bool Update();

            ClickArea(const Core::Coursor &cours,
                      const Component::Data::Floating &x,
                      const Component::Data::Floating &y,
                      const Component::Data::Integer &w,
                      const Component::Data::Integer &h);
            ~ClickArea();
        };

    } // namespace Modificator

} // namespace Component
